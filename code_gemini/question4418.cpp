/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    map<char, int> counts;
    char c;
    int n;
    while (cin >> c && c != 'x') {
        cin >> n;
        counts[c] = n;
    }

    int max_count = 0;
    for (auto const& [key, val] : counts) {
        max_count = max(max_count, val);
    }

    vector<string> grid(max_count + 1, string(20, '.'));

    for (auto const& [key, val] : counts) {
        for (int i = 0; i < val; ++i) {
            grid[i][counts.size() * 4 - 4] = '|';
        }
        grid[val][counts.size() * 4 - 4] = (key < 'g' ? '-' : '<');
         grid[val][counts.size() * 4 - 3] = (key < 'g' ? '-' : '-');
          grid[val][counts.size() * 4 - 2] = (key < 'g' ? '-' : '-');
           grid[val][counts.size() * 4 - 1] = (key < 'g' ? '>' : '<');

            for (int i = counts.size() * 4 - 5; i >= (key < 'g' ? 0 : counts.size() * 4 -5 - (val-1) * 4) ; i-=4) {
               if(key < 'g'){
                 grid[val-1][i] = '-';
                grid[val-1][i+1] = '-';
                grid[val-1][i+2] = '-';
                 grid[val-1][i+3] = '-';
                 
                 
               }
                else{
                    grid[i/4][counts.size() * 4 -5 - (val-1)*4 + 3] = '|';
                }
            }


        
        
        grid[0][(key - 'a')*4] = '.';
        grid[0][(key - 'a')*4 +1 ] = '-';';
        grid[0][(key - 'a')*4 + 2] = '-';';
        grid[0][(key - 'a')*4 + 3] = '-';';
        grid[0][(key - 'a')*4 + 4] = '>';

        

    }



    for (const auto& row : grid) {
        cout << row << endl;
    }

    return 0;
}
