#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to add an element to the end of the list
void addElement(Node** head, int data) {
    Node* newNode = new Node{data, nullptr};

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to reverse a singly linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to print the elements of the list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    // Add some elements to the list
    addElement(&head, 1);
    addElement(&head, 2);
    addElement(&head, 3);
    addElement(&head, 4);
    addElement(&head, 5);

    std::cout << "Original list: ";
    printList(head);

    // Reverse the list
    head = reverseList(head);

    std::cout << "Reversed list: ";
    printList(head);

    return 0;
}

