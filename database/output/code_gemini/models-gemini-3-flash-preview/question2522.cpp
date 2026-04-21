/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int SIZE = 5;
    vector<int> setA(SIZE);
    
    for (int i = 0; i < SIZE; ++i) {
        if (!(cin >> setA[i])) break;
    }

    unordered_set<int> setB;
    for (int i = 0; i < SIZE; ++i) {
        int val;
        if (cin >> val) {
            setB.insert(val);
        }
    }

    bool first = true;
    for (int i = 0; i < SIZE; ++i) {
        if (setB.count(setA[i])) {
            if (!first) {
                cout << " ";
            }
            cout << setA[i];
            first = false;
        }
    }
    cout << endl;

    return 0;
}