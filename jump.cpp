
// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <set>
#include <map>

using namespace std;

int main() {

    int n,k;
    cin>>n>>k;

    int aci[100000],ami[100000],asi[100000],api[100000];
    set<pair<int,int>> ci,mi,si;
    for(int i=0;i<n;i++){
        int ciin,miin,siin,piin;
        cin>>ciin>>miin>>siin>>piin;
//        scanf("%d %d %d %d",&ciin,&miin,&siin,&piin);
        ci.insert(pair<int,int>(ciin,i));
        mi.insert(pair<int,int>(miin,i));
        si.insert(pair<int,int>(siin,i));
        aci[i]=ciin;
        ami[i]=miin;
        asi[i]=siin;
        api[i]=piin;
    }
    for(int i=0;i<k;i++){
        int t,in,o=0;
        bool f=false;
        cin>>t>>in;
//        scanf("%d %d",&t,&in);
        if(t==1){
            if(ci.lower_bound(pair<int,int>(in,-1))!=ci.end()){
                o = ci.lower_bound(pair<int,int>(in,-1))->second;
                f=true;
            }

        }
        if(t==2){
            if(mi.lower_bound(pair<int,int>(in,-1))!=mi.end()){
                o = mi.lower_bound(pair<int,int>(in,-1))->second;
                f=true;
            }
        }
        if(t==3){
            if(si.lower_bound(pair<int,int>(in,-1))!=si.end()){
                o = si.lower_bound(pair<int,int>(in,-1))->second;
                f=true;
            }
        }
        if(t>=1&&t<=3&&f){
            cout<<api[o]<<endl;
            ci.erase(pair<int,int>(aci[o],o));
            mi.erase(pair<int,int>(ami[o],o));
            si.erase(pair<int,int>(asi[o],o));
        }
        if(t>=1&&t<=3&&!f){
           cout<<0<<endl;
        }
    }
}
