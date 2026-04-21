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

    for (int t = 1; t <= T; ++t) {
        string x;
        if (!(cin >> x)) break;

        int freq[10] = {0};
        for (char c : x) {
            if (c >= '0' && c <= '9') {
                freq[c - '0']++;
            }
        }

        cout << "Caso " << t << ": ";
        bool any_printed = false;
        for (int i = 9; i >= 0; --i) {
            while (freq[i] > 0) {
                cout << (char)(i + '0');
                freq[i]--;
                any_printed = true;
            }
        }
        
        if (!any_printed) {
            // This part technically won't be reached given X >= 0
            // but is a safety for non-digit inputs
            if (x == "0") cout << "0";
        }
        
        cout << "\n";
    }

    return 0;
}