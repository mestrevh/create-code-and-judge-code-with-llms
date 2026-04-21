/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, D, K, P;
    
    if (cin >> L >> D >> K >> P) {
        long long travel_cost = L * K;
        long long toll_count = L / D;
        long long toll_cost = toll_count * P;
        
        long long total_cost = travel_cost + toll_cost;
        
        cout << total_cost << "\n";
    }

    return 0;
}