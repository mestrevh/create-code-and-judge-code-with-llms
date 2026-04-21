/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

string referencia(string nome) {
    if (nome.empty()) return "";

    stringstream ss(nome);
    string word;
    vector<string> parts;
    while (ss >> word) {
        parts.push_back(word);
    }

    if (parts.empty()) return "";

    string last = parts.back();
    string upper_last = last;
    for (char &c : upper_last) {
        c = (char)toupper((unsigned char)c);
    }

    string result = upper_last + ",";
    for (size_t i = 0; i < parts.size() - 1; ++i) {
        result += " " + parts[i];
    }
    result += ".";

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string full_name;
    if (getline(cin, full_name)) {
        if (!full_name.empty() && full_name.back() == '\r') {
            full_name.pop_back();
        }
        cout << referencia(full_name) << endl;
    }

    return 0;
}