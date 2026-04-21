/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string to_lower(string s) {
    for (char &c : s) {
        c = (char)tolower((unsigned char)c);
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int countJP5 = 0;
    int sumCG = 0;
    int countCG = 0;
    int countRT = 0;

    for (int i = 0; i < 10; ++i) {
        string type, city;
        int stars;

        if (!(cin >> type)) break;
        cin >> stars;
        getline(cin >> ws, city);

        type = to_lower(type);
        city = to_lower(city);

        if (type == "hotel" && city == "joão pessoa" && stars == 5) {
            countJP5++;
        }

        if (city == "campina grande") {
            sumCG += stars;
            countCG++;
        }

        if (type == "pousada" && city == "rio tinto") {
            countRT++;
        }
    }

    int avgCG = 0;
    if (countCG > 0) {
        avgCG = sumCG / countCG;
    }

    cout << countJP5 << "\n";
    cout << avgCG << "\n";
    cout << countRT << endl;

    return 0;
}