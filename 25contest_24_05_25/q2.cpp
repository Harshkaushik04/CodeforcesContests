#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int len=s.size();
        int index=0;
        int offset=0;
        int num_sequences=0;
        for(char ch:s){
            if(ch=='('){
                offset++;
            }
            else{
                offset--;
            }
            if(offset==0 && index!=0){
                num_sequences++;
            }
            if(num_sequences>1){
                cout<<"YES"<<endl;
                break;
            }
            index++;
        }
        if(num_sequences<=1){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}