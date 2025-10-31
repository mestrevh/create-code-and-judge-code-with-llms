/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

struct AlbumInfo {
    std::string title;
    int status;
    int stars;
};

struct Artist {
    std::string name;
    std::vector<AlbumInfo> albums;
};

struct Album {
    std::string artistName;
    std::string albumTitle;
    int status;
    int stars;
};

struct SelectedAlbum {
    std::string artistName;
    std::string albumTitle;
    int status;
    int stars;
    int originalOrder;
};

bool compareArtists(const Artist& a, const Artist& b) {
    return a.name < b.name;
}

bool compareSelectedAlbums(const SelectedAlbum& a, const SelectedAlbum& b) {
    if (a.stars != b.stars) {
        return a.stars > b.stars;
    }
    return a.originalOrder < b.originalOrder;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Artist> artists;
    for (int i = 0; i < n; ++i) {
        Artist currentArtist;
        std::getline(std::cin, currentArtist.name);

        int m;
        std::cin >> m;
        
        currentArtist.albums.resize(m);
        for (int j = 0; j < m; ++j) {
            std::string starsStr;
            std::cin >> currentArtist.albums[j].title >> currentArtist.albums[j].status >> starsStr;
            currentArtist.albums[j].stars = starsStr.length();
        }
        artists.push_back(currentArtist);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::sort(artists.begin(), artists.end(), compareArtists);

    std::vector<Album> allAlbums;
    for (const auto& artist : artists) {
        for (const auto& albumInfo : artist.albums) {
            allAlbums.push_back({artist.name, albumInfo.title, albumInfo.status, albumInfo.stars});
        }
    }

    int idx1, idx2, idx3;
    std::cin >> idx1 >> idx2 >> idx3;

    std::vector<SelectedAlbum> selected;
    
    Album a1 = allAlbums[idx1 - 1];
    selected.push_back({a1.artistName, a1.albumTitle, a1.status, a1.stars, 1});

    Album a2 = allAlbums[idx2 - 1];
    selected.push_back({a2.artistName, a2.albumTitle, a2.status, a2.stars, 2});

    Album a3 = allAlbums[idx3 - 1];
    selected.push_back({a3.artistName, a3.albumTitle, a3.status, a3.stars, 3});

    std::sort(selected.begin(), selected.end(), compareSelectedAlbums);

    for (const auto& album : selected) {
        if (album.status == 1) {
            std::cout << "Infelizmente " << album.albumTitle << " ta emprestado:(\n";
        } else {
            std::cout << album.artistName << " - " << album.albumTitle << "\n";
        }
    }

    return 0;
}
