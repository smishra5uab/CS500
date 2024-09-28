#include "deque.h"
#include <iostream>

// COnstructor for node struct
Deque::Node::Node(int cVal, Node* cNext, Node* cPrev) {
    val = cVal;
    next = cNext;
    previous = cPrev;
} 

// Constructor for deque
Deque::Deque() {
    front = nullptr;
    back = nullptr;
}

// Push an element to the front of the deque
void Deque::push_front(int i) {
    Node* newNode = new Node(i, front, nullptr);

    if (front) {
        front->previous = newNode;
    } else {
        back = newNode;
    }

    front = newNode;
}

// Push element to the back of the deque
void Deque::push_back(int i) {
    Node* newNode = new Node(i, nullptr, back);

    if (back) {
        back->next = newNode;
    } else {
        front = newNode;
    }

    back = newNode;
}

// Pop and return front element of the deque
int Deque::pop_front() {
    if (!front) {
        std::cerr << "Error: Tried popping from an empty deque (front)\n";
        return -1;
    }

    int val = front->val;
    Node* oldFront = front;
    front = front->next;

    if (front) {
        front->previous = nullptr;
    } else {
        back = nullptr;
    }

    delete oldFront;
    return val;
}

// Pop and return back element of the deque
int Deque::pop_back() {
    if (!back) {
        std::cerr << "Error: Tried popping from an empty deque (back)\n";
        return -1;
    }

    int val = back->val;
    Node* oldBack = back;
    back = back->previous;

    if (back) {
        back->next = nullptr;
    } else {
        front = nullptr;
    }

    delete oldBack;
    return val;
}

// Return front element of the deque
int Deque::peak_front() const {
    if (!front) {
        std::cerr << "Error: Tried peeking at an empty deque (front)\n";
        return -1;
    }

    return front->val;
}

// Return back element of the deque
int Deque::peak_back() const {
    if (!back) {
        std::cerr << "Error: Tried peeking at an empty deque (back)\n";
        return -1;
    }

    return back->val;
}

// Remove all elements from the deque
void Deque::remove_all() {
    while (front) {
        pop_front();
    }
}

// Deconstructor of deque
Deque::~Deque() {
    remove_all();
}
