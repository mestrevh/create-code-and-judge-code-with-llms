/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int i;
    std::cin >> i;
    std::string temp;
    std::getline(std::cin, temp); 

    std::map<std::string, int> cd_counts;
    for (int k = 0; k < i; ++k) {
        std::string line;
        std::getline(std::cin, line);
        cd_counts[line]++;
    }

    std::map<std::string, int> cover_counts;
    for (int k = 0; k < i; ++k) {
        std::string line;
        std::getline(std::cin, line);
        cover_counts[line]++;
    }

    std::vector<std::string> matched_pairs_formatted;
    std::set<std::string> unmatched_cd_artists;
    std::set<std::string> unmatched_cover_artists;
    std::set<std::string> all_keys;

    for (const auto& pair : cd_counts) {
        all_keys.insert(pair.first);
    }
    for (const auto& pair : cover_counts) {
        all_keys.insert(pair.first);
    }

    for (const auto& key : all_keys) {
        int num_cds = cd_counts.count(key) ? cd_counts[key] : 0;
        int num_covers = cover_counts.count(key) ? cover_counts[key] : 0;
        int num_matches = std::min(num_cds, num_covers);

        if (num_matches > 0) {
            std::string formatted_key = key;
            size_t pos = formatted_key.find_last_of('-');
            if (pos != std::string::npos) {
                formatted_key.replace(pos, 1, " ");
            }
            for (int k = 0; k < num_matches; ++k) {
                matched_pairs_formatted.push_back(formatted_key);
            }
        }

        if (num_cds != num_covers) {
            size_t pos = key.find_last_of('-');
            std::string artist_name = (pos != std::string::npos) ? key.substr(0, pos) : key;
            if (num_cds > num_covers) {
                unmatched_cd_artists.insert(artist_name);
            } else {
                unmatched_cover_artists.insert(artist_name);
            }
        }
    }

    std::sort(matched_pairs_formatted.begin(), matched_pairs_formatted.end());

    for (const auto& pair_str : matched_pairs_formatted) {
        std::cout << pair_str << "\n";
    }

    bool has_unmatched_cds = !unmatched_cd_artists.empty();
    bool has_unmatched_covers = !unmatched_cover_artists.empty();

    if (has_unmatched_cds || has_unmatched_covers) {
        std::cout << "Chandler, você vai ter que comprar ";
        if (has_unmatched_cds) {
            std::cout << "a capa para os CDs: ";
            bool first = true;
            for (const auto& artist : unmatched_cd_artists) {
                if (!first) {
                    std::cout << ", ";
                }
                std::cout << artist;
                first = false;
            }
        }
        if (has_unmatched_cds && has_unmatched_covers) {
            std::cout << ". E ";
        }
        if (has_unmatched_covers) {
            std::cout << "os CDs para as capas: ";
            bool first = true;
            for (const auto& artist : unmatched_cover_artists) {
                if (!first) {
                    std::cout << ", ";
                }
                std::cout << artist;
                first = false;
            }
        }
        std::cout << ".\n";
    }

    return 0;
}
