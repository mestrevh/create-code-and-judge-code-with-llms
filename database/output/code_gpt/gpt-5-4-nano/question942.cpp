/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    const int COLS = 7;
    int rows = (N + COLS - 1) / COLS;

    vector<vector<double>> a(rows, vector<double>(COLS, 0.0));
    vector<double> sales(N + 1, 0.0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i * COLS + j < N) cin >> a[i][j];
            else a[i][j] = 0.0;
        }
    }

    int diasFunc = 0;
    double somaMes = 0.0;
    double maior = -1.0;
    double menor = 1e300;

    for (int day = 1; day <= N; day++) {
        int idx = day - 1;
        int i = idx / COLS;
        int j = idx % COLS;
        double v = a[i][j];
        sales[day] = v;

        somaMes += v;
        if (v != 0.0) diasFunc++;

        if (v > maior) maior = v;
        if (v < menor) menor = v;
    }

    vector<int> diasMaior, diasMenor;
    for (int day = 1; day <= N; day++) {
        double v = sales[day];
        if (v == maior) diasMaior.push_back(day);
        if (v == menor) diasMenor.push_back(day);
    }

    cout << diasFunc << "\n";
    cout << fixed << setprecision(2) << (somaMes / N) << "\n";
    cout << fixed << setprecision(2) << (diasFunc ? somaMes / diasFunc : 0.0) << "\n";
    cout << fixed << setprecision(2) << maior << "\n";

    for (size_t i = 0; i < diasMaior.size(); i++) {
        if (i) cout << ' ';
        cout << diasMaior[i];
    }
    if (!diasMaior.empty()) cout << " ";
    cout << "\n";

    cout << fixed << setprecision(2) << menor << "\n";

    for (size_t i = 0; i < diasMenor.size(); i++) {
        if (i) cout << ' ';
        cout << diasMenor[i];
    }
    if (!diasMenor.empty()) cout << " ";
    return 0;
}