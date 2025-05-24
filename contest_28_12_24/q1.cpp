#include <iostream>
#include<vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    vector<int> arr;
    bool flag=false;
    while(t--){
        flag=false;
        cin>>n;
        arr=vector<int>(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<n-1;i++){
            if((arr[i]<=arr[i-1] && 2*arr[i]>arr[i-1])||(arr[i]<=arr[i+1] && 2*arr[i]>arr[i+1])){
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            continue;
        }
        if(arr[0]<=arr[1] && 2*arr[0]>arr[1]){
            cout<<"YES"<<endl;
            continue;
        }
        if(arr[n-1]<=arr[n-2] && 2*arr[n-1]>arr[n-2]){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}