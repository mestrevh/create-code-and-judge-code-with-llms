/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long target;
    // Reading the target value
    if (!(cin >> target)) {
        return 0;
    }

    // Reading the array until EOF
    vector<long long> arr;
    long long value;
    while (cin >> value) {
        arr.push_back(value);
    }

    int n = (int)arr.size();
    int low = 0;
    int high = n - 1;
    int ops = 0;
    int ans_idx = -1;

    // Binary search logic with operation counting
    // The "operations" count includes the final comparison check for the loop condition.
    while (true) {
        ops++;
        // If search range is exhausted
        if (low > high) {
            break;
        }
        
        // Arredondar para baixo is handled naturally by integer division
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            ans_idx = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Output results: Index followed by total operations
    cout << ans_idx << "\n" << ops << endl;

    return 0;
}