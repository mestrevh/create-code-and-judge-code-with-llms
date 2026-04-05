/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, long long> value;
    vector<string> order;

    string token;
    while (true) {
        if (!(cin >> token)) return 0;
        if (token == "EOF") break;
        if (token != "=") continue;

        string var;
        cin >> var;

        stack<long long> st;
        while (cin >> token) {
            if (token == ";") break;

            if (token == "+" || token == "-" || token == "*") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else st.push(a * b);
            } else {
                bool isNum = !token.empty() && (isdigit((unsigned char)token[0]) || token[0] == '-' || token[0] == '+');
                if (isNum) {
                    char* endp = nullptr;
                    long long x = strtoll(token.c_str(), &endp, 10);
                    st.push(x);
                } else {
                    st.push(value[token]);
                }
            }
        }

        long long res = st.empty() ? 0 : st.top();
        if (!value.count(var)) order.push_back(var);
        value[var] = res;
    }

    for (const auto& name : order) {
        cout << name << " = " << value[name] << "\n";
    }
    return 0;
}