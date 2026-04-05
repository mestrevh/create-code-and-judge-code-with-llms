/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

float velmed(float p1, float p5, int t){
    return (p5 - p1) / (float)t;
}

float media5(float p1, float p2, float p3, float p4, float p5){
    return (p1 + p2 + p3 + p4 + p5) / 5.0f;
}

float desvio5(float p1, float p2, float p3, float p4, float p5, float med){
    float sumsq = (p1 - med)*(p1 - med) + (p2 - med)*(p2 - med) + (p3 - med)*(p3 - med) + (p4 - med)*(p4 - med) + (p5 - med)*(p5 - med);
    return sqrt(sumsq / 5.0f);
}

float desviom(float desv){
    return desv / sqrt(5.0f);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float p1, p2, p3, p4, p5;
    if(!(cin >> p1 >> p2 >> p3 >> p4 >> p5)) return 0;
    int t;
    cin >> t;
    char c1, c2;
    cin >> c1 >> c2;

    cout.setf(ios::fixed);
    cout << setprecision(2);

    float v = velmed(p1, p5, t);
    cout << v << "\n";

    bool needMed = (c1 != 'x');
    bool needDev = (c2 != 'x');

    float med = 0.0f, desv = 0.0f, desvmed = 0.0f;

    if(needMed || needDev){
        med = media5(p1, p2, p3, p4, p5);
        if(needMed){
            cout << med << "\n";
        }
        if(needDev){
            desv = desvio5(p1, p2, p3, p4, p5, med);
            desvmed = desviom(desv);
            cout << desv << "\n";
            cout << desvmed << "\n";
        }
    }

    return 0;
}