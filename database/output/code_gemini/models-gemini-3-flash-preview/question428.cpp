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

    string street, num, neighborhood, city, state, cep;

    while (getline(cin, street)) {
        if (!getline(cin, num)) break;
        if (!getline(cin, neighborhood)) break;
        if (!getline(cin, city)) break;
        if (!getline(cin, state)) break;
        if (!getline(cin, cep)) break;

        cout << street << ", " << num << "." << "\n";
        cout << "Bairro: " << neighborhood << ". Cep: " << cep << "\n";
        cout << city << "/" << state << "\n";
    }

    return 0;
}