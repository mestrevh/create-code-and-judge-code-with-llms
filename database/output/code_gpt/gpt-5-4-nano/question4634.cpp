/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long sum = 0;
    int count = 0;

    while (count < n) {
        int x;
        cin >> x;
        if (x > 40) {
            cout << "O numero de alunos nao pode ser maior do que 40\n";
        } else {
            sum += x;
            count++;
        }
    }

    double media = (double)sum / n;
    long long arred = llround(media);
    cout << arred;
    return 0;
}