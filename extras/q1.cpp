#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long n,k;
    int test_cases;
    cin>>test_cases;
    for(int i=0;i<test_cases;i++){
        cin>>n>>k;
        int* chests=new int[n];
        for(int j=0;j<n;j++){
            cin>>chests[j];
        }
        sort(chests,chests+n,greater<int>());
        int sum=k;
        int current=chests[0];
        int current_index=0;
        while(sum>=current && current_index<n){
            sum-=current;
            current_index+=1;
            current=chests[current_index];
        }
        cout<<sum<<endl;
    }
    return 0;
}