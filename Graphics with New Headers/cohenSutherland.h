#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

const int LEFT=4;//0100
const int RIGHT=1;//0001
const int TOP=8;//1000
const int BOTTOM=2;//0010

const int xMax = 400;
const int yMax = 300;
const int xMin = 100;
const int yMin = 200;

int computeCode(int x,int y) {
    int code=0;
    if(x<xMin) {
        code|=LEFT;
    }
    else if(x>xMax) {
        code|=RIGHT;
    }
    if(y<yMin)
        code|=BOTTOM;
    else if(y>yMax)
        code|=TOP;
    return code;
}

void computer(int x1,int y1,int x2,int y2) {
    //for x1 and y1 coordinates
    int code1=0,code2=0;
    if(x1<xMin) {
        code1|=LEFT;
    }
    else if(x1>xMax) {
        code1|=RIGHT;
    }
    if(y1<yMin)
        code1|=BOTTOM;
    else if(y1>yMax)
        code1|=TOP;
    if(x2<xMin) {
        code2|=LEFT;
    }
    else if(x2>xMax) {
        code2|=RIGHT;
    }
    if(y2<yMin)
        code2|=BOTTOM;
    else if(y2>yMax)
        code2|=TOP;
    cout<<code1<<" "<<code2<<endl;
    bool accept=false;
    while (true) {
        if((code1==0) && (code2==0)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int codeOut;
            double x, y;
            if (code1 != 0)
                codeOut=code1;
            else
                codeOut=code2;
            if(codeOut & TOP) {
                x=x1+(x2 - x1)*(yMax - y1)/(y2 - y1);
                y=yMax;
            } else if(codeOut & BOTTOM) {
                x=x1+(x2 - x1)*(yMin - y1)/(y2 - y1);
                y=yMin;
            } else if(codeOut & RIGHT) {
                y=y1+(y2 - y1)*(xMax - x1)/(x2 - x1);
                x=xMax;
            } else if(codeOut & LEFT) {
                y=y1+(y2 - y1)*(xMin - x1)/(x2 - x1);
                x=xMin;
            }
            if (codeOut==code1) {
                x1=x;
                y1=y;
                code1=computeCode(x1, y1);
            } else{
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept) {
        setcolor(YELLOW);
        line(x1,y1,x2,y2);
    }
}
