/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string,int> heightBins = {
        {"Abaixo de 1.20", 0},
        {"1.20 - 1.39", 0},
        {"1.40 - 1.59", 0},
        {"1.60 - 1.79", 0},
        {"1.80 - 1.99", 0},
        {"2.00 ou mais", 0}
    };

    vector<int> ageCounts(19, 0);
    int men = 0, women = 0;

    while (true) {
        double h;
        int age;
        char sex;

        cout << "Digite a altura do entrevistado: ";
        if (!(cin >> h)) return 0;
        if (h == 0) break;

        cout << "Digite a idade do entrevistado: ";
        cin >> age;

        cout << "Digite o sexo do entrevistado (M ou F): ";
        cin >> sex;

        if (h < 1.20) heightBins["Abaixo de 1.20"]++;
        else if (h < 1.40) heightBins["1.20 - 1.39"]++;
        else if (h < 1.60) heightBins["1.40 - 1.59"]++;
        else if (h < 1.80) heightBins["1.60 - 1.79"]++;
        else if (h < 2.00) heightBins["1.80 - 1.99"]++;
        else heightBins["2.00 ou mais"]++;

        if (0 <= age && age <= 18) ageCounts[age]++;

        sex = toupper(static_cast<unsigned char>(sex));
        if (sex == 'M') men++;
        else if (sex == 'F') women++;
    }

    cout << "\n";
    cout << "Quantidade por classe de altura (histograma):\n";
    for (auto &kv : heightBins) cout << kv.first << ": " << kv.second << "\n";

    cout << "\n";
    cout << "Quantidade por idade (0 a 18):\n";
    for (int i = 0; i <= 18; i++) {
        cout << i << ": " << ageCounts[i] << "\n";
    }

    cout << "\n";
    cout << "Quantidade por sexo:\n";
    cout << "Homens: " << men << "\n";
    cout << "Mulheres: " << women << "\n";

    return 0;
}