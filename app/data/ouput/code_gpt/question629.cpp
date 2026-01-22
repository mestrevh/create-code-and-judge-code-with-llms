/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

struct Proposal {
    int start, end, value;
};

bool comp(const Proposal &a, const Proposal &b) {
    return a.end < b.end;
}

int main() {
    int caseNum = 1;
    std::string line;
    
    while (std::getline(std::cin, line) && !line.empty()) {
        int N = std::stoi(line);
        std::vector<Proposal> proposals(N);
        
        for (int i = 0; i < N; ++i) {
            std::getline(std::cin, line);
            sscanf(line.c_str(), "%d %d %d", &proposals[i].start, &proposals[i].end, &proposals[i].value);
        }
        
        std::sort(proposals.begin(), proposals.end(), comp);
        
        std::vector<int> dp(N, 0);
        dp[0] = proposals[0].value;

        for (int i = 1; i < N; ++i) {
            dp[i] = proposals[i].value;
            for (int j = 0; j < i; ++j) {
                if (proposals[j].end < proposals[i].start) {
                    dp[i] = std::max(dp[i], dp[j] + proposals[i].value);
                }
            }
        }

        int maxRevenue = *std::max_element(dp.begin(), dp.end());
        std::cout << "caso " << caseNum++ << ": " << maxRevenue << "\n\n";
    }

    return 0;
}
