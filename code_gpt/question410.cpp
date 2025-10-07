/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; ++i)
        cin >> prices[i];

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; ++i) {
        if(prices[i] < minPrice)
            minPrice = prices[i];
        else
            maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    cout << maxProfit << endl;
    return 0;
}
