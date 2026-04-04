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
        int scoreA = 0;
        int scoreB = 0;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            if (a > b) {
                scoreA++;
            } else if (b > a) {
                scoreB++;
            }
        }
        cout << scoreA << " " << scoreB << "\n";
    }

    return 0;
}