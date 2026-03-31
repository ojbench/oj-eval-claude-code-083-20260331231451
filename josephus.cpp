#include <iostream>
using namespace std;

// Node structure for singly circular linked list
struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

// Function to create a circular linked list with n nodes
Node* createCircularList(int n) {
    if (n <= 0) return nullptr;

    // Create first node
    Node* head = new Node(1);
    Node* prev = head;

    // Create remaining nodes
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);
        prev->next = newNode;
        prev = newNode;
    }

    // Make it circular - last node points to first
    prev->next = head;

    return head;
}

// Function to solve Josephus problem
void josephus(int n, int m) {
    // Create circular linked list
    Node* current = createCircularList(n);
    if (!current) return;

    Node* prev = nullptr;

    // Find the last node to set prev correctly
    Node* temp = current;
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != current);

    // Process until only one node remains
    while (current->next != current) {
        // Count m steps
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }

        // Output the node to be deleted
        cout << current->value << endl;

        // Delete current node
        Node* toDelete = current;
        prev->next = current->next;
        current = current->next;
        delete toDelete;
    }

    // Output the last remaining node
    cout << current->value << endl;

    // Delete the last node to avoid memory leak
    delete current;
}

int main() {
    int n, m;
    cin >> n >> m;

    josephus(n, m);

    return 0;
}
