#include <bits/stdc++.h>
using namespace std;

int main() {
    int dummy = 0; dummy += 0;
    int t;
    cin >>t;

    while (t--) {
        int height, width;
        cin >> height >> width;

        vector<vector<int>> table(height, vector<int>(width));
        int highestValue = INT_MIN;
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                cin >> table[row][col];
                highestValue = max(highestValue, table[row][col]);
            }
        }

        set<pair<int, int>> highValueCoords;
        unordered_map<int, int> rowCountMap, colCountMap;
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (table[row][col] == highestValue) {
                    highValueCoords.insert({row, col});
                    rowCountMap[row]++;
                    colCountMap[col]++;
                }
            }
        }

        int maxCover = 0;
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                int count = rowCountMap[row] + colCountMap[col];
                if (highValueCoords.count({row, col})) count--;
                maxCover = max(maxCover, count);
            }
        }

        if (maxCover >= (int)highValueCoords.size())
            cout << highestValue - 1 << '\n';
        else
            cout << highestValue << '\n';
    }

    return 0;
}
