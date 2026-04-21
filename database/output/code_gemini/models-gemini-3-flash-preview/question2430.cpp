/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Problem: Playlist (Antônio's commute music)
 * Logic:
 * - 'r' (reproduce): Play current song, then move cursor to next.
 * - 'p' (skip): Skip current song, move cursor to next.
 * - 'v' (replay): Play the song that was most recently played.
 * - 's' (stop): End the trip.
 * 
 * Data: Songs are stored in a list with names and durations.
 * Complexity: O(T * (M + |commands|))
 */

struct Song {
    string name;
    double duration;
};

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        int M;
        if (!(cin >> M)) break;
        
        // Consume newline after M to prepare for getline
        cin.ignore(1000, '\n');

        vector<Song> playlist(M);
        for (int i = 0; i < M; ++i) {
            getline(cin, playlist[i].name);
            // Handle possible Windows-style carriage return
            if (!playlist[i].name.empty() && playlist[i].name.back() == '\r') {
                playlist[i].name.pop_back();
            }
            cin >> playlist[i].duration;
            // Consume newline after duration
            cin.ignore(1000, '\n');
        }

        string commands;
        if (!(cin >> commands)) commands = "";

        vector<string> reproducedSongs;
        double totalDuration = 0.0;
        int currentIndex = 0;
        int lastReproducedIndex = -1;

        for (char cmd : commands) {
            if (cmd == 's') {
                break;
            } else if (cmd == 'r') {
                if (currentIndex < M) {
                    reproducedSongs.push_back(playlist[currentIndex].name);
                    totalDuration += playlist[currentIndex].duration;
                    lastReproducedIndex = currentIndex;
                    currentIndex++;
                }
            } else if (cmd == 'p') {
                if (currentIndex < M) {
                    currentIndex++;
                }
            } else if (cmd == 'v') {
                if (lastReproducedIndex != -1) {
                    reproducedSongs.push_back(playlist[lastReproducedIndex].name);
                    totalDuration += playlist[lastReproducedIndex].duration;
                    // lastReproducedIndex remains the same
                }
            }
        }

        // Output results
        // setprecision(17) is used to match the raw double precision seen in sample outputs
        cout << "Viagem " << t << ": " << setprecision(17) << totalDuration << "\n";
        for (size_t i = 0; i < reproducedSongs.size(); ++i) {
            cout << reproducedSongs[i] << (i + 1 == reproducedSongs.size() ? "" : ", ");
        }
        cout << "\n";
    }

    return 0;
}