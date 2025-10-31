/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, vector<string>> digits = {
    {'0', {" -- ", "|  |", "|  |", "    ", "|  |", "|  |", " -- "}},
    {'1', {"    ", "   |", "   |", "    ", "   |", "   |", "    "}},
    {'2', {" -- ", "   |", "   |", " -- ", "|   ", "|   ", " -- "}},
    {'3', {" -- ", "   |", "   |", " -- ", "   |", "   |", " -- "}},
    {'4', {"    ", "|  |", "|  |", " -- ", "   |", "   |", "    "}},
    {'5', {" -- ", "|   ", "|   ", " -- ", "   |", "   |", " -- "}},
    {'6', {" -- ", "|   ", "|   ", " -- ", "|  |", "|  |", " -- "}},
    {'7', {" -- ", "   |", "   |", "    ", "   |", "   |", "    "}},
    {'8', {" -- ", "|  |", "|  |", " -- ", "|  |", "|  |", " -- "}},
    {'9', {" -- ", "|  |", "|  |", " -- ", "   |", "   |", " -- "}}
};

void printLCD(int s, const string& number) {
    for (int row = 0; row < 2 * s + 3; ++row) {
        string line;
        for (char digit : number) {
            if (row == 0) line += digits[digit][0];
            else if (row == 1 || row == 2) line += (row == 1 ? (digits[digit][1] + string(s-1, ' ')) : (digits[digit][2] + string(s-1, ' ')));
            else if (row == s + 3) line += digits[digit][3];
            else if (row > s + 3) line += (row - s - 4 == 0 || row - s - 4 == 1 ? (digits[digit][4] + string(s - 1, ' ')) : (digits[digit][5] + string(s - 1, ' ')));
            else line += (row == 3 * s + 2 ? digits[digit][6] : string(s + 2, ' '));
            line += " ";
        }
        cout << line << endl;
    }
    cout << endl;
}

int main() {
    int s;
    string n;
    
    while (true) {
        cin >> s >> n;
        if (s == 0 && n == "0") break;
        printLCD(s, n);
    }

    return 0;
}
