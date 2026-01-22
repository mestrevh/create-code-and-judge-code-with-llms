/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; i++) {
            cin >> items[i].first >> items[i].second; // Preço e Peso
        }
        int G;
        cin >> G;
        vector<int> maxWeights(G);
        for (int i = 0; i < G; i++) {
            cin >> maxWeights[i]; // Peso máximo que cada pessoa pode carregar
        }

        vector<int> dp(31, 0); // DP para peso máximo de 30
        for (auto &item : items) {
            int price = item.first;
            int weight = item.second;
            for (int j = 30; j >= weight; j--) {
                dp[j] = max(dp[j], dp[j - weight] + price);
            }
        }

        int total = 0;
        for (int mw : maxWeights) {
            total += dp[mw]; // Soma o valor máximo para cada peso máximo
        }
        
        cout << total << endl;
    }
    return 0;
}
