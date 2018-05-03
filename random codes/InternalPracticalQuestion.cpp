#include<bits/stdc++.h>
#include<graphics.h>
#include"bresenham_line.h"
#include"bresenhamCircle.h"

using namespace std;

int globalCenterX=320,globalCenterY=200;

void drawScreen() {
    setcolor(LIGHTGREEN);
    line(100,20,600,20);
    line(100,400,600,400);
    line(100,20,100,400);
    line(600,20,600,400);
    setcolor(YELLOW);
    outtextxy(140,40,"1644");
    outtextxy(300,40,"1644");
    outtextxy(200,100,"1644");
    outtextxy(410,100,"1644");
    outtextxy(300,160,"1644");
    outtextxy(140,200,"1644");
    outtextxy(500,200,"1644");
    outtextxy(300,280,"1644");
    outtextxy(140,380,"1644");
    outtextxy(500,380,"1644");
}

void plotPixel(int x,int y) {
    putpixel(globalCenterX+x,globalCenterY-y,WHITE);
    putpixel(globalCenterX+x,globalCenterY+y,WHITE);
    putpixel(globalCenterX-x,globalCenterY-y,WHITE);
    putpixel(globalCenterX-x,globalCenterY+y,WHITE);
    putpixel(globalCenterX+y,globalCenterY+x,WHITE);
    putpixel(globalCenterX+y,globalCenterY-x,WHITE);
    putpixel(globalCenterX-y,globalCenterY-x,WHITE);
    putpixel(globalCenterX-y,globalCenterY+x,WHITE);
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
    line((globalCenterX+x1),(globalCenterY+y1),(globalCenterX+x2),(globalCenterY+y2));
}

void plotter(int x1,int y1,int x2,int y2) {
    setcolor(WHITE);
    line((globalCenterX+x1),(globalCenterY+y1),(globalCenterX+x2),(globalCenterY+y2));
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
    float cx=0,cy=20,cr=20,CXX=-70,CYY=5;
    drawCircleGamma(cr,0,cy,CXX+globalCenterX,CYY+globalCenterY);
    float tx1=60,tx2=-60,tx3=0,ty1=60,ty2=60,ty3=90;
    float sx1=60,sx2=-60,sx3=-60,sx4=60,sy1=-30,sy2=-30,sy3=-60,sy4=-60;
    float shmx1=60,shmx2=20,shmx3=20,shmx4=60,shmy1=-10,shmy2=-10,shmy3=30,shmy4=30;
    drawSquare(shmx1,shmy1,shmx2,shmy2,shmx3,shmy3,shmx4,shmy4);
    drawSquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4);
    int theta=0.0;
    //getReadyToDraw the screen

    while(true) {
        int countAA=10;
        while(countAA--) {
            drawCircle(r,0,r);
            float CXXP,CYYP;
            float tx1P,tx2P,tx3P,ty1P,ty2P,ty3P;
            float sx1P,sx2P,sx3P,sx4P,sy1P,sy2P,sy3P,sy4P;
            float shmx1P,shmx2P,shmx3P,shmx4P,shmy1P,shmy2P,shmy3P,shmy4P;
            float thetaP=3.14*theta/180;
            CXXP=CXX*cos(thetaP)+CYY*sin(thetaP);
            CYYP=-CXX*sin(thetaP)+CYY*cos(thetaP);
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

            shmx1P=shmx1*cos(thetaP)+shmy1*sin(thetaP);
            shmy1P=-shmx1*sin(thetaP)+shmy1*cos(thetaP);
            shmx2P=shmx2*cos(thetaP)+shmy2*sin(thetaP);
            shmy2P=-shmx2*sin(thetaP)+shmy2*cos(thetaP);
            shmx3P=shmx3*cos(thetaP)+shmy3*sin(thetaP);
            shmy3P=-shmx3*sin(thetaP)+shmy3*cos(thetaP);
            shmx4P=shmx4*cos(thetaP)+shmy4*sin(thetaP);
            shmy4P=-shmx4*sin(thetaP)+shmy4*cos(thetaP);

            theta=(theta+1)%360;
            cout<<theta<<endl;
            eraseCircleGamma(cr,0,cy,CXX+globalCenterX,CYY+globalCenterY);
            hideTriangle(tx1,ty1,tx2,ty2,tx3,ty3);
            hideSquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4);
            hideSquare(shmx1,shmy1,shmx2,shmy2,shmx3,shmy3,shmx4,shmy4);
            eraseCircleGamma(r,0,r,globalCenterX,globalCenterY);
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
            CXX=CXXP;
            CYY=CYYP;
            shmx1=shmx1P;
            shmy1=shmy1P;
            shmx2=shmx2P;
            shmy2=shmy2P;
            shmx3=shmx3P;
            shmy3=shmy3P;
            shmx4=shmx4P;
            shmy4=shmy4P;
            drawSquare(sx1,sy1,sx2,sy2,sx3,sy3,sx4,sy4);
            drawTriangle(tx1,ty1,tx2,ty2,tx3,ty3);
            drawCircleGamma(cr,0,cy,CXX+globalCenterX,CYY+globalCenterY);
            drawCircleGamma(r,0,r,globalCenterX,globalCenterY);
            drawSquare(shmx1,shmy1,shmx2,shmy2,shmx3,shmy3,shmx4,shmy4);
            drawScreen();
            Sleep(100);
        }
        globalCenterX=(globalCenterX+10)%400+100;
        globalCenterY=(globalCenterY+10)%200+100;
        cleardevice();
    }
    getch();
    return 0;
}

