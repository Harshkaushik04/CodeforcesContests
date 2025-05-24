#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    int t;
    cin>>t;
    int n;
    bool flag;
    int temp;
    while(t--){
        cin>>n;
        flag=true;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        for(int i=0;i<n-1;i++){
            if(vec[i]<=vec[i+1]){
                temp=vec[i+1]-vec[i];
                vec[i]=0;
                vec[i+1]=temp;
            }
            else{
                cout<<"NO"<<endl;
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}