#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n;
    long long long_ans=1;
    int ans;
    for(int i=0;i<t;i++){
        cin>>n;
        long_ans=1;
        ans=0;
        while(true){
            if(n<=long_ans){
                break;
            }
            long_ans=long_ans*2+2;
            ans++;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}