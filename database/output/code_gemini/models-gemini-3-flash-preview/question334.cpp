/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, z;
    if (!(cin >> x)) return 0;

    while (cin >> z && z <= x);

    long long current_sum = 0;
    int count = 0;
    int current_value = x;

    while (current_sum <= z) {
        current_sum += current_value;
        current_value++;
        count++;
    }

    cout << count << "\n";

    return 0;
}