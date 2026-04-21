/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string name;
    getline(cin, name);
    if (!name.empty() && name.back() == '\r') name.pop_back();
    
    for (char &c : name) if (c == '\t') c = ' ';
    
    cout << "Ola, " << name << " !";
    return 0;
}