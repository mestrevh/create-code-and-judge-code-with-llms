/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Movie {
    string name;
    int r, d, a;
    int id;
};

bool compare(const Movie& m1, const Movie& m2, char cat) {
    int v1, v2;
    if (cat == 'R') {
        v1 = m1.r; v2 = m2.r;
    } else if (cat == 'D') {
        v1 = m1.d; v2 = m2.d;
    } else {
        v1 = m1.a; v2 = m2.a;
    }
    if (v1 != v2) return v1 > v2;
    return m1.id < m2.id;
}

void merge(vector<Movie>& arr, int l, int m, int r, char cat, vector<Movie>& tmp) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (compare(arr[i], arr[j], cat)) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while (i <= m) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    for (int x = l; x <= r; x++) arr[x] = tmp[x];
}

void mergeSort(vector<Movie>& arr, int l, int r, char cat, vector<Movie>& tmp) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, cat, tmp);
        mergeSort(arr, m + 1, r, cat, tmp);
        merge(arr, l, m, r, cat, tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Movie> movies;
    vector<Movie> tmp;
    string cmd;
    int current_id = 0;

    while (cin >> cmd && cmd != "END") {
        if (cmd == "ADD") {
            string name;
            int r, d, a;
            cin >> name >> r >> d >> a;
            movies.push_back({name, r, d, a, current_id++});
        } else if (cmd == "DEL") {
            string name;
            cin >> name;
            for (int i = (int)movies.size() - 1; i >= 0; i--) {
                if (movies[i].name == name) {
                    movies.erase(movies.begin() + i);
                    break;
                }
            }
        } else if (cmd == "SHOW") {
            char cat;
            cin >> cat;
            if (!movies.empty()) {
                tmp.resize(movies.size());
                mergeSort(movies, 0, (int)movies.size() - 1, cat, tmp);
                for (const auto& m : movies) {
                    cout << m.name << ": R " << m.r << ", D " << m.d << ", A " << m.a << "\n";
                }
            }
        } else if (cmd == "FIRST") {
            char cat;
            int n;
            cin >> cat >> n;
            if (!movies.empty()) {
                tmp.resize(movies.size());
                mergeSort(movies, 0, (int)movies.size() - 1, cat, tmp);
                int found = -1;
                for (int i = 0; i < (int)movies.size(); i++) {
                    int val = (cat == 'R' ? movies[i].r : (cat == 'D' ? movies[i].d : movies[i].a));
                    if (val == n) {
                        found = i;
                        break;
                    }
                }
                if (found != -1) {
                    cout << movies[found].name << ": R " << movies[found].r << ", D " << movies[found].d << ", A " << movies[found].a << "\n";
                } else {
                    cout << "Nenhum\n";
                }
            } else {
                cout << "Nenhum\n";
            }
        } else if (cmd == "LAST") {
            char cat;
            int n;
            cin >> cat >> n;
            if (!movies.empty()) {
                tmp.resize(movies.size());
                mergeSort(movies, 0, (int)movies.size() - 1, cat, tmp);
                int found = -1;
                for (int i = (int)movies.size() - 1; i >= 0; i--) {
                    int val = (cat == 'R' ? movies[i].r : (cat == 'D' ? movies[i].d : movies[i].a));
                    if (val == n) {
                        found = i;
                        break;
                    }
                }
                if (found != -1) {
                    cout << movies[found].name << ": R " << movies[found].r << ", D " << movies[found].d << ", A " << movies[found].a << "\n";
                } else {
                    cout << "Nenhum\n";
                }
            } else {
                cout << "Nenhum\n";
            }
        }
    }

    return 0;
}