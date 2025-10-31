/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int K, N, M;
    cin >> K >> N >> M;
    vector<string> auditorium(N);
    for (int i = 0; i < N; ++i) {
        cin >> auditorium[i];
    }

    bool foundBlock = false;
    bool allSeated = true;
    vector<int> seats(N, 0); // Count of free seats in each row
    vector<pair<int, int>> bestPos; // Store best positions for output

    for (int i = 0; i < N; ++i) {
        int count = 0;
        for (int j = 0; j < M; ++j) {
            if (auditorium[i][j] == 'o') {
                count++;
            } else {
                count = 0;
            }
            if (count >= K) {
                foundBlock = true;
                bestPos = {i, j - K + 1}; // Update to the rightmost position
            }
        }
        seats[i] = count; // Store total free seats in row
    }

    if (foundBlock) {
        cout << "Todos sentados e juntos" << endl;
        for (int i = 0; i < N; ++i) {
            if (i == bestPos.first) {
                for (int j = bestPos.second; j < bestPos.second + K; ++j)
                    auditorium[i][j] = '*';
            }
            cout << auditorium[i] << endl;
        }
        return 0;
    }

    // Check for ability to sit separately
    int totalFree = 0;
    for (int i = 0; i < N; ++i) {
        totalFree += seats[i];
    }

    if (totalFree >= K) {
        cout << "Todos sentados, mas separados" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (auditorium[i][j] == 'o' && K > 0) {
                    auditorium[i][j] = '*';
                    K--;
                }
            }
            cout << auditorium[i] << endl;
        }
        return 0;
    }

    // Case where not everyone can sit
    cout << K - totalFree << " sentados, " << totalFree << " em pé" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            auditorium[i][j] = '*';
        }
        cout << auditorium[i] << endl;
    }
    return 0;
}
