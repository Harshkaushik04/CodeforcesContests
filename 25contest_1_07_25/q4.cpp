#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,k;
    string s;
    cin>>t;
    int ones;
    while(t--){
        cin>>n>>k;
        cin>>s;
        ones=0;
        for(char ch:s){
            if(ch=='1') ones++;
        }
        if(ones<=k) cout<<"alice"<<endl;
        else{
            if(2*k<=n) cout<<"bob"<<endl;
            else cout<<"alice"<<endl;
        }
    }
    return 0;
}