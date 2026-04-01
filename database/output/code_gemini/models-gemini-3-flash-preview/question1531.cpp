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

    string team;
    if (!(cin >> team)) return 0;

    if (team == "GSW" || team == "HOU" || team == "CLE" || team == "BOS") {
        string player;
        getline(cin >> ws, player);

        int att2, made2, att3, made3;
        if (cin >> att2 >> made2 >> att3 >> made3) {
            int total_points = (made2 * 2) + (made3 * 3);
            
            bool destacar = false;

            if (total_points > 30) {
                destacar = true;
            } else if (att2 > 10 && (static_cast<double>(made2) / att2) > 0.5) {
                destacar = true;
            } else if (att3 > 7 && (static_cast<double>(made3) / att3) > 0.4) {
                destacar = true;
            }

            if (destacar) {
                cout << "O time " << team << " estah jogando, e " << player << " estah indo bem." << endl;
            } else {
                cout << "O time " << team << " estah jogando, mas " << player << " nao estah indo bem." << endl;
            }
        }
    } else {
        cout << "Nenhum time de interesse jogando." << endl;
    }

    return 0;
}