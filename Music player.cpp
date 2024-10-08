/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 02 - Exercise 01
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;

class MusicPlayer {
private:
    list<string> playlist;                         // Doubly linked list to store playlist
    unordered_map<string, list<string>::iterator> songMap;  // Map to quickly find song positions
    list<string>::iterator currentSong;            // Iterator pointing to the current song

public:
    MusicPlayer() {
        currentSong = playlist.end();              // Initialize currentSong to the end of the playlist
    }

    // Add a new song to the playlist
    void addSong(const string& songName) {
        playlist.push_back(songName);              // Add the song to the end of the playlist
        songMap[songName] = --playlist.end();      // Store the iterator to the new song in songMap

        if (playlist.size() == 1) {
            currentSong = playlist.begin();        // If the playlist only has one song, set it as currentSong
        }
    }

    // Play the next song
    void playNext() {
        if (playlist.empty()) return;              // If playlist is empty, do nothing
        currentSong++;
        if (currentSong == playlist.end()) {       // If at the end, loop back to the first song
            currentSong = playlist.begin();
        }
    }

    // Play the previous song
    void playPrev() {
        if (playlist.empty()) return;              // If playlist is empty, do nothing
        if (currentSong == playlist.begin()) {     // If at the first song, loop to the last song
            currentSong = --playlist.end();
        } else {
            currentSong--;
        }
    }

    // Remove a song from the playlist by name
    void removeSong(const string& songName) {
        if (songMap.find(songName) == songMap.end()) return;  // If song doesn't exist, do nothing

        if (currentSong == songMap[songName]) {               // If current song is being removed
            if (next(currentSong) == playlist.end()) {        // If it's the last song, move to the first song
                currentSong = playlist.begin();
            } else {
                currentSong++;                                // Otherwise, move to the next song
            }
        }

        playlist.erase(songMap[songName]);        // Remove the song from the playlist
        songMap.erase(songName);                  // Remove the song from the map
    }

    // Display the current playlist
    void display() const {
        for (const string& song : playlist) {
            cout << song << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;  // Number of operations

    MusicPlayer player;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string songName;
            cin >> songName;
            player.addSong(songName);
        } else if (command == "NEXT") {
            player.playNext();
        } else if (command == "PREV") {
            player.playPrev();
        } else if (command == "REMOVE") {
            string songName;
            cin >> songName;
            player.removeSong(songName);
        } else if (command == "DISPLAY") {
            player.display();
        }
    }

    return 0;
}
