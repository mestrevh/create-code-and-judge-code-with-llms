/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long C, N;
    if (!(cin >> C >> N)) return 0;

    if (C <= 0) {
        cout << "Nao possuem caminhoes para fazer a coleta!" << endl;
    } else {
        long long total_ml = 0;
        const long long truck_cap_ml = 3000000LL;

        for (long long i = 0; i < N; ++i) {
            long long A;
            if (!(cin >> A)) break;

            if (A > 0) {
                long long V, Pa, Pl, M;
                if (cin >> V >> Pa >> Pl >> M) {
                    long long building_ml = 0;
                    building_ml += V * 1000LL;
                    building_ml += Pa * 1000000LL;
                    building_ml += Pl * 1000LL;
                    building_ml += M;
                    total_ml += A * building_ml;
                }
            }
        }

        long long total_trips = (total_ml + truck_cap_ml - 1) / truck_cap_ml;
        long long avg_trips_per_truck = (total_trips + C - 1) / C;

        cout << avg_trips_per_truck << endl;
    }

    return 0;
}