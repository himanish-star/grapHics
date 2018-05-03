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

    setcolor(LIGHTMAGENTA);
    line(200,300,500,300);
    line(200,300,350,100);
    line(500,300,350,100);

    float points[][2]={
        //1
        {350,300},
        {350,292},
        {350,305},
        {350,300},

        //6
        {360,292},
        {358,297.5},
        {358,302.5},
        {360,305},

        {370,294},
        {367.5,292},
        {362.5,292},
        {360,294},

        {360,300},
        {370,300},
        {370,305},
        {360,306},

        //4
        {390,300},
        {390,292},
        {390,305},
        {390,300},

        {390,292},
        {386,292.5},
        {384,295},
        {380,300},

        {380,300},
        {380,300},
        {390,300},
        {390,300},

        //4
        {410,300},
        {410,292},
        {410,305},
        {410,300},

        {410,292},
        {406,292.5},
        {404,295},
        {400,300},

        {400,300},
        {400,300},
        {410,300},
        {410,300},
    };

    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
    }
    int moveLeft=500;
    while(moveLeft>=210) {
        float min=100001;
        for(int i=0;i<40;i+=4) {
            plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],BLACK);
        }
        for(int i=0;i<40;i++) {
            points[i][0]-=10;
            if(points[i][0]<min)
                min=points[i][0];
        }
        for(int i=0;i<40;i+=4) {
            plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
        }
        moveLeft=min;
        setcolor(LIGHTMAGENTA);
        line(200,300,500,300);
        line(200,300,350,100);
        line(500,300,350,100);
    }
    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],BLACK);
    }
    int moveRight=0;
    for(int i=0;i<40;i++) {
        float tempXX,tempYY;
        tempXX=(points[i][0]-200)*(0.6)+(points[i][1]-300)*(0.8);
        tempYY=(points[i][0]-200)*(-0.8)+(points[i][1]-300)*(0.6);
        points[i][0]=tempXX+200;
        points[i][1]=tempYY+300;
    }
    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
    }
    while(moveRight<=350) {
        float max=0;
        for(int i=0;i<40;i+=4) {
            plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],BLACK);
        }
        for(int i=0;i<40;i++) {
            points[i][0]+=6;
            points[i][1]-=8;
            if(points[i][0]>max)
                max=points[i][0];
        }
        for(int i=0;i<40;i+=4) {
            plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
        }
        moveRight=max;
        setcolor(LIGHTMAGENTA);
        line(200,300,500,300);
        line(200,300,350,100);
        line(500,300,350,100);
    }

    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],BLACK);
    }
    for(int i=0;i<40;i++) {
        float tempXX,tempYY;
        float angle=3.14*74/180;
        tempXX=(points[i][0]-350)*(cos(angle))+(points[i][1]-100)*(sin(angle));
        tempYY=(points[i][0]-350)*(-sin(angle))+(points[i][1]-100)*(cos(angle));
        points[i][0]=tempXX+350;
        points[i][1]=tempYY+100;
    }
    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
    }

    moveRight=0;
    while(moveRight<=500) {
        float max=0;
        for(int i=0;i<40;i+=4) {
            plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],BLACK);
        }
        for(int i=0;i<40;i++) {
            points[i][0]+=6;
            points[i][1]+=8;
            if(points[i][0]>max)
                max=points[i][0];
        }
        for(int i=0;i<40;i+=4) {
            plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
        }
        moveRight=max;
        setcolor(LIGHTMAGENTA);
        line(200,300,500,300);
        line(200,300,350,100);
        line(500,300,350,100);
    }
    getch();
    return 0;
}

