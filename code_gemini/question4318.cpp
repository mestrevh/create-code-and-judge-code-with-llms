/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

struct Candidate {
    std::string name;
    double diff;
};

bool compareCandidates(const Candidate& a, const Candidate& b) {
    return a.diff < b.diff;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    double x;
    std::cin >> n >> m >> x;

    std::vector<Candidate> candidates;
    candidates.reserve(n);

    for (int i = 0; i < n; ++i) {
        std::string name;
        int age;
        double height;
        std::cin >> name >> age >> height;

        double value = height * age * name.length();
        double difference = std::abs(value - x);
        
        candidates.push_back({name, difference});
    }

    std::sort(candidates.begin(), candidates.end(), compareCandidates);

    for (int i = 0; i < m; ++i) {
        std::cout << candidates[i].name << "\n";
    }

    return 0;
}
