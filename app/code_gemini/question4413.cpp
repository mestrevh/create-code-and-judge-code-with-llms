/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<char> all_wires(6);
    for (int i = 0; i < 6; ++i) {
        std::cin >> all_wires[i];
    }

    std::vector<std::pair<char, char>> connected_wires;
    for (int i = 0; i < 6; ++i) {
        if (all_wires[i] != 'x') {
            connected_wires.push_back({all_wires[i], (char)('a' + i)});
        }
    }

    int count = connected_wires.size();
    char wire_to_cut = ' ';

    if (count == 4) {
        bool has_red = false;
        for (const auto& wire : connected_wires) {
            if (wire.first == 'r') {
                has_red = true;
                break;
            }
        }

        if (!has_red) {
            wire_to_cut = connected_wires[1].second;
        } else {
            if (connected_wires.back().first == 'b') {
                wire_to_cut = connected_wires.back().second;
            } else {
                wire_to_cut = connected_wires[0].second;
            }
        }
    } else if (count == 5) {
        if (connected_wires[0].first == 'y' && connected_wires[1].first == 'y') {
            wire_to_cut = connected_wires[0].second;
        } else {
            wire_to_cut = connected_wires[1].second;
        }
    } else if (count == 6) {
        int green_count = 0;
        char green_wire_name = ' ';
        for (const auto& wire : connected_wires) {
            if (wire.first == 'g') {
                green_count++;
                green_wire_name = wire.second;
            }
        }

        if (green_count == 1) {
            wire_to_cut = green_wire_name;
        } else {
            wire_to_cut = connected_wires[4].second;
        }
    }

    std::cout << "corta " << wire_to_cut << std::endl;

    return 0;
}
