/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!getline(cin, s)) {
        return 0;
    }

    // Tratar possíveis quebras de linha Windows (\r\n) que o getline possa deixar
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
        s.pop_back();
    }

    int count_a = 0, count_e = 0, count_i = 0, count_o = 0, count_u = 0;
    for (char c : s) {
        char lc = (char)tolower((unsigned char)c);
        if (lc == 'a') count_a++;
        else if (lc == 'e') count_e++;
        else if (lc == 'i') count_i++;
        else if (lc == 'o') count_o++;
        else if (lc == 'u') count_u++;
    }

    int total_vowels = count_a + count_e + count_i + count_o + count_u;
    double percentage = 0.0;
    if (!s.empty()) {
        percentage = (double)total_vowels * 100.0 / s.length();
    }

    cout << "a " << count_a << "\n";
    cout << "e " << count_e << "\n";
    cout << "i " << count_i << "\n";
    cout << "o " << count_o << "\n";
    cout << "u " << count_u << "\n";
    cout << fixed << setprecision(2) << percentage << "%\n";

    return 0;
}