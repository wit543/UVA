// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(){
   char a[100][100];
    int n,m;
   while(true){

       cin>>n;
       if(n==0){break;}
       cin>>m;
       if(m==0){break;}
       for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
               cin>>a[i][j];
       int out =0;

       for(int k=0;k<n;k++)
           for(int l=0;l<m;l++) {
               if(a[k][l]!='1'){ continue;}
               for(int i=1;i<=n;i++)
                   for(int j=1;j<=m;j++){
                       if (a[k][l] != '1') continue;
                       int c = 0;
                       bool have = true;
                       bool in = false;
                       for (int o = k; o < k+i&&o<n; o++) {
                           for (int p = l; p < l + j && p < m; p++) {
                               if (a[o][p] != '1') {
                                   have = false;
                                   o+=i;
                                   p+=j;
                               }
                           }
                       }

                       if(have&&(k+i)<=n&&(l+j)<=m){
                           out++;
                       }
                   }
           }
       cout<<out<<endl;
   }
}
