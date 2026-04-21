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

    string s;
    vector<char> st;
    while (cin >> s && s != "Z") {
        st.clear();
        st.reserve(s.size());
        int pairings = 0;
        for (char c : s) {
            if (!st.empty()) {
                char top = st.back();
                if ((top == 'B' && c == 'S') || (top == 'S' && c == 'B') ||
                    (top == 'C' && c == 'F') || (top == 'F' && c == 'C')) {
                    st.pop_back();
                    pairings++;
                } else {
                    st.push_back(c);
                }
            } else {
                st.push_back(c);
            }
        }
        cout << pairings << "\n";
    }

    return 0;
}