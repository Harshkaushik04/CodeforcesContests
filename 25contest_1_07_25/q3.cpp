#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,temp;
    vector<int> arr,mini,maxi;
    int tempMini,tempMaxi;
    cin>>t;
    while(t--){
        cin>>n;
        arr.resize(n,0);
        mini.resize(n,0);
        maxi.resize(n,0);
        tempMini=INT32_MAX;
        tempMaxi=INT32_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]<tempMini){
                tempMini=arr[i];
                mini[i]=tempMini;
            }
            else mini[i]=tempMini;
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]>tempMaxi){
                tempMaxi=arr[i];
                maxi[i]=tempMaxi;
            }
            else maxi[i]=tempMaxi;
        }
        string ans;
        for(int i=0;i<n;i++){
            if(i==0||i==n-1||arr[i]==maxi[0]||arr[i]==mini[n-1]||
                (arr[i]==maxi[i] && arr[i]>=mini[i])||(arr[i]==mini[i] && arr[i]<=maxi[i])){
                ans+='1';
                continue;
            }
            ans+='0';
        }
        cout<<ans<<endl;
    }
    return 0;
}