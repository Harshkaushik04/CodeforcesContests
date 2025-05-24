#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void sortByFirstElement(vector<vector<int>>& vec) {
    sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];  // Compare first elements of the inner vectors
    });
}

int main(){
    int n,m;
    int t;
    cin>>t;
    int temp;
    bool flag;
    while(t--){
        cin>>n>>m;
        vector<int> count;
        vector<vector<int>> vec(n);
        flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>temp;
                vec[i].emplace_back(temp);
            }
            sort(vec[i].begin(),vec[i].end());
        } 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vec[j][0]==i){
                    count.emplace_back(j);
                    break;
                }
            }
        }
        set<int> countSet(count.begin(),count.end());
        if(countSet.size()!=count.size()){
            cout<<-1<<endl;
            continue;
        }
        sortByFirstElement(vec);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j]!=j*n+i){
                    cout<<-1<<endl;
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            for(int i=0;i<n;i++){
                cout<<count[i]+1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}