/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

float vantagem(float candidato[], float concorrente[], int n) {
    float max_v = 0.0f;
    for (int i = 0; i < n; ++i) {
        float diff = candidato[i] - concorrente[i];
        if (diff > max_v) {
            max_v = diff;
        }
    }
    return max_v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        cout << fixed << setprecision(2) << 0.00 << endl;
        return 0;
    }

    vector<float> cand(n);
    for (int i = 0; i < n; ++i) {
        cin >> cand[i];
    }

    vector<float> conc(n);
    for (int i = 0; i < n; ++i) {
        cin >> conc[i];
    }

    float resultado = vantagem(cand.data(), conc.data(), n);

    cout << fixed << setprecision(2) << resultado << endl;

    return 0;
}