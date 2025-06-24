#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int oddStart1=1,oddStart2=1;
        int oddDistance1=0,oddDistance2=n;
        int evenStart1=1,evenStart2=n;
        int evenDistance1=n-1,evenDistance2=1;
        cout<<2*n-1<<endl;
        for(int i=1;i<=n;i++){
            if(i%2==1){ //odd
                if(i!=1) {
                    cout<<i<<" "<<oddStart1<<" "<<oddStart1+oddDistance1-1<<endl;
                }
                cout<<i<<" "<<oddStart2<<" "<<oddStart2+oddDistance2-1<<endl;
                oddDistance1++;
                oddDistance2--;
                oddStart2++;
            }
            else if(i%2==0){ //even
                cout<<i<<" "<<evenStart1<<" "<<evenStart1+evenDistance1-1<<endl;
                cout<<i<<" "<<evenStart2<<" "<<evenStart2+evenDistance2-1<<endl;
                evenDistance1--;
                evenDistance2++;
                evenStart2--;
            }
        }
    }
    return 0;
}