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

    int N;
    if (!(cin >> N)) return 0;

    int max_nocautes = -1;
    int best_event = 1;

    for (int i = 1; i <= N; ++i) {
        int x;
        if (!(cin >> x)) break;
        int current_nocautes = 0;
        for (int j = 0; j < x; ++j) {
            string dName, aName;
            int dG, dS, dC, aG, aS, aC;
            if (!(cin >> dName >> dG >> dS >> dC >> aName >> aG >> aS >> aC)) break;

            string winner, method;
            // Criterion 1: Desafiante Grappling vs Defensor Striking
            if (aG > dS) {
                winner = aName;
                method = "submissao";
            } else if (dS > aG) {
                winner = dName;
                method = "nocaute";
                current_nocautes++;
            }
            // Criterion 2: Desafiante Striking vs Defensor Grappling
            else if (aS > dG) {
                winner = aName;
                method = "nocaute";
                current_nocautes++;
            } else if (dG > aS) {
                winner = dName;
                method = "submissao";
            }
            // Criterion 3: Cardio Decision
            else if (aC > dC) {
                winner = aName;
                method = "decisao";
            } else {
                // Criterion 4: Defensor wins by decision if all attributes equal or Cd > Ca
                winner = dName;
                method = "decisao";
            }
            cout << winner << " ganhou por " << method << "\n";
        }
        
        // Find best event based on most nocautes (first event if tied)
        if (current_nocautes > max_nocautes) {
            max_nocautes = current_nocautes;
            best_event = i;
        }
    }
    
    cout << "Melhor evento foi " << best_event << endl;

    return 0;
}