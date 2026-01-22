/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> prices(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    int max_profit = 0;
    int min_price = prices[0];

    for (int i = 1; i < N; ++i) {
        max_profit = max(max_profit, prices[i] - min_price - C);
        min_price = min(min_price, prices[i]);
    }

    cout << max(max_profit, 0) << endl;
    return 0;
}
