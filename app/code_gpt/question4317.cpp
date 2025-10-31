/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>

struct Album {
    std::string title;
    int status;
    std::string rating;
};

struct Artist {
    std::string name;
    std::vector<Album> albums;
};

bool compare(const Album &a, const Album &b) {
    return std::tie(a.rating, a.title) > std::tie(b.rating, b.title);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Artist> artists(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> artists[i].name;
        int m;
        std::cin >> m;
        artists[i].albums.resize(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> artists[i].albums[j].title >> artists[i].albums[j].status >> artists[i].albums[j].rating;
        }
    }

    std::vector<int> indices(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> indices[i];
    }

    std::vector<std::tuple<std::string, Album>> selected;
    for (int i = 0; i < 3; ++i) {
        int index = indices[i] - 1;
        int artistIndex = 0;
        for (int j = 0; j < n; ++j) {
            if (index >= artists[j].albums.size()) {
                index -= artists[j].albums.size();
            } else {
                artistIndex = j;
                break;
            }
        }
        selected.emplace_back(artists[artistIndex].name, artists[artistIndex].albums[index]);
    }

    std::sort(selected.begin(), selected.end(), [](const auto &a, const auto &b) {
        return compare(std::get<1>(a), std::get<1>(b));
    });

    for (const auto &entry : selected) {
        const std::string &artist = std::get<0>(entry);
        const Album &album = std::get<1>(entry);
        if (album.status == 1) {
            std::cout << "Infelizmente " << album.title << " tá emprestado:(" << std::endl;
        } else {
            std::cout << artist << " - " << album.title << std::endl;
        }
    }
    return 0;
}
