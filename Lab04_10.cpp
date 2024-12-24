/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 10
Notes or Remarks:
*/
#include <iostream>
#include <string>
using namespace std;
struct Song {
    string title;
    string artist;
    int duration;
};

void heapify(Song arr[], int n, int i, string criteria) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (criteria == "artist") {
        if (left < n && arr[left].artist < arr[largest].artist)
            largest = left;
        if (right < n && arr[right].artist < arr[largest].artist)
            largest = right;
    } else if (criteria == "duration") {
        if (left < n && arr[left].duration < arr[largest].duration)
            largest = left;
        if (right < n && arr[right].duration < arr[largest].duration)
            largest = right;
    }

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, criteria);
    }
}

void heapSort(Song arr[], int n, string criteria) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, criteria);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, criteria);
    }
}

int main() {
    int n;
    cout << "Enter the number of songs: ";
    cin >> n;

    Song playlist[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter song " << i + 1 << " details:\n";
        cout << "Title: ";
        cin >> playlist[i].title;
        cout << "Artist: ";
        cin >> playlist[i].artist;
        cout << "Duration: ";
        cin >> playlist[i].duration;
    }

    string criteria;
    cout << "Sort by (artist or duration): ";
    cin >> criteria;

    heapSort(playlist, n, criteria);

    cout << "\nSorted Playlist:\n";
    for (int i = 0; i < n; i++) {
        cout << "Title: " << playlist[i].title << endl;
        cout << "Artist: " << playlist[i].artist << endl;
        cout << "Duration: " << playlist[i].duration << " minutes\n";
    }

    return 0;
}