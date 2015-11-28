#include <iostream>
#include <string>

using namespace std;
string toHex(int n){
    // cout<<"n: "<<n<<endl;
    if(n<10){return to_string(n);}
    if(n==15){return "F";}
    if(n==14){return "E";}
    if(n==13){return "D";}
    if(n==12){return "C";}
    if(n==11){return "B";}
    if(n==10){return "A";}
    
    if(n%16==15){return toHex(n/16)+"F";}
    else if(n%16==14){return toHex(n/16)+"E";}
    else if(n%16==13){return toHex(n/16)+"D";}
    else if(n%16==12){return toHex(n/16)+"C";}
    else if(n%16==11){return toHex(n/16)+"B";}
    else if(n%16==10){return toHex(n/16)+"A";}
    else{ return toHex(n/16)+to_string(n%16);}
}

int main()
{
    string n=" ";
    while(n.at(0)!='-'){
        cin>>n;
        if(n.at(0)=='-'){
            break;    
        }
        if(n.length()>1&&n.at(1)=='x'){
             cout<<stoi(n,nullptr,16)<<endl;
        }
        else{
            cout<<"0x"<<toHex(stoi(n,nullptr,0))<<endl;
        }
    }
    return 0;
}
