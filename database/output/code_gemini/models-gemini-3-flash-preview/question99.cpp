/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Sprinkler {
    int id;
    double temp;
    char smoke;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numTestCases;
    if (!(cin >> numTestCases)) return 0;

    for (int t = 1; t <= numTestCases; ++t) {
        int n;
        if (!(cin >> n)) break;

        vector<Sprinkler> sprinklers(n);
        double sumTemp = 0;
        for (int i = 0; i < n; ++i) {
            cin >> sprinklers[i].id >> sprinklers[i].temp >> sprinklers[i].smoke;
            sumTemp += sprinklers[i].temp;
        }

        double avgTemp = 0;
        if (n > 0) {
            avgTemp = sumTemp / (double)n;
        }
        
        // A condition for safety is that the temperature variation must be up to 15% 
        // relative to the average and always in the upward direction. 
        // This is interpreted as: Fire is triggered if (Temp > Avg * 1.15).
        // If Temp <= Avg, it's not a "variation for more", so it's safe.
        double limitTemp = avgTemp * 1.15;

        cout << "TESTE " << t << "\n";
        for (int i = 0; i < n; ++i) {
            bool isFire = false;

            // Safe conditions:
            // 1. No smoke (smoke == 'N')
            // 2. Temp variation <= 15% (only for more than average)
            // 3. Temp < 40
            
            // Fire conditions (negation of safe):
            if (sprinklers[i].smoke == 'S') {
                isFire = true;
            } else if (sprinklers[i].temp >= 40.0) {
                isFire = true;
            } else if (sprinklers[i].temp > limitTemp + 1e-9) {
                isFire = true;
            }

            if (isFire) {
                cout << sprinklers[i].id << "\n";
            }
        }
    }

    return 0;
}