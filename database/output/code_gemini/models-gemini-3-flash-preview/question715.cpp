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

    int year;
    string era;

    while (cin >> year >> era) {
        if (era == "aC") {
            if (year > 4000) {
                cout << "PRE-HISTORIA" << endl;
            } else {
                cout << "ANTIGUIDADE" << endl;
            }
        } else if (era == "dC") {
            if (year <= 476) {
                cout << "ANTIGUIDADE" << endl;
            } else if (year <= 1453) {
                cout << "IDADE MEDIA" << endl;
            } else if (year <= 1789) {
                cout << "IDADE MODERNA" << endl;
            } else {
                cout << "IDADE CONTEMPORANEA" << endl;
            }
        }
    }

    return 0;
}