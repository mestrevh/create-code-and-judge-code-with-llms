/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a[4];
    while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
        sort(a, a + 4);
        long long s1 = a[0] + a[1];
        long long s2 = a[0] + a[2];
        cout << s1 << s2 << "\n";
    }
    return 0;
}