#include <iostream>
#include <string>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int x=0;
    for(int i = 0;i<n;i++){
    int a;
    cin>>a;
    if(a>1000){a=1000;}
    x+=a;
    if(a>=1000){cin>>a;i++;}
    }
    cout<<x;
}
