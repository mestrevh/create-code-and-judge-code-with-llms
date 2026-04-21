/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char house;
    int totalSoldiers = 0;
    float maxHeightCV = 0.0f;
    int countLanceirosStark = 0;
    int minAgeArqueiroSelvagens = 999;
    float maxH_PN_Espadachim = -1.0f;
    char sexMaxH_PN_Espadachim = 'X';

    while (cin >> house) {
        if (house != 'S' && house != 'P' && house != 'C' && house != 'O') {
            break;
        }

        char sex;
        int age;
        float height;
        char ability;

        if (!(cin >> sex >> age >> height >> ability)) break;

        totalSoldiers++;

        if (house == 'C') {
            if (height > maxHeightCV) {
                maxHeightCV = height;
            }
        }

        if (house == 'S' && ability == 'l') {
            countLanceirosStark++;
        }

        if (house == 'O' && ability == 'a') {
            if (age < minAgeArqueiroSelvagens) {
                minAgeArqueiroSelvagens = age;
            }
        }

        if (house == 'P' && ability == 'e') {
            if (height > maxH_PN_Espadachim) {
                maxH_PN_Espadachim = height;
                sexMaxH_PN_Espadachim = sex;
            }
        }
    }

    cout << totalSoldiers << "\n";
    cout << fixed << setprecision(2) << maxHeightCV << "\n";
    cout << countLanceirosStark << "\n";
    cout << minAgeArqueiroSelvagens << "\n";
    cout << sexMaxH_PN_Espadachim << "\n";

    return 0;
}