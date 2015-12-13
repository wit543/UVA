// Example program
#include <iostream>
#include <string>
#include <vector>

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
    if((100-x)*(100-x)+(100-y)*(100-y)<=r*r)
    {
        return 1;
    }
    int o=10000;
    for(int i=0;i<=n;i++){;
        if((gaphX[x][y][i]-x)*(gaphX[x][y][i]-x)+(gaphY[x][y][i]-y)*(gaphY[x][y][i]-y)<=r*r)
        {
            if(!visitedX[gaphX[x][y][i]][gaphY[x][y][i]]&&!visitedY[gaphX[x][y][i]][gaphY[x][y][i]])
            {
                cout<<"::"<<x<<" "<<y<<" : "<<visitedX[gaphX[x][y][i]][gaphY[x][y][i]]<<" "<<visitedY[gaphX[x][y][i]][gaphY[x][y][i]]<<endl;
                cout<<"? "<<gaphX[x][y][i]<<" "<<gaphY[x][y][i]<<endl;
                visitedX[gaphX[x][y][i]][gaphY[x][y][i]]=true;
                visitedY[gaphX[x][y][i]][gaphY[x][y][i]]=true;
                if(search(gaphX[x][y][i],gaphY[x][y][i])<o)
                {
                    o = search(gaphX[x][y][i],gaphY[x][y][i])+1;
                }
            }
        }
    }
    if(o<10000)
    {
    return o;
    }
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
        }
        // cout<<i<<endl;
    }
    cout<<search(0,0)<<endl;
}
