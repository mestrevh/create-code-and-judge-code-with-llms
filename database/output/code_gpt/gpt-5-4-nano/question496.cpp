/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string normalize(string s) {
    for (char &c : s) c = (char)tolower((unsigned char)c);
    string out;
    bool prevSpace = false;
    for (char c : s) {
        if (isspace((unsigned char)c)) {
            if (!prevSpace) out.push_back(' ');
            prevSpace = true;
        } else {
            out.push_back(c);
            prevSpace = false;
        }
    }
    if (!out.empty() && out.front() == ' ') out.erase(out.begin());
    if (!out.empty() && out.back() == ' ') out.pop_back();
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int hotelsJP5 = 0;
    long long sumStarsCG = 0;
    int countCG = 0;
    int pousadasRT = 0;

    for (int i = 0; i < 10; i++) {
        string type, city;
        int stars;
        if (!(cin >> type >> stars >> city)) return 0;

        type = normalize(type);
        city = normalize(city);

        if (type == "hotel" && city == "joão pessoa") hotelsJP5++;
        if (city == "campina grande") {
            sumStarsCG += stars;
            countCG++;
        }
        if (type == "pousada" && city == "rio tinto") pousadasRT++;
    }

    int mediaCG = countCG ? (int)(sumStarsCG / countCG) : 0;

    cout << hotelsJP5 << "\n" << mediaCG << "\n" << pousadasRT;
    return 0;
}