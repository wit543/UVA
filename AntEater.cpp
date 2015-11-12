#include <iostream>
#include <string>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int x;
    for(int i = 0;i<n;i++){
    int a;
    cin>>a;
    x+=a;
    if(a==1000){cin>>a;i++;}
    }
    cout<<x;
}
