/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double impulse, height_mario, distance, weight;
    string mounted;

    if (!(cin >> impulse >> height_mario >> distance >> weight >> mounted)) {
        return 0;
    }

    if (mounted == "Sim") {
        weight += 50.0;
        impulse += 5.0;
    }

    double denominator = sqrt(height_mario) + (distance / 2.0) + (weight / 3.0);
    double jump_height = (impulse * impulse * impulse) / denominator;

    if (jump_height >= 100.0) {
        cout << "Voce consegue" << endl;
    } else {
        cout << "Isso e perda de tempo" << endl;
    }

    return 0;
}