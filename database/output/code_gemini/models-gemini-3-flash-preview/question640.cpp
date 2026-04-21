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

    int T, N;
    while (cin >> T >> N && T != 0) {
        long long total_points = 0;
        for (int i = 0; i < T; ++i) {
            string team_name;
            int points;
            cin >> team_name >> points;
            total_points += points;
        }
        
        // Total games N = W + D (Wins/Losses matches + Drawn matches)
        // Total points P = 3*W + 2*D
        // P = 3*(N - D) + 2*D
        // P = 3*N - 3*D + 2*D
        // P = 3*N - D
        // D = 3*N - P
        
        long long draws = 3LL * N - total_points;
        cout << draws << "\n";
    }

    return 0;
}
