/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string original;
    long long id;
};

bool compareBooks(const Book& a, const Book& b) {
    return a.id < b.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    string line;
    getline(cin, line); // Consome a quebra de linha após a leitura de N

    vector<Book> books;
    books.reserve(n);

    for (int i = 0; i < n; ++i) {
        if (!getline(cin, line)) break;
        if (line.empty()) {
            i--;
            continue;
        }

        size_t pos = line.find_last_of('#');
        if (pos != string::npos) {
            try {
                long long id = stoll(line.substr(pos + 1));
                books.push_back({line, id});
            } catch (...) {
                // Em caso de erro na conversão, ignora ou trata conforme necessário
            }
        }
    }

    sort(books.begin(), books.end(), compareBooks);

    for (const auto& b : books) {
        cout << b.original << "\n";
    }

    return 0;
}