
The open sky planetarium is an open source education tool for school
kids about planetarium. We know it’s hard to set up planetarium everywhere
across the world as it costs really high. So Open sky planetarium is the solution.

Open sky planetarium uses an open source software called stellarium, the stellarium
gives the real time sky at different locations across the globe. In our project, 
we are using a 5mW laser pointer which has a sharp beam(can be seen with naked eyes)
projection, to point at different planets and stars at open sky, and the moment of 
this laser is controlled by stepper motors.

Working:

The first part that should be done is calibration. In the calibration
we choose three bright stars from the sky and then select the same 
stars in stellarium and set these stars as reference points. To explain
in details, we point at a particular bright star at open sky manually, 
thereby we get two coordinates for that star(x and y), then we select 
the same star from stellarium and we get two  coordinates again for 
that star from stellarium, repeat the same thing for two more stars,
at the end we get three set of coordinates from both hardware and 
stellarium, using these coordinates we calculate a transformation 
matrix and this will be the reference for whole planetarium show.

After the calibration we just have to point at any star that we wish 
to see through stellarium and the pointer will move accordingly. 
In the software we have a plugin which will help us to know details 
about the particular star which is selected, also in the plugin we 
can write the script and run an audio file which narrates story of 
that star chosen.


