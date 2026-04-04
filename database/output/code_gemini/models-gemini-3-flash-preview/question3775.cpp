/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float velmed(float p1, float p5, int t) {
    if (t == 0) return 0.0f;
    return (p5 - p1) / (float)t;
}

float media(float p1, float p2, float p3, float p4, float p5) {
    return (p1 + p2 + p3 + p4 + p5) / 5.0f;
}

float desvio(float p1, float p2, float p3, float p4, float p5, float med) {
    float sum = 0.0f;
    float d1 = p1 - med; sum += d1 * d1;
    float d2 = p2 - med; sum += d2 * d2;
    float d3 = p3 - med; sum += d3 * d3;
    float d4 = p4 - med; sum += d4 * d4;
    float d5 = p5 - med; sum += d5 * d5;
    return sum / 5.0f;
}

float desviom(float desv) {
    return desv / sqrt(5.0f);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float p1, p2, p3, p4, p5;
    if (!(cin >> p1 >> p2 >> p3 >> p4 >> p5)) return 0;

    int t;
    if (!(cin >> t)) return 0;

    char c1, c2;
    if (!(cin >> c1 >> c2)) return 0;

    cout << fixed << setprecision(2);

    cout << velmed(p1, p5, t) << "\n";

    float m = media(p1, p2, p3, p4, p5);
    if (c1 == 'm') {
        cout << m << "\n";
    }

    if (c2 == 'd') {
        float d = desvio(p1, p2, p3, p4, p5, m);
        cout << d << "\n";
        cout << desviom(d) << "\n";
    }

    return 0;
}