/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    int count = 0;
    if (a != 0 && b != 0) {
        for (int i = 1; i < 50; ++i) {
            if (i % a == 0 && i % b == 0) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}