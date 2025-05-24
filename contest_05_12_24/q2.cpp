#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    long long oddSum=0;
    long long evenSum=0;
    int oddIndex=1;
    int evenIndex=0;
    int oddNum=0;
    int evenNum=0;
    int n;
    vector<int> numbers;
    cin>>t;
    int temp;
    for(int i=0;i<t;i++){
        oddSum=0;
        evenSum=0;
        oddIndex=1;
        evenIndex=0;
        oddNum=0;
        evenNum=0;
        numbers=vector<int>();
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>temp;
            numbers.emplace_back(temp);
        }
        while(oddIndex<n){
            oddSum+=numbers[oddIndex];
            oddIndex+=2;
            oddNum++;
        }
        while(evenIndex<n){
            evenSum+=numbers[evenIndex];
            evenIndex+=2;
            evenNum++;
        }
        if(oddSum%oddNum==0 && evenSum%evenNum==0 && oddSum/oddNum==evenSum/evenNum){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}