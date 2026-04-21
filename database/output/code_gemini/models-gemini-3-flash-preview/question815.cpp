/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ia, ib, fa, fb;
    if (cin >> ia >> ib >> fa >> fb) {
        int presses = 0;
        
        // Switch C2 is the only way to change the state of lamp B.
        // If IB and FB are different, C2 must be pressed an odd number of times.
        // To minimize presses, we press it exactly once if needed.
        if (ib != fb) {
            presses++;
            // Pressing C2 also toggles the state of lamp A.
            ia = 1 - ia;
        }
        
        // Now we check if lamp A's current state matches the desired state FA.
        // If not, we use switch C1 to toggle only lamp A.
        if (ia != fa) {
            presses++;
        }
        
        cout << presses << "\n";
    }

    return 0;
}