#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string xorBinaryStrings(const string& str1, const string& str2) {
    // Make strings the same length by padding with leading zeros
    int len1 = str1.size(), len2 = str2.size();
    int maxLength = max(len1, len2);

    string s1 = string(maxLength - len1, '0') + str1;
    string s2 = string(maxLength - len2, '0') + str2;

    // Perform XOR bit by bit
    string result;
    for (int i = 0; i < maxLength; ++i) {
        result += (s1[i] == s2[i]) ? '0' : '1'; // XOR logic
    }

    return result;
}


int main(){
    int t;
    cin>>t;
    string s;
    int s_size;
    int index=0;
    int maxIndex=0;
    string temp;
    string s1;
    string s2;
    for(int i=0;i<t;i++){
        index=0;
        maxIndex=0;
        cin>>s;
        s_size=s.size();
        while(s[index]=='1' && index<s_size){
            index++;
        }
        if(index==s_size){
            cout<<1<<" "<<s_size<<" "<<s_size<<" "<<s_size<<endl;
            continue;
        }
        string maxString=s.substr(0,s_size-index);
        for(int j=0;j<index;j++){
            temp=s.substr(j,s_size-index);
            s1=xorBinaryStrings(temp,s);
            s2=xorBinaryStrings(maxString,s);
            for(int k=0;k<s_size;k++){
                if((int)s1[k]>(int)s2[k]){
                    maxString=temp;
                    maxIndex=j;
                    break;
                }
                else if((int)s1[k]<(int)s2[k]){
                    break;
                }
                else{
                    continue;
                }
            }
        }
        cout<<1<<" "<<s_size<<" "<<maxIndex+1<<" "<<maxIndex+s_size-index<<endl;
    }
    return 0;
}