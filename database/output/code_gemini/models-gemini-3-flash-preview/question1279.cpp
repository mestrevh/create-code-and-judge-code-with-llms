/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the order of the square matrices
    if (!(cin >> n) || n <= 0) {
        cout << "Vazia" << endl;
        return 0;
    }

    // Using a multidimensional array (vector of vectors) to store the first matrix
    // Using long long to prevent potential overflow during summation
    vector<vector<long long>> matrix(n, vector<long long>(n));

    // Read elements of the first matrix (M1)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(cin >> matrix[i][j])) break;
        }
    }

    // Read elements of the second matrix (M2), sum with M1, and print immediately
    // to keep space complexity O(N^2) and time O(N^2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long element_m2;
            if (!(cin >> element_m2)) break;
            
            // The resulting matrix element
            long long result = matrix[i][j] + element_m2;
            
            // Output the result followed by a newline as per requirements
            cout << result << "\n";
        }
    }

    return 0;
}