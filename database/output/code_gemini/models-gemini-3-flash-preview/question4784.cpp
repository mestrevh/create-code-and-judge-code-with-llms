/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string bit_str;
    if (!(cin >> bit_str)) {
        cout << "Sem bits no momento..." << endl;
        return 0;
    }

    if (bit_str.length() == 0) {
        cout << "Sem bits no momento..." << endl;
        return 0;
    }

    int total_sum = 0;
    int len = (int)bit_str.length();
    for (int i = 0; i + 3 < len; i += 4) {
        int val = 0;
        if (bit_str[i] == '1') val += 8;
        if (bit_str[i + 1] == '1') val += 4;
        if (bit_str[i + 2] == '1') val += 2;
        if (bit_str[i + 3] == '1') val += 1;
        total_sum += val;
    }

    cout << "O codigo de entrada eh: " << total_sum << endl;

    if (n == 0) {
        return 0;
    }

    sort(words.begin(), words.end());

    string suffix = "";
    for (int i = 0; i + 3 < len; i += 4) {
        int val = 0;
        if (bit_str[i] == '1') val += 8;
        if (bit_str[i + 1] == '1') val += 4;
        if (bit_str[i + 2] == '1') val += 2;
        if (bit_str[i + 3] == '1') val += 1;

        if (val > 9) {
            cout << "Numero invalido!" << endl;
        } else {
            suffix += (char)('0' + val);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << words[i] << suffix << endl;
    }

    return 0;
}