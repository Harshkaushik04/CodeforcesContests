#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    int temp,last,streak;
    while(t--){
        cin>>n;
        last=-1,streak=1;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(last==temp) streak++;
            else{
                if(last!=-1){
                    if(mpp.find(last)!=mpp.end()){
                        mpp[last]=streak;
                    }
                    else{
                        mpp[last]=max(streak,mpp[last]);
                    }
                    streak=1;
                }
            }
            last=temp;
        }
        mpp[temp]=streak;
        long mini=INT64_MAX;
        for(pair<int,int> p:mpp){
            mini=min(mini,(long)(n-p.second)*(long)p.first);
        }
        cout<<mini<<endl;
    }
    return 0;
}