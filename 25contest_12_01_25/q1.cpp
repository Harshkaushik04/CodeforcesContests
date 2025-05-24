#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int t,n,a,b;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        if((abs(a-b)-1)%2==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}