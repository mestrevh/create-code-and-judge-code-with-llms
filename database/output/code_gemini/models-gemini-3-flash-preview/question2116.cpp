/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string opt;
    if (!(cin >> opt)) return 0;

    if (opt != "C" && opt != "BF" && opt != "BS") {
        cout << "Opção inválida." << endl;
        return 0;
    }

    char garlic, drinkA, drinkK;
    int kids, adults;

    if (!(cin >> garlic >> drinkA >> drinkK >> kids >> adults)) return 0;

    double total = 0.0;

    if (opt == "C") {
        // Completo: 200g bov/A, 100g frango/A, 100g suina/A, 200g bov/K
        total += (adults * 0.2 + kids * 0.2) * 32.0;
        total += (adults * 0.1) * 18.0;
        total += (adults * 0.1) * 15.0;
    } else if (opt == "BF") {
        // BF: 250g bov/A, 150g frango/A, 200g bov/K
        total += (adults * 0.25 + kids * 0.2) * 32.0;
        total += (adults * 0.15) * 18.0;
    } else if (opt == "BS") {
        // BS: 250g bov/A, 150g suina/A, 200g bov/K
        total += (adults * 0.25 + kids * 0.2) * 32.0;
        total += (adults * 0.15) * 15.0;
    }

    if (drinkA == 'S') {
        // 2 beers per adult, 8.00 each
        total += (adults * 2.0) * 8.0;
    }
    if (drinkK == 'S') {
        // 0.5 sodas per child, 6.00 each
        total += (kids * 0.5) * 6.0;
    }

    if (garlic == 'N') {
        // 2% discount
        total *= 0.98;
    }

    cout << "R$: " << fixed << setprecision(2) << total << endl;

    return 0;
}