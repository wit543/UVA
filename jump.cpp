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
    bool visited[1000];
void init()
{
    for(int i=0; i<n; i++)
    visited[i] = false;
}
int search(int x,int y)
{
    if((100-x)*(100-x)+(100-y)*(100-y)<=r*r)
    {
        return 1;
    }
    for(int i=0;i<=n;i++){;
        if((x-gaphX[x][y][i])*(x-gaphX[x][y][i])+(y-gaphY[x][y][i])*(y-gaphY[x][y][i])<=r*r)
        {
            cout<<"::"<<x<<" "<<y<<endl;
            return search(gaphX[x][y][i],gaphY[x][y][i])+1;
        }
    }
    return -1;
}
int main()
{
    cin>>n>>r;
    init();
    x[0]=0;
    y[0]=0;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        x[i]=u;
        y[i]=v;
        
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
