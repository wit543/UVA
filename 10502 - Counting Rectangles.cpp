// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(){

   while(true){
       int n,m;
       cin>>n;
       if(n==0){break;}
       cin>>m;
       char a[n][m];
       for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
               cin>>a[i][j];
       int out =0;

       for(int i=0;i<=n;i++)
           for(int j=0;j<=m;j++)
               for(int k=0;k<n;k++)
                   for(int l=0;l<m;l++) {
                       int c = 0;
                       for (int o = k; o < k+i&&o<n; o++) {
                           for (int p = l; p < l + j && p < m; p++) {
                               if (a[o][p] == '1') {
                                   c++;
                               }
                           }
                       }
                       if(c==i*j&&c>0){
//                           cout<<"ok"<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                           out++;
                       }
                   }
       cout<<out<<endl;
   }
}
