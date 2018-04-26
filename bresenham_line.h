#include<iostream>
#include<graphics.h>

using namespace std;

void drawBresenhamLine(int x1,int y1,int x2,int y2,int color) {
    if(color==3) {
        int dy=y2-y1;
    int dx=x2-x1;
    int yMin,xMin,yMax;

    /**
    *Let's Play The Slope Game: SHM:
    */
    float slope;
    if(dx==0) {
        slope=100001;
        yMin=y1<y2?y1:y2;
        for(int i=yMin;i<=yMin+abs(y2-y1);i++)
            putpixel(x1,i,WHITE);
    } else {
        slope=(float)(dy)/(dx);
    }
    dy=abs(dy),dx=abs(dx);
    int d=2*dy-dx;
    int x,y;
    if(slope>=0) {
        yMin=y1<y2?y1:y2;
        xMin=x1<x2?x1:x2;
        x=xMin,y=yMin;
        putpixel(x,y,WHITE);
        while(x<=abs(x2-x1)+xMin) {
            if(d>=0) {
                d+=2*(dy-dx);
                y++;
                x++;
            } else {
                d+=2*dy;
                x++;
            }
            putpixel(x,y,WHITE);
        }
    } else {
       yMax=y1>y2?y1:y2;
       xMin=x1<x2?x1:x2;
       x=xMin,y=yMax;
       putpixel(x,y,WHITE);
       while(x<=abs(x2-x1)+xMin) {
            if(d>=0) {
                d+=2*(dy-dx);
                y--;
                x++;
            } else {
                d+=2*dy;
                x++;
            }
            putpixel(x,y,WHITE);
        }
    }
    return;
    } else if (color=15){
        int dy=y2-y1;
    int dx=x2-x1;
    int yMin,xMin,yMax;

    /**
    *Let's Play The Slope Game: SHM:
    */
    float slope;
    if(dx==0) {
        slope=100001;
        yMin=y1<y2?y1:y2;
        for(int i=yMin;i<=yMin+abs(y2-y1);i++)
            putpixel(x1,i,BLACK);
    } else {
        slope=(float)(dy)/(dx);
    }
    dy=abs(dy),dx=abs(dx);
    int d=2*dy-dx;
    int x,y;
    if(slope>=0) {
        yMin=y1<y2?y1:y2;
        xMin=x1<x2?x1:x2;
        x=xMin,y=yMin;
        putpixel(x,y,BLACK);
        while(x<=abs(x2-x1)+xMin) {
            if(d>=0) {
                d+=2*(dy-dx);
                y++;
                x++;
            } else {
                d+=2*dy;
                x++;
            }
            putpixel(x,y,BLACK);
        }
    } else {
       yMax=y1>y2?y1:y2;
       xMin=x1<x2?x1:x2;
       x=xMin,y=yMax;
       putpixel(x,y,BLACK);
       while(x<=abs(x2-x1)+xMin) {
            if(d>=0) {
                d+=2*(dy-dx);
                y--;
                x++;
            } else {
                d+=2*dy;
                x++;
            }
            putpixel(x,y,BLACK);
        }
    }
    return;
    }
}
