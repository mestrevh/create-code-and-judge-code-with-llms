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

    string pool;
    while (cin >> pool) {
        int n;
        if (!(cin >> n)) break;

        int freq[256];
        for (int i = 0; i < 256; ++i) freq[i] = 0;

        for (char c : pool) {
            freq[(unsigned char)c]++;
        }

        int formed_words = 0;
        for (int i = 0; i < n; ++i) {
            string word;
            cin >> word;

            int word_req[256];
            for (int j = 0; j < 256; ++j) word_req[j] = 0;

            for (char c : word) {
                word_req[(unsigned char)c]++;
            }

            bool possible = true;
            for (int j = 0; j < 256; ++j) {
                if (word_req[j] > freq[j]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                formed_words++;
                for (int j = 0; j < 256; ++j) {
                    freq[j] -= word_req[j];
                }
            }
        }

        cout << "E possivel formar " << formed_words << " palavras com esse conjunto" << "\n";
    }

    return 0;
}