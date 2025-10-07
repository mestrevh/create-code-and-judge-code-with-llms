/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int total_people = D + 4;
    int required_sake = total_people * 4;
    int required_manjus = total_people * 5;
    int required_yakitoris = total_people * 3;

    int available_sake = (A * 675) / 45;
    int available_manjus = B;
    int available_yakitoris = C;

    int faltaram_sake = max(0, required_sake - available_sake);
    int faltaram_manjus = max(0, required_manjus - available_manjus);
    int faltaram_yakitoris = max(0, required_yakitoris - available_yakitoris);

    if (faltaram_sake == 0 && faltaram_manjus == 0 && faltaram_yakitoris == 0) {
        cout << "Partiu Festa do Japa!" << endl;
    } else if (faltaram_sake > 0 && faltaram_manjus > 0 && faltaram_yakitoris > 0) {
        cout << "Partiu Festa do Japa...Japacama" << endl;
    } else {
        if (faltaram_sake > 0 && faltaram_manjus > 0) {
            cout << "Faltaram " << faltaram_sake << " saques e " << faltaram_manjus << " manjus" << endl;
        } else if (faltaram_sake > 0 && faltaram_yakitoris > 0) {
            cout << "Faltaram " << faltaram_sake << " saques e " << faltaram_yakitoris << " yakitoris" << endl;
        } else if (faltaram_manjus > 0 && faltaram_yakitoris > 0) {
            cout << "Faltaram " << faltaram_manjus << " manjus e " << faltaram_yakitoris << " yakitoris" << endl;
        } else if (faltaram_sake > 0) {
            cout << "Faltaram " << faltaram_sake << " saques" << endl;
        } else if (faltaram_manjus > 0) {
            cout << "Faltaram " << faltaram_manjus << " manjus" << endl;
        } else if (faltaram_yakitoris > 0) {
            cout << "Faltaram " << faltaram_yakitoris << " yakitoris" << endl;
        }
    }
    return 0;
}
