/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: Figurinhas dos Irmãos
 * João gets even sticker series numbers.
 * Maria gets odd sticker series numbers.
 * Count all stickers for each (including repetitions).
 * Sum unique series numbers for each.
 * The winner is the one with the higher unique sum.
 * Constraints: N <= 10,000; Series Number <= 13,000.
 * Time Complexity: O(N)
 * Space Complexity: O(MaxSeriesNumber)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int joaoCount = 0;
    int mariaCount = 0;
    long long joaoSum = 0;
    long long mariaSum = 0;
    
    // Array to track unique series numbers (up to 13,000)
    static bool seen[13001];
    for (int i = 0; i <= 13000; ++i) seen[i] = false;

    for (int i = 0; i < n; ++i) {
        int series;
        if (!(cin >> series)) break;

        if (series % 2 == 0) {
            // João's sticker (Even)
            joaoCount++;
            if (series >= 0 && series <= 13000 && !seen[series]) {
                joaoSum += series;
                seen[series] = true;
            }
        } else {
            // Maria's sticker (Odd)
            mariaCount++;
            if (series >= 0 && series <= 13000 && !seen[series]) {
                mariaSum += series;
                seen[series] = true;
            }
        }
    }

    // Output: J (João's count), M (Maria's count), S (Max unique sum)
    cout << joaoCount << "\n";
    cout << mariaCount << "\n";
    cout << (joaoSum >= mariaSum ? joaoSum : mariaSum) << "\n";

    return 0;
}