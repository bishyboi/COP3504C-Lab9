#pragma once

template <typename T>
class LinkedList
{
    struct Node
    {
        T data;
        Node *next;
        Node *previous;
        Node(T _data, Node *_next = nullptr, Node *_previous = nullptr) : data(_data), next(_next), previous(_previous) {}
    };
    Node *first = nullptr;
    Node *last = nullptr;

public:
    // Code from: https://en.cppreference.com/w/cpp/iterator/iterator 
    // and https://medium.com/geekculture/iterator-design-pattern-in-c-42caec84bfc 
    //FIXME: implement iterator class methods
    class Iterator
    {
    public:
        T operator*() const;
        Iterator& operator++();
        Iterator& operator--();
        bool operator==(Iterator const &rhs);
        bool operator!=(Iterator const &rhs);
    }
    void add(T data);
    void remove(T element);
    bool isEmpty() const;
    T getFront() const;
    T getBack() const;
    bool contains(T element) const;
    void enqueue(T element);
    void dequeue();
    void pop();
    void clear();
    void remove(T element);
};

//From Linked List lecture slides
template <typename T>
void LinkedList<T>::add(T data)
{
    Node *newNode = new Node(data);
    if (first == nullptr)
        first = last = newNode;
    else 
    {
        last->next = newNode;
        last = newNode;
    }
}

//From Linked List lecture slides
template <typename T>
void LinkedList<T>::remove(T element)
{
    Node *removeMe = first;
    T returnMe = first->data;
    if (first == nullptr)
        throw EmptyException(); // Not real 
    if (last == first)
        last = nullptr;
    first = first->next;
    delete removeMe;
    return returnMe;
}