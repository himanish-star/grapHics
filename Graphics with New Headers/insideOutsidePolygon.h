bool checkInsideOrOutside(float vertices[][2],int n,float p1,float p2) {
    int negCount=0,posCount=0;
    for(int i=0;i<n-1;i++) {
        float normalVector[2]={(vertices[i+1][1]-vertices[i][1]),-(vertices[i+1][0]-vertices[i][0])};
        float pVector[2]={(p1-vertices[i][0]),(p2-vertices[i][1])};
        float sign=(normalVector[0]*pVector[0])+(normalVector[1]*pVector[1]);
        if(sign<0) {
            negCount++;
        } else if(sign>0) {
            posCount++;
        }
    }
    float normalVector[2]={(vertices[0][1]-vertices[n-1][1]),-(vertices[0][0]-vertices[n-1][0])};
    float pVector[2]={(p1-vertices[n-1][0]),(p2-vertices[n-1][1])};
    float sign=(normalVector[0]*pVector[0])+(normalVector[1]*pVector[1]);
    if(sign<0) {
        negCount++;
    } else if(sign>0) {
        posCount++;
    }
    if(negCount==n) {
        return true;
    }
    else if(posCount==n) {
        return true;
    }
    return false;
}
