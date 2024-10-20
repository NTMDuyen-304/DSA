/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session Homework - Exercise 01
Notes or Remarks: ......
*/
#include <iostream>
using namespace std;

const int MAX_DISKS = 3; // Number of disks

// Function to display the current state of the towers
void displayTowers(int A[], int B[], int C[]) {
    cout << "=========================\n";
    cout << "A Tower:"<<endl;
    cout << "Stack = <";
    for (int i = 0; i < MAX_DISKS; ++i) {
        if (A[i] != 0) cout << A[i] << " ";
    }
    cout << ">\n";

    cout << "B Tower: "<<endl;
    cout << "Stack = <";
    for (int i = 0; i < MAX_DISKS; ++i) {
        if (B[i] != 0) cout << B[i] << " ";
    }
    cout << ">\n";

    cout << "C Tower: "<<endl;
    cout << "Stack = <";
    for (int i = 0; i < MAX_DISKS; ++i) {
        if (C[i] != 0) cout << C[i] << " ";
    }
    cout << ">\n";
    cout << "=========================\n";
}

// Function to move a disk from one tower to another
bool moveDisk(int from[], int to[]) {
    int fromIndex = -1, toIndex = -1;

    // Find the top disk in 'from' tower
    for (int i = MAX_DISKS - 1; i >= 0; --i) {
        if (from[i] != 0) {
            fromIndex = i;
            break;
        }
    }

    // Find the top empty position in 'to' tower
    for (int i = 0; i < MAX_DISKS; ++i) {
        if (to[i] == 0) {
            toIndex = i;
            break;
        }
    }

    // Validate the move
    if (fromIndex == -1 || (toIndex > 0 && to[toIndex - 1] < from[fromIndex])) {
        return false; // Invalid move
    }

    // Move the disk
    to[toIndex] = from[fromIndex];
    from[fromIndex] = 0;
    return true;
}

bool isSolved(int C[]) {
    // Check if all disks are moved to Tower C in the correct order
    for (int i = 0; i < MAX_DISKS; ++i) {
        if (C[i] != MAX_DISKS - i) return false;
    }
    return true;
}

int main() {
    // Towers initialized as arrays
    int A[MAX_DISKS] = { 3, 2, 1 }; // Tower A with all disks
    int B[MAX_DISKS] = { 0 };       // Tower B (empty)
    int C[MAX_DISKS] = { 0 };       // Tower C (empty)

    int choice;
    cout << "========= Tower of Hanoi =========\n";
    cout << "0. Exit\n";
    cout << "1. A -> B\n";
    cout << "2. B -> A\n";
    cout << "3. B -> C\n";
    cout << "4. C -> B\n";
    cout << "5. C -> A\n";
    cout << "6. A -> C\n";

    while (true) {
        displayTowers(A, B, C); // Display current tower status
        cout << "Please input your move: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        // Perform the move based on user's choice
        bool validMove = false;
        switch (choice) {
            case 1: validMove = moveDisk(A, B); break; // A -> B
            case 2: validMove = moveDisk(B, A); break; // B -> A
            case 3: validMove = moveDisk(B, C); break; // B -> C
            case 4: validMove = moveDisk(C, B); break; // C -> B
            case 5: validMove = moveDisk(C, A); break; // C -> A
            case 6: validMove = moveDisk(A, C); break; // A -> C
            default:
                cout << "Invalid input! Try again.\n";
                continue;
        }

        if (!validMove) {
            cout << "Invalid move! Please try again.\n";
            continue;
        }

        // Check if the puzzle is solved
        if (isSolved(C)) {
            cout << "Congratulations! You solved the puzzle!\n";
            displayTowers(A, B, C);
            break;
        }
    }

    return 0;
}
