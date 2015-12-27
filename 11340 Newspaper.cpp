// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(){

    int n,m;
    char a[100];
    int b[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        int out =0;
        for(int j=0;j<m;j++){
            cin>>a[j]>>b[j];
        }
        int o;
        cin>>o;
        for(int j=0;j<=o;){
            char c;
            scanf("%c",&c);
            if(c=='\n'){
                j++;
                continue;}
            if(c==' '){ continue;}
            for(int l=0;l<m;l++){
                if(c==a[l]){
                    out+=b[l];
                    break;
                }

            }
        }
        cout<<out/100<<".";
        printf("%02d$\n",out%100);
    }

}
