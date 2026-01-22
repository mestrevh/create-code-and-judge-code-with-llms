/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<float> u(n), v(n);
    
    for (int i = 0; i < n; ++i) cin >> u[i];
    for (int i = 0; i < n; ++i) cin >> v[i];

    float dot_product = 0, norm_u = 0;
    for (int i = 0; i < n; ++i) {
        dot_product += u[i] * v[i];
        norm_u += u[i] * u[i];
    }

    if (norm_u == 0) return 0;

    float scalar = dot_product / norm_u;
    vector<float> projection(n);
    for (int i = 0; i < n; ++i) {
        projection[i] = scalar * u[i];
    }

    if (u == v) {
        cout << "Os vetores sao iguais, logo, a projecao de v na direcao de u, eh o proprio u." << endl;
    } else {
        cout << "A projecao ortogonal de v na direcao de u eh:" << endl;
        for (float val : projection) {
            cout << "| " << fixed << setprecision(3) << val << " |" << endl;
        }
    }

    return 0;
}
