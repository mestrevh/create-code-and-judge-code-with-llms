/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        uint32_t low = 0x00000000U;
        uint32_t high = 0xFFFFFFFFU;

        for (int k = 0; k < n; ++k) {
            string cmd;
            cin >> cmd;
            if (cmd == "SET") {
                int i;
                cin >> i;
                low |= (1U << i);
                high |= (1U << i);
            } else if (cmd == "CLEAR") {
                int i;
                cin >> i;
                low &= ~(1U << i);
                high &= ~(1U << i);
            } else if (cmd == "OR") {
                int i, j;
                cin >> i >> j;
                uint32_t bit_j_low = (low >> j) & 1U;
                uint32_t bit_j_high = (high >> j) & 1U;
                
                if (bit_j_low) low |= (1U << i);
                if (bit_j_high) high |= (1U << i);
            } else if (cmd == "AND") {
                int i, j;
                cin >> i >> j;
                uint32_t bit_j_low = (low >> j) & 1U;
                uint32_t bit_j_high = (high >> j) & 1U;

                if (!bit_j_low) low &= ~(1U << i);
                if (!bit_j_high) high &= ~(1U << i);
            }
        }

        for (int i = 31; i >= 0; --i) {
            int bl = (low >> i) & 1U;
            int bh = (high >> i) & 1U;
            if (bl == bh) {
                cout << (bl ? '1' : '0');
            } else {
                cout << '?';
            }
        }
        cout << "\n";
    }

    return 0;
}