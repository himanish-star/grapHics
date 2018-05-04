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

void drawEllipsePro(float cx,float cy,float x,float y,colors color)
{
    putpixel(cx + x, cy - y, color);
    putpixel(cx + x, cy + y, color);
    putpixel(cx - x, cy - y, color);
    putpixel(cx - x, cy + y, color);
}

void myellipsePro(float cx, float cy, float a, float b,colors color,
                  float angleX,float angleY,float angleZ)
{
    float x = 0, y = b;
    float d = 2 * b * b + a * a - 2 * a * a * b;
    drawEllipse(cx, cy, x, y,color);

    while (a * a * y > x * b * b) {
        if (d > 0) {
            d += (2 * b * b * (2 * x + 3) - 4 * a * a * (y - 1));
            y--;
        }
        else {
            d += (2 * b * b * (2 * x + 3));
        }
        x++;
        drawEllipse(cx, cy, x, y,color);

    }

    d = 2 * b * b * x * x + b * b + 2 * b * b * x + 2 * a * a * y * y + 2 * a * a - 4 * a * a * y - 2 * a * a * b * b;

    while (y >= 0) {
        if (d < 0) {
            d += (4 * b * b * (x + 1) - 2 * a * a * (2 * y - 3));
            x++;
        }
        else {
            d += 2 * a * a * (3 - 2 * y);
        }
        y--;
        drawEllipse(cx, cy, x, y,color);
    }
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,NULL);

    //compute the x,y,z angles
    float globalXCenter=-1200,globalYCenter=300,globalZCenter=0;
    float angleX=3.14*82/180,angleY=3.14*34/180,angleZ=3.14*56/180;

    //for points to be shifted .. .. ..
    float tempX=(globalXCenter)*(cos(angleZ))+(globalYCenter)*(sin(angleZ));
    float tempY=(globalXCenter)*(-sin(angleZ))+(globalYCenter)*(cos(angleZ));

    float tempYY=(tempY)*(cos(angleX))+(globalZCenter)*(sin(angleX));
    float tempZ=(tempY)*(-sin(angleX))+(globalZCenter)*(cos(angleX));

    float tempZZ=(tempZ)*(cos(angleY))+(tempX)*(sin(angleY));
    float tempXX=(tempZ)*(-sin(angleY))+(tempX)*(cos(angleY));

    myellipsePro(tempXX,tempYY,80,40,LIGHTMAGENTA,angleX,angleY,angleZ);
    getch();
    return 0;
}

