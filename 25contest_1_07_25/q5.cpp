#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    vector<int> arr,vec,ans;
    cin>>t;
    while(t--){
        cin>>n;
        arr.resize(n,0);
        vec.resize(n,0);
        ans.resize(n,-1);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            vec[arr[i]]++;
        } 
        int templ=n;
        for(int i=0;i<n;i++){
            if(templ==0) break;
            for(int j=0;j<templ;j++){
                if(vec[j]<=i){
                    templ=j;
                    ans[templ]=i;
                    break;
                }
            }
        }
        int current=-1;
        for(int i=0;i<n;i++){
            if(ans[i]!=-1){
                current=i;
                continue;
            }
            ans[i]=current;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}