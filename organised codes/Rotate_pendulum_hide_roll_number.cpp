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

void rollNumberInsideCircle(int r,float xc,float yc,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,colors color) {
    double t=0,incr=0.001;
    while(t<=1) {
        float x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        float y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        if(pow(x-xc,2)+pow(y-yc,2)-pow(r,2)>0) {
            putpixel(x,y,LIGHTCYAN);
        }
        if(pow(x-xc,2)+pow(y-yc,2)-pow(r,2)<0) {
            putpixel(x,y,BLACK);
        }
        t+=incr;
    }
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,NULL);

    float xGlobalCenter=320,yGlobalCenter=350;

    putpixel(320,20,LIGHTCYAN);
    setcolor(LIGHTCYAN);

    float theta=60;
    xGlobalCenter=0,yGlobalCenter=210;
    float tempX=0,tempY=210;
    bool left=true,right=false;
    while(true) {
         //1
        rollNumberInsideCircle(60,tempX+320,tempY+20,200,200,210,190,220,200,210,210,LIGHTCYAN);
        rollNumberInsideCircle(60,tempX+320,tempY+20,200,200,205,208,206,209,210,210,LIGHTCYAN);
        rollNumberInsideCircle(60,tempX+320,tempY+20,220,200,219,215,217,225,205,240,LIGHTCYAN);
        rollNumberInsideCircle(60,tempX+320,tempY+20,205,240,206,239,215,238,225,260,LIGHTCYAN);

        //6
        rollNumberInsideCircle(60,tempX+320,tempY+20,260,190,240,205,255,210,260,210,LIGHTCYAN);
        rollNumberInsideCircle(60,tempX+320,tempY+20,265,210,240,225,260,230,270,225,LIGHTCYAN);
        rollNumberInsideCircle(60,tempX+320,tempY+20,270,225,265,220,260,225,270,260,LIGHTCYAN);

        //4
        rollNumberInsideCircle(60,tempX+320,tempY+20,280,190,283,210,320,230,300,250,LIGHTCYAN);
        rollNumberInsideCircle(60,tempX+320,tempY+20,300,250,280,244,300,230,320,190,LIGHTCYAN);

        //4
        rollNumberInsideCircle(60,tempX+320,tempY+20,330,190,333,210,370,230,350,250,LIGHTCYAN);
        rollNumberInsideCircle(60,tempX+320,tempY+20,350,250,330,244,350,230,370,190,LIGHTCYAN);

        float anglePi=3.14*theta/180;
        setcolor(BLACK);
        drawBresenhamCircle(60,0,60,tempX+320,tempY+20,BLACK);
        line(320,20,tempX+320,tempY+20);
        tempX=(xGlobalCenter)*(cos(anglePi))+(yGlobalCenter)*(sin(anglePi));
        tempY=(xGlobalCenter)*(-sin(anglePi))+((yGlobalCenter)*(cos(anglePi)));
        setcolor(LIGHTCYAN);
        line(320,20,tempX+320,tempY+20);
        drawBresenhamCircle(60,0,60,tempX+320,tempY+20,LIGHTMAGENTA);
        if(left) {
            theta-=5;
        }
        if(right) {
            theta+=5;
        }
        cout<<theta<<endl;
        if(theta==-60) {
            right=true;
            left=false;
        }
        if(theta==60) {
            left=true;
            right=false;
        }
    }
    getch();
    return 0;
}

