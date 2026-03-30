/*
Código criado pelo models/gemini-3.1-flash-lite-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_prefix(const string& W, const string& S) {
    if (S.length() > W.length()) return false;
    return W.compare(0, S.length(), S) == 0;
}

bool is_suffix(const string& W, const string& S) {
    if (S.length() > W.length()) return false;
    return W.compare(W.length() - S.length(), S.length(), S) == 0;
}

bool is_substring(const string& W, const string& S) {
    return W.find(S) != string::npos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string W;
    getline(cin, W);

    int N;
    cin >> N;
    string buffer;
    getline(cin, buffer);

    for (int i = 0; i < N; ++i) {
        string S;
        getline(cin, S);

        if (is_prefix(W, S)) {
            cout << "PREFIXO" << endl;
        } else if (is_suffix(W, S)) {
            cout << "SUFIXO" << endl;
        } else if (is_substring(W, S)) {
            cout << "SUBPALAVRA" << endl;
        } else {
            cout << "PALAVRA LIVRE" << endl;
        }
    }

    return 0;
}