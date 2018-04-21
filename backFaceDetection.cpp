#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void drawLine(int x1,int y1,int x2,int y2) {
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    line(x1+320,y1+200,x2+320,y2+200);
}

void drawPrism(int points[][3]) {
    for(int i=1;i<4;i++) {
        drawLine(points[0][0],points[0][1],points[i][0],points[i][1]);
    }
    for(int i=2;i<4;i++) {
        drawLine(points[1][0],points[1][1],points[i][0],points[i][1]);
    }
    for(int i=3;i<4;i++) {
        drawLine(points[2][0],points[2][1],points[i][0],points[i][1]);
    }
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,"c:\\TURBOC3\BGI");
    int points[4][3]={
        {100,100,100},
        {300,100,100},
        {200,100,300},
        {200,200,200}
    },temp[4][3];
    setcolor(YELLOW);
    line(0,200,640,200);
    line(320,0,320,400);
    //setcolor(WHITE);
    //drawPrism(points);
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            temp[i][j]=points[i][j];
        }
    }
    double zAngle;
    cout<<"Enter Z rotation: ";
    cin>>zAngle;
    zAngle=(3.14*zAngle)/180;
    for(int i=0;i<4;i++) {
        temp[i][0]=points[i][0]*cos(zAngle)+points[i][1]*sin(zAngle);
        temp[i][1]=-points[i][0]*sin(zAngle)+points[i][1]*cos(zAngle);
    }
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            points[i][j]=temp[i][j];
        }
    }
    double xAngle;
    cout<<"Enter X rotation: ";
    cin>>xAngle;
    xAngle=(3.14*xAngle)/180;
    for(int i=0;i<4;i++) {
        temp[i][1]=points[i][1]*cos(xAngle)+points[i][2]*sin(xAngle);
        temp[i][2]=-points[i][1]*sin(xAngle)+points[i][2]*cos(xAngle);
    }
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            points[i][j]=temp[i][j];
        }
    }
    double yAngle;
    cout<<"Enter Y rotation: ";
    cin>>yAngle;
    yAngle=(3.14*yAngle)/180;
    for(int i=0;i<4;i++) {
        temp[i][2]=points[i][2]*cos(yAngle)+points[i][0]*sin(yAngle);
        temp[i][0]=-points[i][2]*sin(yAngle)+points[i][0]*cos(yAngle);
    }
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            points[i][j]=temp[i][j];
        }
    }
    setcolor(YELLOW);
    drawPrism(points);
    getch();
    return 0;
}
