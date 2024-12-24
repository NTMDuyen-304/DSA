/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 08
Notes or Remarks:
*/
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <random>
using namespace std;

// Add function declarations
void quickSort(vector<int>& arr) {
    // Quick sort implementation
    if (arr.size() <= 1) return;
    
    int pivot = arr[arr.size()/2];
    vector<int> left, right;
    
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

void hybridSort(vector<int>& arr) {
    const int INSERTION_THRESHOLD = 10;
    
    if (arr.size() <= INSERTION_THRESHOLD) {
        // Use insertion sort for small arrays
        for (size_t i = 1; i < arr.size(); i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    } else {
        // Use quicksort for larger arrays
        int pivot = arr[arr.size()/2];
        vector<int> left, right;
        
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

vector<int> generateRandomList(int size, int min = 1, int max = 1000) {
    vector<int> list(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    for (int& num : list) {
        num = dist(gen);
    }
    return list;
}

template <typename Func>
void measureTime(Func func, vector<int> arr, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    func(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << sortName << " took " << duration.count() << " seconds.\n";
}

void HybridSorting() {
    vector<int> sizes = { 10, 100, 1000, 10000 };
    for (int size : sizes) {
        cout << "\nTesting with size: " << size << "\n";
        auto originalList = generateRandomList(size);
        vector<int> quickSortList = originalList;
        measureTime(quickSort, quickSortList, "Quick Sort");
        vector<int> hybridSortList = originalList;
        measureTime(hybridSort, hybridSortList, "Hybrid Sort");
    }
}

int main() {
    HybridSorting();
    return 0;
}