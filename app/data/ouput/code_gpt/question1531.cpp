/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string team, player;
    cin >> team;
    
    if (team != "GSW" && team != "HOU" && team != "CLE" && team != "BOS") {
        cout << "Nenhum time de interesse jogando." << endl;
        return 0;
    }
    
    cin.ignore();
    getline(cin, player);
    int attempts2, made2, attempts3, made3;
    cin >> attempts2 >> made2 >> attempts3 >> made3;
    
    int totalPoints = made2 * 2 + made3 * 3;
    double percent2 = (attempts2 > 0) ? (made2 * 100.0 / attempts2) : 0;
    double percent3 = (attempts3 > 0) ? (made3 * 100.0 / attempts3) : 0;

    bool isGood = totalPoints > 30 || (percent2 > 50 && attempts2 > 10) || (percent3 > 40 && attempts3 > 7);

    if (isGood) {
        cout << "O time " << team << " estah jogando, e " << player << " estah indo bem." << endl;
    } else {
        cout << "O time " << team << " estah jogando, mas " << player << " nao estah indo bem." << endl;
    }

    return 0;
}
