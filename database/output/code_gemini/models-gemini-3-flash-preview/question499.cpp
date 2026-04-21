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

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    long long low = min(a, b);
    long long high = max(a, b);

    long long sum = 0;
    // Candidates are numbers 'x' such that (1000 % x == 0) and (x % 4 == 0)
    // Divisors of 1000: 1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000
    // Multiples of 4 in that set: 4, 8, 20, 40, 100, 200, 500, 1000
    int valid_numbers[] = {4, 8, 20, 40, 100, 200, 500, 1000};

    for (int num : valid_numbers) {
        if (num > low && num < high) {
            sum += num;
        }
    }

    cout << sum << "\n";

    return 0;
}