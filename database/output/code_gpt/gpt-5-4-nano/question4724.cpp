/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    tuple<string, string, string, string> frutas = make_tuple("banana", "laranja", "melancia", "morango");
    cout << get<2>(frutas) << "\n";
    return 0;
}