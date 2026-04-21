/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Controle de armas (Weapon Control)
 * Strategy: Decision-based logic according to nationality and occupation rules.
 * Nationality: (B)razilian, (E)xotic/Foreigner
 * Occupation: (M)ilitary, (T)ourist, (C)trucker, (O)ther
 * Rules:
 * - Foreigner: Liberated only if qty of weapons == 0.
 * - Brazilian Military: Liberated regardless of qty or caliber.
 * - Brazilian Tourist/Other: Liberated if qty <= 1 and caliber <= 22.
 * - Brazilian Trucker: Liberated if qty <= 2 and caliber <= 38.
 */

int main() {
    // Standard CP optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char nationality, occupation;
    int quantity, caliber;

    // Process input while available (handles single or multiple test cases)
    while (cin >> nationality >> occupation >> quantity >> caliber) {
        bool allowed = false;

        if (nationality == 'E') {
            // Foreigners are only allowed if they carry no weapons
            if (quantity == 0) {
                allowed = true;
            }
        } else if (nationality == 'B') {
            // Brazilians have different rules based on occupation
            if (occupation == 'M') {
                // Military can carry any quantity and any caliber
                allowed = true;
            } else if (occupation == 'T' || occupation == 'O') {
                // Tourist or Other: at most 1 weapon, caliber <= 22
                if (quantity == 0 || (quantity == 1 && caliber <= 22)) {
                    allowed = true;
                }
            } else if (occupation == 'C') {
                // Trucker: at most 2 weapons, caliber <= 38
                if (quantity == 0 || (quantity <= 2 && caliber <= 38)) {
                    allowed = true;
                }
            }
        }

        // Final determination
        if (allowed) {
            cout << "Liberado\n";
        } else {
            cout << "Barrado\n";
        }
    }

    return 0;
}