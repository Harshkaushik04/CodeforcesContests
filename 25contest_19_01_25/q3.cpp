#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    int n,k;
    int left,right;
    int score;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> vec(n);
        score=0;
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        left=0,right=vec.size()-1;
        while(left<right){
            if(vec[left]+vec[right]==k){
                score++;
                left++,right--;
            }
            else if(vec[left]+vec[right]>k){
                right--;
            }
            else{
                left++;
            }
        }
        cout<<score<<endl;
    }
    return 0;
}