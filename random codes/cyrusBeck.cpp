#include<iostream>
#include<graphics.h>
using namespace std;

struct Coords{
    int x;
    int y;
};

struct vectors{
    double x;
    double y;
};
void clipping(Coords p1,Coords p2,Coords minXY,Coords maxXY);

int main()
{
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,NULL);
    Coords minXY,maxXY,p1,p2;
    p1.x=180;
    p1.y=180;
    p2.x=480;
    p2.y=240;

    setcolor(WHITE);
    line(p1.x,p1.y,p2.x,p2.y);

    minXY.x=220;
    minXY.y=160;
    maxXY.x=420;
    maxXY.y=320;
    line(minXY.x,minXY.y,minXY.x,maxXY.y);
    line(minXY.x,minXY.y,maxXY.x,minXY.y);
    line(minXY.x,maxXY.y,maxXY.x,maxXY.y);
    line(maxXY.x,minXY.y,maxXY.x,maxXY.y);

    clipping(p1,p2,minXY,maxXY);
    getch();
    closegraph();
    return 0;
}

double dotproduct(vectors a,vectors b)
{
    return a.x*b.x + a.y*b.y;
}

vectors createVectors(Coords a,Coords b)
{
    vectors temp;
    temp.x = a.x-b.x;
    temp.y = a.y-b.y;
    return temp;
}
void clipping(Coords p1,Coords p2,Coords minXY,Coords maxXY)
{
    vectors normalAB,normalBC,normalCD,normalDA;
    normalAB.x = -1*abs(maxXY.y - minXY.y);
    normalAB.y = 0;

    normalBC.x = 0;
    normalBC.y = abs(maxXY.x - minXY.x);

    normalCD.x = abs(minXY.y - maxXY.y);
    normalCD.y = 0;

    normalDA.x = 0;
    normalDA.y = -1*abs(minXY.x - maxXY.x);

    vectors p2p1 = createVectors(p2,p1);
    double t[4][2];
    Coords temp;
    temp.x = minXY.x;
    temp.y = maxXY.y;
    t[0][1] = dotproduct(normalAB,p2p1);
    if(t[0][1]!=0)
        t[0][0] = (-1) *(dotproduct(normalAB,createVectors(p1,temp))/dotproduct(normalAB,p2p1));
    else
        t[0][0] = -1;

    temp.x = maxXY.x;
    temp.y = maxXY.y;
    t[1][1] = dotproduct(normalBC,p2p1);
    if(t[1][1]!=0)
        t[1][0] = (-1) *(dotproduct(normalBC,createVectors(p1,temp))/dotproduct(normalBC,p2p1));
    else
        t[1][0] = -1;

    temp.x = maxXY.x;
    temp.y = minXY.y;
    t[2][1] = dotproduct(normalCD,p2p1);
    if(t[2][1]!=0)
        t[2][0] = (-1) *(dotproduct(normalCD,createVectors(p1,temp))/dotproduct(normalCD,p2p1));
    else
        t[2][0] = -1;

    temp.x = minXY.x;
    temp.y = minXY.y;
    t[3][1] = dotproduct(normalDA,p2p1);
    if(t[3][1]!=0)
        t[3][0] = (-1) *(dotproduct(normalDA,createVectors(p1,temp))/dotproduct(normalDA,p2p1));
    else
        t[3][0] = -1;


    float t1=0,t2=1;
    for(int i=0;i<4;i++)
    {
        if(t[i][1]<0)
        {
            if(t[i][0]>t1)
                t1 =t[i][0];
        }
    }
    for(int i=0;i<4;i++)
    {
        if(t[i][1]>0)
        {
            if(t[i][0]<t2)
                t2 =t[i][0];
        }
    }

    Coords res1,res2;
    res1.x = p1.x + (p2.x-p1.x)*t1;
    res1.y = p1.y + (p2.y-p1.y)*t1;

    res2.x = p1.x + (p2.x-p1.x)*t2;
    res2.y = p1.y + (p2.y-p1.y)*t2;
    if(t1<=1 && t1 >=0 && t2<=1 && t2>=0) {
        setcolor(LIGHTRED);
        line(res1.x,res1.y,res2.x,res2.y);
    }

    cout<<t[0][0]<<" "<<t[1][0]<<" "<<t[2][0]<<" "<<t[3][0]<<endl;
    cout<<t[0][1]<<" "<<t[1][1]<<" "<<t[2][1]<<" "<<t[3][1]<<endl;
}
