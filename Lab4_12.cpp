/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 12
Notes or Remarks:
*/
#include <bits/stdc++.h>
using namespace std;

struct Stock {
    char companyName[100];
    double price;
    char timestamp[50];
};

void swap(Stock* a, Stock* b) {
    Stock temp = *a;
    *a = *b;
    *b = temp;
}

double calculatePercentageChange(Stock current, Stock previous) {
    if (previous.price == 0) {
        return 0; // Handle division by zero
    }
    return (current.price - previous.price) / previous.price * 100;
}

int partition(Stock arr[], int low, int high, bool sortByPrice) {
    Stock pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (sortByPrice) {
            if (arr[j].price <= pivot.price) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        } else {
            if (j > low) { // Avoid out-of-bounds access
                double percentageChange = calculatePercentageChange(arr[j], arr[j - 1]);
                double pivotPercentageChange = calculatePercentageChange(pivot, arr[high - 1]);
                if (percentageChange <= pivotPercentageChange) {
                    i++;
                    swap(&arr[i], &arr[j]);
                }
            }
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Stock arr[], int low, int high, bool sortByPrice) {
    if (low < high) {
        int pi = partition(arr, low, high, sortByPrice);
        quickSort(arr, low, pi - 1, sortByPrice);
        quickSort(arr, pi + 1, high, sortByPrice);
    }
}

int readData(Stock arr[], int n, const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 0; // Return 0 if file cannot be opened
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp) && i < n) {
        sscanf(line, "%[^,],%lf,%s", arr[i].companyName, &arr[i].price, arr[i].timestamp);
        i++;
    }

    fclose(fp);
    return i; // Return the actual number of stocks read
}

int main() {
    const int MAX_STOCKS = 1000;
    Stock stocks[MAX_STOCKS];

    int n = readData(stocks, MAX_STOCKS, "stocks.csv");
    if (n == 0) {
        return 1; // Exit if no data was read
    }

    printf("Sort by (price or percentage change)? (p/c): ");
    char criteria;
    scanf(" %c", &criteria); // Space before %c to handle newline characters

    bool sortByPrice = (criteria == 'p');
    quickSort(stocks, 0, n - 1, sortByPrice);

    // Print sorted stocks
    for (int i = 0; i < n; i++) {
        printf("Company: %s\n", stocks[i].companyName);
        printf("Price: %.2f\n", stocks[i].price);
        printf("Timestamp: %s\n\n", stocks[i].timestamp);
    }

    return 0;
}
