// Example program
#include <iostream>
#include <string>

using namespace std;
int main()
{
  int n,r;
  cin>>n>>r;
  int x[n];
  int y[n];
  int xI=0,yI=0;
  int count=0;
  for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
      }
      for(int i=0;i<n;i++){
          int xM=xI,yM=yI;
          for(int j=0;j<n;j++){
              if((x[j]-xI)*(x[j]-xI)+(y[j]-yI)*(y[j]-yI)<=r*r){
                 
                 if((xI-x[j])*(xI-x[j])+(yI-y[j])*(yI-y[j])>
                 (xI-xM)*(xI-xM)+(yI-yM)*(yI-yM)&&
                  (100-x[j])*(100-x[j])+(100-y[j])*(100-y[j])<
                 (100-xM)*(100-xM)+(100-yM)*(100-yM)){
                     xM=x[j];
                     yM=y[j];
                     x[i]=-100;
                     y[i]=-100;

                     }
              }
             
          }
          xI=xM;
          yI=yM;
          count++;
          // cout<<"x: "<<xI<<"y: "<<yI<<endl;
        if(xI!=xM&&yI!=yM){
          count ++;}
          if((100-xI)*(100-xI)+(100-yI)*(100-yI)<=r*r){
            count++;
            break;
            }
      }
      if((100-xI)*(100-xI)+(100-yI)*(100-yI)>r*r){
            count=-1;
            }
      cout<<count<<endl;
}
