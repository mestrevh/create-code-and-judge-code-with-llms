/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long x1, y1, x2, y2;
    long long x3, y3, x4, y4;

    while (std::cin >> x1 >> y1 >> x2 >> y2) {
        std::cin >> x3 >> y3 >> x4 >> y4;

        long long den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

        if (den == 0) {
            std::cout << "NUNCA\n";
        } else {
            long long c1 = (x1 * y2 - y1 * x2);
            long long c2 = (x3 * y4 - y3 * x4);
            
            long long px_num = c1 * (x3 - x4) - (x1 - x2) * c2;
            long long py_num = c1 * (y3 - y4) - (y1 - y2) * c2;
            
            double px = static_cast<double>(px_num) / den;
            double py = static_cast<double>(py_num) / den;
            
            if (px == 0.0) px = 0.0;
            if (py == 0.0) py = 0.0;

            std::cout << std::fixed << std::setprecision(2) << px << " " << py << "\n";
        }
    }

    return 0;
}
