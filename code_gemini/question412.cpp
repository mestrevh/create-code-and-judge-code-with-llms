/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <ios>

struct Update {
    int friend_id;
    std::string message;
    double score;
};

bool compareUpdates(const Update& a, const Update& b) {
    return a.score > b.score;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int m;
    std::cin >> m;

    std::unordered_map<int, double> proximities;
    proximities.reserve(m);
    for (int i = 0; i < m; ++i) {
        int id;
        double proximity;
        std::cin >> id >> proximity;
        proximities[id] = proximity;
    }

    int x;
    std::cin >> x;

    std::vector<Update> updates;
    updates.reserve(x);
    
    for (int i = 0; i < x; ++i) {
        int id;
        double time;
        std::string msg;
        
        std::cin >> id >> time;
        std::cin.get(); 
        std::getline(std::cin, msg);

        double score = 0.8 * proximities[id] + 0.2 * time;
        updates.push_back({id, msg, score});
    }

    int count_to_print = std::min(n, (int)updates.size());
    
    if (count_to_print > 0) {
        std::partial_sort(updates.begin(), updates.begin() + count_to_print, updates.end(), compareUpdates);
    }
    
    for (int i = 0; i < count_to_print; ++i) {
        std::cout << updates[i].friend_id << " " << updates[i].message << "\n";
    }

    return 0;
}
