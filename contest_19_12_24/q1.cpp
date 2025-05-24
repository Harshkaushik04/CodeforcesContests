#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    int x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x;
        if(x%33==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}