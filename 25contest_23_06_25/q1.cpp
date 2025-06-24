#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,a,x,y;
    cin>>t;
    while(t--){
        cin>>a>>x>>y;
        if(x>y){
            if(a<x && a>y){
                cout<<"no"<<endl;
                continue;
            }
            else cout<<"yes"<<endl;
        }
        else{
            if(a<y && a>x){
                cout<<"no"<<endl;
            }
            else cout<<"yes"<<endl;
        }
    }
    return 0;
}