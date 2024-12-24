/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 00
Notes or Remarks:
*/
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <random>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    double distanceFromOrigin() const {
        return sqrt(x*x + y*y);
    }
    
    bool operator<=(const Point& other) const {
        return distanceFromOrigin() <= other.distanceFromOrigin();
    }
};

// Generate random points
vector<Point> generateRandomPoints(int size) {
    vector<Point> points(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(-1000.0, 1000.0);
    
    for (Point& p : points) {
        p.x = dist(gen);
        p.y = dist(gen);
    }
    return points;
}

// Modified quickSort for Points
void quickSort(vector<Point>& arr) {
    if (arr.size() <= 1) return;
    
    Point pivot = arr[arr.size()/2];
    vector<Point> left, right;
    
    for (size_t i = 0; i < arr.size(); i++) {
        if (i == arr.size()/2) continue;
        if (arr[i] <= pivot)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    
    quickSort(left);
    quickSort(right);
    
    arr.clear();
    arr.insert(arr.end(), left.begin(), left.end());
    arr.push_back(pivot);
    arr.insert(arr.end(), right.begin(), right.end());
}

// Modified hybridSort for Points
void hybridSort(vector<Point>& arr) {
    const int INSERTION_THRESHOLD = 10;
    
    if (arr.size() <= INSERTION_THRESHOLD) {
        for (size_t i = 1; i < arr.size(); i++) {
            Point key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j].distanceFromOrigin() > key.distanceFromOrigin()) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    } else {
        Point pivot = arr[arr.size()/2];
        vector<Point> left, right;
        
        for (size_t i = 0; i < arr.size(); i++) {
            if (i == arr.size()/2) continue;
            if (arr[i] <= pivot)
                left.push_back(arr[i]);
            else
                right.push_back(arr[i]);
        }
        
        hybridSort(left);
        hybridSort(right);
        
        arr.clear();
        arr.insert(arr.end(), left.begin(), left.end());
        arr.push_back(pivot);
        arr.insert(arr.end(), right.begin(), right.end());
    }
}

template <typename Func>
void measureTime(Func func, vector<Point> arr, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    func(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds.\n";
}

void Exercise09() {
    vector<int> sizes = { 10, 100, 1000, 10000 };
    for (int size : sizes) {
        cout << "\nTesting with size: " << size << "\n";
        auto originalList = generateRandomPoints(size);
        vector<Point> quickSortList = originalList;
        measureTime(quickSort, quickSortList, "Quick Sort");
        vector<Point> hybridSortList = originalList;
        measureTime(hybridSort, hybridSortList, "Hybrid Sort");
    }
}
int main() {
    Exercise09();
    return 0;
}