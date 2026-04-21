/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long budget;
    if (!(cin >> budget)) return 0;

    long long total_cost = 0;
    for (int i = 0; i < 6; ++i) {
        long long price;
        string name;
        if (cin >> price >> name) {
            total_cost += price;
        }
    }

    if (total_cost <= budget) {
        cout << "Mario gastara um total de R$ " << total_cost << "." << endl;
    } else {
        cout << "Infelizmente nao sera possivel comprar tudo, faltam R$ " << (total_cost - budget) << "." << endl;
    }

    return 0;
}