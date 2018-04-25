#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void plotPixel(int x,int y) {
    putpixel(320+x,200-y,WHITE);
    putpixel(320+x,200+y,WHITE);
    putpixel(320-x,200-y,WHITE);
    putpixel(320-x,200+y,WHITE);
    putpixel(320+y,200+x,WHITE);
    putpixel(320+y,200-x,WHITE);
    putpixel(320-y,200-x,WHITE);
    putpixel(320-y,200+x,WHITE);
}

drawCircle(int r,int x,int y) {
    int d=3-(2*r);
    plotPixel(x,y);
    while(x<=y) {
        if(d<0) {
            d+=4*x+6;
            x++;
        } else {
            d+=4*(x-y)+10;
            x++;
            y--;
        }
        plotPixel(x,y);
    }
}

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int r;
    cin>>r;
    drawCircle(r,0,r);
    getch();
    return 0;
}
