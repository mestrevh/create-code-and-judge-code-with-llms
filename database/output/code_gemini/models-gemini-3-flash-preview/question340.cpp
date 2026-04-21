/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    if (!(cin >> n >> k)) return 0;

    long long current_computers = 1;
    long long hours = 0;

    while (current_computers < k && current_computers < n) {
        current_computers *= 2;
        hours++;
    }

    if (current_computers < n) {
        long long remaining = n - current_computers;
        hours += (remaining + k - 1) / k;
    }

    cout << hours << endl;

    return 0;
}