/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    int total_consistent_players = 0;

    for (int i = 0; i < N; ++i) {
        bool scored_all = true;
        for (int j = 0; j < M; ++j) {
            int goals;
            cin >> goals;
            if (goals == 0) {
                scored_all = false;
            }
        }
        if (scored_all) {
            total_consistent_players++;
        }
    }

    cout << total_consistent_players << endl;

    return 0;
}

