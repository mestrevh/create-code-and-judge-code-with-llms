/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int nA, nB, k, m;
    std::cin >> nA >> nB >> k >> m;
    std::vector<int> A(nA), B(nB);
    
    for (int i = 0; i < nA; ++i) std::cin >> A[i];
    for (int i = 0; i < nB; ++i) std::cin >> B[i];
    
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    
    if (A[k - 1] < B[nB - m]) 
        std::cout << "YES" << std::endl;
    else 
        std::cout << "NO" << std::endl;

    return 0;
}
