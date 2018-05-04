#include<bits/stdc++.h>
#include<graphics.h>
#include"shm_Headers/hermiteGraph.h"
#include"shm_Headers/bresenhamLine.h"
#include"shm_Headers/bresenhamCircle.h"
#include"shm_Headers/scanFill.h"
#include"shm_Headers/bresenhamEllipse.h"
#include"shm_Headers/XYZRotator.h"
#include"shm_Headers/cohenSutherland.h"
#include"shm_Headers/insideOutsidePolygon.h"

using namespace std;

/**
Documentation for the various prototypes available inside the header files
*/

void visibilityGame(float vertices[][2],int n,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,colors color) {
    double t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        if(checkInsideOrOutside(vertices,n,x,y)) {
            putpixel(x,y,color);
        }
        t+=incr;
    }
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,NULL);

    int points[][2]={
        {20,50},
        {30,35},
        {40,35},
        {50,50},
        {20,50},
        {30,65},
        {40,65},
        {50,75},
        {35,65},
        {20,80},
        {35,105},
        {60,80},
        {35,30},
        {35,5},
        {15,10},
        {10,10},
        {10,10},
        {10,30},
        {10,60},
        {10,105},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
    }
    getch();
    return 0;
}

