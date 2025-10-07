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

    int n, m;
    std::cin >> n >> m;

    if (n == 0 || m == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<std::pair<int, int>> appointments(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> appointments[i].first >> appointments[i].second;
    }

    std::vector<int> patients(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> patients[i];
    }

    std::sort(appointments.begin(), appointments.end());
    std::sort(patients.begin(), patients.end());

    std::vector<int> gaps;
    
    if (appointments[0].first > 0) {
        gaps.push_back(appointments[0].first);
    }

    for (int i = 0; i < n - 1; ++i) {
        int gap_size = appointments[i+1].first - appointments[i].second;
        if (gap_size > 0) {
            gaps.push_back(gap_size);
        }
    }

    int attended_count = 0;
    for (int patient_time : patients) {
        for (int& gap : gaps) {
            if (gap >= patient_time) {
                attended_count++;
                gap -= patient_time;
                break;
            }
        }
    }

    std::cout << attended_count << std::endl;

    return 0;
}
