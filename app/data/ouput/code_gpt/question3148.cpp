/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int P, N;
    double M, K;

    cin >> P >> N;
    cin >> M >> K;

    double probInfect = M * 0.01 * K; // probabilidade de Zilde infectar alguém
    double probNotInfect = 1.0 - probInfect; // probabilidade de não infectar

    double totalProbNotInfect = pow(probNotInfect, N); // probabilidade de todos os N familiares não serem infectados
    double result = 1.0 - totalProbNotInfect; // probabilidade de pelo menos um ser infectado

    cout << fixed << setprecision(4) << result << endl;
    return 0;
}
