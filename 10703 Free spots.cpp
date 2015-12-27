// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(){

    int n,m,o;
   while(true){
       bool** a = new bool*[501];
       for(int i=0;i<501;i++)
           a[i]=new bool[501];
       cin>>n>>m>>o;
       if(n==0&&m==0&&o==0){break;}
       int x1,y1,x2,y2;
        for(int i=0;i<o;i++){
                cin>>x1>>y1>>x2>>y2;

            if (x1 > x2) {
                swap(x1, x2);
                swap(y1,y2);
            }

            if (y1 > y2) {
                swap(y1, y2);
            }

           for(int k=y1;k<=y2;k++){
               for(int j=x1;j<=x2;j++){
                   a[k][j]=true;
               }
           }
        }
       int out =0;
       for(int i=1;i<=m;i++){
           for(int j=1;j<=n;j++){
               if(!a[i][j]){
               out++;
               }
           }
       }
       if(out==0){
           cout<<"There is no empty spots."<<endl;
       }
       else if(out == 1){
           cout<<"There is one empty spot."<<endl;
       }
       else{
           cout<<"There are "<<out<<" empty spots."<<endl;
       }
   }
}
