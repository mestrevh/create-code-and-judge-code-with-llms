/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> actions;
    string s;
    while (cin >> s) actions.push_back(s);

    vector<int> backStack, forwardStack;
    int idx = 0;
    for (const auto& a : actions) {
        if (a == "ENTER") {
            backStack.push_back(idx++);
            forwardStack.clear();
        } else if (a == "BACK") {
            if (!backStack.empty()) {
                forwardStack.push_back(backStack.back());
                backStack.pop_back();
            }
        } else if (a == "FORWARD") {
            if (!forwardStack.empty()) {
                backStack.push_back(forwardStack.back());
                forwardStack.pop_back();
            }
        }
    }

    cout << "BACK: " << backStack.size() << "\n";
    cout << "FORWARD: " << forwardStack.size() << "\n";
    return 0;
}