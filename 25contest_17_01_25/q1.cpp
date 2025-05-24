#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n,m;
    int temp1,temp2;
    int sum=0;
    while(t--){
        cin>>n>>m;
        sum=4*m;
        for(int i=0;i<n;i++){
            cin>>temp1>>temp2;
            if(i!=0){
                sum+=(2*(temp1+temp2));
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}