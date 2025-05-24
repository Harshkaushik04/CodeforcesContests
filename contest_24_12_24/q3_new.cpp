#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> transformArr(vector<int> arr){
    int arrSize=arr.size();
    vector<int> finalArr;
    if(arrSize==1){
        return arr;
    }
    bool flag=false;
    for(int i=0;i<arrSize-1;i++){
        flag=false;
        if(arr[i]==1 && arr[i+1]==-1){
            finalArr.emplace_back(INT32_MAX);
            i++;
            flag=true;
        }
        else if(arr[i]==-1 && arr[i+1]==1){
            finalArr.emplace_back(INT32_MIN);
            i++;
            flag=true;
        }
        else{
            finalArr.emplace_back(arr[i]);
        }
    }
    if(!flag){
        finalArr.emplace_back(arr[arrSize-1]);
    }
    return finalArr;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> finalArr=transformArr(arr);
        set<int> distinctSums={0};
        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            if(finalArr[i]==INT32_MAX){
                currentSum=-1;
            }
            else if(finalArr[i]==INT32_MIN){
                currentSum=1;
            }
            for (int j = i; j < n; j++) {
                if(arr[j]==INT32_MAX){
                    distinctSums.insert(currentSum+1);
                }
                else if(arr[j]==INT32_MIN){
                    distinctSums.insert(currentSum-1);
                }
                else{
                    currentSum += arr[j]; 
                    distinctSums.insert(currentSum);
                }
            }
        }
        cout << distinctSums.size() << endl;
        for (int sum : distinctSums) {
            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}
