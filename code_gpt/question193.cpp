/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, N;
    cin >> A >> N;
    int perceptiveStars = 0;
    const int requiredPhotons = 40000000;

    for (int i = 0; i < N; i++) {
        int F;
        cin >> F;
        if (F * A >= requiredPhotons) {
            perceptiveStars++;
        }
    }

    cout << perceptiveStars << endl;
    return 0;
}
