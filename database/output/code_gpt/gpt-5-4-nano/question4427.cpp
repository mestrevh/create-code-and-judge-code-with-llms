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
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    double sum = 0;
    for (int x : a) sum += x;
    double media = sum / N;

    vector<int> b = a;
    sort(b.begin(), b.end());
    double mediana;
    if (N % 2 == 1) mediana = b[N / 2];
    else mediana = (b[N / 2 - 1] + b[N / 2]) / 2.0;

    map<int,int> freq;
    for (int x : a) freq[x]++;
    int maxFreq = 0;
    int modaVal = -1;
    for (auto &p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            modaVal = p.first;
        }
    }
    bool temModa = maxFreq > 1;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    cout << "Media: " << media << "\n";
    cout << "Mediana: " << mediana << "\n";
    if (temModa) cout << "Moda: " << modaVal << ".00\n";
    else cout << "Nao tem moda\n";
    return 0;
}