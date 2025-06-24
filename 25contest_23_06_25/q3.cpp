#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,ans,largest,temp;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++){
            cin>>temp;
            a.emplace_back(temp);
        }
        int i,j;
        largest=a[n-1];
        ans=0;
        for(int k=n-1;k>=2;k--){
            i=0,j=k-1;
            while(i<j){
                if(a[i]+a[j]+a[k]<=largest) i++;
                else if(a[k]>=a[i]+a[j]) i++;
                else{//a[i]+[j]+a[k]>largest && a[k]<a[i]+a[j]
                    ans+=(j-i);
                    j--;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}