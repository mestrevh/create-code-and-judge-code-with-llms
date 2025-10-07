/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float velmed(float p1, float p5, int t) {
    return (p5 - p1) / t;
}

float media(float p1, float p2, float p3, float p4, float p5) {
    return (p1 + p2 + p3 + p4 + p5) / 5;
}

float desvio(float p1, float p2, float p3, float p4, float p5, float med) {
    return sqrt((pow(p1 - med, 2) + pow(p2 - med, 2) + pow(p3 - med, 2) + pow(p4 - med, 2) + pow(p5 - med, 2)) / 5);
}

float desviom(float desv) {
    return desv / sqrt(5);
}

int main() {
    float p1, p2, p3, p4, p5;
    int t;
    char avg, stddev;

    cin >> p1 >> p2 >> p3 >> p4 >> p5 >> t >> avg >> stddev;

    float velocidade = velmed(p1, p5, t);
    cout << fixed << setprecision(2) << velocidade << endl;

    if (avg == 'm') {
        float med = media(p1, p2, p3, p4, p5);
        cout << fixed << setprecision(2) << med << endl;

        if (stddev == 'd') {
            float desv = desvio(p1, p2, p3, p4, p5, med);
            cout << fixed << setprecision(2) << desv << endl;
            cout << fixed << setprecision(2) << desviom(desv) << endl;
        }
    } else if (stddev == 'd') {
        float desv = desvio(p1, p2, p3, p4, p5, media(p1, p2, p3, p4, p5));
        cout << fixed << setprecision(2) << desv << endl;
    }

    return 0;
}
