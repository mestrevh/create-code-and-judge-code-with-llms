/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void troca(double &a, double &b){
    double t = a;
    a = b;
    b = t;
}

void trocaInt(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void trocaString(string &a, string &b){
    string t = a;
    a = b;
    b = t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;
    vector<string> nome(n);
    vector<double> nota(n);
    vector<int> idade(n);

    for(int i = 0; i < n; i++){
        if(!(cin >> ws) ) return 0;
        getline(cin, nome[i]);
        cin >> nota[i] >> idade[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(nota[i] > nota[j]){
                trocaString(nome[i], nome[j]);
                troca(nota[i], nota[j]);
                trocaInt(idade[i], idade[j]);
            }
        }
    }

    cout.setf(ios::fixed);
    cout << setprecision(2);

    for(int i = 0; i < n; i++){
        cout << nome[i] << " " << nota[i] << " " << idade[i] << "\n";
    }

    return 0;
}