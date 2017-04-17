int AxesLib::movx(bool dir)
{
         int bytes_recv = 0;        
  char comm[5]="nost";
        //Serial.println(_x);


  comm[bytes_recv++] = Serial.read();
  //Serial.print("value of comm is ");
  //Serial.println(comm);
  while(strcmp(comm, "stop")!=0)
  {
    if(stepx>2190)
      stepx=2190;
    if(stepx<590)
      stepx=590;
    //Serial.println("inside button ");
    Serial.println(stepx);
   Xservo.writeMicroseconds(stepx); 
   if(dir==false)
   {
   stepx=stepx+5;
   delay(50); 
 }
   if(dir==true)
   {
   stepx=stepx-5;
 delay(50);
 _x=stepx;
 }
   //delay(5);
   while(Serial.available() > 0)
      comm[bytes_recv++] = Serial.read();
                //Serial.println(comm);
                //Serial.println("inside second while");
    //Safeguard...
    if(bytes_recv>4)
      break;
   
}

      
  return stepx;
}

int AxesLib::movy(bool dir)
{
  int bytes_recv = 0;        
  char comm[5]="nost";
        //Serial.println(_x);


  comm[bytes_recv++] = Serial.read();
  //Serial.print("value of comm is ");
  //Serial.println(comm);
  while(strcmp(comm, "stop")!=0)
  {
    if(stepy>2190)
      stepy=2190;
    if(stepy<590)
      stepy=590;
    //Serial.println("inside button ");
    Serial.println(stepy);
   Yservo.writeMicroseconds(stepy); 
   if(dir==false)
   {
   stepy=stepy+5;
   delay(50); 
 }
   if(dir==true)
   {
   stepy=stepy-5;
 delay(50);
 _y=stepy;
 }
   //delay(5);
   while(Serial.available() > 0)
      comm[bytes_recv++] = Serial.read();
    //Safeguard...
    if(bytes_recv>4)
      break;
   
}

      
  return stepy;
}

/*
float AxesLib::getX()
{
  float degx;
  
  if(_x_rev==false) degx = (float) _x/_pgrad_x;
  else{
    if(_x>=_revx)
      degx = (float) (_x-_revx)/_pgrad_x;
    else
      degx = (float) (_x+_revx)/_pgrad_x;
  }
  //_rx = _deg2rad(360.0 - degx);
 _rx = _deg2rad(180.0-degx);
  return _rx;
}*/

float AxesLib::getX()
{
  float degx = _x/_pgrad_x;
 _rx = _deg2rad(180.0-degx);
  return _rx;
}

float AxesLib::getY()
{
  return _y/_pgrad_y;
}

int AxesLib::getPX()
{
  return _pv_x;
}

int AxesLib::getPx()
{
  return _x;
}

int AxesLib::getPY()
{
  return _pv_y;//*4;
}

int AxesLib::getPy()
{
  return _y;
}


int AxesLib::_rad2deg(float rad){
  return lrint( (float) (rad * 180.0)/M_PI );
}

float AxesLib::_deg2rad(float deg){
  return (float) (deg * M_PI)/ 180;
}

/*
void AxesLib::goToRads(float rx, float ry){
  float degsH = (360.0 - _rad2deg(rx));
  if(degsH >= 360.0)
    degsH = degsH - 360.0;
  
  _moveTo((float) degsH*_pgrad_x, (float) _rad2deg(ry)*_pgrad_y);
}*/


void AxesLib::goToRads(float rx, float ry){
  Serial.print("value of rx = ");
        Serial.println(rx);
  float degsH = (_rad2deg(rx));
  Serial.print("value of degsH = ");
        Serial.println(degsH);

  /*
  if(degsH >= 360.0)
    degsH = degsH - 360.0;
  */
  if(degsH >= 170.0)
    degsH = degsH - 170.0;
    
  _moveTo((float) degsH*_pgrad_x, (float) _rad2deg(ry)*_pgrad_y);
}

void AxesLib::_moveTo(int x, int y, char* method){
  _enableMotors();
  
  if(x<0) x = _X - fabs(x);
  if(0<0) y = 0;
  if(x>_X) x = _X;
  if(y>_Y) y = _Y;
  
  //Lets see if X axis has been "reverted" previously..
  if(y>_topy && _x_rev==false){
    _x_rev = true;
    y = _topy - (y-_topy);
    if(x>=_revx)  x = x-_revx;
    else      x = x+_revx;
  }else if(y>_topy && _x_rev){
    y = _topy - (y-_topy);
    if(x>=_revx)  x = x-_revx;
    else      x = x+_revx;
  }else if(_x_rev)
    _x_rev = false;
  
  if(strcmp(method, "DDA")==0)
    _moveDDA(x, y);
  else if(strcmp(method, "XY")==0)
    _moveXY(x, y);
  
  _disableMotors();
}

void AxesLib::_moveXY(int x, int y, bool nodelay){
  if(x>_x)
    _x += _step(_stPin_x, (x>_x), (x-_x), _s360Pin_x, nodelay);
  else
    _x -= _step(_stPin_x, (x>_x), (_x-x), _s0Pin_x, nodelay);
  
  if(y>_y)
    _y += _step(_stPin_y, (y>_y), (y-_y), _stopPin_y, nodelay);
  else
    _y -= _step(_stPin_y, (y>_y), (_y-y), _sbottomPin_y, nodelay);
}

void AxesLib::_moveDDA(int x, int y){
  int dx, dy, steps;
  float x_inc, y_inc, x_, y_;
  
  dx = x-_x;
  dy = y-_y;
  
  if(fabs(dx)>fabs(dy))
    steps = fabs(dx);
  else
    steps = fabs(dy);
    
  x_inc = (float) dx/steps;
  y_inc = (float) dy/steps;
  x_ = _x;
  y_ = _y;
  
  for(int i=1; i<steps+1; i++){
    x_ = x_+x_inc;
    y_ = y_+y_inc;
    _moveXY(lrint(x_), lrint(y_), true);
  }
}
