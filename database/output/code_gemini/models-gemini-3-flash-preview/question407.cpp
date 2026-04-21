/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

static int memo[1000001];

int get_cycle(long long n) {
    if (n == 1) return 1;
    if (n <= 1000000 && memo[n] != 0) return memo[n];
    
    long long next_n = (n % 2 != 0) ? (3 * n + 1) : (n / 2);
    int res = 1 + get_cycle(next_n);
    
    if (n <= 1000000) memo[n] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int i, j;
    while (cin >> i >> j) {
        int low = i, high = j;
        if (low > high) {
            int temp = low;
            low = high;
            high = temp;
        }
        
        int max_len = 0;
        for (int k = low; k <= high; ++k) {
            int current_len = get_cycle(k);
            if (current_len > max_len) {
                max_len = current_len;
            }
        }
        
        cout << i << " " << j << " " << max_len << "\n";
    }
    
    return 0;
}