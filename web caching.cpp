
// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <set>
#include <map>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    set<int> s;
    queue<int> q;
    int o=0;
    for(int i=0;i<k;i++){
        int in;
        cin>>in;
        if(s.find(in)==s.end()){
            if(q.size()>=n){
                s.erase(q.front());
                q.pop();
            }
            s.insert(in);
            q.push(in);
            o++;
        }
    }
    cout<<o<<endl;
}
