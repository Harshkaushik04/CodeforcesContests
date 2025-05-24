#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    int d;
    long n;
    while(t--){
        cin>>n>>d;
        cout<<1<<" ";
        if(n>=3){
            cout<<3<<" ";
        }
        else{
            if(d==3 || d==6 || d==9){
                cout<<3<<" ";
            }
        }
        if(d==5){
            cout<<5<<" ";
        }
        if(n>=3){
            cout<<7<<" ";
        }
        else{
            if(d==7){
                cout<<7<<" ";
            }
        }
        if(n>=6){
            cout<<9;
        }
        else{
            if(n>=3){
                if(d==3||d==6||d==9){
                    cout<<9;
                }
            }
            else{
                if(d==9){
                    cout<<9;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}