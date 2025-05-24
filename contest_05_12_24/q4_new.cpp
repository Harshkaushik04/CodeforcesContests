#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    stack<char> st;
    
    // Process each character in the string
    for (char c : s) {
        while (!st.empty() && st.top() < c && st.top() != '0') {
            st.pop();  // Pop elements to maximize the lexicographical order
        }
        st.push(c);  // Push the current character
    }
    
    // Output the result by constructing the final string from the stack
    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    
    // Process all test cases
    while (t--) {
        solve();
    }
    
    return 0;
}
