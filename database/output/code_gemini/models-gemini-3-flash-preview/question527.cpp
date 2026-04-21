/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * Prints the vector elements separated by " | ".
 */
void printArr(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : " | ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line) || line.empty()) {
        return 0;
    }

    stringstream ss(line);
    vector<int> v;
    int num;
    while (ss >> num) {
        v.push_back(num);
    }

    int n = static_cast<int>(v.size());
    if (n == 0) return 0;

    // Insertion Sort simulation with step-by-step reporting
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        
        cout << "Chave: " << key << "\n";
        cout << "Estado Atual: ";
        printArr(v);

        int j = i;
        // The algorithm moves the key to the left by swapping until it is in the correct position
        while (j > 0 && v[j - 1] > v[j]) {
            swap(v[j - 1], v[j]);
            printArr(v);
            j--;
        }
        
        // Blank line between one key block and another (or the final result)
        cout << "\n";
    }

    cout << "Resultado Final: ";
    printArr(v);

    return 0;
}