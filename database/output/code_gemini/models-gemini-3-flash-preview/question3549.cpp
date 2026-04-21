/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    if (!(cin >> A >> B)) return 0;
    
    int C;
    long long D, E;
    if (!(cin >> C >> D >> E)) return 0;

    long long total_budget = A + B;
    long long raw_cost = D * E;
    
    double final_cost;
    if (C == 0) {
        // 5% discount means 95% of the price
        final_cost = (double)raw_cost * 0.95;
    } else {
        // 15% discount means 85% of the price
        final_cost = (double)raw_cost * 0.85;
    }

    // Using a small epsilon for floating point comparison safety, 
    // though for these specific percentages and integer inputs, 
    // a direct comparison usually suffices.
    if (final_cost <= (double)total_budget + 1e-9) {
        cout << "Faz um Ifood!" << endl;
    } else {
        cout << "pede menos que as esfihas nao vao acabar hoje!" << endl;
    }

    return 0;
}