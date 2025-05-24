#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    int n;
    int m;
    int k;
    vector<string> strings;
    string temp;
    int ans=0;
    cin>>t;
    for(int i=0;i<t;i++){
        strings=vector<string>();
        ans=0;
        cin>>n>>m;
        for(int j=0;j<n;j++){
            cin>>temp;
            strings.emplace_back(temp);
        }
        k=0;
        while(m>0 && k<n){
            if(m>=strings[k].size()){
                m-=strings[k].size();
                ans+=1;
            }
            else{
                break;
            }
            k++;
        }
        cout<<ans<<endl;
    }
    return 0;
}