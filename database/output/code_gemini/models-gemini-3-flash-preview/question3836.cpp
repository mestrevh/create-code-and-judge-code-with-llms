/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long tempo;
    if (!(cin >> tempo)) return 0;

    if (tempo < 0) {
        cout << "Meme man quebrou o tempo! De volta ao transito :(" << endl;
    } else if (tempo < 62) {
        cout << "...Ainda no transito..." << endl;
    } else if (tempo >= 3713 && tempo <= 3736) {
        cout << "Stonks has been born!" << endl;
    } else {
        cout << "Lar doce lar" << endl;
    }

    return 0;
}