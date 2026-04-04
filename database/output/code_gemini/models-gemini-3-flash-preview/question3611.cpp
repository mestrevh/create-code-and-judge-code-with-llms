/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contact {
    string fullName;
    string firstName;
    string phone;
    string vinculoStr;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    string dummy;
    getline(cin, dummy);

    vector<Contact> contacts;
    contacts.reserve(n);
    for (int i = 0; i < n; ++i) {
        Contact c;
        if (!getline(cin, c.fullName)) break;
        if (c.fullName.empty()) {
            if (!getline(cin, c.fullName)) break;
        }
        
        size_t spacePos = c.fullName.find(' ');
        if (spacePos != string::npos) {
            c.firstName = c.fullName.substr(0, spacePos);
        } else {
            c.firstName = c.fullName;
        }

        if (!getline(cin, c.phone)) break;
        
        int code;
        if (!(cin >> code)) break;
        getline(cin, dummy);

        if (code == 1) c.vinculoStr = "Familia";
        else if (code == 2) c.vinculoStr = "Faculdade";
        else if (code == 3) c.vinculoStr = "Amigo";
        else c.vinculoStr = "";
        
        contacts.push_back(c);
    }

    string query;
    bool firstPrint = true;
    while (cin >> query && query != "#") {
        bool foundQuery = false;
        for (const auto& c : contacts) {
            if (c.firstName == query) {
                if (!firstPrint) {
                    cout << "\n\n";
                }
                cout << "Nome: " << c.fullName << "\n";
                cout << "Numero: " << c.phone << "\n";
                cout << "Vinculo: " << c.vinculoStr;
                foundQuery = true;
                firstPrint = false;
            }
        }
        if (!foundQuery) {
            if (!firstPrint) {
                cout << "\n\n";
            }
            cout << query << " nao foi cadastrado";
            firstPrint = false;
        }
    }

    return 0;
}