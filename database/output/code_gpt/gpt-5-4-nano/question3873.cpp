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

    vector<string> nomes(N);
    vector<string> cartoes(N);
    vector<int> cvvs(N);
    vector<long double> vals(N);

    vector<bool> beneficiado(N, false);

    for (int i = 0; i < N; i++) {
        cin >> ws;
        getline(cin, nomes[i]);
        cin >> cartoes[i];
        cin >> cvvs[i];
        long double v;
        cin >> v;
        vals[i] = v;

        int soma = 0;
        for (char c : cartoes[i]) if (isdigit((unsigned char)c)) soma += c - '0';

        if (soma >= cvvs[i]) {
            beneficiado[i] = true;
            vals[i] = 0.0L;
        } else {
            beneficiado[i] = false;
            long double diff = (long double)(soma - cvvs[i]);
            vals[i] = vals[i] * diff;
        }
    }

    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        if (beneficiado[i]) x++;
        else y++;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    cout << "Um total de " << x << " clientes se beneficiaram da nova politica!\n";
    for (int i = 0; i < N; i++) {
        if (beneficiado[i]) {
            cout << nomes[i] << " " << (double)vals[i] << "\n";
        }
    }

    cout << "No entanto, " << y << " clientes nao se beneficiaram da nova politica.\n";
    for (int i = 0; i < N; i++) {
        if (!beneficiado[i]) {
            cout << nomes[i] << " " << (double)vals[i] << "\n";
        }
    }

    return 0;
}