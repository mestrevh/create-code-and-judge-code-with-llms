/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

void somarRecursivo(vector<long long>& total, const vector<long long>& parcel, size_t idx, long long carry) {
    if (idx >= parcel.size() && carry == 0) return;
    if (idx >= total.size()) total.push_back(0);
    long long pDigit = (idx < parcel.size()) ? parcel[idx] : 0;
    long long current = total[idx] + pDigit + carry;
    total[idx] = current % 10;
    somarRecursivo(total, parcel, idx + 1, current / 10);
}

void calcularResultadoRecursivo(int P, vector<long long>& total) {
    if (P <= 0) return;
    int N;
    if (!(cin >> N)) return;
    vector<long long> parcel(N);
    for (int i = 0; i < N; ++i) {
        cin >> parcel[i];
    }
    somarRecursivo(total, parcel, 0, 0);
    calcularResultadoRecursivo(P - 1, total);
}

void imprimirRecursivo(const vector<long long>& total, int idx) {
    if (idx < 0) return;
    cout << total[idx];
    imprimirRecursivo(total, idx - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int P_val;
    if (!(cin >> P_val)) return 0;

    vector<long long> total;
    total.push_back(0);

    calcularResultadoRecursivo(P_val, total);

    while (total.size() > 1 && total.back() == 0) {
        total.pop_back();
    }

    imprimirRecursivo(total, (int)total.size() - 1);
    cout << endl;

    return 0;
}