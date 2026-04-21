/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int idade;
    string porte;

    if (!(cin >> idade >> porte)) {
        return 0;
    }

    // Convert the first character to lowercase to handle case-insensitivity
    // and possible accents in "médio" by just checking the first letter.
    char s = tolower(porte[0]);

    int idadeHumana = 0;

    // The logic is based on the dog age scale where:
    // Pequeno: 1st year = 5, subsequent years = +8 (e.g., 3 years = 21)
    // Médio:   1st year = 8, subsequent years = +7 (e.g., 3 years = 22)
    // Grande:  1st year = 10, subsequent years = +7 (e.g., 5 years = 38)
    // This matches the test cases provided and the description range for 3 years (21-27).
    if (s == 'p') {
        idadeHumana = 5 + (idade - 1) * 8;
    } else if (s == 'm') {
        idadeHumana = 8 + (idade - 1) * 7;
    } else if (s == 'g') {
        idadeHumana = 10 + (idade - 1) * 7;
    }

    cout << idadeHumana << endl;

    return 0;
}