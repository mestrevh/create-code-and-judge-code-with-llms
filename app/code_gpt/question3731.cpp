/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int next_prime(int num) {
    while (true) {
        num++;
        if (is_prime(num)) return num;
    }
}

int digit_sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void move_books(int *codigo, int *posicao) {
    int n = 100;
    vector<bool> used_code(1000, false);
    vector<bool> used_pos(1000, false);
    vector<pair<int, int>> books;

    for (int i = 0; i < n; i++) {
        if (codigo[i] == 0) break;
        
        // Calculate new code
        int new_code = (codigo[i] + next_prime(codigo[i])) / digit_sum(codigo[i]);
        // Calculate new position
        int sum_multiples = 0;
        for (int j = 6; j < codigo[i]; j += 6)
            sum_multiples += j;
        
        int new_pos = (sum_multiples - posicao[i]) % 1000;
        if (new_pos < 0) new_pos += 1000;

        // Resolve duplicates
        while (used_code[new_code] || used_pos[new_pos]) {
            if (used_code[new_code]) new_code++;
            if (used_pos[new_pos]) new_pos++;
        }

        used_code[new_code] = true;
        used_pos[new_pos] = true;
        books.push_back({new_code, new_pos});
    }

    for (int i = books.size() - 1; i >= 0; i--) {
        cout << books[i].first << " - " << books[i].second << endl;
    }
}

int main() {
    int codigo[100], posicao[100], m, n, index = 0;

    while (true) {
        cin >> m >> n;
        if (m == 0) break;
        codigo[index] = m;
        posicao[index] = n;
        index++;
    }

    move_books(codigo, posicao);
    return 0;
}
