/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int estoque[4];
    if (!(cin >> estoque[0] >> estoque[1] >> estoque[2] >> estoque[3])) {
        return 0;
    }

    // Preços convertidos para a menor unidade (Nuques):
    // 1 Galeão = 17 Sicles * 29 Nuques = 493 Nuques
    // 1 Sicle = 29 Nuques
    // Fenix: 5 Galeões, 16 Sicles, 22 Nuques = 5*493 + 16*29 + 22 = 2465 + 464 + 22 = 2951
    // Dragao: 1 Galeão, 2 Sicles, 28 Nuques = 1*493 + 2*29 + 28 = 493 + 58 + 28 = 579
    // Unicornio: 2 Galeões, 10 Sicles, 12 Nuques = 2*493 + 10*29 + 12 = 986 + 290 + 12 = 1288
    // Testralio: 3 Galeões, 10 Sicles, 0 Nuques = 3*493 + 10*29 = 1479 + 290 = 1769

    const long long PRECO_FENIX = 2951;
    const long long PRECO_DRAGAO = 579;
    const long long PRECO_UNICORNIO = 1288;
    const long long PRECO_TESTRALIO = 1769;

    long long totalNuques = 0;
    string s;

    while (cin >> s && s != "FIM") {
        if (s == "Fenix") {
            estoque[0]--;
            totalNuques += PRECO_FENIX;
        } else if (s == "Dragao") {
            estoque[1]--;
            totalNuques += PRECO_DRAGAO;
        } else if (s == "Unicornio") {
            estoque[2]--;
            totalNuques += PRECO_UNICORNIO;
        } else if (s == "Testralio") {
            estoque[3]--;
            totalNuques += PRECO_TESTRALIO;
        }
    }

    cout << "Fenix " << estoque[0] << "\n";
    cout << "Dragao " << estoque[1] << "\n";
    cout << "Unicornio " << estoque[2] << "\n";
    cout << "Testralio " << estoque[3] << "\n";

    long long g = totalNuques / 493;
    long long resto = totalNuques % 493;
    long long sic = resto / 29;
    long long nuq = resto % 29;

    cout << g << " " << sic << " " << nuq << endl;

    return 0;
}