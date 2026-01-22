/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int main() {
    std::vector<double> numbers;
    double num, sum = 0.0;

    while (std::cin >> num && num != -1) {
        numbers.push_back(num);
        sum += num;
    }
    
    int n = numbers.size();
    double mean = sum / n;
    double variance = 0.0;
    
    for (double x : numbers) {
        variance += (x - mean) * (x - mean);
    }
    variance /= n;
    double stddev = std::sqrt(variance);
    
    int countGreaterThanMean = 0;
    for (double x : numbers) {
        if (x > mean) countGreaterThanMean++;
    }

    std::cout << std::fixed << std::setprecision(2) << mean << std::endl;
    std::cout << std::fixed << std::setprecision(2) << stddev << std::endl;
    std::cout << countGreaterThanMean << std::endl;

    return 0;
}
