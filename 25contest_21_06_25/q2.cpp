#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,s;
    int d1,d2,x1,x2;
    int ans;
    cin>>t;
    while(t--){
        cin>>n>>s;
        ans=0;
        for(int i=0;i<n;i++){
            cin>>d1>>d2>>x1>>x2;
            if(x1+x2==s && ((d1==1&& d2==-1)||(d1==-1 && d2==1))) ans++;
            else if(x1==x2 &&((d1==1 && d2==1)||(d1==-1 && d2==-1))) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}