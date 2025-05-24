#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    int a=0,b=0,c=0,m=0;
    for(int i=0;i<t;i++){
        cin>>m>>a>>b>>c;
        if(m>=a && m>=b){
            if(2*m-a-b>=c){
                cout<<a+b+c<<endl;
            }
            else{
                cout<<2*m<<endl;
            }
        }
        else if(m>=a && m<b){
            if(m-a>=c){
                cout<<a+c+m<<endl;
            }
            else{
                cout<<2*m<<endl;
            }
        }
        else if(m>=b && m<a){
            if(m-b>=c){
                cout<<b+c+m<<endl;
            }
            else{
                cout<<2*m<<endl;
            }
        }
        else{
            cout<<2*m<<endl;
        }
    }
    return 0;
}