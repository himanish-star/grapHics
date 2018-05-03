#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void plotPixel(int x,int y,int xc,int yc) {
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc+y,yc+x,WHITE);
    putpixel(xc+y,yc-x,WHITE);
    putpixel(xc-y,yc-x,WHITE);
    putpixel(xc-y,yc+x,WHITE);
}

drawCircleGamma(int r,int x,int y,int xc,int yc) {
    int d=3-(2*r);
    plotPixel(x,y,xc,yc);
    while(x<=y) {
        if(d<0) {
            d+=4*x+6;
            x++;
        } else {
            d+=4*(x-y)+10;
            x++;
            y--;
        }
        plotPixel(x,y,xc,yc);
    }
}

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    drawCircle(120,0,120,320,200);
    getch();
    return 0;
}
