/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int age;
    string continue_str;
    long long total_diapers = 0;

    while (cin >> age >> continue_str) {
        if (age <= 2) {
            total_diapers += (9 * 30);
        } else {
            total_diapers += (6 * 30);
        }

        string temp = continue_str;
        for (auto &c : temp) {
            c = tolower((unsigned char)c);
        }

        // Standard comparison for "não" in common encodings (UTF-8/Latin1)
        // and "nao" as a safety fallback.
        if (temp == "não" || temp == "nao") {
            break;
        }
    }

    long long packs = (total_diapers + 99) / 100;
    long long remainder = (packs * 100) - total_diapers;

    cout << packs << "\n" << remainder << endl;

    return 0;
}