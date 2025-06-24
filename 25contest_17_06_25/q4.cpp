#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int length;
        cin>>length;
        vector<int> sequenceA(length);
        vector<int> sequenceB(length);
        for (int i= 0; i< length;i++)
            cin>>sequenceA[i];
        for (int i= 0; i< length;i++)
            cin>>sequenceB[i];
        vector<pair<int, int>> actionList;
        int operationCount = 0;
        for (int pass = 0;pass <length -1; ++pass) {
            bool changed=false;
            for (int j=0;j <length-1;j++) {
                if (sequenceA[j]>sequenceA[j+1]) {
                    swap(sequenceA[j], sequenceA[j+1]);
                    actionList.emplace_back(1,j+1);
                    changed = true;
                    operationCount++;
                }
                if (sequenceB[j]>sequenceB[j+1]) {
                    swap(sequenceB[j], sequenceB[j+1]);
                    actionList.emplace_back(2,j+1);
                    changed = true;
                    operationCount++;
                }
            }
            if (!changed) break;
        }
        for (int k = 0;k<length;k++) {
            if (sequenceA[k]>sequenceB[k]) {
                actionList.emplace_back(3,k+1);
                operationCount++;
            }
        }

        cout<<operationCount<<endl;
        for (const auto& act:actionList)
            cout << act.first << " "<< act.second<<endl;
    }

    return 0;
}
