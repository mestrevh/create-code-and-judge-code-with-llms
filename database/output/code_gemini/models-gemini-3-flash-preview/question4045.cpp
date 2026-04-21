/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Multiplas entradas e eof: Read n until EOF
    while (cin >> n) {
        // Text is an n x n matrix of strings
        // Each string can be up to 25 characters
        vector<vector<string>> matrix(n, vector<string>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        // X palavras de interesse (queries), indefinite number until EOF
        string query;
        while (cin >> query) {
            // Check if the current query is actually the 'n' for the next test case
            // This is a safety measure for "multiplas entradas" if queries are not specified
            bool isNextN = true;
            if (query.length() > 0) {
                for (char c : query) {
                    if (!isdigit(c)) {
                        isNextN = false;
                        break;
                    }
                }
            } else {
                isNextN = false;
            }

            // In most ICPC-style problems with indefinite queries, we assume query until EOF
            // If the format suggests n can appear again, we'd handle it here.
            // For this specific problem, we treat the rest of the file as queries.
            
            bool foundAny = false;
            bool first = true;
            
            // Search for the word (or part of it) in the matrix in row-major order
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    // find() returns string::npos if the substring is not found
                    // Case-sensitive search as per constraints
                    if (matrix[i][j].find(query) != string::npos) {
                        if (!first) cout << " ";
                        cout << "(" << i << "," << j << ")";
                        first = false;
                        foundAny = true;
                    }
                }
            }
            
            // Output format: all positions of a word on one line
            if (foundAny) {
                cout << "\n";
            }
        }
    }

    return 0;
}