#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,"C:\\TURBOC3\BGI");

    int x1,y1,x2,y2,x3,y3,x4,y4,prevX,prevY;
    double t,incr;
    x1=40,y1=200,x2=45,y2=205,x3=40,y3=210,x4=40,y4=200;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,WHITE);
        t+=incr;
    }

    x1=40,y1=210,x2=40,y2=220,x3=40,y3=230,x4=40,y4=240;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,WHITE);
        t+=incr;
    }

    x1=40,y1=240,x2=35,y2=242,x3=32,y3=244,x4=30,y4=246;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,WHITE);
        t+=incr;
    }

    x1=30,y1=230,x2=35,y2=220,x3=45,y3=220,x4=50,y4=230;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,WHITE);
        t+=incr;
    }

    x1=40,y1=240,x2=45,y2=242,x3=47,y3=244,x4=49,y4=246;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,WHITE);
        t+=incr;
    }

    x1=50,y1=200,x2=150,y2=35,x3=250,y3=35,x4=350,y4=200;
    t=0,incr=0.001;
    prevX=x1,prevY=y1;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,WHITE);
        putpixel(x+1,y,WHITE);
        putpixel(x+1,y+1,WHITE);
        putpixel(x+1,y-1,WHITE);
        putpixel(x-1,y-1,WHITE);
        putpixel(x-1,y+1,WHITE);
        putpixel(x-1,y,WHITE);
        putpixel(x,y+1,WHITE);
        putpixel(x,y-1,WHITE);
        prevX=x,prevY=y;
        setcolor(YELLOW);
        Sleep(1);
        t+=incr;
    }
    getch();
}
