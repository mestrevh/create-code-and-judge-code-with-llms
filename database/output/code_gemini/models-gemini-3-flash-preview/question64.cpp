/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: O Salão do Clube (The Club Ballroom)
 * Goal: Cover an M x N room with planks of width L and various lengths.
 * Each strip must be covered by at most 2 planks. Planks cannot be cut.
 * Minimize the total number of planks used.
 */

const long long INF = 1e18;

/**
 * solve_orientation calculates the minimum planks to cover the room
 * given the target length of each strip (T) and the number of strips (S).
 */
long long solve_orientation(int T, int S, int K, const vector<int>& count) {
    // If the number of required strips exceeds the total number of planks, 
    // it's impossible (since each strip needs at least one plank).
    if (S > K) return INF;

    long long strips_covered = 0;
    long long planks_used = 0;
    vector<int> current_count = count;

    // 1. Use planks that are exactly the target length T.
    if (T <= 10000 && current_count[T] > 0) {
        int take = min((long long)current_count[T], (long long)S);
        strips_covered += take;
        planks_used += take;
        // current_count[T] is not needed anymore in this logic
    }

    // 2. Use pairs of planks that sum up to the target length T.
    // We use a greedy approach: try to form pairs from the outer ends 
    // of the length spectrum (1 and T-1, 2 and T-2, etc.)
    // because any available combination that sums to T is equally useful.
    int i = 1;
    int j = T - 1;
    
    // Iterate from i = 1 to i < T/2 to handle pairs where a != b
    while (i < j && strips_covered < S) {
        if (i <= 10000 && j <= 10000) {
            int take = min({(long long)current_count[i], (long long)current_count[j], (long long)(S - strips_covered)});
            strips_covered += take;
            planks_used += 2LL * take;
        }
        i++;
        j--;
    }

    // 3. Handle the case where T is even and we use two planks of length T/2.
    if (T % 2 == 0 && strips_covered < S) {
        int half = T / 2;
        if (half <= 10000) {
            int take = min((long long)current_count[half] / 2, (long long)(S - strips_covered));
            strips_covered += take;
            planks_used += 2LL * take;
        }
    }

    return (strips_covered == S) ? planks_used : INF;
}

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    // M and N are room dimensions in meters
    while (cin >> M >> N && (M != 0 || N != 0)) {
        int L, K;
        // L is plank width in cm, K is number of planks
        cin >> L >> K;
        
        // Frequency array for plank lengths (lengths are up to 10,000 meters)
        vector<int> count(10001, 0);
        for (int i = 0; i < K; ++i) {
            int x;
            cin >> x;
            if (x <= 10000) count[x]++;
        }

        long long min_planks = INF;

        // Try both possible orientations:
        
        // Orientation 1: Planks aligned parallel to side N. 
        // Strips have length N. Number of strips needed S = (M * 100) / L.
        if ((M * 100) % L == 0) {
            long long res = solve_orientation(N, (M * 100) / L, K, count);
            if (res < min_planks) min_planks = res;
        }

        // Orientation 2: Planks aligned parallel to side M.
        // Strips have length M. Number of strips needed S = (N * 100) / L.
        if ((N * 100) % L == 0) {
            long long res = solve_orientation(M, (N * 100) / L, K, count);
            if (res < min_planks) min_planks = res;
        }

        if (min_planks >= INF) {
            cout << "impossivel" << "\n";
        } else {
            cout << min_planks << "\n";
        }
    }

    return 0;
}

