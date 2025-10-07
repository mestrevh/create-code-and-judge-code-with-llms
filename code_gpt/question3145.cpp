/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int turn = 0; // 0 for Paula, 1 for Carlos
    int last_taken = 0;

    while (N > 0) {
        int can_take = 0;
        for (int i = 1; i <= M; ++i) {
            if (i != last_taken && i <= N) {
                can_take = i;
            }
        }
        if (can_take == 0) {
            break;
        }
        N -= can_take;
        last_taken = can_take;
        turn = 1 - turn; // Change turn
    }

    if (turn == 0) {
        cout << "Carlos" << endl;
    } else {
        cout << "Paula" << endl;
    }

    return 0;
}
