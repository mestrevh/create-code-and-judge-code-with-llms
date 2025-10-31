/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n) {
        std::vector<std::pair<int, int>> intervals(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> intervals[i].first >> intervals[i].second;
        }

        std::sort(intervals.begin(), intervals.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        });

        int photo_count = 1;
        int last_focus_point = intervals[0].second;

        for (int i = 1; i < n; ++i) {
            if (intervals[i].first > last_focus_point) {
                photo_count++;
                last_focus_point = intervals[i].second;
            }
        }
        std::cout << photo_count << std::endl;
    }

    return 0;
}
