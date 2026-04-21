/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int age;
    int sarampo = 0;
    int hepatite = 0;
    int ambas = 0;

    while (cin >> age && age != 100) {
        bool s = (age >= 3 && age <= 6);
        bool h = (age >= 5 && age <= 8);
        
        if (s) {
            sarampo++;
        }
        if (h) {
            hepatite++;
        }
        if (s && h) {
            ambas++;
        }
    }

    cout << sarampo << "\n" << hepatite << "\n" << ambas << "\n";

    return 0;
}