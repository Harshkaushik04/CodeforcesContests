#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main() {
    int t;
    string n;
    int digitSum=0;
    int num2=0;
    int num3=0;
    bool flag=false;
    cin>>t;
    for(int k=0;k<t;k++){
        cin>>n;
        digitSum=0;
        num2=0;
        num3=0;
        flag=false;
        for (char ch : n) {
        digitSum += ch - '0';
        if(ch-'0'==2){
            num2+=1;
        } 
        else if(ch-'0'==3){
            num3+=1;
        }
        }
        for(int i=0;i<=num2;i++){
            for(int j=0;j<=num3;j++){
                if((digitSum+i*2+j*6)%9==0){
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