/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string clima;
    if (!(cin >> clima)) return 0;

    string data;
    if (!(cin >> data)) return 0;

    string mensagem;
    // Consume the leading whitespace and read the message
    getline(cin >> ws, mensagem);

    // Step 2: Parse data and calculate key
    // Expected format: xx/xx/xxxx
    if (data.length() >= 10) {
        int soma_dia = (data[0] - '0') + (data[1] - '0');
        int soma_mes = (data[3] - '0') + (data[4] - '0');
        int soma_ano = (data[6] - '0') + (data[7] - '0') + (data[8] - '0') + (data[9] - '0');
        int chave = abs(soma_ano - (soma_dia + soma_mes));

        // Step 2: Apply subtraction of key (except spaces)
        for (int i = 0; i < (int)mensagem.length(); i++) {
            if (mensagem[i] != ' ') {
                mensagem[i] = (char)(mensagem[i] - chave);
            }
        }
    }

    // Step 3: Perform climate-based transformation
    if (clima == "ensolarado") {
        reverse(mensagem.begin(), mensagem.end());
        cout << mensagem << endl;
    } else if (clima == "chuvoso") {
        for (int i = 0; i < (int)mensagem.length(); ) {
            if (mensagem[i] == ' ') {
                i++;
                continue;
            }
            int j = i;
            while (j < (int)mensagem.length() && mensagem[j] != ' ') {
                j++;
            }
            int len = j - i;
            for (int k = i; k < j; k++) {
                if (len % 2 == 0) {
                    mensagem[k] = (char)(mensagem[k] + 1);
                } else {
                    mensagem[k] = (char)(mensagem[k] - 1);
                }
            }
            i = j;
        }
        cout << mensagem << endl;
    } else {
        cout << "Mensagem codificada invalida, provavelmente mais uma tentativa dos aliens de nos enganar!" << endl;
    }

    return 0;
}