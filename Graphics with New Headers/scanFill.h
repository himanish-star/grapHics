#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v;
vector<pair<int,pair<float,float> > > edgeTable[10001];

/**
edge table will store vector arrays also called the scanLines with each member containing details of yScanFillMax,xOfyScanFillMin,slopeInverse
respectively thus
edgeTable[i].first=yScanFillMax;
edgeTable[i].first.first=xOfyScanFillMin;
edgeTable[i].first.second=slopeInverse;
*/

int yGlobalScanFillMax=0,yGlobalScanFillMin=10001;

void addToEdgeTable(int yScanFillMin,float xOfyScanFillMin, int yScanFillMax, float slopeInverse) {
    edgeTable[yScanFillMin].push_back(make_pair(yScanFillMax,make_pair(xOfyScanFillMin,slopeInverse)));
}

void plotDino(int edgePoints[][2],int n,colors colorOutline) {
    for(int i=0;i<n;i++) {
        v.push_back(make_pair(edgePoints[i][0],edgePoints[i][1]));
        if(edgePoints[i][1]<yGlobalScanFillMin) {
            yGlobalScanFillMin=edgePoints[i][1];
        }
        if(edgePoints[i][1]>yGlobalScanFillMax) {
            yGlobalScanFillMax=edgePoints[i][1];
        }
    }
    setcolor(colorOutline);
    for(int i=0;i<v.size()-1;i++) {
        line(v[i].first,v[i].second,v[i+1].first,v[i+1].second);
        if((v[i+1].second-v[i].second)) {
            float slopeInverse=(v[i+1].first-v[i].first)/(float)(v[i+1].second-v[i].second);
            float xOfyScanFillMin,yScanFillMin,yScanFillMax;
            if(v[i+1].second<v[i].second) {
                xOfyScanFillMin=v[i+1].first;
                yScanFillMin=v[i+1].second;
                yScanFillMax=v[i].second;
            } else {
                xOfyScanFillMin=v[i].first;
                yScanFillMin=v[i].second;
                yScanFillMax=v[i+1].second;
            }
            addToEdgeTable(yScanFillMin,xOfyScanFillMin,yScanFillMax,slopeInverse);
        }
    }
    line(v[v.size()-1].first,v[v.size()-1].second,v[0].first,v[0].second);
    if((v[v.size()-1].second-v[0].second)) {
        float slopeInverse=(v[v.size()-1].first-v[0].first)/(float)(v[v.size()-1].second-v[0].second);
        float xOfyScanFillMin,yScanFillMin,yScanFillMax;
        if(v[v.size()-1].second<v[0].second) {
            xOfyScanFillMin=v[v.size()-1].first;
            yScanFillMin=v[v.size()-1].second;
            yScanFillMax=v[0].second;
        } else {
            xOfyScanFillMin=v[0].first;
            yScanFillMin=v[0].second;
            yScanFillMax=v[v.size()-1].second;
        }
        addToEdgeTable(yScanFillMin,xOfyScanFillMin,yScanFillMax,slopeInverse);
    }
}

bool compare(pair<int,pair<float,float> > it1,pair<int,pair<float,float> > it2) {
    return it1.second.first<it2.second.first;
}

int colorFigureScanFill(int edgePoints[][2],int n,colors colorOutline,colors colorFill) {
    yGlobalScanFillMax=0,yGlobalScanFillMin=10001;
    v.clear();
    for(int kl=0;kl<10001;kl++) {
        edgeTable[kl].clear();
    }
    vector<pair<int,pair<float,float> > > activeList;

    plotDino(edgePoints,n,colorOutline);
    cout<<yGlobalScanFillMax<<", "<<yGlobalScanFillMin<<endl;
    vector<pair<int,pair<float,float> > >::iterator it;
    int i=yGlobalScanFillMin;
    while(i!=yGlobalScanFillMax) {
        for(it=edgeTable[i].begin();it!=edgeTable[i].end();it++) {
            cout<<"yScanFillMin: "<<i<<" || "<<"yScanFillMax: "<<it->first<<" xOfyScanFillMin: "<<it->second.first<<" slopeInverse: "<<it->second.second<<endl;
        }
        i++;
    }
    i=yGlobalScanFillMin;
    while(i!=yGlobalScanFillMax) {
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
            setcolor(colorFill);
            line(it->second.first,i,(it+1)->second.first,i);
        }
        for(it=activeList.begin();it<activeList.end();it++) {
            it->second.first+=it->second.second;
        }
        i++;
    }
    setcolor(RED);
    return 0;
}

