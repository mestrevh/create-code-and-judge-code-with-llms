/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

char determine_move(int num) {
    if (is_prime(num)) return 'P';
    return (num % 2 == 0) ? 'R' : 'C';
}

int main() {
    int N;
    cin >> N;
    int A, B;

    int sapos = 0, shuas = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A >> B;
        char moveA = determine_move(A);
        char moveB = determine_move(B);

        if (moveA == moveB) {
            continue;
        } else if ((moveA == 'R' && moveB == 'C') || (moveA == 'C' && moveB == 'P') || (moveA == 'P' && moveB == 'R')) {
            sapos++;
        } else {
            shuas++;
        }
    }

    if (sapos > shuas) {
        cout << "Sapo sopa esta de boa na lagoa!" << endl;
    } else if (shuas > sapos) {
        cout << "Testemunhe a verdadeira forca!" << endl;
    } else {
        cout << "Impending doom approaches..." << endl;
    }

    return 0;
}
