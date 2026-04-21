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
    while (cin >> n && n != -1) {
        int occurrences = 0;
        bool input_ended = false;
        int x;
        for (int i = 0; i < 20; ++i) {
            if (!(cin >> x)) {
                input_ended = true;
                break;
            }
            if (x == -1) {
                input_ended = true;
                break;
            }
            if (x == n) {
                occurrences++;
            }
        }
        cout << n << " aparece " << occurrences << " vezes\n";
        if (input_ended) {
            break;
        }
    }

    return 0;
}