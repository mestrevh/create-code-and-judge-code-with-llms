/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Movie {
    std::string name;
    int r, d, a;
};

int getScore(const Movie& movie, char category) {
    if (category == 'R') return movie.r;
    if (category == 'D') return movie.d;
    return movie.a;
}

void printMovie(const Movie& movie) {
    std::cout << movie.name << ": R " << movie.r << ", D " << movie.d << ", A " << movie.a << std::endl;
}

void heapify(std::vector<Movie>& arr, int n, int i, char category) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && getScore(arr[l], category) < getScore(arr[smallest], category)) {
        smallest = l;
    }

    if (r < n && getScore(arr[r], category) < getScore(arr[smallest], category)) {
        smallest = r;
    }

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest, category);
    }
}

void heapSort(std::vector<Movie>& arr, char category) {
    int n = arr.size();
    if (n <= 1) return;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, category);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, category);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Movie> catalog;
    std::string command;

    while (std::cin >> command && command != "END") {
        if (command == "ADD") {
            Movie m;
            std::cin >> m.name >> m.r >> m.d >> m.a;
            catalog.push_back(m);
        } else if (command == "DEL") {
            std::string movieName;
            std::cin >> movieName;
            for (int i = catalog.size() - 1; i >= 0; --i) {
                if (catalog[i].name == movieName) {
                    catalog.erase(catalog.begin() + i);
                    break;
                }
            }
        } else if (command == "SHOW") {
            char category;
            std::cin >> category;
            std::vector<Movie> tempCatalog = catalog;
            heapSort(tempCatalog, category);
            for (const auto& movie : tempCatalog) {
                printMovie(movie);
            }
        } else if (command == "FIRST" || command == "LAST") {
            char category;
            int score;
            std::cin >> category >> score;

            std::vector<Movie> tempCatalog = catalog;
            heapSort(tempCatalog, category);

            bool found = false;
            if (command == "FIRST") {
                for (const auto& movie : tempCatalog) {
                    if (getScore(movie, category) == score) {
                        printMovie(movie);
                        found = true;
                        break;
                    }
                }
            } else { // LAST
                for (int i = tempCatalog.size() - 1; i >= 0; --i) {
                    if (getScore(tempCatalog[i], category) == score) {
                        printMovie(tempCatalog[i]);
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                std::cout << "Nenhum" << std::endl;
            }
        }
    }

    return 0;
}
