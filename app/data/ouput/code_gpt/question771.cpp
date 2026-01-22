/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    double xp, yp;
    cin >> xp >> yp;
    int n;
    cin >> n;

    int num_ret = 0, num_cir = 0;
    
    for (int i = 0; i < n; ++i) {
        string tipo;
        cin >> tipo;
        if (tipo == "retangulo") {
            double xmin, ymin, xmax, ymax;
            cin >> xmin >> ymin >> xmax >> ymax;
            if (xp >= xmin && xp <= xmax && yp >= ymin && yp <= ymax) {
                num_ret++;
            }
        } else if (tipo == "circulo") {
            double xcentro, ycentro, raio;
            cin >> xcentro >> ycentro >> raio;
            if (raio < 0) raio = -raio;
            if (sqrt(pow(xp - xcentro, 2) + pow(yp - ycentro, 2)) <= raio) {
                num_cir++;
            }
        }
    }

    cout << "Retangulos: " << num_ret << endl;
    cout << "Circulos: " << num_cir << endl;

    return 0;
}
