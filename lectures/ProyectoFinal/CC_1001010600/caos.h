#include <raylib.h>
#include <cmath>

const double pi{3.14159265358}; //pi
const double g{9.81}; //Gravedad
using namespace std;

class Ball{
	
	public:
	
		Ball(double x, double y, double vx,  double vy, double t, double R){
			this->x0 = x; this->x = x0;
			this->y0 = y; this->y = y0;
			this->vx = vx; this->R = R;
			this->vy = vy;
			this->t = t;
			this->ang = 0;
		}
		
		void rebote(){
			if( x*x + y*y > R*R){
			    	v = sqrt(2*g*(y0 - y));
			    	if(x>0){
				    	if(vx>0)
				    		ang = abs(atan(vy/vx)) + atan(x*pow(R*R - x*x, -0.5));
				    	else if(vx<0)
				    		ang = 2*abs(atan(vy/vx)) + atan(x*pow(R*R - x*x, -0.5));
				    	else
				    		ang = 0.5*pi + 2*atan(x*pow(R*R - x*x, -0.5));
			    	}
			    	else{
				    	if(vx<0)
				    		ang = pi - abs(atan(vx/vy)) + atan(x*pow(R*R - x*x, -0.5));
				    	else if(vx>0)
			    			ang = abs(atan(vy/vx));
			    	}
			    	vx = v*cos(ang);
			    	vy = v*sin(ang);
			    	x = xp;
			    	y = yp;
            	
            		}
		}
		 	
		void evolVy(){
			vy = vy - g*t;
		}
		
		double xPos(){
			xp = x;
			x = x + t*vx;
			rebote();
			return x;
		}
		
		double yPos(){
			yp = y;
			evolVy();
			y = y + t*vy - 0.5*g*t*t;
			rebote();
			return y;
		}
	
	private:
	
	double x0, y0; //Posiciones iniciales
	double x, y; //Poisiciones en t
	double xp, yp; //Posiciones auxiliares
	
	double vx, vy; //Velocidades
	double v; //Velocidad total
	
	double R;
	double ang; //Angulo de rebote
	double t; //Paso de tiempo
	
	
};
