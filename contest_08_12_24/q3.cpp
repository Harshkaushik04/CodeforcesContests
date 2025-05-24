#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    int n,k;
    long long sum;
    long long total_sum;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        total_sum=pow(2,n-1);
        sum=1;
        if(k>pow(2,n-1)){
            cout<<-1<<endl;
        }
        while(sum>0){

        }
    }
    return 0;
}

int do_q(int sum,int n){
    int inner_sum=1;
    if(sum==1){
        return n;
    }
    for(int alpha=1;alpha<n;alpha++){
        inner_sum+=pow(2,alpha-1);
        if(inner_sum>=sum){
            return n-alpha;
        }
    }
}