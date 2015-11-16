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
    
    
    if(n/16==15){return "F"+toHex(n%16);}
    else if(n/16==14){return "E"+toHex(n%15);}
    else if(n/16==13){return "D"+toHex(n%14);}
    else if(n/16==12){return "C"+toHex(n%13);}
    else if(n/16==11){return "B"+toHex(n%12);}
    else if(n/6==10){return "A"+toHex(n%11);}
    else{ return to_string(n/16)+toHex(n%16);}
}

int main()
{
    string n="";
    while(n!="-1"){
        cin>>n;
        if(stoi(n,nullptr,0)==-1){
            break;
            }
        if(n.length()>1&&n.at(1)=='x'){
            cout<<stoi(n,nullptr,0)<<endl;
            }
        else{
            cout<<hex<<n<<endl;
        // cout<<"0x"<<itoa (n,buffer,16)<<endl;
        }
    }
    return 0;
}
