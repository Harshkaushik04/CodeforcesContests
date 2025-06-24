#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    long long k;
    cin>>t;
    int temp;
    while(t--){
        cin>>n>>k;
        unordered_map<int,int> mpp;
        for(int i=0;i<63;i++){
            mpp[i]=0;
        }
        int beauty=0;
        for(int i=0;i<n;i++){
            cin>>temp;
            for(int j=0;j<64;j++){
                if(((temp>>j)&0b1)==0){
                    mpp[j]++;
                }
                else beauty++;
            }
        }
        for(int i=0;i<64;i++){
            if(k<=0) break;
            if(mpp[i]*(long long)(1<<i)<=k){
                k-=mpp[i]*(long long)(1<<i);
                beauty+=mpp[i];
            }
            else{
                for(int j=0;j<mpp[i];j++){
                    if(k<=0) break;
                    if(j*(long long)(1<<i)<k){
                        continue;
                    }
                    else if(j*(long long)(1<<i)==k){
                        k=0;
                        beauty+=j;
                    }
                    else{
                        beauty+=(j-1);
                        k-=j*(long long)(1<<i);
                        break;
                    }
                }
            }
        }
        cout<<beauty<<endl;
    }
    return 0;
}