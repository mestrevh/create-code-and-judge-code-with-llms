/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    vector<long long> a;
    while (cin >> n) a.push_back(n);

    long long totalStudents = 0;
    for (long long x : a) totalStudents += x;

    long long numClasses = a.size();
    long long provasPorTurma = 4;
    long long gramposPorAlunoPorProva = 3;

    long long totalGrampso = totalStudents * numClasses * provasPorTurma * gramposPorAlunoPorProva;

    long long caixas = (totalGrampso + 29) / 30;

    cout << totalGrampso << "\n" << caixas << "\n";
    return 0;
}