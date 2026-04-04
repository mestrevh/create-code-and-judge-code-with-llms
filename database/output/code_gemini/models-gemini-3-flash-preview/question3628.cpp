/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * Problem: Academia digital access control.
 * Constraints: Max 100 clients, SAIR sentinel, integer password, 'P' or 'F' status.
 * Complexity: O(N log N) for registration, O(Q log N) for queries using std::map.
 */

struct Client {
    string name;
    char status;
};

int main() {
    // Standard CP optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, Client> clients;
    string name;
    int pass;
    char status;
    int count = 0;

    // Registration Phase
    while (count < 100) {
        // Use ws to consume leading whitespace/newlines before reading the full name line
        if (!(getline(cin >> ws, name)) || name == "SAIR") {
            break;
        }
        if (!(cin >> pass >> status)) {
            break;
        }
        clients[pass] = {name, status};
        count++;
    }

    // Access Phase
    int query;
    while (cin >> query && query != -1) {
        auto it = clients.find(query);
        if (it != clients.end()) {
            // Case 1: Password exists and status is Paid
            if (it->second.status == 'P') {
                cout << it->second.name << ", seja bem-vindo(a)!\n";
            } 
            // Case 2: Password exists but status is Unpaid
            else {
                cout << "Não está esquecendo de algo, " << it->second.name << "? Procure a recepção!\n";
            }
        } 
        // Case 3: Password does not exist
        else {
            cout << "Seja bem-vindo(a)! Procure a recepção!\n";
        }
    }

    return 0;
}