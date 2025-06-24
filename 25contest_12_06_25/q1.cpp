#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(k==0){
            string s(n,'0');
            cout<<s<<endl;
        }
        else if(k==n){
            string s(n,'1');
            cout<<s<<endl;
        }
        else{
            string s(n,'0');
            s[0]='1';
            for(int i=0;i<k-1;i++){
                s[n-2-i]='1';
            }
            cout<<s<<endl;
        }
    }
    return 0;
}