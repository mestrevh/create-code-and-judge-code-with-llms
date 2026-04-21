/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int hamburguer, cheeseburger, fritas, refrigerante, milkshake;

    if (cin >> hamburguer >> cheeseburger >> fritas >> refrigerante >> milkshake) {
        double total = (hamburguer * 3.0) + (cheeseburger * 2.5) + (fritas * 2.5) + (refrigerante * 1.0) + (milkshake * 3.0);
        
        cout << "conta final: " << fixed << setprecision(1) << total << endl;
    }

    return 0;
}