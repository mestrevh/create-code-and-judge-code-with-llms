/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int binToDec4(const string& s) {
    int v = 0;
    for (char c : s) v = (v << 1) + (c - '0');
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> tokens;
    string x;
    while (cin >> x) tokens.push_back(x);

    auto getBits4 = [&](size_t idx) -> string {
        return tokens[idx];
    };
    auto getBits8First = [&]() -> void {
        return;
    };

    size_t i = 0;
    if (tokens.size() < 4) return 0;

    string highBits = tokens[i++];
    string lowBits = tokens[i++];

    int high = binToDec4(highBits);
    int low = binToDec4(lowBits);

    while (true) {
        if (high == 15) break;

        int instr = high;
        if (instr == 0) {
            if (i >= tokens.size()) break;
            string v4 = tokens[i++];
            low = binToDec4(v4);
        } else if (instr == 2) {
            cout << "O registrador tem os seguintes valores:\n";
            cout << "High: " << high << "\n";
            cout << "Low: " << low << "\n";
        } else if (instr == 5) {
            cout << (low * low) << "\n";
        } else if (instr == 8) {
            cout << uppercase << hex << low << nouppercase << dec << "\n";
        } else if (instr == 12) {
            if (i >= tokens.size()) break;
            int a = binToDec4(tokens[i++]);
            cout << (a * low) << "\n";
        } else if (instr == 15) {
            break;
        } else {
            cout << "ERRO: A instrucao nao existe.\n";
        }

        if (i >= tokens.size()) break;
        high = binToDec4(tokens[i++]);
    }

    return 0;
}