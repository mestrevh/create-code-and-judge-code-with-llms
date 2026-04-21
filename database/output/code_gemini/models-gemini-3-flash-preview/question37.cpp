/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        long long h = n / 3600;
        long long rem = n % 3600;
        long long m = rem / 60;
        long long s = rem % 60;

        cout << h << " h " << m << " m " << s << " s" << "\n";
    }

    return 0;
}