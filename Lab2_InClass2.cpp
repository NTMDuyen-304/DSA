/*
MSSV: 22520350 
Full name: Nguyen Thi My Duyen 
Lab2 - In-Class Part 2
*/
#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node *head, *tail;

public:
    // 1. Implement a queue using linked list
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    // 2. Check if the queue is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // 3. Check if the queue is full (linked list queues are never full unless memory is exhausted)
    bool isFull() {
        return false; // Always returns false for a linked list-based queue
    }

    // Enqueue: Add element to the end of the queue
    void enqueue(int val) {
        Node *newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Dequeue: Remove element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
    }

    // Get the front element of the queue
    int front() {
        if (isEmpty()) throw runtime_error("Queue is empty.");
        return head->value;
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
};

// 4. Simulate the bank queue scenario
void bankScenario() {
    Queue bankQueue;
    srand(time(0)); // Seed for random number generation

    // Simulate customers arriving at the bank (IDs 1 to 10)
    for (int i = 1; i <= 10; ++i) {
        bankQueue.enqueue(i);
    }

    cout << "Initial queue: ";
    bankQueue.display();

    // Simulate the teller assisting customers
    for (int i = 0; i < 10; ++i) {
        int customer = bankQueue.front();
        bankQueue.dequeue();

        // 25% chance that a customer has insufficient paperwork
        if (rand() % 4 == 0) {
            cout << "Customer " << customer << " has insufficient paperwork, returning to the end of the queue.\n";
            bankQueue.enqueue(customer);  // Customer goes to the end of the queue
        } else {
            cout << "Customer " << customer << " is being assisted.\n";
        }
    }

    cout << "Final queue: ";
    bankQueue.display();
}

// 5. Pairing on the dance floor
void enterDancers(Queue &q) {
    string s;
    while (true) {
        cin >> s;
        if (s == "0") break;
        q.enqueue(s[0]); // Store first character (assuming first character of name is used)
    }
}

void dancePairing() {
    Queue maleQueue, femaleQueue;
    
    cout << "Enter the male's name (0 to stop): \n";
    enterDancers(maleQueue);
    
    cout << "Enter the female's name (0 to stop): \n";
    enterDancers(femaleQueue);

    while (!maleQueue.isEmpty() && !femaleQueue.isEmpty()) {
        cout << "Pairing: Male " << char(maleQueue.front()) << " with Female " << char(femaleQueue.front()) << '\n';
        maleQueue.dequeue();
        femaleQueue.dequeue();
    }

    // Handling the "spares"
    if (!maleQueue.isEmpty()) cout << "Spare males: ";
    while (!maleQueue.isEmpty()) {
        cout << char(maleQueue.front()) << " ";
        maleQueue.dequeue();
    }

    if (!femaleQueue.isEmpty()) cout << "Spare females: ";
    while (!femaleQueue.isEmpty()) {
        cout << char(femaleQueue.front()) << " ";
        femaleQueue.dequeue();
    }
    cout << '\n';
}

// Main function with menu
int main() {
    Queue myQueue;
    int choice;

    do {
        cout << "Menu: "<< endl;
        cout << "1. Implement a queue:"<< endl;
        cout << "2. Input and display the queue: "<< endl;
        cout << "3. Check if the queue is empty: "<< endl;
        cout << "4. Check if the queue is full: "<< endl;
        cout << "5. Simulate bank queue scenario: "<< endl;
        cout << "6. Dance floor pairing: "<< endl;
        cout << "7. Exit."<< endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Queue initialized.\n";
                break;
            case 2: {
                int n;
                cout << "Enter integer elements to enqueue (0 to stop): ";
                cin >> n;
                while (n != 0) {
                    myQueue.enqueue(n);
                    cin >> n;
                }
                cout << "Queue elements: ";
                myQueue.display();
                break;
            }
            case 3:
                cout << (myQueue.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 4:
                cout << (myQueue.isFull() ? "Queue is full\n" : "Queue is not full\n");
                break;
            case 5:
                bankScenario();
                break;
            case 6:
                dancePairing();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
