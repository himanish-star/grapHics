#include<bits/stdc++.h>
#include<graphics.h>
#include"hermiteGraph.h"
#include"bresenhamLine.h"
#include"bresenhamCircle.h"
#include"scanFill.h"
#include"bresenhamEllipse.h"
#include"XYZRotator.h"
#include"cohenSutherland.h"
#include"insideOutsidePolygon.h"

using namespace std;

/**
Documentation for the various prototypes available inside the header files
*/

void visibilityGame(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,colors color) {
    double t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        if(pow(x-320,2)+pow(y-200,2)-pow(60,2)>0) {
            putpixel(x,y,color);
        }
        t+=incr;
    }
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,NULL);

    circle(320,200,60);
    //1
    visibilityGame(200,200,210,190,220,200,210,210,LIGHTCYAN);
    visibilityGame(200,200,205,208,206,209,210,210,LIGHTCYAN);
    visibilityGame(220,200,219,215,217,225,205,240,LIGHTCYAN);
    visibilityGame(205,240,206,239,215,238,225,260,LIGHTCYAN);

    //6
    visibilityGame(260,190,240,205,255,210,260,210,LIGHTCYAN);
    visibilityGame(265,210,240,225,260,230,270,225,LIGHTCYAN);
    visibilityGame(270,225,265,220,260,225,270,260,LIGHTCYAN);

    //4
    visibilityGame(280,190,283,210,320,230,300,250,LIGHTCYAN);
    visibilityGame(300,250,280,244,300,230,320,190,LIGHTCYAN);

    //4
    visibilityGame(330,190,333,210,370,230,350,250,LIGHTCYAN);
    visibilityGame(350,250,330,244,350,230,370,190,LIGHTCYAN);

    getch();
    return 0;
}

