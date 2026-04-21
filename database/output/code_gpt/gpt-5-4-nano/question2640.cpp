/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double altura;
    int idade;

    cout << "Digite a altura em m: ";
    if (!(cin >> altura)) return 0;
    cout << "Digite a idade: ";
    if (!(cin >> idade)) return 0;

    vector<string> brinquedos;
    if (altura >= 1.50 && idade >= 12) brinquedos.push_back("Barca Viking");
    if (altura >= 1.40 && idade >= 14) brinquedos.push_back("Elevator of Death");
    if (altura >= 1.70 || idade >= 16) brinquedos.push_back("Final Killer");

    cout << "Voce pode andar em " << brinquedos.size() << " brinquedos, sendo eles:\n";
    for (size_t i = 0; i < brinquedos.size(); i++) {
        cout << brinquedos[i] << "\n";
    }
    return 0;
}