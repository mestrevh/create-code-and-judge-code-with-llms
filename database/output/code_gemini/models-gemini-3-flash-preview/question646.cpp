/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    while (cin >> n >> l && (n != 0 || l != 0)) {
        vector<int> a(l);
        for (int i = 0; i < l; ++i) {
            cin >> a[i];
        }

        int max_available = 0;
        int j = 0;
        for (int i = 0; i < l; ++i) {
            // Find the furthest locker a[j] that is within the range [a[i], a[i] + n - 1]
            // Any a[j] in this range satisfies a[j] <= a[i] + n - 1, or a[j] < a[i] + n
            while (j < l && a[j] < a[i] + n) {
                j++;
            }
            
            // The number of available lockers in this window is j - i
            int current_available = j - i;
            if (current_available > max_available) {
                max_available = current_available;
            }
        }
        
        // The minimum number of swaps is the number of required lockers minus 
        // the maximum number of lockers already available in a contiguous block of size n.
        cout << n - max_available << "\n";
    }

    return 0;
}