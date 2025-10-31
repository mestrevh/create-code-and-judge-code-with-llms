/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    char ch;
    getline(cin, str);
    cin >> ch;
    bool found = false;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            cout << i << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << -1 << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
