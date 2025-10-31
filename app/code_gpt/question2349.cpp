/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

unsigned int countOccurrences(int x, const vector<int>& L) {
    unsigned int count = 0;
    for (int num : L) {
        if (num == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int x, n;
    cin >> x >> n;
    vector<int> L(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    cout << countOccurrences(x, L) << endl;
    return 0;
}
