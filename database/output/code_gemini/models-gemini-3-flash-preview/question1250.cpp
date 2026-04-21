/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        long long v1, v2, d1, d2;
        if (!(cin >> v1 >> v2 >> d1 >> d2)) break;

        bool win = false;
        
        for (long long s = 0; s * d2 < v1; ++s) {
            long long cur_d1 = d1 + 50 * s;
            
            if (cur_d1 >= v2) {
                win = true;
                break;
            }
            
            long long a = (v2 + cur_d1 - 1) / cur_d1;
            
            if (v1 > (s + a - 1) * d2) {
                win = true;
                break;
            }
        }

        if (win) {
            cout << "Clodes\n";
        } else {
            cout << "Bezaliel\n";
        }
    }

    return 0;
}