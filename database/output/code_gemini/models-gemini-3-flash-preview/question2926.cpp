/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    // Optimization for fast I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Read the first token of the test case. If it's "FIM", stop.
    while (cin >> s && s != "FIM") {
        // Convert the string token to integer representing the number of participants
        int x = stoi(s);
        
        // Use an unordered_map to store participant wishes for O(1) average lookup
        // Each name maps to an unordered_set of 3 gift strings
        unordered_map<string, unordered_set<string>> wishes;
        wishes.reserve(x);

        for (int i = 0; i < x; ++i) {
            string name, p1, p2, p3;
            if (cin >> name >> p1 >> p2 >> p3) {
                wishes[name] = {p1, p2, p3};
            }
        }

        string qn;
        // Process queries until the sentinel string "FIM" is encountered
        while (cin >> qn && qn != "FIM") {
            string qp;
            if (cin >> qp) {
                // Look up the participant in the map
                auto it = wishes.find(qn);
                // If participant exists, check if the gift qp is in their suggestion set
                if (it != wishes.end() && it->second.count(qp)) {
                    cout << "Uhul! Seu amigo secreto vai adorar\n";
                } else {
                    cout << "Tente Novamente!\n";
                }
            }
        }
    }

    return 0;
}