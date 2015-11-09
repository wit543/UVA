
#include "iostream"
#include "string"
using namespace std;
unsigned int expro(int n){
    if(n==0){return 1;}
    return expro(n-1)*2;
}
using namespace std;
int* toBinary(int n[],int b,unsigned int m){
    if(b<0){return n;}
    n[31-b]=m/expro(b);
    m%=expro(b);
    return toBinary(n,b-1,m);
}
unsigned toDec(int n[],int m[],int b){
    if(b<0){return 0;}
    if(n[31-b]!=m[31-b]&&(n[31-b]==1||m[31-b]==1)){
        return toDec(n,m,b-1)+expro(b);
    }
    return toDec(n,m,b-1);
}
main(){
  while(!cin.eof()){
      unsigned int n,m;
      cin>>n>>m;
      int arrayN[32],arrayM[32],arrayO[32];
      if(cin.eof()){
          break;
      }
      int *outn = toBinary(arrayN,31,n);
      int *outm = toBinary(arrayM,31,m);
      unsigned out = toDec(arrayN,arrayM,31);
      cout<<out<<endl;

  }
}
