/*
Código criado pelo models/gemini-3.1-pro-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int count = 0;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x != last) {
                count++;
                last = x;
            }
        }
        cout << count << "\n";
    }

    return 0;
}