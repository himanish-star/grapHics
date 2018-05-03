#include<bits/stdc++.h>
#include<graphics.h>
#include"scanFillHeaderFile.h"

using namespace std;

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,"C:\\TURBOC3\\BGI");

    int x1,y1,x2,y2,x3,y3,x4,y4;
    double t,incr;

    setcolor(WHITE);
    line(50,50,100,50);
    line(25,100,125,100);
    line(50,50,25,100);
    line(100,50,125,100);

    line(50,100,100,100);
    line(60,120,90,120);
    line(50,100,60,120);
    line(100,100,90,120);

    line(75,120,75,200);
    line(76,120,76,200);
    line(74,120,74,200);

    line(25,200,125,200);

    x1=76,y1=200,x2=320,y2=190,x3=340,y3=170,x4=372,y4=166;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,WHITE);
        t+=incr;
    }

    x1=372,y1=166,x2=375,y2=170,x3=372,y3=166,x4=375,y4=162;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,WHITE);
        t+=incr;
    }

    x1=375,y1=166,x2=375,y2=162,x3=375,y3=161,x4=375,y4=176;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,WHITE);
        t+=incr;
    }

    colorFigure(1);
    setcolor(WHITE);
    line(380,200,390,250);
    setcolor(BLACK);
    getch();
    line(380,200,390,250);
    setcolor(WHITE);
    line(390,250,400,200);
    colorFigure(2);
    getch();
    setcolor(WHITE);
    line(380,200,390,250);
    setcolor(BLACK);
    line(390,250,400,200);
    colorFigure(2);
    getch();
    return 0;
}
