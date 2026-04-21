/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm> // Not strictly necessary, but good to include for competitive programming habits

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int test_case_num = 1;

    while (std::cin >> N && N != 0) {
        int max_sum = 0;             // Stores the maximum positive accumulated goal difference found.
                                     // Initialized to 0, so if no positive period is found, it remains 0.
        int best_start_idx = 1;      // 1-based index for the start of the period with max_sum.
        int best_end_idx = 0;        // 1-based index for the end of the period with max_sum.
                                     // (best_end_idx - best_start_idx) + 1 is the length of the period.

        int current_sum = 0;         // Stores the sum of the current contiguous subarray.
        int current_start_idx = 1;   // 1-based index for the start of the current contiguous subarray.

        for (int i = 1; i <= N; ++i) {
            int X, Y;
            std::cin >> X >> Y;
            int diff = X - Y; // Goal difference for the current match

            current_sum += diff;

            // If the current sum is greater than the overall maximum sum found so far,
            // update the maximum sum and the indices of the best period.
            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_start_idx = current_start_idx;
                best_end_idx = i;
            } else if (current_sum == max_sum && max_sum > 0) {
                // If the current sum is equal to the maximum sum and it's a positive sum,
                // apply the tie-breaking rule: choose the longest period.
                // The length of current period is (i - current_start_idx + 1).
                // The length of the best period found so far is (best_end_idx - best_start_idx + 1).
                // Comparing (i - current_start_idx) and (best_end_idx - best_start_idx) is equivalent.
                if ((i - current_start_idx) > (best_end_idx - best_start_idx)) {
                    best_start_idx = current_start_idx;
                    best_end_idx = i;
                }
            }

            // If the current sum becomes negative, it means this period is dragging down
            // the total sum. It's better to reset and start a new potential best period
            // from the next match.
            if (current_sum < 0) {
                current_sum = 0;
                current_start_idx = i + 1;
            }
        }

        std::cout << "Teste " << test_case_num++ << std::endl;
        if (max_sum <= 0) {
            // If the maximum accumulated goal difference found is 0 or negative,
            // output "nenhum" as per problem specification.
            std::cout << "nenhum" << std::endl;
        } else {
            // Otherwise, output the start and end indices of the best period.
            std::cout << best_start_idx << " " << best_end_idx << std::endl;
        }
        std::cout << std::endl; // Blank line after each test case
    }

    return 0;
}