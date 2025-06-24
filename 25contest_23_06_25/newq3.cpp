#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using int64=long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        int length;
        cin>>length;
        vector<int>values(length+1);
        for(int idx=1;idx<=length;++idx){
            cin>>values[idx];
        }
        int64 totalWays=0;
        for(int third=3;third<=length;third++){
            int limit=max(2*values[third],(third<length?values[length]:values[length-1]));
            int threshold=limit-values[third];
            int left=1,right=third-1;
            while(left<right){
                if(values[left]+values[right]>threshold){
                    totalWays+=(right-left);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        cout<<totalWays<<endl;
    }
    return 0;
}
