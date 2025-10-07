/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int F;
    while (cin >> F) {
        vector<string> names(F);
        int countD = 0, countR = 0;

        for (int i = 0; i < F; i++) {
            cin >> names[i];
            countD += count(names[i].begin(), names[i].end(), 'D');
            countR += count(names[i].begin(), names[i].end(), 'R');
        }

        int maxPairs = min(countD, countR);
        cout << maxPairs << endl;
    }
    return 0;
}
