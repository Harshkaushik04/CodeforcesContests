#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) { 
        int n;
        cin >> n;
        vector<int> numbers(n); 
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (numbers[i] != 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << 0 << endl;
            continue;
        }

        flag = true;
        if(numbers[0]!=0 && numbers[n-1]!=0){
            for (int i = 1; i < n - 1; i++) {
                if (numbers[i] == 0) {
                    cout << 2 << endl;
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << 1 << endl;
            }
        }
        else if(numbers[0]==0 && numbers[n-1]!=0){
            int k=0;
            while(numbers[k]==0 && k<n){
                k++;
            }
            // k==n case not possible
            for (int i = k; i < n - 1; i++) {
                if (numbers[i] == 0) {
                    cout << 2 << endl;
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << 1 << endl;
            }
        }
        else if(numbers[0]!=0 && numbers[n-1]==0){
            int k=n-1;
            while(numbers[k]==0 && k>=0){
                k--;
            }
            // k==0 case not possible
            for (int i = k; i >= 0; i--) {
                if (numbers[i] == 0) {
                    cout << 2 << endl;
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << 1 << endl;
            }
        }
        else{
            int k=0;
            while(numbers[k]==0 && k<n){
                k++;
            }
            while(numbers[k]!=0){
                k++;
            }
            while(numbers[k]==0 && k<n){
                k++;
            }
            if(k>=n-1){
                cout<<1<<endl;
            }
            else{
                // cout<<"new"<<endl;
                cout<<2<<endl;
            }
        }
    }
    return 0;
}
