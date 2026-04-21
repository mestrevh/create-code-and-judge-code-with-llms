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
    if (getline(cin, name)) {
        size_t start = name.find_first_not_of(" \t\r\n");
        size_t end = name.find_last_not_of(" \t\r\n");
        if (start == string::npos) name = "";
        else name = name.substr(start, end - start + 1);
        
        cout << "Olah, " << name << "!" ;
    }
    return 0;
}