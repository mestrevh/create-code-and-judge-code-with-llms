/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int countOccurrences(const vector<string>& matrix, const string& word, int n, int m) {
    int count = 0;
    int wordLen = word.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + wordLen <= n) // vertical down
                count += (matrix[i].substr(j, wordLen) == word);
            if (i - wordLen >= -1) // vertical up
                count += (matrix[i].substr(j, wordLen) == word);
            if (j + wordLen <= m) // horizontal right
                count += (matrix[i].substr(j, wordLen) == word);
            if (j - wordLen >= -1) // horizontal left
                count += (matrix[i].substr(j, wordLen) == word);
        }
    }
    return count;
}

int main() {
    int Q, X, C, N, M;
    cin >> Q >> X >> C >> N >> M;
    
    vector<string> names(C);
    for (int i = 0; i < C; ++i) {
        cin >> names[i];
    }

    cin.ignore();
    int validCount = 0;

    for (int q = 0; q < Q; ++q) {
        vector<string> matrix(N);
        for (int i = 0; i < N; ++i) {
            getline(cin, matrix[i]);
        }
        
        int totalOccurrences = 0;
        for (const string& name : names) {
            string loweredName = name;
            transform(loweredName.begin(), loweredName.end(), loweredName.begin(), ::tolower);
            totalOccurrences += countOccurrences(matrix, loweredName, N, M);
        }

        if (totalOccurrences <= X) ++validCount;

        cin.ignore();
    }

    cout << validCount << endl;
    return 0;
}
