/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

string makeGoodString(const string &s) {
    string result;
    for (char c : s) {
        if (result.empty() || result.back() != c) {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string S;
        getline(cin, S);
        cout << makeGoodString(S) << endl;
    }
    return 0;
}
