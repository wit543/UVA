// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
       int m,o;
        cin>>m>>o;
        m-=2;
        o-=2;
        if(m%3==0){m/=3;}
        else{m/=3;m++;}
        if(o%3==0){o/=3;}
        else{o/=3;o++;}
        cout<<m*o<<endl;
    }

}
