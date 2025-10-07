/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int bin_to_dec(string bin) {
    int dec = 0;
    for (int i = 0; i < bin.length(); i++) {
        if (bin[i] == '1') {
            dec += (1 << (bin.length() - 1 - i));
        }
    }
    return dec;
}

int main() {
    int n;
    cin >> n;

    vector<string> palavras(n);
    for (int i = 0; i < n; i++) {
        cin >> palavras[i];
    }

    string bits;
    cin >> bits;

    if (bits.empty()) {
        cout << "Sem bits no momento..." << endl;
        return 0;
    }

    string senha = "";
    int codigo = 0;
    for (int i = 0; i < bits.length(); i += 4) {
        if (i + 4 > bits.length()) {
            break;
        }
        string num_bin = bits.substr(i, 4);
        int num = bin_to_dec(num_bin);
        codigo += num;
        if (num > 9) {
            cout << "Numero invalido!" << endl;
        }
        senha += to_string(num);
    }

    cout << "O codigo de entrada eh: " << codigo << endl;

    if (n > 0) {
        sort(palavras.begin(), palavras.end());
        for (int i = 0; i < n; i++) {
            cout << palavras[i] + senha << endl;
        }
    }

    return 0;
}
