#include <iostream>
#include <vector>
#include<string>
using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     int n;
//     int leftmostp=INT32_MAX;
//     int rightmosts=INT32_MIN;
//     bool flag=true;
//     bool tempflag=false;
//     vector<int> plocations;
//     vector<int> slocations;
//     while (t--) {
//         plocations=vector<int>();
//         slocations=vector<int>();
//         string s;
//         leftmostp=INT32_MAX;
//         rightmosts=INT32_MIN;
//         flag=true;
//         cin>>n;
//         cin>>s;
//         for(int p=0;p<n;p++){
//             if(s[p]=='p'){
//                 leftmostp=p;
//                 break;
//             }
//         }
//         for(int m=0;m<n;m++){
//             if(s[m]=='s'){
//                 rightmosts=m;
//                 break;
//             }
//         }
//         if(leftmostp==INT32_MAX || rightmosts==INT32_MIN){
//             cout<<"YES"<<endl;
//             continue;
//         }
//         if(leftmostp<rightmosts){
//             cout<<"NO"<<endl;
//             continue;
//         }
//         while(true){
//             if(leftmostp-rightmosts+1<min(n-rightmosts,leftmostp+1)){
//                 flag=false;
//                 break;
//             }
//             tempflag=false;
//             for(int i=leftmostp+1;i<n;i++){
//                 if(s[i]=='p'){
//                     leftmostp=i;
//                     tempflag=true;
//                     break;
//                 }
//             }
//             if(!tempflag){
//                 break;
//             }
//             tempflag=false;
//             for(int i=rightmosts-1;i>=0;i--){
//                 if(s[i]=='s'){
//                     rightmosts=i;
//                     tempflag=true;
//                     break;
//                 }
//             }
//             if(!tempflag){
//                 break;
//             }
//             if(leftmostp>=n || rightmosts<0){
//                 break;
//             }
//         }
//         if(flag){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<<"NO"<<endl;
//         }
//     }
//     return 0;
// }

int main() {
    int t;
    cin >> t;
    int n;
    int leftmostp=INT32_MAX;
    int rightmosts=INT32_MIN;
    bool flag=true;
    bool tempflag=false;
    vector<int> plocations;
    vector<int> slocations;
    while (t--) {
        plocations=vector<int>();
        slocations=vector<int>();
        string s;
        leftmostp=INT32_MAX;
        rightmosts=INT32_MIN;
        flag=true;
        cin>>n;
        cin>>s;
        for(int p=0;p<n;p++){
            if(s[p]=='p'){
                leftmostp=p;
                break;
            }
        }
        for(int m=0;m<n;m++){
            if(s[m]=='s'){
                rightmosts=m;
                break;
            }
        }
        if(leftmostp==INT32_MAX || rightmosts==INT32_MIN){
            cout<<"YES"<<endl;
            continue;
        }
        if(leftmostp<rightmosts){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='p'){
                plocations.emplace_back(i);
            }        
        }
        for(int i=0;i<n;i++){
            if(s[i]=='s'){
                slocations.emplace_back(i);
            }        
        }
        int plocationsLength=plocations.size();
        int slocationsLength=slocations.size();
        for(int i=0;i<plocationsLength;i++){
            for(int j=0;j<slocationsLength;j++){
                if(plocations[i]-slocations[j]+1<min(n-slocations[j],plocations[i]+1)){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}