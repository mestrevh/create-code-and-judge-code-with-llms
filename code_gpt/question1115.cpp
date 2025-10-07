/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Toy {
    int S, B, C;
};

int main() {
    int N;
    cin >> N;

    vector<Toy> toys(N);
    for (int i = 0; i < N; ++i) {
        cin >> toys[i].S >> toys[i].B >> toys[i].C;
    }

    int V;
    cin >> V;
    vector<int> K(V);
    for (int j = 0; j < V; ++j) {
        cin >> K[j];
    }

    for (int j = 0; j < V; ++j) {
        int credits = K[j];
        vector<int> dp(credits + 1, 0);

        for (int i = 0; i < N; ++i) {
            int k = 1, current_fun;
            while (true) {
                current_fun = toys[i].S - (k - 1) * (k - 1) * toys[i].B;
                if (current_fun <= 0) break;

                for (int c = credits; c >= toys[i].C; --c) {
                    dp[c] = max(dp[c], dp[c - toys[i].C] + current_fun);
                }
                ++k;
            }
        }

        cout << j << ": " << dp[credits] << endl;
    }

    return 0;
}
