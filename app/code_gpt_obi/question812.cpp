/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, test = 1;
    while (cin >> N && N != 0) {
        vector<int> saldo(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            int x, y;
            cin >> x >> y;
            saldo[i] = (x - y);
        }
        int max_sum = -1e9, sum = 0, start = 1, bestA = 1, bestB = 1, len = 0;
        int currA = 1;
        bool found = false;
        sum = 0;
        for (int i = 1; i <= N; ++i) {
            sum += saldo[i];
            if (sum > max_sum || (sum == max_sum && (i - currA > len))) {
                max_sum = sum;
                bestA = currA;
                bestB = i;
                len = i - currA;
                found = true;
            }
            if (sum < 0) {
                sum = 0;
                currA = i + 1;
            }
        }
        cout << "Teste " << test++ << endl;
        if (found && max_sum > 0)
            cout << bestA << " " << bestB << endl;
        else
            cout << "nenhum" << endl;
        cout << endl;
    }
    return 0;
}
