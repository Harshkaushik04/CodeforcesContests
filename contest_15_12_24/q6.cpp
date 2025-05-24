#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n,m,q,x;
    long long sum=0;
    cin>>n>>m>>q;
    vector<int> a;
    vector<int> b;
    int temp;
    bool flag=false;
    for(int i=0;i<n;i++){
        cin>>temp;
        a.emplace_back(temp);
    }
    for(int i=0;i<m;i++){
        cin>>temp;
        b.emplace_back(temp);
    }
    for(int i=0;i<q;i++){
        cin>>x;
        flag=false;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                sum=0;
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(i!=r && j!=c){
                            sum+=b[i]*a[j];
                        }
                    }
                }
                if(sum==x){
                    cout<<"YES"<<endl;
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}