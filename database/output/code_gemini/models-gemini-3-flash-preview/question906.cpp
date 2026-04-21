/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double nums[10];

    for (int i = 0; i < 10; ++i) {
        cout << "Digite um numero:" << "\n";
        if (!(cin >> nums[i])) break;
    }

    for (int i = 9; i >= 0; --i) {
        double val = nums[i];
        long long int_val = (long long)val;
        if (val == (double)int_val) {
            cout << int_val << ".0" << "\n";
        } else {
            cout << val << "\n";
        }
    }

    return 0;
}