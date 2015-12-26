// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
vector<int> gaphX[101][101];
vector<int> gaphY[101][101];
int x[1000],y[1000];
//bool xVisit[101][101],yVisit[101][101];
int main(){
    int n,r;
    cin>>n>>r;
    x[0]=0;
    y[0]=0;
    cout<<n<<" "<<r<<endl;
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        cout<<u<<" "<<v<<endl;
        x[i]=u;
        y[i]=v;
        cout<<u<<" "<<v<<endl;
        for(int j=0;j<i;j++)
        {
            gaphX[x[j]][y[j]].push_back(u);
            gaphY[x[j]][y[j]].push_back(v);
            gaphX[u][v].push_back(x[j]);
            gaphY[u][v].push_back(y[j]);
        }
    }
//    queue<int> qx,qy;
//    qx.push(x[0]);
//    qy.push(y[0]);
//    xVisit[x[0]][y[0]]=true;
//    yVisit[x[0]][y[0]]=true;
//    int out =0;
//    int lx=0,ly=0;
//    bool layer = true;
//    while(!qx.empty()&&!qy.empty()){
//        int ix = qx.front();
//        qx.pop();
//        int iy = qy.front();
//        qy.pop();
//        if(abs((100-ix)*(100-ix))+
//           abs((100-iy)*(100-iy))<=r*r){
////            cout<<"o: "<<out<<endl;
////            cout<<"go: "<<gaphX[x[ix]][y[iy]][i]<<" "<<gaphY[x[ix]][y[iy]][i]<<endl;
//            out++;
//            break;
//        }
//        if(lx==ix&&ly==iy){
//            out++;
////            cout<<"out: "<<ix<<" "<<iy<<endl;
//            layer= true;
//        }
//        int ilx,ily;
//        for(int i=0;i<n;i++){
//            if(abs((gaphX[x[ix]][y[iy]][i]-ix)*(gaphX[x[ix]][y[iy]][i]-ix))+
//                    abs((gaphY[x[ix]][y[iy]][i]-iy)*(gaphY[x[ix]][y[iy]][i]-iy))<=r*r){
//                if(!xVisit[gaphX[x[ix]][y[iy]][i]][gaphY[x[ix]][y[iy]][i]]&&
//                        !yVisit[gaphX[x[ix]][y[iy]][i]][gaphY[x[ix]][y[iy]][i]]){
//                    xVisit[gaphX[x[ix]][y[iy]][i]][gaphY[x[ix]][y[iy]][i]]=true;
//                    yVisit[gaphX[x[ix]][y[iy]][i]][gaphY[x[ix]][y[iy]][i]]=true;
//                    qx.push(gaphX[x[ix]][y[iy]][i]);
//                    qy.push(gaphY[x[ix]][y[iy]][i]);
//                    ilx=gaphX[x[ix]][y[iy]][i];
//                    ily=gaphY[x[ix]][y[iy]][i];
////                    cout<<"g: "<<gaphX[x[ix]][y[iy]][i]<<" "<<gaphY[x[ix]][y[iy]][i]<<" "<<ix<<" "<<iy<<endl;
//                }
//            }
//        }
//        if(layer){
//            lx=ilx;
//            ly=ily;
//            layer=false;
////            cout<<"layer:  "<<lx<<" "<<ly<<endl;
//        }
//    }
////    for(int i=0;i<n;i++){
////        for(int j=0;j<n;j++) {
////            cout << gaphX[x[i]][y[i]][j] << "," << gaphY[x[i]][y[i]][j] << " ";
////        }
////        cout<<endl;
////    }
//    cout<<out<<endl;
}
