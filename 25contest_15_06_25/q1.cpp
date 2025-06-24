#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,a,b,x,y,k;
    cin>>t;
    int m,ans,tempK;
    while(t--){
        ans=0;
        cin>>k>>a>>b>>x>>y;
        tempK=k;
        if(tempK>=a && tempK>=b){
            if(x>=y){
                if(b>=a){
                    m=(int)(tempK-b)/y;
                    ans+=(m+1);
                        tempK-=(m+1)*y;
                    if(tempK<a){
                        cout<<ans<<endl;
                        continue;
                    }
                    m=(int)(tempK-a)/x;
                    ans+=(m+1);
                    cout<<ans<<endl;
                }
                else{ //a>b
                    m=(int)(tempK-b)/y;
                    cout<<m+1<<endl;
                }
            }
            else{
                if(a>=b){
                    m=(int)(tempK-a)/x;
                    ans+=(m+1);
                        tempK-=(m+1)*x;
                        // cout<<"ans:"<<ans<<endl;
                        // cout<<"tempK"<<tempK<<endl;
                    if(tempK<b){
                        cout<<ans<<endl;
                        continue;
                    }
                    m=(int)(tempK-b)/y;
                    ans+=(m+1);
                    // cout<<"ans:"<<ans<<endl;
                    //     cout<<"tempK"<<tempK<<endl;
                    cout<<ans<<endl;
                }
                else{ //b>a
                    m=(int) (tempK-a)/x;
                    cout<<m+1<<endl;
                }
            }
        }
        else if(tempK>=a && tempK<b){
            m=(int)(tempK-a)/x;
            cout<<m+1<<endl;
        }
        else if(tempK>=b && tempK<a){
            m=(int)(tempK-b)/y;
            cout<<m+1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}