/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> substrings;
    substrings.reserve(n);

    for (int i = 0; i < n; ++i) {
        string s;
        if (!(cin >> s)) break;

        int len = static_cast<int>(s.length());
        int x = static_cast<int>(sqrt(static_cast<double>(len)));

        int firstVowelIdx = -1;
        for (int j = 0; j < len; ++j) {
            char c = s[j];
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                firstVowelIdx = j;
                break;
            }
        }

        if (firstVowelIdx != -1) {
            substrings.push_back(s.substr(firstVowelIdx, x));
        }
    }

    sort(substrings.begin(), substrings.end());

    for (const string& sub : substrings) {
        cout << sub;
    }
    cout << endl;

    return 0;
}