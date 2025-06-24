#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,l1,b1,l2,b2,l3,b3;
    cin>>t;
    while(t--){
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        if(l1==l2 && l2==l3 && b1+b2+b3==l1){
            cout<<"yes"<<endl;
            continue;
        }
        if(b1==b2 && b2==b3 && l1+l2+l3==b1){
            cout<<"yes"<<endl;
            continue;
        }
        if((b1==b2+b3 && l2==l3 && l1+l2==b1)||(b2==b1+b3 && l1==l3 && l1+l2==b2)||(b3==b1+b2 && l1==l2 && l2+l3==b3)){
            cout<<"yes"<<endl;
            continue;
        }
        if((l1==l2+l3 && b2==b3 && b1+b2==l1)||(l2==l1+l3 && b1==b3 && b1+b2==l2)||(l3==l1+l2 && b1==b2 && b2+b3==l3)){
            cout<<"yes"<<endl;
            continue;
        }
        cout<<"no"<<endl;
    }
    return 0;
}