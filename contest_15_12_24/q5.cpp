#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    int Ntemp;
    long k,l1,r1,l2,r2;
    vector<long> possible;
    int ans;
    for(int i=0;i<t;i++){
        Ntemp=0;
        ans=0;
        cin>>k>>l1>>r1>>l2>>r2;
        while(pow(k,Ntemp)<=r2/l1){
            possible.emplace_back(pow(k,Ntemp));
            Ntemp++;
        }
        for(long element:possible){
            for(long j=l1;j<=r1;j++){
                if(j*element<=r2){
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}