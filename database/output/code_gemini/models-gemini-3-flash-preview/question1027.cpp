/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> names(n);
    unordered_map<string, int> nameToIndex;
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        nameToIndex[names[i]] = i;
    }

    vector<double> balances(n, 0.0);
    string input;
    while (cin >> input && input != "FIM") {
        char op;
        double val;
        cin >> op >> val;
        if (nameToIndex.find(input) != nameToIndex.end()) {
            int idx = nameToIndex[input];
            if (op == 'C') {
                balances[idx] += val;
            } else if (op == 'P') {
                balances[idx] -= val;
            }
        }
    }

    int above100 = 0;
    int zeroDebt = 0;
    double totalDebt = 0;
    double maxDebtVal = -1.0;
    string maxDebtorName = "";

    for (int i = 0; i < n; ++i) {
        if (balances[i] > 100.0000001) {
            above100++;
        }
        if (balances[i] < 0.0000001 && balances[i] > -0.0000001) {
            zeroDebt++;
        }
        totalDebt += balances[i];
        if (balances[i] > maxDebtVal) {
            maxDebtVal = balances[i];
            maxDebtorName = names[i];
        }
    }

    if (maxDebtVal < 0) maxDebtVal = 0.0;

    cout << "Contas acima de 100 reais: " << above100 << "\n";
    cout << "Contas sem dividas: " << zeroDebt << "\n";
    cout << fixed << setprecision(2);
    cout << "Soma das dividas: R$ " << totalDebt << "\n";
    cout << "Maior divida: " << maxDebtorName << " - R$ " << maxDebtVal << endl;

    return 0;
}