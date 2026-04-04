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

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        string rgStatus, rgDate, passStatus, passDate, seat;

        // Reading RG information
        cin >> rgStatus;
        if (rgStatus == "Nao") {
            string dummy;
            cin >> dummy; // Consume "possui"
        }
        cin >> rgDate;

        // Reading Passagem information
        cin >> passStatus;
        if (passStatus == "Nao") {
            string dummy;
            cin >> dummy; // Consume "possui"
        }
        cin >> passDate;

        // Reading seat information
        cin >> seat;

        // Decision logic based on priority described in requirements and test cases
        if (rgStatus == "Nao") {
            cout << "a saida e nessa direção\n";
        } else if (passStatus == "Nao") {
            cout << "a recepição e nessa direção\n";
        } else if (rgDate != passDate) {
            cout << "190\n";
        } else {
            cout << "o seu assento e " << seat << " tenha um bom dia\n";
        }
    }

    return 0;
}