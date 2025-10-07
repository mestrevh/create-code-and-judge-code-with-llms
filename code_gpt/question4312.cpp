/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <set>
#include <sstream>

int main() {
    std::string text1, text2;
    scanf("%[^'\n']%*c%[^'\n']%*c", &text1, &text2);
    
    std::set<std::string> words;
    std::istringstream stream1(text1), stream2(text2);
    std::string word;

    while (stream1 >> word) {
        words.insert(word);
    }
    int count1 = std::distance(std::istream_iterator<std::string>(stream1), std::istream_iterator<std::string>());

    while (stream2 >> word) {
        words.insert(word);
    }
    int count2 = std::distance(std::istream_iterator<std::string>(stream2), std::istream_iterator<std::string>());

    double plagiarismIndex = static_cast<double>(words.size()) / (count1 + count2) * 100;
    printf("%.1f\n", plagiarismIndex);

    return 0;
}
