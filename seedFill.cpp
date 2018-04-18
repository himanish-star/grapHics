#include<iostream>
#include<graphics.h>

using namespace std;

void seedFill(int x,int y) {
    cout<<"("<<x<<","<<y<<") "<<getpixel(x,y)<<endl;
    if(x>=420 || x<=220 || y>=300 || y<=100)
        return;
    if(getpixel(x,y)==2)
        return;
    putpixel(x,y,GREEN);
    seedFill(x,y+1);
    seedFill(x,y-1);
    seedFill(x+1,y);
    seedFill(x-1,y);
    seedFill(x+1,y+1);
    seedFill(x+1,y-1);
    seedFill(x-1,y+1);
    seedFill(x-1,y-1);
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,"C:\\TURBOC3\\BGI");
    setcolor(RED);
    rectangle(220,100,420,300);
    setcolor(WHITE);
    seedFill(320,200);
    getch();
    return 0;
}
