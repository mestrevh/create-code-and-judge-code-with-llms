/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int N, D;
    while (cin >> N >> D, N || D) {
        string number;
        cin >> number;
        stack<char> st;
        int to_remove = D;

        for (char digit : number) {
            while (!st.empty() && to_remove > 0 && st.top() < digit) {
                st.pop();
                to_remove--;
            }
            st.push(digit);
        }

        // If we still have digits to remove, remove from the end
        while (to_remove > 0) {
            st.pop();
            to_remove--;
        }

        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        cout << result.substr(0, N - D) << endl;
    }
    return 0;
}
