/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    if (!(cin >> K)) return 0;

    string dummy;
    getline(cin, dummy); 

    int freq[256];
    for (int i = 0; i < 256; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < K; i++) {
        string line;
        if (getline(cin, line)) {
            for (unsigned char c : line) {
                freq[c]++;
            }
        }
    }

    char X;
    if (cin >> X) {
        int max_f = -1;
        int best_c = 0;

        for (int i = 0; i < 256; i++) {
            if (freq[i] > max_f) {
                max_f = freq[i];
                best_c = i;
            }
        }

        cout << (char)best_c << " " << max_f << " " << freq[(unsigned char)X] << endl;
    }

    return 0;
}