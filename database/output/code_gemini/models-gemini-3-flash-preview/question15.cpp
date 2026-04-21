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

    string name;
    if (getline(cin, name)) {
        if (!name.empty() && name.back() == '\r') {
            name.pop_back();
        }
        cout << "Seja muito bem-vindo " << name << "\n";
    }

    return 0;
}