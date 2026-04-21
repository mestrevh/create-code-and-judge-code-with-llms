/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> tokens;
    string temp;
    // Reading all input tokens as the item name can contain spaces and the duration is the last part
    while (cin >> temp) {
        tokens.push_back(temp);
    }

    // Safety check for empty or insufficient input
    if (tokens.size() < 2) return 0;

    // The last token is the duration in years (integer)
    int years = stoi(tokens.back());
    tokens.pop_back();

    // Combine remaining tokens into a single lowercase string for case-insensitive matching
    string itemName = "";
    for (const string& t : tokens) {
        for (char c : t) {
            itemName += (char)tolower((unsigned char)c);
        }
    }

    /*
     * Pricing and logic:
     * - Jornal Mural: R$ 200.00
     * - Jornal O Coreto: R$ 235.00
     * - Revista Meu Lar: R$ 180.00 (10% discount)
     * - Revista Sua Mesa: R$ 230.00 (10% discount)
     */
    double unitPrice = 0;
    if (itemName.find("mural") != string::npos) {
        unitPrice = 200.0;
    } else if (itemName.find("coreto") != string::npos) {
        unitPrice = 235.0;
    } else if (itemName.find("lar") != string::npos) {
        unitPrice = 180.0 * 0.9; // Applying 10% discount for magazine
    } else if (itemName.find("mesa") != string::npos) {
        unitPrice = 230.0 * 0.9; // Applying 10% discount for magazine
    }

    // Output formatted to two decimal places
    cout << fixed << setprecision(2) << (double)years * unitPrice << endl;

    return 0;
}