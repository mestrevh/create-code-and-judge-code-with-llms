/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxPairs(const string &rna) {
    vector<int> bCount(rna.size() + 1, 0);
    vector<int> sCount(rna.size() + 1, 0);
    vector<int> cCount(rna.size() + 1, 0);
    vector<int> fCount(rna.size() + 1, 0);

    for (int i = 0; i < rna.size(); ++i) {
        bCount[i + 1] = bCount[i] + (rna[i] == 'B');
        sCount[i + 1] = sCount[i] + (rna[i] == 'S');
        cCount[i + 1] = cCount[i] + (rna[i] == 'C');
        fCount[i + 1] = fCount[i] + (rna[i] == 'F');
    }

    int pairs = 0;
    for (int i = 0; i < rna.size(); ++i) {
        if (rna[i] == 'B') {
            pairs += min(sCount[rna.size()] - sCount[i + 1], 1);
        } else if (rna[i] == 'C') {
            pairs += min(fCount[rna.size()] - fCount[i + 1], 1);
        }
    }

    return pairs;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "Z") break;
        cout << maxPairs(line) << endl;
    }
    return 0;
}
