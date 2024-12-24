/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 11
Notes or Remarks:
*/
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

struct Route {
    char origin[100];
    char destination[100];
    double distance;
    int time;
};

void swap(Route *a, Route *b) {
    Route temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Route arr[], int low, int high, bool sortByDistance) {
    Route pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (sortByDistance) {
            if (arr[j].distance <= pivot.distance) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        } else {
            if (arr[j].time <= pivot.time) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Route arr[], int low, int high, bool sortByDistance) {
    if (low < high) {
        int pi = partition(arr, low, high, sortByDistance);
        quickSort(arr, low, pi - 1, sortByDistance);
        quickSort(arr, pi + 1, high, sortByDistance);
    }
}

int main() {
    int n;
    std::cout << "Enter the number of routes: ";
    std::cin >> n;

    Route *routes = new Route[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Enter route " << i + 1 << " details:\n";
        std::cout << "Origin: ";
        std::cin >> routes[i].origin;
        std::cout << "Destination: ";
        std::cin >> routes[i].destination;
        std::cout << "Distance: ";
        std::cin >> routes[i].distance;
        std::cout << "Time: ";
        std::cin >> routes[i].time;
    }

    std::cout << "Sort by (distance or time): ";
    char criteria;
    std::cin >> criteria;

    bool sortByDistance = (criteria == 'd');
    quickSort(routes, 0, n - 1, sortByDistance);

    std::cout << "\nSorted Routes:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Origin: " << routes[i].origin << std::endl;
        std::cout << "Destination: " << routes[i].destination << std::endl;
        std::cout << "Distance: " << routes[i].distance << std::endl;
        std::cout << "Time: " << routes[i].time << std::endl;
        std::cout << std::endl;
    }

    delete[] routes;
    return 0;
}