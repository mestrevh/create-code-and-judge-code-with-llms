/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: Phone Directory Search
 * Strategy: Store 15 pairs of area codes and phone numbers in a vector.
 * Read a target area code and output matches or a "not found" message.
 * Optimized with fast I/O and O(N) complexity where N is the fixed number of entries (15).
 */

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int TOTAL_ENTRIES = 15;
    vector<pair<string, string>> directory(TOTAL_ENTRIES);

    // Read 15 pairs of area code and phone number
    for (int i = 0; i < TOTAL_ENTRIES; ++i) {
        if (!(cin >> directory[i].first >> directory[i].second)) {
            break;
        }
    }

    // Read the target area code to search for
    string targetCode;
    cin >> targetCode;

    // Output the prompts as requested by the output format/test cases
    for (int i = 0; i < TOTAL_ENTRIES; ++i) {
        cout << "Digite o codigo de area e o telefone:" << "\n";
    }
    cout << "Digite o codigo de area desejado:" << "\n";

    bool found = false;
    bool headerPrinted = false;

    // Search for matches
    for (int i = 0; i < TOTAL_ENTRIES; ++i) {
        if (directory[i].first == targetCode) {
            if (!headerPrinted) {
                cout << "Telefones com o codigo de area " << targetCode << ":" << "\n";
                headerPrinted = true;
            }
            // Print area code and phone as shown in test case 0
            cout << directory[i].first << " " << directory[i].second << "\n";
            found = true;
        }
    }

    // If no results found, print the specific error message
    if (!found) {
        cout << "Nao ha nenhum telefone com o codigo " << targetCode << "\n";
    }

    return 0;
}