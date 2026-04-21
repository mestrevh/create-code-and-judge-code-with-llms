/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < N; ++i) {
            string s;
            if (!getline(cin, s)) break;

            for (char &c : s) {
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    c += 3;
                }
            }

            reverse(s.begin(), s.end());

            int len = s.length();
            int start = len / 2;
            for (int j = start; j < len; ++j) {
                s[j] -= 1;
            }

            cout << s << "\n";
        }
    }

    return 0;
}