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

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string S;
        if (!(cin >> S)) break;
        int N;
        if (!(cin >> N)) break;

        vector<string> shortcuts(26, "");
        vector<bool> has(26, false);

        for (int i = 0; i < N; ++i) {
            char C;
            string A;
            if (cin >> C >> A) {
                if (C >= 'A' && C <= 'Z') {
                    shortcuts[C - 'A'] = A;
                    has[C - 'A'] = true;
                }
            }
        }

        string result;
        result.reserve(S.length());

        int len = (int)S.length();
        for (int i = 0; i < len; ++i) {
            if (S[i] == '*' && i + 1 < len) {
                char nextC = S[i + 1];
                if (nextC >= 'A' && nextC <= 'Z' && has[nextC - 'A']) {
                    result += shortcuts[nextC - 'A'];
                    i++;
                } else {
                    result += '*';
                }
            } else {
                result += S[i];
            }
        }
        cout << result << '\n';
    }
    return 0;
}