/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string trim(const string& s) {
    size_t i = 0, j = s.size();
    while (i < j && isspace((unsigned char)s[i])) i++;
    while (j > i && isspace((unsigned char)s[j - 1])) j--;
    return s.substr(i, j - i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string crimeDelator;
    if (!(cin >> crimeDelator)) return 0;

    auto validCrime = [&](const string& c) {
        return c == "roubo" || c == "tráfico" || c == "homicídio";
    };

    long long valorDelator = 0, valorDelatado = 0;
    if (validCrime(crimeDelator)) {
        if (crimeDelator == "roubo" || crimeDelator == "tráfico") {
            if (!(cin >> valorDelator)) return 0;
        }
    } else {
        string dummy;
        if (!(cin >> dummy)) {
            cout << "Crime inválido.";
            return 0;
        }
        string crimeDelatado = dummy;
        cout << "Crime inválido.";
        return 0;
    }

    string crimeDelatado;
    cin >> crimeDelatado;

    if (!validCrime(crimeDelatado)) {
        cout << "Crime inválido.";
        return 0;
    }

    if (crimeDelatado == "roubo" || crimeDelatado == "tráfico") {
        cin >> valorDelatado;
    }

    bool concedida = false;

    if (crimeDelator == "homicídio" && crimeDelatado == "homicídio") conceded = true;
    else if (crimeDelator == "roubo") {
        if (crimeDelatado == "homicídio") conceded = true;
        else if (crimeDelatado == "roubo") {
            conceded = (valorDelatado > 5 * valorDelator);
        } else if (crimeDelatado == "tráfico") {
            conceded = (valorDelatado > 3 * valorDelator);
        }
    } else if (crimeDelator == "tráfico") {
        if (crimeDelatado == "homicídio") conceded = false;
        else if (crimeDelatado == "tráfico") {
            conceded = (valorDelatado > 5 * valorDelator);
        }
    }

    if (concedida) cout << "Delação concedida.";
    else cout << "Delação rejeitada.";
    return 0;
}