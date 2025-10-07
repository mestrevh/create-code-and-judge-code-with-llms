/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> check_in(N);
        vector<int> check_out(N);

        for (int i = 0; i < N; ++i)
            cin >> check_in[i];
        for (int i = 0; i < N; ++i)
            cin >> check_out[i];

        vector<pair<int, int>> times;
        for (int i = 0; i < N; ++i) {
            times.push_back({check_in[i], 1});  // Chegada
            times.push_back({check_out[i], -1}); // Saída
        }

        sort(times.begin(), times.end());

        int current_guests = 0, max_guests = 0;
        for (const auto& time : times) {
            current_guests += time.second;
            max_guests = max(max_guests, current_guests);
        }

        cout << max_guests << endl;
    }

    return 0;
}
