#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        // cout<<"n:"<<n<<endl;
        vector<int>a(n);
        vector<int>b(n);
        int low=INT32_MIN,lowerBound=INT32_MAX;
        bool flag=false,flag1=false;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            // cout<<"hi"<<endl;
            cin>>b[i];
            if(b[i]-a[i]>0){
                low=b[i]-a[i];
                if(flag){
                    flag1=true;
                }
                flag=true;
            }
            else{
                lowerBound=min(lowerBound,a[i]-b[i]);
            }
        }
        if(low==INT32_MIN){
            cout<<"YES"<<endl;
            continue;
        }
        if(flag1){
            cout<<"NO"<<endl;
            continue;
        }
        if(lowerBound-low>=0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}