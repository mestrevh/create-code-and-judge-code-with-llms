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

    long long hunger;
    if (!(cin >> hunger)) return 0;

    for (int i = 0; i < 3; ++i) {
        string sushi;
        long long quantity;
        if (!(cin >> sushi >> quantity)) break;

        if (sushi == "Hossomaki") {
            hunger -= (quantity * 3);
        } else if (sushi == "Futomaki") {
            hunger -= (quantity * 5);
        } else if (sushi == "Nigirizushi") {
            hunger -= (quantity * 7);
        } else if (sushi == "Temaki") {
            hunger -= (quantity * 10);
        }
    }

    if (hunger <= 0) {
        cout << "Nossa, o Japao e um otimo lugar para comer, vou dar conta do recado!" << endl;
    } else if (hunger <= 10) {
        cout << "Estou satisfeito mas nao sei se darei conta do recado" << endl;
    } else {
        cout << "Uma feijoada seria bem melhor... Estou me sentindo fraco" << endl;
    }

    return 0;
}