#include <iostream>
#include <vector>
using namespace std;

int arrSum(vector<int> arr,int left,int right){
    int sum=0;
    for(int i=left;i<=right;i++){
        sum+=arr[i];
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    int n;
    vector<int> arr;
    int temp;
    int tempIndex;
    vector<int> sumArr;
    bool flag=false;
    int sizeArr=0;
    while(t--){
        cin>>n;
        arr=vector<int>();
        sumArr={0};
        for(int i=0;i<n;i++){
            cin>>temp;
            arr.emplace_back(temp);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                flag=false;
                temp=arrSum(arr,j,i);
                sizeArr=sumArr.size();
                for(int k=0;k<sizeArr;k++){
                    if(temp<sumArr[k]){
                        tempIndex=k;
                        break;
                    }
                    else if(temp==sumArr[k]){
                        flag=true;
                        break;
                    }
                    if(k==sizeArr-1){
                        tempIndex=sizeArr;
                    }
                }
                if(!flag){
                sumArr.insert(sumArr.begin()+tempIndex,temp);
                }
                // cout<<"hi"<<endl;
            }
        }
        cout<<sumArr.size()<<endl;
        sizeArr=sumArr.size();
        for(int i=0;i<sizeArr;i++){
            cout<<sumArr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}