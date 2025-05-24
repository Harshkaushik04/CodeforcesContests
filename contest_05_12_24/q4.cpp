#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    string n;
    vector<int> digits;
    cin>>t;
    string ans="";
    int temp;
    int temp_max;
    int temp_max_index;
    vector<int>::iterator temp_pointer;
    for(int i=0;i<t;i++){
        cin>>n;
        int* values=new int[n];
        digits=vector<int>();
        ans="";
        for(char ch:n){
            digits.emplace_back(ch-'0');
        }
        for(int j=0;j<digits.size();j++){
            values[j]
        }
        for (int digit : digits) {
            ans += to_string(digit);
        }
        cout<<ans<<endl;
    }
    return 0;
}