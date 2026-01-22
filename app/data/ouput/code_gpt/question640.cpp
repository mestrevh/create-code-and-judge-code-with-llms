/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    while (true) {
        int T, N;
        cin >> T >> N;
        if (T == 0) break;

        unordered_map<string, int> points;
        for (int i = 0; i < T; i++) {
            string team;
            int point;
            cin >> team >> point;
            points[team] = point;
        }

        int totalPoints = 0;
        for (const auto& p : points) {
            totalPoints += p.second;
        }

        int maxPoints = N * 3;
        int draws = (maxPoints - totalPoints) / 2;

        cout << draws << endl;
    }
    return 0;
}
