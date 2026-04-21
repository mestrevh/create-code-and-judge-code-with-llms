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

    string x, y;
    if (getline(cin, x)) {
        while (!x.empty() && (x.back() == '\r' || x.back() == '\n' || x.back() == ' ')) {
            x.pop_back();
        }
        
        if (getline(cin, y)) {
            while (!y.empty() && (y.back() == '\r' || y.back() == '\n')) {
                y.pop_back();
            }
            
            if (!x.empty() && y.find(x) != string::npos) {
                cout << "existe!" << endl;
            } else {
                cout << "nao existe" << endl;
            }
        } else {
            cout << "nao existe" << endl;
        }
    }

    return 0;
}