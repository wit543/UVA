// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
int n,r;
vector<int> gaphX[101][101];
vector<int> gaphY[101][101];
int x[1000];
int y[1000];
bool visitedX[101][101];
bool visitedY[101][101];
int search(int x,int y)
{
    queue<int> qX,qY;
    qX.push(x);
    qY.push(y);
    visitedX[x][y]=true;
    visitedY[x][y]=true;
    int count =0;
    int tX=x,tY=y;
    int aa[n],ab[n];
    int ac=0;
    int ba=-100,bb=-100;
    bool isLast = true;
    while(!qX.empty()&&!qY.empty())
    {
        int dX = qX.front();
        qX.pop();
        int dY = qY.front();
        qY.pop();
        // cout<<"======="<<dX<<" "<<ba<<" "<<dY<<" "<<bb<<endl;
        if(dX==ba&&dY==bb)
        {
            count++;
            isLast=true;
        }
        if((100-dX)*(100-dX)+(100-dY)*(100-dY)<=r*r)
        {
            return count;
        }
        
        for(int i=0;i<=n;i++)
        {
            if((gaphX[dX][dY][i]-dX)*(gaphX[dX][dY][i]-dX)+(gaphY[dX][dY][i]-dY)*(gaphY[dX][dY][i]-dY)<=r*r)
            {
                if(!visitedX[gaphX[dX][dY][i]][gaphY[dX][dY][i]]&&!visitedY[gaphX[dX][dY][i]][gaphY[dX][dY][i]])
                {
                    // cout<<"::"<<dX<<" "<<dY<<" : "<<visitedX[gaphX[dX][dY][i]][gaphY[dX][dY][i]]<<" "<<visitedY[gaphX[dX][dY][i]][gaphY[dX][dY][i]]<<endl;
                    // cout<<"? "<<gaphX[dX][dY][i]<<" "<<gaphY[dX][dY][i]<<endl;
                    visitedX[gaphX[dX][dY][i]][gaphY[dX][dY][i]]=true;
                    visitedY[gaphX[dX][dY][i]][gaphY[dX][dY][i]]=true;;
                    qX.push(gaphX[dX][dY][i]);
                    qY.push(gaphY[dX][dY][i]);
                    tX=dX;tY=dY;
                    aa[ac]=gaphX[dX][dY][i];
                    ab[ac]=gaphY[dX][dY][i];
                    if(isLast){
                        ba=gaphX[dX][dY][i];
                        bb=gaphY[dX][dY][i];
                        ac++;
                        isLast=false;
                    }
                }
            }
        }
        
        // cout<<"size: "<<qX.size()<<endl;
        // cout<<"out"<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<aa[i]<<","<<ab[i]<<" ";
        // }
        // cout<<endl;
    }
    
    // if((100-x)*(100-x)+(100-y)*(100-y)<=r*r)
    // {
    //     return 1;
    // }
    // int o=10000;
    // for(int i=0;i<=n;i++){
    //     if((gaphX[x][y][i]-x)*(gaphX[x][y][i]-x)+(gaphY[x][y][i]-y)*(gaphY[x][y][i]-y)<=r*r)
    //     {
    //         if(!visitedX[gaphX[x][y][i]][gaphY[x][y][i]]&&!visitedY[gaphX[x][y][i]][gaphY[x][y][i]])
    //         {
    //             cout<<"::"<<x<<" "<<y<<" : "<<visitedX[gaphX[x][y][i]][gaphY[x][y][i]]<<" "<<visitedY[gaphX[x][y][i]][gaphY[x][y][i]]<<endl;
    //             cout<<"? "<<gaphX[x][y][i]<<" "<<gaphY[x][y][i]<<endl;
    //             visitedX[gaphX[x][y][i]][gaphY[x][y][i]]=true;
    //             visitedY[gaphX[x][y][i]][gaphY[x][y][i]]=true;
    //             if(search(gaphX[x][y][i],gaphY[x][y][i])<o&&search(gaphX[x][y][i],gaphY[x][y][i])>0)
    //             {
    //                 o = search(gaphX[x][y][i],gaphY[x][y][i])+1;
    //             }
    //         }
    //     }
    // }
    // if(o<10000)
    // {
    // return o;
    // }
    return -1;
}
int main()
{
    cin>>n>>r;
    x[0]=0;
    y[0]=0;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        x[i]=u;
        y[i]=v;
        visitedX[u][v]=false;
        visitedY[u][v]=false;
        for(int j=0;j<i;j++)
        {
            // cout<<"::"<<i<<" "<<j<<endl;
            gaphX[x[j]][y[j]].push_back(u);
            gaphY[x[j]][y[j]].push_back(v);
            gaphX[u][v].push_back(x[j]);
            gaphY[u][v].push_back(y[j]);
        }
        // cout<<i<<endl;
    }
    for(int i=0;i<n;i++)
    {
        // cout<<"x: "<<x[i]<<"y: "<<y[i]<<endl;
        // for(int j=0;j<n;j++)
        // {
        //     cout<<gaphX[x[i]][y[i]][j]<<","<<gaphY[x[i]][y[i]][j]<<" ";
        // }
        // cout<<endl;
    }
    cout<<search(0,0)+1<<endl;
}
