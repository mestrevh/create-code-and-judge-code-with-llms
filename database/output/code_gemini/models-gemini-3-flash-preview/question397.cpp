/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long total_people = 0;
    double total_extra_cost = 0.0;

    while (cin >> n && n >= 0) {
        int guests = n;
        if (guests > 25) {
            guests = 25;
        }
        
        total_people += (1 + guests);
        
        if (guests > 15) {
            int extra = guests - 15;
            total_extra_cost += extra * 42.0;
        }
    }

    cout << fixed << setprecision(2) << total_extra_cost << "\n";
    cout << total_people << endl;

    return 0;
}