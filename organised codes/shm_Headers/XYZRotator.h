using namespace std;

void makecubeFront(float obj[8][4],colors color)
{
    setcolor(color);
    for(int i=0;i<4;i++){
        line(210+obj[i][0],240-obj[i][1],210+obj[(i+1)%4][0],240-obj[(i+1)%4][1]);
        line(210+obj[i+4][0],240-obj[i+4][1],210+obj[((i+1)%4)+4][0],240-obj[((i+1)%4)+4][1]);
        line(210+obj[i][0],240-obj[i][1],210+obj[i+4][0],240-obj[i+4][1]);
    }
}

void axisMutilpier(float obj[][4],float trans[4][4], int rows)
{
        float mul[rows][4];
        for(int i=0;i<rows;i++){
            for(int j=0;j<4;j++){
                float sum=0;
                for(int k=0;k<4;k++){
                    sum=sum+(obj[i][k]*trans[k][j]);
                }
                mul[i][j]=sum;
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<4;j++)
                obj[i][j]=mul[i][j];
        }
}

void xAxisRotation(float obj[][4],float xA) {
    float pi=3.14159265;
    xA=pi*xA;
    float rotx[4][4]={1,0,0,0,0,cos(xA/180),-1*sin(xA/180),0,0,sin(xA/180),cos(xA/180),0,0,0,0,1};
    axisMutilpier(obj,rotx,8);
}

void yAxisRotation(float obj[][4],float yA) {
    float pi=3.14159265;
    yA=pi*yA;
    float roty[4][4]={cos(yA/180),0,sin(yA/180),0,0,1,0,0,-1*sin(yA/180),0,cos(yA/180),0,0,0,0,1};
    axisMutilpier(obj,roty,8);
}

void zAxisRotation(float obj[][4],float zA) {
    float pi=3.14159265;
    zA=pi*zA;
    float rotz[4][4]={cos(zA/180),-1*sin(zA/180),0,0,sin(zA/180),cos(zA/180),0,0,0,0,1,0,0,0,0,1};
    axisMutilpier(obj,rotz,8);
}

