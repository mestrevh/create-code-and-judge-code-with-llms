/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    char g;
    bool first = true;

    double bestAvg = -1e100;
    char bestGender = 'H';

    double sumAll = 0.0;
    int n = 0;

    int approved = 0;
    int finalExam = 0;
    int failed = 0;

    double sumWomen = 0.0, sumMen = 0.0;
    int cntWomen = 0, cntMen = 0;

    auto calcAvg = [&](double x, double y, double z) -> double {
        return (x + y + z) / 3.0;
    };

    while (true) {
        if (!(cin >> a >> b >> c >> g)) break;
        double avg = calcAvg(a, b, c);

        bool qualified = (avg >= 7.0);
        bool canFinal = (avg >= 3.0 && avg < 7.0);
        bool directFail = (avg < 3.0);

        sumAll += avg;
        n++;

        if (g == 'M') {
            sumMen += avg;
            cntMen++;
        } else if (g == 'H') {
            sumMen += avg;
            cntMen++;
        } else if (g == 'm') {
            sumMen += avg;
            cntMen++;
        } else if (g == 'M') {
            sumMen += avg;
            cntMen++;
        } else if (g == 'F') {
            sumWomen += avg;
            cntWomen++;
        }

        if (g == 'H') {
            sumMen += avg;
            cntMen++;
        } else if (g == 'M') {
            sumWomen += avg;
            cntWomen++;
        } else if (g == 'h') {
            sumMen += avg;
            cntMen++;
        } else if (g == 'm') {
            sumWomen += avg;
            cntWomen++;
        }

        if (qualified) approved++;
        else if (canFinal) finalExam++;
        else if (directFail) failed++;

        if (first || avg > bestAvg || (abs(avg - bestAvg) < 1e-12)) {
            bestAvg = avg;
            bestGender = g;
            first = false;
        } else if (avg == bestAvg) {
            bestGender = g;
        }
    }

    auto oneDec = [&](double x) -> string {
        ostringstream oss;
        oss.setf(ios::fixed);
        oss << setprecision(1) << x;
        return oss.str();
    };

    double mediaGeral = (n ? sumAll / n : 0.0);
    double mediaMulheres = (cntWomen ? sumWomen / cntWomen : 0.0);
    double mediaHomens = (cntMen ? sumMen / cntMen : 0.0);

    string gStr;
    if (bestGender == 'M') gStr = "mulher";
    else if (bestGender == 'H') gStr = "homem";
    else gStr = string("homem");
    if (bestGender == 'm') gStr = "mulher";
    if (bestGender == 'h') gStr = "homem";

    cout << "A maior media da turma foi " << oneDec(bestAvg) << " e pertence a uma/um " << gStr << ".\n";
    cout << "A media geral foi de " << oneDec(mediaGeral) << ".\n";
    cout << approved << " alunos foram aprovados por media.\n";
    cout << finalExam << " alunos podem fazer o exame final.\n";
    cout << failed << " alunos foram reprovados.\n";
    cout << "A media das mulheres foi de " << oneDec(mediaMulheres) << "\n";
    cout << "A media dos homens foi de " << oneDec(mediaHomens) << ".\n";

    return 0;
}