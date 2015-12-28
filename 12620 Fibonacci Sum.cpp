// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main(){
    int a[307];
    int d[301];
    a[1]=1;
    a[2]=1;
    d[0]=0;
    d[1]=1;
    d[2]=2;
    int n;
    cin>>n;
    for(int i=3;i<307;i++){
        a[i]=(a[i-1]+a[i-2])%100;
        d[i]=d[i-1]+a[i];
    }
    for(int i=0;i<n;i++){
        long long c,b;
        cin>>c>>b;
        long long out=0;
        out = ((b)/300*14800+d[(b)%300])-((c-1)/300*14800+d[(c-1)%300]);
        cout<<out<<endl;
    }
}
