/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    for (int t = 1; t <= T; ++t) {
        int M;
        cin >> M;
        cin.ignore();
        
        map<string, float> musicDuration;
        vector<string> musicList;
        
        for (int i = 0; i < M; ++i) {
            string music;
            float duration;
            getline(cin, music);
            cin >> duration;
            cin.ignore();
            musicDuration[music] = duration;
            musicList.push_back(music);
        }
        
        string commands;
        getline(cin, commands);
        
        float totalDuration = 0.0;
        vector<string> playedMusic;
        int currentIndex = 0;
        
        for (char command : commands) {
            if (command == 'r') {
                if (currentIndex < musicList.size()) {
                    playedMusic.push_back(musicList[currentIndex]);
                    totalDuration += musicDuration[musicList[currentIndex]];
                }
            } else if (command == 'p') {
                currentIndex = (currentIndex + 1) % musicList.size(); 
            } else if (command == 'v') {
                if (!playedMusic.empty()) {
                    playedMusic.push_back(playedMusic.back());
                    totalDuration += musicDuration[playedMusic.back()];
                }
            } else if (command == 's') {
                break;
            }
        }
        
        cout << "Viagem " << t << ": " << fixed << setprecision(10) << totalDuration << endl;
        cout << (playedMusic.empty() ? "" : playedMusic.front());
        for (size_t i = 1; i < playedMusic.size(); ++i) {
            cout << ", " << playedMusic[i];
        }
        cout << endl;
    }
    
    return 0;
}
