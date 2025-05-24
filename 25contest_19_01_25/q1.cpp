#include<iostream>

using namespace std;

int main(){
    int a1,a2,a3,a4,a5;
    int t;
    cin>>t;
    while(t--){
        cin>>a1>>a2>>a4>>a5;
        if(a4==a1+2*a2 && a5==2*a1+3*a2){
            cout<<3<<endl;
        }
        else if((a4!=a1+2*a2 && 2*a4-a5==a2)||(a5==a1+a2+a4 && a4!=a1+2*a2)||(a4==a1+2*a2 && a5!=a1+a2+a4)){
            cout<<2<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    return 0;
}