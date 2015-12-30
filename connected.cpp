// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
vector<int> gaphX[100001];
bool xVisit[100001];
int main(){

    int n,r;
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        gaphX[i]= *new vector<int>();
        xVisit[i]=false;
    }
    for(int i=1;i<=r;i++){
        int u,v;
        cin>>u>>v;
        gaphX[u].push_back(v);
        gaphX[v].push_back(u);

    }
    int out =0;
    for(int i=1;i<=n;i++){
        if(!xVisit[i]) {
            out++;
            xVisit[i]=true;
            while (true) {
                if(gaphX[i].empty())break;
                int p = gaphX[i].back();
                gaphX[i].pop_back();
                xVisit[p]=true;
            }
        }
    }
    cout<<out<<endl;
}
