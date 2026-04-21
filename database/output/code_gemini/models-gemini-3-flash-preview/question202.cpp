/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Minimum Arithmetic Progression Partitioning
 * Strategy: Greedy approach. Any sequence of length 1 or 2 is an AP.
 * We can define an AP with the first two elements and extend it as far as possible.
 * Once the common difference changes, we start a new AP.
 */

int main() {
    // Optimize C++ I/O performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // Constraints: 1 <= N <= 100,000
    if (N <= 0) return 0;

    // Handle N=1 explicitly to simplify logic
    if (N == 1) {
        int val;
        cin >> val;
        cout << 1 << endl;
        return 0;
    }

    // Storage for the sequence
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int count = 0;
    int i = 0;
    
    // Greedy partitioning:
    while (i < N) {
        count++;
        
        // If there is only one element left, it must be its own AP.
        if (i + 1 >= N) {
            i++;
            break;
        }
        
        // Two elements A[i] and A[i+1] define a common difference 'd'.
        // This pair always forms a valid AP.
        int d = A[i + 1] - A[i];
        i += 2;
        
        // Extend the current AP as far as possible.
        // Elements are part of the AP as long as the step between 
        // consecutive terms remains equal to 'd'.
        while (i < N && A[i] - A[i - 1] == d) {
            i++;
        }
        
        // When the condition fails, we move to start a new AP from index 'i'.
    }

    // Output the total number of partitions found.
    cout << count << endl;

    return 0;
}