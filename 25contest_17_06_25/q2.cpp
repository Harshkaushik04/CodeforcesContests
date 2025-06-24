#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    string s;
    vector<char> vec;
    int first,last;
    bool flag;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        first=s[0];
        last=s[n-1];
        flag=false;
        unordered_map<char,int> mpp;
        mpp[first]=1;
        if(first==last) mpp[last]++;
        else mpp[last]=1;
        for(int i=1;i<n-1;i++){
            if((s[i]==first)||(s[i]==last)){
                cout<<"yes"<<endl;
                flag=true;
                break;
            }
            else if(mpp.find(s[i])!=mpp.end()){
                cout<<"yes"<<endl;
                flag=true;
                break;
            }
            else{
                mpp[s[i]]=1;
            }
        }
        if(!flag) cout<<"no"<<endl;
    }
    return 0;
}