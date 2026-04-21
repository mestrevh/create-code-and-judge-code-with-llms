/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string clima;
    if (!getline(cin, clima)) return 0;

    string data;
    getline(cin, data);

    string msg;
    getline(cin, msg);
    if (msg.size() == 0) getline(cin, msg);

    auto sumDigits = [](int x) {
        int s = 0;
        x = abs(x);
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    };

    int dd = 0, mm = 0, yyyy = 0;
    {
        string t = data;
        for (char &c : t) if (c == '\r' || c == '\n') c = ' ';
        dd = stoi(t.substr(0,2));
        mm = stoi(t.substr(3,2));
        yyyy = stoi(t.substr(6,4));
    }

    int key = sumDigits(yyyy) - (sumDigits(dd) + sumDigits(mm));
    key = abs(key);

    string decoded = msg;
    for (char &c : decoded) {
        if (c != ' ') c = char(c - key);
    }

    if (clima == "ensolarado") {
        reverse(decoded.begin(), decoded.end());
        cout << decoded;
        return 0;
    }

    if (clima == "chuvoso") {
        string out;
        out.reserve(decoded.size());
        size_t i = 0;
        while (i < decoded.size()) {
            if (decoded[i] == ' ') {
                out.push_back(' ');
                i++;
                continue;
            }
            size_t j = i;
            while (j < decoded.size() && decoded[j] != ' ') j++;
            int len = int(j - i);
            if (len % 2 == 0) {
                for (size_t k = i; k < j; k++) out.push_back(char(decoded[k] + 1));
            } else {
                for (size_t k = i; k < j; k++) out.push_back(char(decoded[k] - 1));
            }
            i = j;
        }
        cout << out;
        return 0;
    }

    cout << "Mensagem codificada invalida, provavelmente mais uma tentativa dos aliens de nos enganar!";
    return 0;
}