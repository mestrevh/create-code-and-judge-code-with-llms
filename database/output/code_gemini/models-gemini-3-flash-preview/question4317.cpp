/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct CD {
    string artist;
    string album;
    int status;
    int stars;
    int original_idx;
};

struct Artist {
    string name;
    vector<CD> cds;
};

bool artist_cmp(const Artist& a, const Artist& b) {
    return a.name < b.name;
}

bool cd_cmp(const CD& a, const CD& b) {
    if (a.stars != b.stars) {
        return a.stars > b.stars;
    }
    return a.original_idx < b.original_idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Artist> artists(N);
    for (int i = 0; i < N; ++i) {
        string artist_name;
        getline(cin >> ws, artist_name);
        artists[i].name = artist_name;
        int M;
        cin >> M;
        for (int j = 0; j < M; ++j) {
            string alb_name, stars_str;
            int status;
            cin >> alb_name >> status >> stars_str;
            CD cd;
            cd.artist = artist_name;
            cd.album = alb_name;
            cd.status = status;
            cd.stars = (int)stars_str.length();
            artists[i].cds.push_back(cd);
        }
    }

    sort(artists.begin(), artists.end(), artist_cmp);

    vector<CD> flat_list;
    for (int i = 0; i < N; ++i) {
        for (size_t j = 0; j < artists[i].cds.size(); ++j) {
            flat_list.push_back(artists[i].cds[j]);
        }
    }

    vector<CD> selected;
    for (int i = 0; i < 3; ++i) {
        int idx;
        if (cin >> idx) {
            if (idx >= 1 && idx <= (int)flat_list.size()) {
                CD chosen = flat_list[idx - 1];
                chosen.original_idx = i;
                selected.push_back(chosen);
            }
        }
    }

    sort(selected.begin(), selected.end(), cd_cmp);

    for (size_t i = 0; i < selected.size(); ++i) {
        if (selected[i].status == 1) {
            cout << "Infelizmente " << selected[i].album << " ta emprestado:(" << "\n";
        } else {
            cout << selected[i].artist << " - " << selected[i].album << "\n";
        }
    }

    return 0;
}