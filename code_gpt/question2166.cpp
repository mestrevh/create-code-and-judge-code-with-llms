/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        vector<int> heights(t), costs(t);
        for (int i = 0; i < t; i++) cin >> heights[i];
        for (int i = 0; i < t; i++) cin >> costs[i];

        int min_cost = INT_MAX;
        for (int target = *min_element(heights.begin(), heights.end());
             target <= *max_element(heights.begin(), heights.end()); target++) {
            
            int current_cost = 0;
            for (int i = 0; i < t; i++) {
                current_cost += abs(heights[i] - target) * costs[i];
            }
            min_cost = min(min_cost, current_cost);
        }
        
        cout << min_cost << endl;
    }
    return 0;
}
