#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void drawLine(int x1,int y1,int x2,int y2) {
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    line(x1,y1,x2,y2);
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
    drawPrism(points);
    /***
    normal for face ACD= AC x AD
    normal for face ABC= AB x AC
    normal for face BCD= BD x BC
    normal for face ABD= AD x AB
    */

    //face1 coordinates
    int vectorAC[3]={
        points[2][0]-points[0][0],
        points[2][1]-points[0][1],
        points[2][2]-points[0][2],
    },vectorAD[3]={
        points[3][0]-points[0][0],
        points[3][1]-points[0][1],
        points[3][2]-points[0][2],
    },normalACD[3]={
        (vectorAC[1]*vectorAD[2]-vectorAD[1]*vectorAC[2])/10000,
        (-vectorAC[0]*vectorAD[2]+vectorAD[0]*vectorAC[2])/10000,
        (vectorAC[0]*vectorAD[1]-vectorAD[0]*vectorAC[1])/10000
    };
    cout<<"NormalACD: ";
    for(int i=0;i<3;i++) {
        cout<<normalACD[i]<<" ";
    }
    cout<<endl;
    int vectorAB1[3]={
        points[1][0]-points[0][0],
        points[1][1]-points[0][1],
        points[1][2]-points[0][2],
    },vectorAC1[3]={
        points[2][0]-points[0][0],
        points[2][1]-points[0][1],
        points[2][2]-points[0][2],
    },normalABC1[3]={
        (vectorAB1[1]*vectorAC1[2]-vectorAC1[1]*vectorAB1[2])/10000,
        (-vectorAB1[0]*vectorAC1[2]+vectorAC1[0]*vectorAB1[2])/10000,
        (vectorAB1[0]*vectorAC1[1]-vectorAC1[0]*vectorAB1[1])/10000
    };
    cout<<"NormalABC: ";
    for(int i=0;i<3;i++) {
        cout<<normalABC1[i]<<" ";
    }
    cout<<endl;
    int vectorAD2[3]={
        points[3][0]-points[0][0],
        points[3][1]-points[0][1],
        points[3][2]-points[0][2],
    },vectorAB2[3]={
        points[1][0]-points[0][0],
        points[1][1]-points[0][1],
        points[1][2]-points[0][2],
    },normalABD2[3]={
        (vectorAD2[1]*vectorAB2[2]-vectorAB2[1]*vectorAD2[2])/10000,
        (-vectorAD2[0]*vectorAB2[2]+vectorAB2[0]*vectorAD2[2])/10000,
        (vectorAD2[0]*vectorAB2[1]-vectorAB2[0]*vectorAD2[1])/10000
    };
    cout<<"NormalABD: ";
    for(int i=0;i<3;i++) {
        cout<<normalABD2[i]<<" ";
    }
    cout<<endl;
    int vectorBD3[3]={
        points[3][0]-points[1][0],
        points[3][1]-points[1][1],
        points[3][2]-points[1][2],
    },vectorBC3[3]={
        points[2][0]-points[1][0],
        points[2][1]-points[1][1],
        points[2][2]-points[1][2],
    },normalCBD3[3]={
        (vectorBD3[1]*vectorBC3[2]-vectorBC3[1]*vectorBD3[2])/10000,
        (-vectorBD3[0]*vectorBC3[2]+vectorBC3[0]*vectorBD3[2])/10000,
        (vectorBD3[0]*vectorBC3[1]-vectorBC3[0]*vectorBD3[1])/10000
    };
    cout<<"NormalCBD: ";
    for(int i=0;i<3;i++) {
        cout<<normalCBD3[i]<<" ";
    }
    cout<<endl;
    int pointP[3]={200,300,400};
    int centroidACD[3]={
        (points[0][0]+points[2][0]+points[3][0])/3,
        (points[0][1]+points[2][1]+points[3][1])/3,
        (points[0][2]+points[2][2]+points[3][2])/3
    };
    int centroidABD[3]={
        (points[0][0]+points[1][0]+points[3][0])/3,
        (points[0][1]+points[1][1]+points[3][1])/3,
        (points[0][2]+points[1][2]+points[3][2])/3
    };
    int centroidBCD[3]={
        (points[1][0]+points[2][0]+points[3][0])/3,
        (points[1][1]+points[2][1]+points[3][1])/3,
        (points[1][2]+points[2][2]+points[3][2])/3
    };
    int centroidACB[3]={
        (points[0][0]+points[2][0]+points[1][0])/3,
        (points[0][1]+points[2][1]+points[1][1])/3,
        (points[0][2]+points[2][2]+points[1][2])/3
    };
    cout<<"CentroidCBD: ";
    for(int i=0;i<3;i++) {
        cout<<centroidBCD[i]<<" ";
    }
    cout<<endl;
    cout<<"CentroidCBA: ";
    for(int i=0;i<3;i++) {
        cout<<centroidACB[i]<<" ";
    }
    cout<<endl;
    cout<<"CentroidABD: ";
    for(int i=0;i<3;i++) {
        cout<<centroidABD[i]<<" ";
    }
    cout<<endl;
    cout<<"CentroidCAD: ";
    for(int i=0;i<3;i++) {
        cout<<centroidACD[i]<<" ";
    }
    cout<<endl;
    //let's decide who's going to get illuminated
    //face ABC
    int p_CentroidABC[3]={
        (pointP[0]-centroidACB[0]),
        (pointP[1]-centroidACB[1]),
        (pointP[2]-centroidACB[2])
    },
    p_CentroidABD[3]={
        (pointP[0]-centroidABD[0]),
        (pointP[1]-centroidABD[1]),
        (pointP[2]-centroidABD[2])
    },
    p_CentroidACD[3]={
        (pointP[0]-centroidACD[0]),
        (pointP[1]-centroidACD[1]),
        (pointP[2]-centroidACD[2])
    },
    p_CentroidCBD[3]={
        (pointP[0]-centroidBCD[0]),
        (pointP[1]-centroidBCD[1]),
        (pointP[2]-centroidBCD[2])
    };
    if(p_CentroidABC[0]*normalABC1[0]+p_CentroidABC[1]*normalABC1[1]+p_CentroidABC[2]*normalABC1[2]>0)
        cout<<"ABC is illuminated"<<endl;
    if(p_CentroidCBD[0]*normalCBD3[0]+p_CentroidCBD[1]*normalCBD3[1]+p_CentroidCBD[2]*normalCBD3[2]>0)
        cout<<"BCD is illuminated"<<endl;
    if(p_CentroidACD[0]*normalACD[0]+p_CentroidACD[1]*normalACD[1]+p_CentroidACD[2]*normalACD[2]>0)
        cout<<"ACD is illuminated"<<endl;
    if(p_CentroidABD[0]*normalABD2[0]+p_CentroidABD[1]*normalABD2[1]+p_CentroidABD[2]*normalABD2[2]>0)
        cout<<"ABD is illuminated"<<endl;
    getch();
    return 0;
}
