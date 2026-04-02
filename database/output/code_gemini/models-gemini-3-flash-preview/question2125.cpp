/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Recursive function to calculate the Demogorgon appearance chance.
 * @param idx: The sequence index starting from 5am (idx 0).
 * @param S: The amount of blood in ml.
 * @return: The accumulated chance.
 */
double calculateChance(int idx, double S) {
    // Base case: Starting hour is 05 am, chance is 5.
    if (idx == 0) return 5.0;

    // Recursive call for the previous hour
    double prev = calculateChance(idx - 1, S);

    // Calculate the actual clock hour (1-12) to determine even/odd rules
    int current_std_h = (idx + 5) % 24;
    int clock_h = current_std_h % 12;
    if (clock_h == 0) clock_h = 12;
    bool is_even = (clock_h % 2 == 0);

    // Sequence rules based on time ranges:
    // idx 1 to 10 corresponds to 06 am to 03 pm
    if (idx >= 1 && idx <= 10) {
        if (is_even) {
            return prev + S / 2.0;
        } else {
            return prev + (double)((long long)prev % 7);
        }
    } 
    // idx 11 to 23 corresponds to 04 pm to 04 am
    else {
        if (is_even) {
            return prev + S;
        } else {
            return prev + (double)((long long)prev % 10);
        }
    }
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H;
    string period;
    double S;

    // Read input: H (hour), period (am/pm), and S (blood amount)
    if (!(cin >> H >> period >> S)) return 0;

    // Validate hour (1-12) and blood amount (non-negative)
    if (H < 1 || H > 12 || S < 0 || (period != "am" && period != "pm")) {
        cout << "Dados Invalidos." << endl;
        return 0;
    }

    // Convert standard clock time to a 24-hour cycle value (0-23)
    int std_h;
    if (period == "am") {
        std_h = (H == 12) ? 0 : H;
    } else { // pm
        std_h = (H == 12) ? 12 : H + 12;
    }

    // Map 24-hour value to a sequence index starting at 5am (index 0)
    int target_idx;
    if (std_h >= 5) {
        target_idx = std_h - 5;
    } else {
        target_idx = std_h + 19;
    }

    // Calculate chance using recursion
    double result = calculateChance(target_idx, S);

    // Output formatting: 1 decimal place
    cout << fixed << setprecision(1);
    cout << "A chance de aparecimento de Demogorgon e de " << result << "%." << endl;

    // Additional warning for high probability
    if (result >= 100.0) {
        cout << "Ou seja, nao olhe para tras." << endl;
    }

    return 0;
}