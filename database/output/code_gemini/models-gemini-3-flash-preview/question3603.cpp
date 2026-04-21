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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line1, line2;
    if (!getline(cin, line1)) return 0;
    if (!getline(cin, line2)) {
        // Continue to process line1 if line2 is missing or empty
    }

    vector<int> x, y;
    int val;
    
    stringstream ss1(line1);
    while (ss1 >> val) {
        x.push_back(val);
    }
    
    stringstream ss2(line2);
    while (ss2 >> val) {
        y.push_back(val);
    }

    bool sorted = true;
    for (size_t i = 1; i < x.size(); ++i) {
        if (x[i] < x[i-1]) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        for (size_t i = 1; i < y.size(); ++i) {
            if (y[i] < y[i-1]) {
                sorted = false;
                break;
            }
        }
    }

    if (!sorted) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> z;
    z.reserve(x.size() + y.size());
    
    size_t i = 0, j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] < y[j]) {
            z.push_back(x[i++]);
        } else {
            z.push_back(y[j++]);
        }
    }
    
    while (i < x.size()) z.push_back(x[i++]);
    while (j < y.size()) z.push_back(y[j++]);

    for (size_t k = 0; k < z.size(); ++k) {
        cout << z[k] << (k == z.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}