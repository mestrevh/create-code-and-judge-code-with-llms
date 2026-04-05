/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; ++i) {
            int black_count = 0;
            int marked_index = -1;
            for (int j = 0; j < 5; ++j) {
                int val;
                cin >> val;
                if (val <= 127) {
                    black_count++;
                    marked_index = j;
                }
            }

            if (black_count == 1) {
                cout << (char)('A' + marked_index) << "\n";
            } else {
                cout << "*\n";
            }
        }
    }

    return 0;
}