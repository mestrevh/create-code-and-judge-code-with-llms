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
    
    string s;
    if (cin >> s) {
        if (s.length() >= 3) {
            string x = s.substr(0, s.length() - 3);
            cout << "Aquilo que " << x << "." << endl;
        }
    }
    
    return 0;
}