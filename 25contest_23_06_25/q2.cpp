#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,temp,prev;
    bool cond1,cond2,increasing;
    cin>>t;
    while(t--){
        cin>>n;
        cond1=false,cond2=false;
        prev=INT32_MIN;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(i==0){
                prev=temp;
                continue;
            }
            if(i==1){
                if(abs(temp-prev)<=1){
                    cond1=true;
                    continue;
                }
                else if(temp-prev>0){
                    increasing=true;
                    prev=temp;
                    continue;
                }
                else{
                    increasing=false;
                    prev=temp;
                    continue;
                }
            }
            if(i>1){
                if(abs(temp-prev)<=1){
                    cond1=true;
                    continue;
                }
                else if(increasing){
                    if(temp>prev){
                        prev=temp;
                        continue;
                    }
                    else{
                        cond2=true;
                        prev=temp;
                    }
                }
                else if(!increasing){
                    if(temp<prev){
                        prev=temp;
                        continue;
                    }
                    else{
                        cond2=true;
                        prev=temp;
                    }
                }
            }
        }
        if(cond1){
            cout<<0<<endl;
            continue;
        }
        else if(cond2){
            cout<<1<<endl;
            continue;
        }
        else{
            cout<<-1<<endl;
            continue;
        }
    }
    return 0;
}
