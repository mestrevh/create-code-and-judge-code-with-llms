/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int total_cost = 7;

    if (n > 100) {
        total_cost += (n - 100) * 5;
        n = 100;
    }
    
    if (n > 30) {
        total_cost += (n - 30) * 2;
        n = 30;
    }
    
    if (n > 10) {
        total_cost += (n - 10) * 1;
    }

    cout << total_cost << endl;

    return 0;
}