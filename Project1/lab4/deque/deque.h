#ifndef deque_h
#define deque_h

// The Deque class initializes a node struct and the member variables that shall store info of the
// node like front and back pointers and the value stored in each node.
class Deque {
private:
    struct Node {
        int val;       
        Node* next;    
        Node* previous;    

        Node(int cVal, Node* cNext = nullptr, Node* cPrevious = nullptr);
    };

    Node* front;
    Node* back;

public:
    // Constructor
    Deque();

    // Push an element to the front of the deque
    void push_front(int i);

    // Push an element to the back of the deque
    void push_back(int i);

    // Pop and return the front element of the deque
    int pop_front();

    // Pop and return the back element of the deque
    int pop_back();

    // Return the front element of the deque
    int peak_front() const;

    // Return the back element of the deque
    int peak_back() const;

    // Remove all elements from the deque
    void remove_all();

    // Destructor
    ~Deque();
};

#endif
