/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a;
    if (!(cin >> a)) return 0;

    int n;
    if (!(cin >> n)) return 0;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        long long f;
        if (!(cin >> f)) break;
        if (f * a >= 40000000LL) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}