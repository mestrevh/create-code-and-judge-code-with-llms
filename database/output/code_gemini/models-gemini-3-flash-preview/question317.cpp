/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1000005;
int nxt[MAXN];
char val[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (getline(cin, s)) {
        if (!s.empty() && s.back() == '\r') {
            s.pop_back();
        }
        
        int n = (int)s.length();
        if (n == 0) {
            cout << "\n";
            continue;
        }

        // dummy head node is 0
        nxt[0] = 0;
        int cur = 0;
        int last = 0;

        for (int i = 1; i <= n; ++i) {
            char c = s[i - 1];
            if (c == '[') {
                cur = 0;
            } else if (c == ']') {
                cur = last;
            } else {
                val[i] = c;
                nxt[i] = nxt[cur];
                if (cur == last) {
                    last = i;
                }
                nxt[cur] = i;
                cur = i;
            }
        }

        for (int i = nxt[0]; i != 0; i = nxt[i]) {
            cout << val[i];
        }
        cout << "\n";
    }

    return 0;
}