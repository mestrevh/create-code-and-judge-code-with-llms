/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int N = 10;
    vector<int> numbers(N);
    double sum = 0;
    int sum_div3 = 0;

    for (int i = 0; i < N; ++i) {
        if (!(cin >> numbers[i])) break;
        sum += numbers[i];
        if (numbers[i] % 3 == 0) {
            sum_div3 += numbers[i];
        }
    }

    cout << fixed << setprecision(1);
    cout << "Média: " << (sum / (double)N) << "\n";
    cout << "Divisíveis: " << sum_div3 << "\n";

    return 0;
}