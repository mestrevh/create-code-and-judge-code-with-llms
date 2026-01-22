/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int p, s;
    std::cin >> p >> s;

    if (s == 0) {
        return 0;
    }

    std::vector<Interval> intervals(s);
    for (int i = 0; i < s; ++i) {
        std::cin >> intervals[i].start >> intervals[i].end;
    }

    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    std::vector<Interval> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < s; ++i) {
        if (intervals[i].start <= merged.back().end) {
            merged.back().end = std::max(merged.back().end, intervals[i].end);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    for (const auto& interval : merged) {
        std::cout << interval.start << " " << interval.end << "\n";
    }

    return 0;
}
