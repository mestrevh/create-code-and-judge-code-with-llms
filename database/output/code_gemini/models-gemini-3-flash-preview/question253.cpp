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
    
    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;
    
    if (s1 == s2) {
        cout << "IGUAIS" << endl;
    } else {
        cout << "DIFERENTES" << endl;
    }
    
    return 0;
}