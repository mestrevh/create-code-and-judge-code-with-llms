/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> v(N);
    double sum = 0;
    map<int, int> freq;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        sum += v[i];
        freq[v[i]]++;
    }

    double media = sum / N;

    sort(v.begin(), v.end());
    double mediana;
    if (N % 2 != 0) {
        mediana = (double)v[N / 2];
    } else {
        mediana = (v[N / 2 - 1] + v[N / 2]) / 2.0;
    }

    int max_freq = 0;
    for (auto const& [val, count] : freq) {
        if (count > max_freq) {
            max_freq = count;
        }
    }

    int count_max = 0;
    int moda_val = -1;
    for (auto const& [val, count] : freq) {
        if (count == max_freq) {
            count_max++;
            moda_val = val;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Media: " << media << "\n";
    cout << "Mediana: " << mediana << "\n";

    if (count_max == 1) {
        cout << "Moda: " << (double)moda_val << "\n";
    } else {
        cout << "Nao tem moda" << "\n";
    }

    return 0;
}

