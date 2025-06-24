#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,w,h,a,b;
    int x1,x2,y1,y2;
    cin>>t;
    while(t--){
        cin>>w>>h>>a>>b;
        cin>>x1>>y1>>x2>>y2;
        if(abs(y1-y2)<h+b){
            cout<<"no"<<endl;
            continue;
        }
        if(abs(x1-x2)<w+a){
            cout<<"no"<<endl;
            continue;
        }
        cout<<"yes"<<endl;
    }
    return 0;
}