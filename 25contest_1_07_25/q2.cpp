#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,j,k,num;
    vector<int> arr;
    bool flag=false;
    cin>>t;
    while(t--){
        cin>>n>>j>>k;
        arr.resize(n,0);
        flag=false;
        for(int i=0;i<n;i++) cin>>arr[i];
        if(k>1){
            cout<<"YES"<<endl;
            continue;
        }
        num=arr[j-1];
        for(int i=0;i<n;i++){
            if(arr[i]>num){
                cout<<"NO"<<endl;
                flag=true;
                break;
            }
        } 
        if(!flag) cout<<"YES"<<endl;
    }
    return 0;
}