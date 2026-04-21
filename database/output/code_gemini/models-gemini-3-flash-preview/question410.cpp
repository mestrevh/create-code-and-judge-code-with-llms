/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem: Maximum Profit with One Transaction
 * Constraints: 1 <= n <= 100,000
 * Time Limit: 1 second
 * Complexity: O(n) Time, O(1) Space (excluding input storage if needed)
 * 
 * Strategy: Iterate through the price list, keeping track of the minimum 
 * price seen so far. For each new price, calculate the potential profit 
 * (current price - min price) and update the maximum profit found.
 */

int main() {
    // Optimize standard I/O for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read n, the number of days
    if (!(cin >> n)) {
        return 0;
    }

    // Edge case: n = 0 or 1 (no profit possible with 1 transaction)
    if (n < 1) {
        return 0;
    }
    if (n == 1) {
        int temp;
        cin >> temp;
        cout << 0 << endl;
        return 0;
    }

    // Initialize the first price as the minimum seen so far
    long long first_price;
    cin >> first_price;

    long long min_price = first_price;
    long long max_profit = 0;
    long long current_price;

    // Iterate through the remaining n-1 prices
    for (int i = 1; i < n; ++i) {
        if (!(cin >> current_price)) break;

        // If current price is lower than our historical min, update it
        if (current_price < min_price) {
            min_price = current_price;
        } else {
            // Otherwise, calculate profit if we sold today
            long long current_profit = current_price - min_price;
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        }
    }

    // Output the maximum profit found
    cout << max_profit << endl;

    return 0;
}