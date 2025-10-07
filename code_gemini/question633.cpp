/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>

using ll = long long;

struct Block {
    ll start_pos;
    ll size;
    bool is_free;
    std::string name;
};

ll total_disk_size;
std::list<Block> disk_layout;
std::map<std::string, std::list<Block>::iterator> file_map;
bool error_occurred;

ll parse_size(ll val, const std::string& unit) {
    if (unit == "Mb") return val * 1024;
    if (unit == "Gb") return val * 1024 * 1024;
    return val;
}

void otimiza() {
    std::list<Block> new_layout;
    ll current_pos = 0;

    for (const auto& block : disk_layout) {
        if (!block.is_free) {
            new_layout.push_back({current_pos, block.size, false, block.name});
            current_pos += block.size;
        }
    }

    if (current_pos < total_disk_size) {
        new_layout.push_back({current_pos, total_disk_size - current_pos, true, ""});
    }

    disk_layout = new_layout;
    
    file_map.clear();
    for (auto it = disk_layout.begin(); it != disk_layout.end(); ++it) {
        if (!it->is_free) {
            file_map[it->name] = it;
        }
    }
}

void insere(const std::string& name, ll req_size) {
    auto best_it = disk_layout.end();
    ll min_fit_size = -1;

    for (auto it = disk_layout.begin(); it != disk_layout.end(); ++it) {
        if (it->is_free && it->size >= req_size) {
            if (best_it == disk_layout.end() || it->size < min_fit_size) {
                best_it = it;
                min_fit_size = it->size;
            }
        }
    }

    if (best_it == disk_layout.end()) {
        otimiza();
        if (!disk_layout.empty() && disk_layout.back().is_free && disk_layout.back().size >= req_size) {
            best_it = std::prev(disk_layout.end());
        } else {
             best_it = disk_layout.end();
        }
    }

    if (best_it == disk_layout.end()) {
        error_occurred = true;
        std::cout << "ERRO: disco cheio\n";
        return;
    }
    
    ll original_start = best_it->start_pos;
    ll original_size = best_it->size;

    best_it->is_free = false;
    best_it->name = name;
    best_it->size = req_size;
    file_map[name] = best_it;

    if (original_size > req_size) {
        Block remainder = {original_start + req_size, original_size - req_size, true, ""};
        disk_layout.insert(std::next(best_it), remainder);
    }
}

void remove(const std::string& name) {
    auto map_it = file_map.find(name);
    if (map_it == file_map.end()) {
        return;
    }

    auto block_it = map_it->second;
    block_it->is_free = true;
    block_it->name = "";
    file_map.erase(map_it);

    auto next_it = std::next(block_it);
    if (next_it != disk_layout.end() && next_it->is_free) {
        block_it->size += next_it->size;
        disk_layout.erase(next_it);
    }

    if (block_it != disk_layout.begin()) {
        auto prev_it = std::prev(block_it);
        if (prev_it->is_free) {
            prev_it->size += block_it->size;
            disk_layout.erase(block_it);
        }
    }
}

void print_output() {
    ll segment_size = total_disk_size / 8;
    std::vector<ll> free_in_segment(8, 0);

    for (const auto& block : disk_layout) {
        if (block.is_free) {
            ll block_start = block.start_pos;
            ll block_end = block_start + block.size;

            for (int i = 0; i < 8; ++i) {
                ll segment_start = i * segment_size;
                ll segment_end = (i + 1) * segment_size;

                ll overlap_start = std::max(block_start, segment_start);
                ll overlap_end = std::min(block_end, segment_end);

                if (overlap_end > overlap_start) {
                    free_in_segment[i] += (overlap_end - overlap_start);
                }
            }
        }
    }

    for (int i = 0; i < 8; ++i) {
        double p = (static_cast<double>(free_in_segment[i]) * 100.0) / segment_size;
        char c;
        if (p > 75.0) {
            c = ' ';
        } else if (p > 25.0) {
            c = '-';
        } else {
            c = '#';
        }
        std::cout << "[" << c << "]";
    }
    std::cout << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    while (std::cin >> N && N != 0) {
        ll d_val;
        std::string unit;
        std::cin >> d_val >> unit;
        total_disk_size = parse_size(d_val, unit);
        
        disk_layout.clear();
        file_map.clear();
        disk_layout.push_back({0, total_disk_size, true, ""});
        error_occurred = false;

        for (int i = 0; i < N; ++i) {
            std::string command;
            std::cin >> command;

            if (error_occurred) {
                std::string line;
                std::getline(std::cin, line);
                continue;
            }

            if (command == "insere") {
                std::string name, size_str;
                std::cin >> name >> size_str;
                std::string size_unit = size_str.substr(size_str.length() - 2);
                ll size_val = std::stoll(size_str.substr(0, size_str.length() - 2));
                insere(name, parse_size(size_val, size_unit));
            } else if (command == "remove") {
                std::string name;
                std::cin >> name;
                remove(name);
            } else {
                otimiza();
            }
        }

        if (!error_occurred) {
            print_output();
        }
    }

    return 0;
}
