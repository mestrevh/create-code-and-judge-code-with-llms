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

    vector<pair<double, string>> notas;
    vector<pair<int, string>> idades;

    for (int i = 0; i < N; i++) {
        string nome;
        int idade;
        double nota;
        cin >> nome >> idade >> nota;
        notas.push_back({nota, nome});
        idades.push_back({idade, nome});
    }

    auto cmpNota = [](const pair<double,string>& a, const pair<double,string>& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    };
    auto cmpId = [](const pair<int,string>& a, const pair<int,string>& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    };

    sort(notas.begin(), notas.end(), cmpNota);
    sort(idades.begin(), idades.end(), cmpId);

    auto formatDouble = [](double x)->string{
        ostringstream oss;
        oss.setf(ios::fixed);
        oss << setprecision(2) << x;
        return oss.str();
    };

    double sumNota = 0.0;
    for (auto &p : notas) sumNota += p.first;
    double mediaNota = sumNota / N;
    double medianaNota;
    if (N % 2 == 1) medianaNota = notas[N/2].first;
    else medianaNota = (notas[N/2 - 1].first + notas[N/2].first) / 2.0;

    cout << "---Notas---\n";
    for (auto &p : notas) {
        cout << p.second << " " << formatDouble(p.first) << "\n";
    }
    cout << "---------\n";
    cout << "Media Nota: " << formatDouble(mediaNota) << "\n";
    cout << "Mediana Nota: " << formatDouble(medianaNota) << "\n\n";

    long long sumId = 0;
    for (auto &p : idades) sumId += p.first;
    double mediaIdade = (double)sumId / N;
    double medianaIdade;
    if (N % 2 == 1) medianaIdade = idades[N/2].first;
    else medianaIdade = (idades[N/2 - 1].first + idades[N/2].first) / 2.0;

    cout << "---Idade---\n";
    for (auto &p : idades) {
        cout << p.second << " " << p.first << "\n";
    }
    cout << "---------\n";
    cout << "Media Idade: " << formatDouble(mediaIdade) << "\n";
    cout << "Mediana Idade: " << formatDouble(medianaIdade) << "\n";

    return 0;
}