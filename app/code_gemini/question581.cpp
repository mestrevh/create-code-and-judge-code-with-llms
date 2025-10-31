/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long c;
    std::cin >> n >> c;

    long long no_stock_profit = 0;
    long long have_stock_profit = -2000000000000000000LL;

    for (int i = 0; i < n; ++i) {
        long long p;
        std::cin >> p;

        long long prev_no_stock_profit = no_stock_profit;
        
        no_stock_profit = std::max(no_stock_profit, have_stock_profit + p);
        have_stock_profit = std::max(have_stock_profit, prev_no_stock_profit - p - c);
    }

    std::cout << no_stock_profit << '\n';

    return 0;
}
