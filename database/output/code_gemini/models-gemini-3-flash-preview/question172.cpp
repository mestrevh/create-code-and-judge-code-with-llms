/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Simulador
 * Memory size N up to 10^9, instructions M up to 3000.
 * Two operations: Inversion (I X Y) and Sum (S X Y).
 * 
 * Strategy: Since N is large but M is small, we use coordinate compression-like
 * technique with a vector of ranges. Each range represents a contiguous
 * segment of the memory, which can be either in original ascending order
 * or reversed order.
 * 
 * Each inversion or sum operation splits existing ranges and manipulates them.
 * Total ranges generated is at most 4 * M + 1.
 * Time complexity: O(M^2) which easily fits in 10s.
 */

struct Range {
    long long L, R;
    
    // Returns the number of elements in this range segment.
    long long size() const {
        return (L <= R ? R - L + 1 : L - R + 1);
    }
    
    // Returns the sum of the elements in this range segment using AP formula.
    long long sum() const {
        return (L + R) * size() / 2;
    }
};

vector<Range> memory;

/**
 * split(k) ensures that there is a boundary between range segments 
 * after the k-th element of the total memory.
 */
void split(long long k, long long N) {
    if (k <= 0 || k >= N) return;
    long long current_pos = 0;
    for (int i = 0; i < (int)memory.size(); ++i) {
        long long sz = memory[i].size();
        if (current_pos + sz > k) {
            // Found the range that contains the k-th position.
            // If k is already at the beginning of a range, no split needed.
            if (current_pos == k) return;
            
            long long cut = k - current_pos;
            Range r1 = memory[i];
            Range r2 = memory[i];
            
            // Adjust boundaries of the split segments based on orientation.
            if (r1.L <= r1.R) {
                r1.R = r1.L + cut - 1;
                r2.L = r1.L + cut;
            } else {
                r1.R = r1.L - cut + 1;
                r2.L = r1.L - cut;
            }
            
            memory[i] = r1;
            memory.insert(memory.begin() + i + 1, r2);
            return;
        }
        current_pos += sz;
    }
}

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    int M;
    if (!(cin >> N >> M)) return 0;

    // Initially, one range covering everything [1, N]
    memory.push_back({1, N});

    while (M--) {
        char op;
        long long X, Y;
        if (!(cin >> op >> X >> Y)) break;
        if (X > Y) swap(X, Y);

        // Ensure boundaries at X-1 and Y
        split(X - 1, N);
        split(Y, N);

        // Find which range indices correspond to memory addresses [X, Y]
        int idx1 = -1, idx2 = -1;
        long long current_pos = 0;
        for (int i = 0; i < (int)memory.size(); ++i) {
            long long sz = memory[i].size();
            if (current_pos == X - 1) idx1 = i;
            if (current_pos + sz == Y) {
                idx2 = i;
                if (idx1 != -1) break;
            }
            current_pos += sz;
        }

        if (op == 'I') {
            // Inversion: Reverse the sequence of ranges and flip each range's orientation
            reverse(memory.begin() + idx1, memory.begin() + idx2 + 1);
            for (int i = idx1; i <= idx2; ++i) {
                swap(memory[i].L, memory[i].R);
            }
        } else if (op == 'S') {
            // Sum: Aggregate the sum of all ranges within the identified block
            long long total_sum = 0;
            for (int i = idx1; i <= idx2; ++i) {
                total_sum += memory[i].sum();
            }
            cout << total_sum << "\n";
        }
    }

    return 0;
}