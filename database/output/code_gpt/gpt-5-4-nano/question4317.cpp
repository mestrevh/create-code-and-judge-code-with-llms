/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Album {
    string artist;
    string title;
    int borrowed;
    int rating;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Album> albums;
    albums.reserve(200000);

    for (int i = 0; i < N; i++) {
        string artist;
        cin >> ws;
        getline(cin, artist);
        if (artist.empty()) getline(cin, artist);

        int M;
        cin >> M;

        for (int j = 0; j < M; j++) {
            string title;
            int state;
            string stars;
            cin >> title >> state >> stars;

            int rating = 0;
            for (char c : stars) if (c == '*') rating++;

            Album a;
            a.artist = artist;
            a.title = title;
            a.borrowed = state;
            a.rating = rating;
            albums.push_back(a);
        }
    }

    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    vector<int> pos = {x1, x2, x3};
    vector<string> requestedTitles;
    requestedTitles.reserve(3);

    for (int k = 0; k < 3; k++) {
        int idx = pos[k];
        idx--;
        if (idx < 0 || idx >= (int)albums.size()) requestedTitles.push_back("");
        else requestedTitles.push_back(albums[idx].title);
    }

    map<pair<string,string>, int> posMap;
    for (int idx = 0; idx < (int)albums.size(); idx++) {
        posMap[{albums[idx].artist, albums[idx].title}] = idx + 1;
    }

    vector<int> sortedIdx(albums.size());
    iota(sortedIdx.begin(), sortedIdx.end(), 0);

    sort(sortedIdx.begin(), sortedIdx.end(), [&](int ia, int ib) {
        const Album &A = albums[ia], &B = albums[ib];
        if (A.rating != B.rating) return A.rating > B.rating;
        if (A.artist != B.artist) return A.artist < B.artist;
        return A.title < B.title;
    });

    vector<Album> chosen;
    chosen.reserve(3);

    auto wantRank = [&](int rankPos) -> Album {
        int rankIdx = rankPos - 1;
        if (rankIdx < 0 || rankIdx >= (int)sortedIdx.size()) return Album();
        return albums[sortedIdx[rankIdx]];
    };

    Album c1 = wantRank(x1);
    Album c2 = wantRank(x2);
    Album c3 = wantRank(x3);
    chosen = {c1, c2, c3};

    vector<pair<int,int>> order; 
    order.reserve(3);
    vector<int> chosenRanks = {x1, x2, x3};
    for (int i = 0; i < 3; i++) order.push_back({chosenRanks[i], i});
    stable_sort(order.begin(), order.end(), [](auto &p1, auto &p2){ return p1.first < p2.first; });

    for (int t = 0; t < 3; t++) {
        int idx = order[t].second;
        Album &a = chosen[idx];
        if (a.artist.empty() && a.title.empty() && a.rating==0 && a.borrowed==0) {
            continue;
        }
        if (a.borrowed == 1) {
            cout << "Infelizmente " << a.title << " tá emprestado:(";
        } else {
            cout << a.artist << " - " << a.title;
        }
        if (t != 2) cout << "\n";
    }

    return 0;
}