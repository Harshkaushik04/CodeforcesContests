#include <bits/stdc++.h>
using namespace std;
void division(){
    
    int n,k;
    cin>>n>>k;
    int a[n],c=0,h,m;

    for(int i=0;i<n;i++){
     cin>>a[i];}
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n; j++){
           if(j==i) continue;
           h= abs(a[i]-a[j]);
           m=h%k;
            if(m==0){
                break;
            }
        }
        if(m!=0){
            cout<<"YES"<<endl;
            cout<<i+1<<endl;
            c=1;
            break;
        }
        
    }
    if(c==0){
        cout<<"NO"<<endl;
    }
    
   
}
int main(){
    int t;
    cin>>t;
    while(t--){
       
        division();
        
    }
}