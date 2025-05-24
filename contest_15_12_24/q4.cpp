// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<unordered_map>
// #include<limits>
// using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     int n;
//     vector<int> a;
//     int temp;
//     int value=1;
//     for(int i=0;i<t;i++){
//         cin>>n;
//         value=1;
//         for(int j=0;j<n;j++){
//             cin>>temp;
//             a.emplace_back(temp);
//         }
//         for(int j=0;j<n;j++){

//         }
//     }
//     return 0;
// }
#include <iostream>
#include <set>
#include <vector>
#include <sstream>  // For splitting input string
#include <algorithm> // For std::find

using namespace std;

int main() {
    int t;  // Number of test cases
    cin >> t;

    while (t--) {
        vector<int> already_done;  // To keep track of already processed elements
        int n;
        cin >> n;  // Number of elements
        int value = 1;

        // Read the space-separated integers into a vector
        cin.ignore();  // To ignore the newline after the integer input
        string input_string;
        getline(cin, input_string);
        stringstream ss(input_string);

        vector<int> a;
        int temp;
        while (ss >> temp) {
            a.push_back(temp);  // Add each number to the vector
        }

        set<int> a_set(a.begin(), a.end());  // Create a set from the vector to store unique values

        // Process each element in the vector a
        for (int j = 0; j < n; ++j) {
            if (find(already_done.begin(), already_done.end(), a[j]) != already_done.end()) {
                // If the element is already in already_done, we find the smallest missing number
                set<int> combined_set(a_set.begin(), a_set.end());
                combined_set.insert(already_done.begin(), already_done.end());

                // Find the smallest missing value
                for (int k = value; k <= n; ++k) {
                    if (combined_set.find(k) == combined_set.end()) {
                        value = k;
                        already_done.push_back(value);
                        break;
                    }
                }
                cout << value << " ";
            } else {
                already_done.push_back(a[j]);
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
