#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;


string reverseAndConvert(const string& input) {
    string result;
    for (int i = input.length() - 1; i >= 0; --i) {
        char ch = input[i];
        if (ch == 'p') {
            result += 'q';
        } else if (ch == 'q') {
            result += 'p';
        } else if (ch == 'w') {
            result += 'w';
        } 
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>s;
        cout<<reverseAndConvert(s)<<endl;
    }
}