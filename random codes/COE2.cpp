#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void drawNumber() {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    double t,incr;
    x1=260,y1=160,x2=260,y2=168,x3=260,y3=179,x4=260,y4=230;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,LIGHTRED);
        t+=incr;
    }

    x1=260,y1=230,x2=280,y2=230,x3=280,y3=230,x4=300,y4=230;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,LIGHTRED);
        t+=incr;
    }

    x1=300,y1=160,x2=300,y2=168,x3=300,y3=179,x4=300,y4=290;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,LIGHTRED);
        t+=incr;
    }


    x1=320,y1=160,x2=320,y2=168,x3=320,y3=179,x4=320,y4=230;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,LIGHTRED);
        t+=incr;
    }

    x1=320,y1=230,x2=340,y2=230,x3=340,y3=230,x4=360,y4=230;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,LIGHTRED);
        t+=incr;
    }

    x1=360,y1=160,x2=360,y2=168,x3=360,y3=179,x4=360,y4=290;
    t=0,incr=0.001;
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);
        putpixel(x,y,LIGHTRED);
        t+=incr;
    }
}

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

void blackPlotter(int x1,int y1,int x2,int y2) {
    setcolor(BLACK);
    line((320+x1),(200+y1),(320+x2),(200+y2));
}

void plotter(int x1,int y1,int x2,int y2) {
    setcolor(WHITE);
    line((320+x1),(200+y1),(320+x2),(200+y2));
}

void hideTriangle(int x1,int y1,int x2,int y2,int x3,int y3) {
    blackPlotter(x1,y1,x2,y2);
    blackPlotter(x2,y2,x3,y3);
    blackPlotter(x3,y3,x1,y1);
    return;
}

void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3) {
    plotter(x1,y1,x2,y2);
    plotter(x2,y2,x3,y3);
    plotter(x3,y3,x1,y1);
    return;
}

void drawSquare(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)  {
    plotter(x1,y1,x2,y2);
    plotter(x2,y2,x3,y3);
    plotter(x3,y3,x4,y4);
    plotter(x4,y4,x1,y1);
}

void hideSquare(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)  {
    blackPlotter(x1,y1,x2,y2);
    blackPlotter(x2,y2,x3,y3);
    blackPlotter(x3,y3,x4,y4);
    blackPlotter(x4,y4,x1,y1);
}

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    int r=120;
    drawCircle(r,0,r);
    float tx1=60,tx2=-60,tx3=0,ty1=60,ty2=60,ty3=90;
    float sx1=60,sx2=-60,sx3=-60,sx4=60,sy1=-30,sy2=-30,sy3=-60,sy4=-60;
    drawSquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4);
    int theta=0.0;
    while(true) {
        float tx1P,tx2P,tx3P,ty1P,ty2P,ty3P;
        float sx1P,sx2P,sx3P,sx4P,sy1P,sy2P,sy3P,sy4P;
        float thetaP=3.14*theta/180;
        tx1P=tx1*cos(thetaP)+ty1*sin(thetaP);
        ty1P=-tx1*sin(thetaP)+ty1*cos(thetaP);
        tx2P=tx2*cos(thetaP)+ty2*sin(thetaP);
        ty2P=-tx2*sin(thetaP)+ty2*cos(thetaP);
        tx3P=tx3*cos(thetaP)+ty3*sin(thetaP);
        ty3P=-tx3*sin(thetaP)+ty3*cos(thetaP);
        sx1P=sx1*cos(thetaP)+sy1*sin(thetaP);
        sy1P=-sx1*sin(thetaP)+sy1*cos(thetaP);
        sx2P=sx2*cos(thetaP)+sy2*sin(thetaP);
        sy2P=-sx2*sin(thetaP)+sy2*cos(thetaP);
        sx3P=sx3*cos(thetaP)+sy3*sin(thetaP);
        sy3P=-sx3*sin(thetaP)+sy3*cos(thetaP);
        sx4P=sx4*cos(thetaP)+sy4*sin(thetaP);
        sy4P=-sx4*sin(thetaP)+sy4*cos(thetaP);
        theta=(theta+1)%360;
        cout<<theta<<endl;
        drawNumber();
        hideTriangle(tx1,ty1,tx2,ty2,tx3,ty3);
        hideSquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4);
        tx1=tx1P;
        ty1=ty1P;
        tx2=tx2P;
        ty2=ty2P;
        tx3=tx3P;
        ty3=ty3P;
        sx1=sx1P;
        sy1=sy1P;
        sx2=sx2P;
        sy2=sy2P;
        sx3=sx3P;
        sy3=sy3P;
        sx4=sx4P;
        sy4=sy4P;
        drawSquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4);
        drawTriangle(tx1,ty1,tx2,ty2,tx3,ty3);
        drawNumber();
        Sleep(500);
    }
    getch();
    return 0;
}
