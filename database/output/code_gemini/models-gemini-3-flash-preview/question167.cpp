/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long c83 = 0;
    long long c93 = 0;
    long long c0 = 0;
    long long cNulo = 0;
    int vote;

    while (cin >> vote && vote != -1) {
        if (vote == 83) {
            c83++;
        } else if (vote == 93) {
            c93++;
        } else if (vote == 0) {
            c0++;
        } else {
            cNulo++;
        }
    }

    long long total_valid = c83 + c93 + c0;
    
    int winner = 83;
    if (c93 > c83) {
        winner = 93;
    }

    double p83 = 0.0;
    double p93 = 0.0;
    
    if (total_valid > 0) {
        p83 = (double)c83 * 100.0 / (double)total_valid;
        p93 = (double)c93 * 100.0 / (double)total_valid;
    }

    cout << c83 << " " 
         << c93 << " " 
         << c0 << " " 
         << cNulo << " " 
         << winner << " " 
         << fixed << setprecision(2) << p83 << " " 
         << p93 << "\n";

    return 0;
}