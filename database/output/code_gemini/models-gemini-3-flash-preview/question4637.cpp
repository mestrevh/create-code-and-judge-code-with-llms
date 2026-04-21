/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long total_sum = 0;
    int current_number;

    while (cin >> current_number) {
        total_sum += current_number;
    }

    cout << total_sum << endl;

    return 0;
}