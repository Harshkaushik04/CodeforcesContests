#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,s;
    cin>>t;
    int left,right,temp;
    while(t--){
        cin>>n>>s;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(i==0) left=temp;
            if(i==n-1) right=temp;
        }
        if((s==left)||(s==right)) cout<<right-left<<endl;
        else if(s>=left && s<=right){
            if(right-s>=s-left) cout<<2*(s-left)+right-s<<endl;
            else cout<<2*(right-s)+s-left<<endl;
        }
        else if(s<left) cout<<right-s<<endl;
        else cout<<s-left<<endl; //s>right
    }
    return 0;
}