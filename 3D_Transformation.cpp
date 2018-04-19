#include<iostream>
#include<math.h>
#include<graphics.h>
#include<bits/stdc++.h>
#include"bresenham_line.h"

using namespace std;

void drawLine(int x1,int y1,int x2,int y2) {
    cout<<x1<<", "<<y1<<", "<<x2<<", "<<y2<<endl;
    drawBresenhamLine(320+x1,200+y1,320+x2,200+y2);
}

void drawCube(int points[][3]) {
    for(int i=0;i<3;i++) {
        drawLine(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
    }
    drawLine(points[3][0],points[3][1],points[0][0],points[0][1]);
    for(int i=4;i<7;i++) {
        drawLine(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
    }
    drawLine(points[7][0],points[7][1],points[4][0],points[4][1]);
    for(int i=0;i<=3;i++) {
        drawLine(points[i][0],points[i][1],points[i+4][0],points[i+4][1]);
    }
}

int main() {
    int gdriver=DETECT,gmode,error;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    int points[8][3]={
        {0,0,0},{0,50,0},{50,50,0},{50,0,0},
        {0,0,50},{0,50,50},{50,50,50},{50,0,50}
    };
    setcolor(RED);
    drawCube(points);
    getch();
    cout<<"Enter rotation angles: ";
    float alpha,beta,gamma;
    cin>>alpha>>beta>>gamma;
    if(alpha) {
        alpha=((float)(22*alpha)/(7*180));
        for(int i=0;i<8;i++) {
            points[i][1]=points[i][1]*cos(alpha)+points[i][2]*sin(alpha);
            points[i][2]=-points[i][1]*sin(alpha)+points[i][2]*cos(alpha);
        }
    }
    if(beta) {
        beta=((float)(22*beta)/(7*180));
        for(int i=0;i<8;i++) {
            points[i][0]=-points[i][2]*sin(beta)+points[i][0]*cos(beta);
            points[i][2]=points[i][2]*cos(beta)+points[i][0]*sin(beta);
        }
    }
    if(gamma) {
        gamma=((float)(22*gamma)/(180*7));
        for(int i=0;i<8;i++) {
            points[i][0]=points[i][0]*cos(gamma)+points[i][1]*sin(gamma);
            points[i][1]=-points[i][0]*sin(gamma)+points[i][1]*cos(gamma);
        }
    }
    setcolor(GREEN);
    drawCube(points);
    getch();
    return 0;
}
