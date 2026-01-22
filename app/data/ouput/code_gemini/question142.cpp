/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int note_to_int(const std::string& s) {
    int val;
    switch (s[0]) {
        case 'C': val = 0; break;
        case 'D': val = 2; break;
        case 'E': val = 4; break;
        case 'F': val = 5; break;
        case 'G': val = 7; break;
        case 'A': val = 9; break;
        case 'B': val = 11; break;
        default: val = 0; break;
    }
    if (s.length() > 1) {
        if (s[1] == '#') {
            val++;
        } else if (s[1] == 'b') {
            val--;
        }
    }
    return (val + 12) % 12;
}

void computeLPS(const std::vector<int>& pattern, std::vector<int>& lps) {
    int m = pattern.size();
    lps.assign(m, 0);
    int length = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool kmpSearch(const std::vector<int>& text, const std::vector<int>& pattern) {
    int n = text.size();
    int m = pattern.size();

    if (n < m) {
        return false;
    }

    std::vector<int> lps(m);
    computeLPS(pattern, lps);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            return true;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, T;
    while (std::cin >> M >> T && (M != 0 || T != 0)) {
        std::vector<int> music_notes(M);
        for (int i = 0; i < M; ++i) {
            std::string note_str;
            std::cin >> note_str;
            music_notes[i] = note_to_int(note_str);
        }

        std::vector<int> trecho_notes(T);
        for (int i = 0; i < T; ++i) {
            std::string note_str;
            std::cin >> note_str;
            trecho_notes[i] = note_to_int(note_str);
        }

        if (T > M) {
            std::cout << "N\n";
            continue;
        }

        if (T <= 1) {
            std::cout << "S\n";
            continue;
        }

        std::vector<int> music_intervals(M - 1);
        for (int i = 0; i < M - 1; ++i) {
            music_intervals[i] = (music_notes[i + 1] - music_notes[i] + 12) % 12;
        }

        std::vector<int> trecho_intervals(T - 1);
        for (int i = 0; i < T - 1; ++i) {
            trecho_intervals[i] = (trecho_notes[i + 1] - trecho_notes[i] + 12) % 12;
        }

        if (kmpSearch(music_intervals, trecho_intervals)) {
            std::cout << "S\n";
        } else {
            std::cout << "N\n";
        }
    }

    return 0;
}
