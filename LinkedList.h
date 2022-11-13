#pragma once

template <typename T>
class LinkedList
{
public:
    struct Node
    {
        T *data;
        Node *next;
        Node *previous;
        Node(T _data, Node *_next = nullptr, Node *_previous = nullptr) : data(_data), next(_next), previous(_previous) {}
    };

    class Iterator
    {
    public:
        Node *currentNode;

        // TODO: Could cause possible problem, solution may be to make current node a pointer
        //  to first node automatically and create a set function
        Iterator(Node _currentNode)
        {
            this->currentNode = _currentNode;
        }

        T operator*() const
        {
            return *(currentNode->data);
        }

        // TODO: Ensure that final result matches end() function
        //FIXME: Not properly returning iterator
        Iterator& operator++()
        {
            currentNode = currentNode->next;
            Iterator iter = Iterator(&currentNode);
            return iter;
        }

        //FIXME: Not properly returning iterator
        Iterator &operator--()
        {
            currentNode = currentNode->previous;
            return &currentNode;
        }

        bool operator==(Iterator const &rhs)
        {
            return (this->currentNode == rhs->currentNode);
        }

        bool operator!=(Iterator const &rhs)
        {
            return !(this == rhs);
        }
        friend class LinkedList;
    };

    Node *first = nullptr;
    Node *last = nullptr;

    Iterator begin() const;
    Iterator tail() const;
    Iterator end() const;
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

template <typename T>
LinkedList<T>::Iterator LinkedList<T>::begin() const
{
    return LinkedList<T>::Iterator(this->first);
}

template <typename T>
LinkedList<T>::Iterator LinkedList<T>::tail() const
{
    return LinkedList<T>::Iterator(this->last);
}

template <typename T>
LinkedList<T>::Iterator LinkedList<T>::end() const
{
    return LinkedList<T>::Iterator(nullptr);
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return (this->first == nullptr);
}

template <typename T>
T LinkedList<T>::getFront() const
{
    return *(this->first);
}

template <typename T>
T LinkedList<T>::getBack() const
{
    return *(this->last);
}

template <typename T>
bool LinkedList<T>::contains(T element) const
{
    LinkedList<T>::Iterator iter = Iterator(this->first);
    while (*(iter->currentNode->data) != element && iter->currentNode->next == nullptr)
    {
        iter++;
        if (*(iter->currentNode->data) == element)
            return true;
    }
    return false;
}

template <typename T>
void LinkedList<T>::enqueue(T element)
{
    Node *newNode = new Node(T, this->last, nullptr);
    Node last = &(this->last);

    last.next = *newNode;
}

template <typename T>
void LinkedList<T>::dequeue()
{
    Node *second = this->first->next;
    delete this->first;
    this->first = second;
}

template <typename T>
void LinkedList<T>::pop()
{
    Node *secondToLast = this->last->previous;
    delete this->last;
    this->last = secondToLast;
}


//FIXME: Incomplete
template <typename T>
void LinkedList<T>::clear()
{
    LinkedList<T>::Iterator iter = Iterator(this->first);
    Node *nextNode = nullptr;
    
}