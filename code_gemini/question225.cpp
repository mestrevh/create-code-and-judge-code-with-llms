/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

const int MAX_SKILL = 100001;
long long bit[MAX_SKILL + 1];

void update(int index, int delta) {
    for (; index <= MAX_SKILL; index += index & -index) {
        bit[index] += delta;
    }
}

long long query(int index) {
    long long sum = 0;
    for (; index > 0; index -= index & -index) {
        sum += bit[index];
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    long long valid_pairs = 0;
    for (int i = 0; i < n; ++i) {
        int current_skill;
        std::cin >> current_skill;
        
        valid_pairs += (long long)i - query(current_skill);
        
        update(current_skill, 1);
    }

    std::cout << valid_pairs << "\n";

    return 0;
}
