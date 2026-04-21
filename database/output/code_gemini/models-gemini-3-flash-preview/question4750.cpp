/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> levels(4);
    for (int i = 0; i < 4; ++i) {
        if (!(std::cin >> levels[i])) break;
    }

    std::sort(levels.begin(), levels.end());

    // With sorted levels a <= b <= c <= d, the minimum difference 
    // between two teams (sums of pairs) is always |(a + d) - (b + c)|.
    int sum1 = levels[0] + levels[3];
    int sum2 = levels[1] + levels[2];
    int diff = sum1 - sum2;
    if (diff < 0) diff = -diff;

    std::cout << diff << std::endl;

    return 0;
}