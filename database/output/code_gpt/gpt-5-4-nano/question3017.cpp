/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string nome;
    long long idade;
    if (!(cin >> nome)) return 0;
    if (!(cin >> idade)) return 0;
    
    long long dias = idade * 365;
    cout << nome << ", você já viveu " << dias << " dias!";
    return 0;
}