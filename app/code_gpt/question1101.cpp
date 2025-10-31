/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

int main() {
    int totalSoldiers = 0, lanceirosStark = 0;
    float maxHeightCavaleirosVale = 0.0, youngestArqueiroSelvagens = numeric_limits<float>::max();
    char sexoEspadachimMaisAltoPatrulha = 'X';
    float height;
    int age;
    char house, sex, skill;

    while (true) {
        cin >> house;
        if (house != 'S' && house != 'P' && house != 'C' && house != 'O') break;

        cin >> sex >> age >> height >> skill;
        totalSoldiers++;

        if (house == 'C') {
            if (height > maxHeightCavaleirosVale) maxHeightCavaleirosVale = height;
        }
        if (house == 'S') {
            if (skill == 'l') lanceirosStark++;
        }
        if (house == 'O' && skill == 'a') {
            if (age < youngestArqueiroSelvagens) youngestArqueiroSelvagens = age;
        }
        if (house == 'P' && skill == 'e') {
            if (sexoEspadachimMaisAltoPatrulha == 'X' || height > heightEspadachimMaisAltoPatrulha) {
                sexoEspadachimMaisAltoPatrulha = sex;
                heightEspadachimMaisAltoPatrulha = height;
            }
        }
    }

    cout << totalSoldiers << endl;
    cout << fixed << setprecision(2) << maxHeightCavaleirosVale << endl;
    cout << lanceirosStark << endl;
    cout << (youngestArqueiroSelvagens == numeric_limits<float>::max() ? 999 : static_cast<int>(youngestArqueiroSelvagens)) << endl;
    cout << sexoEspadachimMaisAltoPatrulha << endl;

    return 0;
}
