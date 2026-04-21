/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T_cases;
    if (!(cin >> T_cases)) return 0;

    while (T_cases--) {
        int N;
        if (!(cin >> N)) break;

        vector<string> recipes(N);
        for (int i = 0; i < N; ++i) {
            cin >> recipes[i];
        }

        string ingredients;
        cin >> ingredients;

        int count_available[256];
        for (int i = 0; i < 256; ++i) {
            count_available[i] = 0;
        }

        for (char c : ingredients) {
            count_available[(unsigned char)c]++;
        }

        for (int i = 0; i < N; ++i) {
            int req[256];
            for (int j = 0; j < 256; ++j) {
                req[j] = 0;
            }

            for (char c : recipes[i]) {
                req[(unsigned char)c]++;
            }

            int max_p = 100001;
            bool has_req = false;
            for (int j = 0; j < 256; ++j) {
                if (req[j] > 0) {
                    has_req = true;
                    int possible = count_available[j] / req[j];
                    if (possible < max_p) {
                        max_p = possible;
                    }
                }
            }

            if (!has_req) {
                max_p = 0;
            }

            cout << max_p << "\n";

            for (int j = 0; j < 256; ++j) {
                if (req[j] > 0) {
                    count_available[j] -= max_p * req[j];
                }
            }
        }
        cout << "\n";
    }

    return 0;
}