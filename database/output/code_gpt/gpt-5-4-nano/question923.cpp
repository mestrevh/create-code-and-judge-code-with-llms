/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> questions = {
        "Telefonou para a vitima?",
        "Esteve no local do crime?",
        "Mora perto da vitima?",
        "Devia para a vitima?",
        "Ja trabalhou com a vitima?"
    };

    int yesCount = 0;
    for (int i = 0; i < 5; i++) {
        cout << questions[i] << "\n";
        string s;
        if (!(cin >> s)) return 0;
        for (auto &ch : s) ch = tolower((unsigned char)ch);
        if (s == "true" || s == "1" || s == "sim") yesCount++;
    }

    string classification;
    if (yesCount == 2) classification = "Suspeita";
    else if (yesCount >= 3 && yesCount <= 4) classification = "Cumplice";
    else if (yesCount == 5) classification = "Assassino";
    else classification = "Inocente";

    cout << classification;
    return 0;
}