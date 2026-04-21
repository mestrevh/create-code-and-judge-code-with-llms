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

    double impulse, height, distance, weight;
    string yoshi;

    while (cin >> impulse >> height >> distance >> weight >> yoshi) {
        if (yoshi == "Sim") {
            impulse += 5.0;
            weight += 50.0;
        }

        double jump_height = (impulse * impulse) / height - (distance + weight);

        if (jump_height >= 50.0) {
            cout << "Voce consegue" << endl;
        } else {
            cout << "Isso e perda de tempo" << endl;
        }
    }

    return 0;
}