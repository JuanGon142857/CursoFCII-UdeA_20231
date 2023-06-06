#include <raylib.h>
#include <cmath>
#include <iostream>
#include "caos.h"

using namespace std;

const unsigned int height{900}, width{1200};	// Window size
const unsigned int Radius{400};		 	// Radius of the circle
const double cX{width*0.5}, cY{height*0.2};	// Center of the circle
const unsigned int FPS = 120; 

Color colorSel(unsigned int i);

int main()
{
    //Window
    InitWindow(width, height, "CAOS IN A CIRCUNFERENCE");  
    SetTargetFPS(FPS);
    
    //Audio
    InitAudioDevice();
    Sound sound = LoadSound("prelude.mp3");
    PlaySound(sound);

    //***********BALLS**********************
    unsigned int N = 100;//Num de pelotas
    Ball *balls[N];
    
    for(unsigned int i = 0; i<N; i++){
    	balls[i] = new Ball(100 + i*1e-3, 0, 0, 0, 0.05, Radius); //double x, double y, double vx,  double vy, double t, double R
    }
    //**************************************
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            
            //**************BACKGROUND**************
            DrawText(TextFormat("Numero de pelotas %03i", N), 100, 750, 40, LIGHTGRAY);
            
            DrawText("Musica: Prelude - Bach (8bits)", 100, 800, 40, LIGHTGRAY);
            
            //Draws center of circle
            DrawCircle(width*0.5, height*0.2, 5, WHITE);    
            
            //Draws a circle in the window
            DrawCircleLines(width*0.5, height*0.2, Radius, WHITE);
            DrawCircleLines(width*0.5, height*0.2, Radius*1.001, WHITE);
            DrawCircleLines(width*0.5, height*0.2, Radius*1.003, WHITE);
            DrawCircleLines(width*0.5, height*0.2, Radius*1.005, WHITE);
            
            //**************************************
            
            //***********BALLS**********************
            unsigned j = 0;
            for(unsigned int i = 0; i < N; i++){
		Color color = colorSel(j);
		DrawCircle(cX + balls[i]->xPos(), cY - balls[i]->yPos(), 8, color);
		if(i%12 == 0)
			j++;
		if(j==12)
			j=0;
            }
            
            //**************************************
        EndDrawing();
    }

    CloseWindow();

    return 0;
}	

Color colorSel(unsigned int i){
	Color color;
	switch(i){
	case 0:
	 color = {255, 0, 0, 255}; break;
	case 1:
	 color = {255, 127, 0, 255}; break;
	case 2:
	 color = {255, 255, 0, 255}; break;
	case 3:
	 color = {127, 255, 0, 255}; break;
	case 4:
	 color = {0, 255, 0, 255}; break;
	case 5:
	 color = {0, 255, 127, 255}; break;
	case 6:
	 color = {0, 255, 255, 255}; break;
	case 7:
	 color = {0, 127, 255, 255}; break;
	case 8:
	 color = {0, 0, 255, 255}; break;
	case 9:
	 color = {127, 0, 255, 255}; break;
	case 10:
	 color = {255, 0, 255, 255}; break;
	case 11:
	 color = {255, 0, 127, 255}; break;
	}
	return color;
}
	
