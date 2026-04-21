/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    vector<char> stack_vec;
    stack_vec.reserve(100005);

    while (t--) {
        string s;
        cin >> s;
        
        stack_vec.clear();
        bool possible = true;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack_vec.push_back(c);
            } else {
                if (stack_vec.empty()) {
                    possible = false;
                    break;
                }
                char top = stack_vec.back();
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    stack_vec.pop_back();
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (possible && stack_vec.empty()) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}