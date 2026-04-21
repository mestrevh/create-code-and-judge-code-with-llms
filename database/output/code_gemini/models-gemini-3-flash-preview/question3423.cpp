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
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long count = 0;
    long long current_odd = 1;
    
    while (n > 0) {
        n -= current_odd;
        current_odd += 2;
        count++;
    }

    cout << count << "\n";

    return 0;
}