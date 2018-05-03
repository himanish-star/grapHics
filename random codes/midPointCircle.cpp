#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;


void drawCircle(int r,int x,int y) {
    int d=1-r;
    putpixel(320+x,200-y,WHITE);
    putpixel(320+x,200+y,WHITE);
    putpixel(320-x,200-y,WHITE);
    putpixel(320-x,200+y,WHITE);
    putpixel(320+y,200+x,WHITE);
    putpixel(320+y,200-x,WHITE);
    putpixel(320-y,200-x,WHITE);
    putpixel(320-y,200+x,WHITE);
    while (x<y)
    {
        if (d < 0)
        {
            x++;
            d += (2 * x) + 3;
        }
        else
        {
            x++;
            y--;
            d += 2 * (x - y) + 5;
        }
        putpixel(320+x,200-y,WHITE);
        putpixel(320+x,200+y,WHITE);
        putpixel(320-x,200-y,WHITE);
        putpixel(320-x,200+y,WHITE);
        putpixel(320+y,200+x,WHITE);
        putpixel(320+y,200-x,WHITE);
        putpixel(320-y,200-x,WHITE);
        putpixel(320-y,200+x,WHITE);
    }
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,NULL);
    int r;
    cin>>r;
    int d=1-r,x=0,y=r;
    drawCircle(r,x,y);
    getch();
    return 0;
}
