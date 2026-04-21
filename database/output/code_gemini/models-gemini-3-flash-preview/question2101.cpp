/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * Competitive Programming Solution
 * Problem: Reconstruindo a comunicação
 * Approach: Index mapping for rows and columns to handle swaps efficiently.
 * Complexity: O(N*M + K) for reading matrix, processing commands, and retrieving the target value.
 */

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    int K;
    if (!(cin >> K)) return 0;

    // We use a flat 1D vector to store the N x M matrix to optimize memory and cache locality.
    // The size is N * M, which is typically up to 10^7 elements given the time limit and memory.
    size_t total_elements = (size_t)N * (size_t)M;
    vector<int> matrix(total_elements);
    for (size_t i = 0; i < total_elements; ++i) {
        cin >> matrix[i];
    }

    // Instead of physically swapping row and column contents (which would be O(N) or O(M) per command),
    // we maintain mappings of current indices to original indices.
    vector<int> row_map(N);
    iota(row_map.begin(), row_map.end(), 0); // row_map[i] = i
    
    vector<int> col_map(M);
    iota(col_map.begin(), col_map.end(), 0); // col_map[j] = j

    string command;
    int A, B;
    for (int k = 0; k < K; ++k) {
        if (!(cin >> command >> A >> B)) break;
        
        if (command == "ataque") {
            // "ataque A B" - Swaps Row A content with Row B content
            if (A >= 0 && A < N && B >= 0 && B < N) {
                swap(row_map[A], row_map[B]);
            }
        } else if (command == "defesa") {
            // "defesa A B" - Swaps Column A content with Column B content
            if (A >= 0 && A < M && B >= 0 && B < M) {
                swap(col_map[A], col_map[B]);
            }
        }
    }

    // Target coordinates (I, J) after all swaps
    int I, J;
    if (cin >> I >> J) {
        if (I >= 0 && I < N && J >= 0 && J < M) {
            // Map the requested coordinates back to the original matrix indices
            int original_row = row_map[I];
            int original_col = col_map[J];
            
            // Calculate 1D index and output result
            size_t final_index = (size_t)original_row * (size_t)M + (size_t)original_col;
            cout << matrix[final_index] << endl;
        }
    }

    return 0;
}