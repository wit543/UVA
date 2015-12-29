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


int a[200];

int left=100;
int right=101;
int insert(int p)
{
    int c;
    cin>>c;
    if(p==0)
        if(c==-1){return 0;}
    a[100+p]+=c;
    if(100+p<left){left=100+p;}
    if(100+p>=right){right=100+p+1;}
    insert(p-1);
    insert(p+1);
//    TreeNode* t = new TreeNode(c);
//    t->parent=p;
//    t->left=insert(p);
//    t->right=insert(p);

    return 1;
}


int main(){
    int t=1;
    int c = 1;
    while(true){
        left=100;
        right=101;
        t =insert(0);
        cout<<"Case "<<c<<":"<<endl;
        for(int i=left;i<right;i++){
            cout<<a[i]<<" ";
        }
        if(t==0){break;}
        c++;
        cout<<endl<<endl;
    }
}
