/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string produto, busca;
    while (cin >> produto >> busca) {
        if (busca.find(produto) != string::npos)
            cout << "I'm on the empire business.\n";
        else
            cout << "HE CAN'T KEEPING GETTING AWAY WITH IT!\n";
    }
    return 0;
}