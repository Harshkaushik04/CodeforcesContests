#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n,k;
    int low=1;
    long lowIndex=0;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        low=1,lowIndex=k-1;
        vector<int> arr(n,0);
        if(k==1){
            for(int j=1;j<=n;j++){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        else{
            while(lowIndex<n){
                arr[lowIndex]=low;
                low++;
                lowIndex+=k;
            }
            for(int j=0;j<n;j++){
                if(arr[j]==0){
                    arr[j]=low;
                    low++;
                }
            }
            for(int j=0;j<n;j++){
                cout<<arr[j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}