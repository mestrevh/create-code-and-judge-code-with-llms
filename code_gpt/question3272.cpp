/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int i1, f1, i2, f2;
    
    getline(cin, s);
    cin >> i1 >> f1 >> i2 >> f2;
    
    string s1 = s.substr(i1, f1 - i1 + 1);
    string s2 = s.substr(i2, f2 - i2 + 1);
    
    cout << s1 + s2 << endl;
    return 0;
}
