#include<bits/stdc++.h>
#include<graphics.h>
#include"shm_Headers/hermiteGraph.h"
#include"shm_Headers/bresenhamLine.h"
#include"shm_Headers/bresenhamCircle.h"
#include"shm_Headers/scanFill.h"
#include"shm_Headers/bresenhamEllipse.h"
#include"shm_Headers/XYZRotator.h"
#include"shm_Headers/cohenSutherland.h"
#include"shm_Headers/insideOutsidePolygon.h"

using namespace std;

/**
Documentation for the various prototypes available inside the header files
*/

void visibilityGamePowerUp(int r,float xc,float yc,
                    float vertices1[][2],float vertices2[][2],int n1,int n2,
                    int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,
                    colors color) {
    double t=0,incr=0.001;
    float temp1[n1][2],temp2[n2][2];
    for(int i=0;i<n1;i++) {
        temp1[i][0]=xc+vertices1[i][0];
        temp1[i][1]=yc+vertices1[i][1];
    }
    for(int i=0;i<n2;i++) {
        temp2[i][0]=xc+vertices2[i][0];
        temp2[i][1]=yc+vertices2[i][1];
    }
    while(t<=1) {
        int x=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*x1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*x2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*x3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*x4);
        int y=((-4.5*pow(t,3)+9*pow(t,2)-5.5*t+1)*y1)+((13.5*pow(t,3)-22.5*pow(t,2)+9*t)*y2)
        +((-13.5*pow(t,3)+18*pow(t,2)-4.5*t)*y3)+((4.5*pow(t,3)-4.5*pow(t,2)+t)*y4);

        if(checkInsideOrOutside(temp1,n1,x,y) || checkInsideOrOutside(temp2,n2,x,y)) {
            putpixel(x,y,WHITE);
        } else {
            putpixel(x,y,BLACK);
        }
        t+=incr;
    }
}

void printRollNumberInBackground(float xc,float yc,float vertices1[][2],float vertices2[][2],
                                 int n1,int n2) {
    float points[][2]={
        //1
        {350,300},
        {350,292},
        {350,305},
        {350,300},

        //6
        {360,292},
        {358,297.5},
        {358,302.5},
        {360,305},

        {370,294},
        {367.5,292},
        {362.5,292},
        {360,294},

        {360,300},
        {370,300},
        {370,305},
        {360,306},

        //4
        {390,300},
        {390,292},
        {390,305},
        {390,300},

        {390,292},
        {386,292.5},
        {384,295},
        {380,300},

        {380,300},
        {380,300},
        {390,300},
        {390,300},

        //4
        {410,300},
        {410,292},
        {410,305},
        {410,300},

        {410,292},
        {406,292.5},
        {404,295},
        {400,300},

        {400,300},
        {400,300},
        {410,300},
        {410,300},
    };
    for(int i=0;i<40;i++) {
        points[i][0]*=3;
        points[i][1]*=3;
        points[i][0]-=850;
        points[i][1]-=700;
    }
    for(int i=0;i<40;i+=4) {
        visibilityGamePowerUp(
                       120,
                       xc,yc,
                       vertices1,vertices2,
                       n1,n2,
                       points[i][0],points[i][1],
                       points[i+1][0],points[i+1][1],
                       points[i+2][0],points[i+2][1],
                       points[i+3][0],points[i+3][1],
                       YELLOW);
    }
}

void makeScreen() {
    float points[][2]={
        //1
        {350,300},
        {350,292},
        {350,305},
        {350,300},

        //6
        {360,292},
        {358,297.5},
        {358,302.5},
        {360,305},

        {370,294},
        {367.5,292},
        {362.5,292},
        {360,294},

        {360,300},
        {370,300},
        {370,305},
        {360,306},

        //4
        {390,300},
        {390,292},
        {390,305},
        {390,300},

        {390,292},
        {386,292.5},
        {384,295},
        {380,300},

        {380,300},
        {380,300},
        {390,300},
        {390,300},

        //4
        {410,300},
        {410,292},
        {410,305},
        {410,300},

        {410,292},
        {406,292.5},
        {404,295},
        {400,300},

        {400,300},
        {400,300},
        {410,300},
        {410,300},
    };
    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
    }
    for(int i=0;i<40;i++) {
        points[i][0]-=200;
        points[i][1]-=100;
    }
    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
    }
    for(int i=0;i<40;i++) {
        points[i][0]-=100;
        points[i][1]+=100;
    }
    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
    }
    for(int i=0;i<40;i++) {
        points[i][0]+=300;
        points[i][1]-=200;
    }
    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
    }
    for(int i=0;i<40;i++) {
        points[i][0]-=300;
    }
    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
    }
    for(int i=0;i<40;i++) {
        points[i][0]+=100;
        points[i][1]+=300;
    }
    for(int i=0;i<40;i+=4) {
        plotHermiteCurve(points[i][0],points[i][1],points[i+1][0],points[i+1][1],points[i+2][0],points[i+2][1],points[i+3][0],points[i+3][1],LIGHTCYAN);
    }
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,NULL);

    float globalCenterX=300,globalCenterY=200;
    setcolor(LIGHTMAGENTA);
    circle(globalCenterX,globalCenterY,120);

    float polygonPoints1[][2]={
      {-59,-100},
      {-89,14},
      {0,0},
      {0,-29},
    };

    float polygonPoints2[][2]={
      {94,-67},
      {78,-62},
      {-53,67},
      {33,109},
      {63,53}
    };

    for(int i=0;i<4;i++) {
        setcolor(LIGHTCYAN);
        line(globalCenterX+polygonPoints1[i][0],globalCenterY+polygonPoints1[i][1],
             globalCenterX+polygonPoints1[(i+1)%4][0],globalCenterY+polygonPoints1[(i+1)%4][1]);
    }

    for(int i=0;i<5;i++) {
        setcolor(LIGHTGREEN);
        line(globalCenterX+polygonPoints2[i][0],globalCenterY+polygonPoints2[i][1],
             globalCenterX+polygonPoints2[(i+1)%5][0],globalCenterY+polygonPoints2[(i+1)%5][1]);
    }

    //printRollNumberInBackground(globalCenterX,globalCenterY,polygonPoints1,polygonPoints2,4,5);
    int theta=0;
    float dubPolygon1[4][2],dubPolygon2[5][2];
    for(int i=0;i<4;i++) {
        dubPolygon1[i][0]=polygonPoints1[i][0];
        dubPolygon1[i][1]=polygonPoints1[i][1];
    }
    for(int i=0;i<5;i++) {
        dubPolygon2[i][0]=polygonPoints2[i][0];
        dubPolygon2[i][1]=polygonPoints2[i][1];
    }
    while(true) {
        printRollNumberInBackground(globalCenterX,globalCenterY,dubPolygon1,dubPolygon2,4,5);
        theta+=100;
        theta%360;
        float angle=3.14*theta/180;
        for(int i=0;i<4;i++) {
            setcolor(BLACK);
            line(globalCenterX+dubPolygon1[i][0],globalCenterY+dubPolygon1[i][1],
                 globalCenterX+dubPolygon1[(i+1)%4][0],globalCenterY+dubPolygon1[(i+1)%4][1]);
        }
        for(int i=0;i<4;i++) {
            dubPolygon1[i][0]=(polygonPoints1[i][0]*cos(angle))+(polygonPoints1[i][1]*sin(angle));
            dubPolygon1[i][1]=(-polygonPoints1[i][0]*sin(angle))+(polygonPoints1[i][1]*cos(angle));
        }
        for(int i=0;i<4;i++) {
            setcolor(LIGHTCYAN);
            line(globalCenterX+dubPolygon1[i][0],globalCenterY+dubPolygon1[i][1],
                 globalCenterX+dubPolygon1[(i+1)%4][0],globalCenterY+dubPolygon1[(i+1)%4][1]);
        }

        for(int i=0;i<5;i++) {
            setcolor(BLACK);
            line(globalCenterX+dubPolygon2[i][0],globalCenterY+dubPolygon2[i][1],
                 globalCenterX+dubPolygon2[(i+1)%5][0],globalCenterY+dubPolygon2[(i+1)%5][1]);
        }
        for(int i=0;i<5;i++) {
            dubPolygon2[i][0]=(polygonPoints2[i][0]*cos(angle))+(polygonPoints2[i][1]*sin(angle));
            dubPolygon2[i][1]=(-polygonPoints2[i][0]*sin(angle))+(polygonPoints2[i][1]*cos(angle));
        }
        for(int i=0;i<5;i++) {
            setcolor(LIGHTCYAN);
            line(globalCenterX+dubPolygon2[i][0],globalCenterY+dubPolygon2[i][1],
                 globalCenterX+dubPolygon2[(i+1)%5][0],globalCenterY+dubPolygon2[(i+1)%5][1]);
        }
    }
    getch();
    return 0;
}

