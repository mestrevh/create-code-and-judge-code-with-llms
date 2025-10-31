/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int total_cost = 0;
    string pyramid;

    for (int i = 0; i < n; ++i) {
        string line(n - i - 1, '.');
        for (int j = 0; j <= i; ++j) {
            if (j > 0) {
                line += '-';
                total_cost += 50;
            }
            line += '&';
            total_cost += 200;
        }
        line += string(n - i - 1, '.');
        pyramid += line + '\n';
    }

    pyramid += string(n, '#') + '\n';
    total_cost += 100 * n;

    cout << pyramid;
    cout << "O valor total foi: " << total_cost << endl;

    return 0;
}
