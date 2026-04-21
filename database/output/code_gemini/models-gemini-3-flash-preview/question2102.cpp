/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m_in, n_in;
    // Read M (rows) and N (columns)
    if (!(cin >> m_in >> n_in)) return 0;

    // Handle cases where matrix might have zero or negative dimensions
    if (m_in <= 0 || n_in <= 0) return 0;

    size_t rows = static_cast<size_t>(m_in);
    size_t cols = static_cast<size_t>(n_in);
    
    // Use a flat vector to store the matrix for efficiency and simple indexing
    // Original matrix A is rows x cols
    vector<int> mat(rows * cols);
    for (size_t i = 0; i < rows * cols; ++i) {
        if (!(cin >> mat[i])) break;
    }

    // To transpose, we output columns as rows
    // The result matrix will have 'cols' rows and 'rows' columns
    for (size_t j = 0; j < cols; ++j) {
        for (size_t i = 0; i < rows; ++i) {
            // The element at original row i and original column j
            // is stored at index (i * cols + j) in the flat array
            cout << mat[i * cols + j];
            
            // Format output with spaces between numbers, but no trailing space at the end of a line
            if (i < rows - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}