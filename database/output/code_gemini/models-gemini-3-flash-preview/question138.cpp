/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Estacionamento (Parking Lot)
 * Logic:
 * - A parking lot is represented as a single row of length C.
 * - For each car arrival (type 'C'), find the FIRST available contiguous gap of at least Q meters.
 * - If found, park the car there and add R$ 10.00 to the total.
 * - For each car departure (type 'S'), free the space occupied by that car.
 * - Constraints: C <= 1000, N <= 10000, P (plate) <= 9999.
 * - Time Complexity: O(N * C) per test case, which is highly efficient for C++ given the 10s limit.
 */

static int lot[1005];
static int car_start[10005];
static int car_len[10005];

int main() {
    // Optimize C++ standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, N;
    // Loop through each test case until C == -1
    while (cin >> C >> N && C != -1) {
        // Initialize the lot and car tracking for the new test case
        for (int i = 0; i < C; i++) lot[i] = -1;
        for (int i = 0; i < 10000; i++) car_start[i] = -1;
        
        int total_faturamento = 0;
        
        for (int i = 0; i < N; i++) {
            char type;
            cin >> type;
            
            if (type == 'C') {
                int p, q;
                cin >> p >> q;
                
                int free_count = 0;
                int start_pos = -1;
                
                // Linear scan to find the first suitable gap of size q
                for (int j = 0; j < C; j++) {
                    if (lot[j] == -1) {
                        free_count++;
                        if (free_count == q) {
                            start_pos = j - q + 1;
                            break;
                        }
                    } else {
                        free_count = 0;
                    }
                }
                
                // If a gap was found, park the car and update revenue
                if (start_pos != -1) {
                    for (int j = start_pos; j < start_pos + q; j++) {
                        lot[j] = p;
                    }
                    car_start[p] = start_pos;
                    car_len[p] = q;
                    total_faturamento += 10;
                }
            } else if (type == 'S') {
                int p;
                cin >> p;
                
                // If the car is parked, release its space
                if (car_start[p] != -1) {
                    int start = car_start[p];
                    int len = car_len[p];
                    for (int j = start; j < start + len; j++) {
                        lot[j] = -1;
                    }
                    car_start[p] = -1;
                }
            }
        }
        // Output the total revenue for the test case
        cout << total_faturamento << "\n";
    }

    return 0;
}

/**
 * Technical Breakdown:
 * - Space Management: Array 'lot' of size 1005 handles the physical meters.
 * - Car Indexing: Array 'car_start' and 'car_len' of size 10005 map plates (1000-9999) to their positions.
 * - Complexity: O(N * C) is roughly 10^7 operations per test case. With 10s limit, it handles hundreds of cases.
 * - Efficiency: Global arrays avoid re-allocation. '\n' is used over 'endl' to avoid unnecessary flushes.
 */