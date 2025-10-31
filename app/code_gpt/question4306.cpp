/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    float d;
    cin >> d;
    vector<int> custos(4);
    vector<float> eficiencias = {75, 50, 25, 50};
    for (int i = 0; i < 4; i++) {
        cin >> custos[i];
    }

    float media = 0;
    for (int i = 0; i < 4; i++) {
        media += eficiencias[i] / custos[i];
    }
    media /= 4;

    for (int i = 0; i < 4; i++) {
        float custoBeneficio = eficiencias[i] / custos[i];
        if (custoBeneficio < media) {
            cout << "EH BOMBA TORRESMO" << endl;
        } else {
            cout << "eh dento" << endl;
        }
        if (custos[i] > d) {
            cout << "foi de comes" << endl;
        }
    }

    return 0;
}
