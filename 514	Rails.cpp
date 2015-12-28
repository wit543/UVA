// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
using namespace std;

int main(){
    int a,b;
    int l[1000];
    while(cin>>a){
        if(a==0){break;}
        int o =1;
        while(true){
            cin>>l[0];
            if(l[0]==0){cout<<endl; break;}
            for(int j=1;j<a;j++){
                cin>>l[j];
            }
            stack<int> s;
            int i=0;
                for(int j=1;j<=a;j++) {
                    s.push(j);
                    while (!s.empty()){
                        if(s.top()!=l[i]||i>=a){
                           break;
                        }
                        s.pop();
                        i++;

                    }
                }
                if(s.empty())
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
                o=1;
        }

    }
}
