#include<iostream>
#include<graphics.h>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
vector<pair<int,pair<float,float> > > edgeTable[10001];
/**
edge table will store vector arrays also called the scanLines with each member containing details of yMax,xOfYMin,slopeInverse
respectively thus
edgeTable[i].first=yMax;
edgeTable[i].first.first=xOfYMin;
edgeTable[i].first.second=slopeInverse;
*/

int yMax=0,yMin=10001;

void addToEdgeTable(int yMin,float xOfYMin, int yMax, float slopeInverse) {
    edgeTable[yMin].push_back(make_pair(yMax,make_pair(xOfYMin,slopeInverse)));
}

void plotDino() {
    ifstream inFile;
    inFile.open("dinoCoord.txt");
    string x;
    while (getline(inFile,x)) {
        int pos=find(x.begin(),x.end(),',')-x.begin();
        string s1=x.substr(0,pos);
        string s2=x.substr(pos+1,x.length());
        int num1=0,num2=0;
        int i=0,j=s1.length();
        while(j--) {
            num1+=(s1[j]-48)*pow(10,i++);
        }
        i=0,j=s2.length();
        while(j--) {
            num2+=(s2[j]-48)*pow(10,i++);
        }
        num1++,num2++;
        if(num2<yMin) {
            yMin=num2;
        }
        if(num2>yMax) {
            yMax=num2;
        }
        v.push_back(make_pair(num1,num2));
    }
    setcolor(GREEN);
    for(int i=0;i<v.size()-1;i++) {
        //cout<<"("<<v[i].first<<","<<v[i].second<<") "<<"("<<v[i+1].first<<","<<v[i+1].second<<")"<<endl;
        line(v[i].first,v[i].second,v[i+1].first,v[i+1].second);
        if((v[i+1].second-v[i].second)) {
            float slopeInverse=(v[i+1].first-v[i].first)/(float)(v[i+1].second-v[i].second);
            float xOfYMin,yMin,yMax;
            if(v[i+1].second<v[i].second) {
                xOfYMin=v[i+1].first;
                yMin=v[i+1].second;
                yMax=v[i].second;
            } else {
                xOfYMin=v[i].first;
                yMin=v[i].second;
                yMax=v[i+1].second;
            }
            addToEdgeTable(yMin,xOfYMin,yMax,slopeInverse);
        }
    }
    line(v[v.size()-1].first,v[v.size()-1].second,v[0].first,v[0].second);
    if((v[v.size()-1].second-v[0].second)) {
        float slopeInverse=(v[v.size()-1].first-v[0].first)/(float)(v[v.size()-1].second-v[0].second);
        float xOfYMin,yMin,yMax;
        if(v[v.size()-1].second<v[0].second) {
            xOfYMin=v[v.size()-1].first;
            yMin=v[v.size()-1].second;
            yMax=v[0].second;
        } else {
            xOfYMin=v[0].first;
            yMin=v[0].second;
            yMax=v[v.size()-1].second;
        }
        addToEdgeTable(yMin,xOfYMin,yMax,slopeInverse);
    }
    inFile.close();
}

bool compare(pair<int,pair<float,float> > it1,pair<int,pair<float,float> > it2) {
    return it1.second.first<it2.second.first;
}

int main() {
    vector<pair<int,pair<float,float> > > activeList;
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,"C:\\TURBOC3\\BGI");

    plotDino();
    cout<<yMax<<", "<<yMin<<endl;
    vector<pair<int,pair<float,float> > >::iterator it;
    int i=yMin;
    while(i!=yMax) {
        /*if(activeList.size()) {
            sort(activeList.begin(),activeList.end(),compare);
        }*/
        for(it=edgeTable[i].begin();it!=edgeTable[i].end();it++) {
            cout<<"yMin: "<<i<<" || "<<"yMax: "<<it->first<<" xOfYMin: "<<it->second.first<<" slopeInverse: "<<it->second.second<<endl;
        }
        i++;
    }
    i=yMin;
    while(i!=yMax) {
        for(it=edgeTable[i].begin();it!=edgeTable[i].end();it++) {
            activeList.push_back(make_pair(it->first,make_pair(it->second.first,it->second.second)));
        }
        sort(activeList.begin(),activeList.end(),compare);
        for(it=activeList.begin();it<activeList.end();it++) {
            if(i==(it->first)) {
                it=activeList.erase(it);
                it--;
            }
        }
        cout<<"\n IMP \n";
        for(it=activeList.begin();it<activeList.end();it++) {
            cout<<(it->first)<<" AND "<<it->second.first<<endl;
        }
        for(it=activeList.begin();it<activeList.end()-1;it+=2) {
            setcolor(YELLOW);
            line(it->second.first,i,(it+1)->second.first,i);
        }
        for(it=activeList.begin();it<activeList.end();it++) {
            it->second.first+=it->second.second;
        }
        i++;
    }
    setcolor(RED);
    plotDino();
    getch();
    return 0;
}
