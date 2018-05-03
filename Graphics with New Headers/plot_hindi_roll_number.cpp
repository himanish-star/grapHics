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
    x1*=3;
    x2*=3;
    x3*=3;
    x4*=3;
    y1*=3;
    y2*=3;
    y3*=3;
    y4*=3;
    double t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,color);
        t+=incr;
    }
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,NULL);

    //1
    visibilityGame(20,20.0,21.0,19.0,22.0,20.0,21.0,21.0,LIGHTCYAN);
    visibilityGame(20,20.0,20.5,20.8,20.6,20.9,21.0,21.0,LIGHTCYAN);
    visibilityGame(22,20.0,21.9,21.5,21.7,22.5,20.5,24.0,LIGHTCYAN);
    visibilityGame(20.5,24.0,20.6,23.9,21.5,23.8,22.5,26.0,LIGHTCYAN);

    //6
    visibilityGame(26.0,19.0,24.0,20.5,25.5,21.0,26.0,21.0,LIGHTCYAN);
    visibilityGame(26.5,21.0,24.0,22.5,26.0,23.0,27.0,22.5,LIGHTCYAN);
    visibilityGame(27.0,22.5,26.5,22.0,26.0,22.5,27.0,26.0,LIGHTCYAN);

    //4
    visibilityGame(28.0,19.0,28.3,21.0,32.0,23.0,30.0,25.0,LIGHTCYAN);
    visibilityGame(30.0,25.0,28.0,24.4,30.0,23.0,32.0,19.0,LIGHTCYAN);

    //4
    visibilityGame(33.0,19.0,33.3,21.0,37.0,23.0,35.0,25.0,LIGHTCYAN);
    visibilityGame(35.0,25.0,33.0,24.4,35.0,23.0,37.0,19.0,LIGHTCYAN);

    getch();
    return 0;
}

