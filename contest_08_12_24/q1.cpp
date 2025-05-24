#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n,k;
    int temp;
    vector<int> numbers;
    bool flag=true;
    bool flag2=false;
    int ans;
    for(int i=0;i<t;i++){
        numbers=vector<int>();
        cin>>n>>k;
        for(int j=0;j<n;j++){
            cin>>temp;
            numbers.emplace_back(temp);
        }
        flag2=false;
        for(int a=0;a<n;a++){
            flag=true;
            for(int b=0;b<n;b++){
                if(a!=b){
                    if(abs(numbers[a]-numbers[b])%k==0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                flag2=true;
                ans=a+1;
                break;
            }
        }
        if(flag2){
            cout<<"YES"<<endl<<ans<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}