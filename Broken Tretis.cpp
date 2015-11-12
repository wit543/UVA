#include <iostream>
#include <string>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int *a = new int[10];
    for(int i = 0;i<n;i++){
        char c;
        int o;
        cin>>c>>o;
        if(c=='-'){
            int max=0;
            for(int j=0;j<4;j++){
                if(a[o+j-1]>max){
                    max = a[o+j-1];
                    }
                }
                for(int j=0;j<4;j++){a[o+j-1]=max+1;}
        }
        else if(c=='o'){
            int max = a[o-1];
            if(a[o]>max){
                max = a[o];
                }
            for(int j=0;j<2;j++){a[o+j-1]=max+2;}
        }
        else if(c=='i'){
            a[o-1]+=4;    
        }
    }
    int max = 0;
    for(int i =0;i<10;i++){
        if(a[i]>max){
            max=a[i];
            }
    }
    cout<<max;
}
