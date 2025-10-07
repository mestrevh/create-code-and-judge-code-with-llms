/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int M;
    std::cin >> M;
    
    std::vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) std::cin >> A[i];
    for (int i = 0; i < M; i++) std::cin >> B[i];
    
    std::set<int> intersection;
    std::set<int> setA(A.begin(), A.end());
    
    for (const int &b : B) {
        if (setA.count(b)) intersection.insert(b);
    }

    std::vector<int> result(intersection.begin(), intersection.end());
    std::sort(result.begin(), result.end());
    
    for (const int &num : result) {
        std::cout << num << std::endl;
    }
    
    return 0;
}
