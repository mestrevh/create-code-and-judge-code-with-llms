/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> reg(8);
    for (int i = 0; i < 8; i++) cin >> reg[i];

    int high = 0, low = 0;
    for (int i = 0; i < 4; i++) high = (high << 1) | reg[i];
    for (int i = 4; i < 8; i++) low = (low << 1) | reg[i];

    int instruction;
    while (true) {
        instruction = 0;
        for (int i = 0; i < 4; i++) {
            int bit;
            cin >> bit;
            instruction = (instruction << 1) | bit;
        }

        if (instruction == 15) break;

        if (instruction == 0) {
            low = 0;
            for (int i = 0; i < 4; i++) {
                int bit;
                cin >> bit;
                low = (low << 1) | bit;
            }
        } else if (instruction == 2) {
            cout << "O registrador tem os seguintes valores:\n";
            cout << "High: " << high << "\n";
            cout << "Low: " << low << "\n";
        } else if (instruction == 5) {
            cout << low * low << "\n";
        } else if (instruction == 8) {
            printf("%X\n", low);
        } else if (instruction == 12) {
            int num;
            cin >> num;
            cout << (low * num) << "\n";
        } else {
            cout << "ERRO: A instrucao nao existe.\n";
        }
    }
    return 0;
}
