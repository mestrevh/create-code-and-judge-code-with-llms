/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string text;
    getline(cin, text);

    string result = "";
    stack<char> deleted_chars;

    for (char c : text) {
        if (c == '<') {
            if (text.substr(text.find('<') + 1, 1) == "B" || text.substr(text.find('<')+1, 1) == "b") {
                if (!result.empty()) {
                    deleted_chars.push(result.back());
                    result.pop_back();
                }
               text.erase(text.find('<'), 3);
            } else if (text.substr(text.find('<') + 1, 1) == "Z" || text.substr(text.find('<') + 1, 1) == "z") {
                if (!deleted_chars.empty()) {
                    result += deleted_chars.top();
                    deleted_chars.pop();
                }
                text.erase(text.find('<'), 3);
            }
         
        }
         else if(c != '<'){
             result += c;
         }
    }

    cout << result << endl;

    return 0;
}
