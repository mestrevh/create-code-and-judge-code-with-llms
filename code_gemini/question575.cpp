/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

const int EMPTY = -1;
const int SEALED = -2;

int M, L;
long long total_graves_used;
std::vector<std::vector<int>> cemetery;
std::vector<int> next_grave;
std::unordered_map<int, std::pair<int, int>> key_location_map;

std::pair<int, int> place_person(int k) {
    long long start_floor = k % M;
    long long current_floor = start_floor;

    do {
        if (next_grave[current_floor] < L) {
            int grave_index = next_grave[current_floor];
            std::pair<int, int> loc = {(int)current_floor, grave_index};
            
            key_location_map[k] = loc;
            cemetery[loc.first][loc.second] = k;
            next_grave[loc.first]++;
            total_graves_used++;
            
            return loc;
        }
        current_floor = (current_floor + 1) % M;
    } while (current_floor != start_floor);
    
    return {-1, -1};
}

void rehash() {
    std::vector<int> keys_in_order;
    int old_M = M;
    keys_in_order.reserve(key_location_map.size()); 
    
    for (int i = 0; i < old_M; ++i) {
        for (int j = 0; j < L; ++j) {
            if (cemetery[i][j] >= 0) {
                keys_in_order.push_back(cemetery[i][j]);
            }
        }
    }
    
    M = 2 * old_M + 1;

    key_location_map.clear();
    cemetery.assign(M, std::vector<int>(L, EMPTY));
    next_grave.assign(M, 0);
    total_graves_used = 0;

    for (int key : keys_in_order) {
        place_person(key);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> M >> L;

    total_graves_used = 0;
    cemetery.assign(M, std::vector<int>(L, EMPTY));
    next_grave.resize(M, 0);
    
    std::string op;
    int k;
    int op_count = 0;

    while (std::cin >> op >> k) {
        std::cout << op_count << " ";

        if (op == "ADD") {
            if (total_graves_used == (long long)M * L) {
                rehash();
            }
            std::pair<int, int> loc = place_person(k);
            std::cout << loc.first << "." << loc.second << "\n";

        } else if (op == "REM") {
            auto it = key_location_map.find(k);
            if (it != key_location_map.end()) {
                std::pair<int, int> loc = it->second;
                key_location_map.erase(it);
                cemetery[loc.first][loc.second] = SEALED;
                std::cout << loc.first << "." << loc.second << "\n";
            } else {
                std::cout << "?.?\n";
            }
        } else if (op == "QRY") {
            auto it = key_location_map.find(k);
            if (it != key_location_map.end()) {
                std::pair<int, int> loc = it->second;
                std::cout << loc.first << "." << loc.second << "\n";
            } else {
                std::cout << "?.?\n";
            }
        }
        op_count++;
    }

    return 0;
}
