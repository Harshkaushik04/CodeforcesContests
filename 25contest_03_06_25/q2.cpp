#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n,m;
    //precompute fibo_list till 10
    vector<int> fibo={1,2};
    for(int i=0;i<8;i++){
        fibo.emplace_back(fibo[i]+fibo[i+1]);
    }
    while(t--){
        cin>>n>>m;
        vector<vector<int>> boxes(m,vector<int>(3,0));
        for(int i=0;i<m;i++){
            cin>>boxes[i][0]>>boxes[i][1]>>boxes[i][2];
        }
        vector<int> cubes;
        for(int i=0;i<n;i++){
            cubes.emplace_back(fibo[i]);
        }
        string ans="";
        for(int i=0;i<m;i++){
            int w=boxes[i][0],l=boxes[i][0],h=boxes[i][2];
            bool flag=true;
            int start=0;
            for(int j=n-1;j>=0;j--){
                if(fibo[j]>boxes[i][0]||fibo[j]>boxes[i][1]){
                    ans+="0";
                    flag=false;
                    break;
                }
                else if(fibo[j]>w||fibo[j]>l){
                    if(h<fibo[j]){
                        ans+="0";
                        flag=false;
                        break;
                    }
                    else{
                        start=0;
                        if(start==0){
                            h-=fibo[j];
                        }
                        w=boxes[i][0],l=boxes[i][1];
                    }
                }
                else{ //fibo[j]<w,l,h
                    w-=fibo[j];
                    l-=fibo[j];
                    if(start==0) h-=fibo[j];
                }
                start++;
            }
            if(flag) ans+="1";
        }
        cout<<ans<<endl;
    }
    return 0;
}

// else if(fibo[j]>h){
//     ans+="0";
//     flag=false;
//     break;
// }