#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s;
    int n;
    unordered_map<int,int> mpp;
    while(t--){
        mpp=unordered_map<int,int>();
        cin>>n;
        for(int i=1;i<=n;i++){
            mpp[i]=n-i;
        }
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=i+1;j<n;j++){
                if(s[j]=='1'){
                    mpp[j+1]++,mpp[i+1]--;
                }
            }
        }
        vector<int> vec(n);
        for(auto element:mpp){
            vec[element.second]=element.first;
        }
        for(int element:vec){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    return 0;
}