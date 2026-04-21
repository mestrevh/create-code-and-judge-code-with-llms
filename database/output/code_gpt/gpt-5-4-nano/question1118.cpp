/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline string toLowerStr(string s){
    for(char &c: s) c = (char)tolower((unsigned char)c);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    if(!(cin >> n)) return 0;
    if(!(cin >> m)) return 0;

    string base;
    if(!(cin >> base)) return 0;

    vector<string> secondary;
    string x;
    while(cin >> x) secondary.push_back(x);

    if(n <= 0 || m <= 0 || (long long)base.size() < n || (long long)base.size() < m){
        cout << "TAMANHO INVALIDO";
        return 0;
    }

    string prefix = base.substr(0, (size_t)n);
    string suffix = base.substr((size_t)base.size() - (size_t)m);

    for(size_t i = 0; i < secondary.size(); i++){
        cout << "CO :\n";
        cout << toLowerStr(prefix + secondary[i]) << "\n";
        cout << secondary[i] + toLowerStr(suffix) << "\n";
        if(i + 1 < secondary.size()){
            cout << "\n";
        }
    }

    return 0;
}