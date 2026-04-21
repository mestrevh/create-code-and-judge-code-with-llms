/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int febre = 0, temp_normal = 0;
    int otima = 0, normalP = 0, limitrofe = 0, hipertensao = 0, psistolica = 0, observacao = 0;

    for (int i = 0; i < n; ++i) {
        int t, s, d;
        if (!(cin >> t >> s >> d)) break;

        if (t > 38) {
            febre++;
        } else {
            temp_normal++;
        }

        if (s >= 140 && d >= 90) {
            hipertensao++;
        } else if (s >= 140 && d < 90) {
            psistolica++;
        } else if (d >= 90) {
            observacao++;
        } else {
            if (s < 120 && d < 80) {
                otima++;
            } else if (s < 130 && d < 85) {
                normalP++;
            } else {
                limitrofe++;
            }
        }
    }

    cout << "febre: " << febre << "\n";
    cout << "temperatura normal: " << temp_normal << "\n";
    cout << "pressao otima: " << otima << "\n";
    cout << "pressao normal: " << normalP << "\n";
    cout << "pressao limitrofe: " << limitrofe << "\n";
    cout << "hipertensao: " << hipertensao << "\n";
    cout << "pressao sistolica: " << psistolica << "\n";
    cout << "observacao: " << observacao << "\n";

    return 0;
}