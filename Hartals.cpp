
#include "iostream"
#include "string"
using namespace std;

main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int d;
        cin >> d;
        int t;
        cin >> t;
        int array[t];
        for(int j =0;j<t;j++){
            cin>>array[j];
        }
        int c=0;
        for(int a=1;a<=d;a++){
            for(int b=0;b<t;b++){
                if(a%array[b]==0&&(a%7!=0&&a%7!=6)){
                    c++;
                    b+=t;
                }
            }
        }
        cout<<c<<endl;
    }
}
