#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != mapping[c]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    string input;
    cin >> input;

    Solution solution;

    if (solution.isValid(input)) {
        cout << "valid";
    } else {
        cout << "invalid";
    }
    return 0;
}
