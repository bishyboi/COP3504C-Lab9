#pragma once

template <typename T>
class LinkedList
{
public:
    struct Node
    {
        // A pointer to the data contained in the node.
        T data;

        // Pointer to the next sequential node in the linked list.
        Node *next;
        
        // Pointer to the previous sequential node in the linked list.
        Node *previous;

        Node(T _data, Node *_next = nullptr, Node *_previous = nullptr) : data(_data), next(_next), previous(_previous) {}

        ~Node()
        {
            delete data;
        }
    };

    class Iterator
    {
    public:
        //Directly attached to a node in linked list.
        Node *currentNode = nullptr;

        Iterator(Node *_currentNode)
        {
            this->currentNode = _currentNode;
        }

        T operator*() const
        {
            return this->currentNode->data;
        }

        // TODO: Ensure that final result matches end() function
        Iterator& operator++()
        {
            if(this->currentNode)
                this->currentNode= this->currentNode->next;
            return *this;
        }

        Iterator& operator++(int)
        {
            if(this->currentNode)
                this->currentNode = this->currentNode->next;

            return *this;
        }

        Iterator& operator--()
        {
            this->currentNode = currentNode->previous;
            return *this;
        }

        Iterator& operator--(int)
        {
            this->currentNode = currentNode->previous;
            return *this;
        }

        bool operator==(Iterator const &rhs)
        {
            return (this->currentNode == rhs.currentNode);
        }

        bool operator!=(Iterator const &rhs)
        {
            return (this->currentNode != rhs.currentNode);
        }
        
        friend class LinkedList;
    };

    Node *first = nullptr;
    Node *last = nullptr;

    LinkedList() {}
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

    void iterTest() const;
};

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const
{
    return LinkedList<T>::Iterator(this->first);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::tail() const
{
    return LinkedList<T>::Iterator(this->last);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const
{
    Iterator iter = Iterator(this->last);
    iter++;
    return iter;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return !(this->first);
}

template <typename T>
T LinkedList<T>::getFront() const
{
    return this->first->data;
}

template <typename T>
T LinkedList<T>::getBack() const
{
    return this->last->data;
}

template <typename T>
bool LinkedList<T>::contains(T element) const
{
    if(this->first == nullptr)
        return false;
        
    LinkedList<T>::Iterator iter = Iterator(this->first);
    while (iter.currentNode->data != element && iter.currentNode->next != nullptr)
    {
        iter++;
        if (iter.currentNode->data == element)
            return true;
    }

    return false;
}

template <typename T>
void LinkedList<T>::enqueue(T element)
{

    if (!this->first)
    {
        Node *newNode = new Node(element, nullptr, nullptr);
        this->first = newNode;
        this->last = newNode;
    }
    else
    {
        Node *newNode = new Node(element, nullptr, this->last);
        this->last->next = newNode;

        this->last = newNode;

        if(this->last->next)
            std::cout<< "It is not pointing towards nullptr. This needs to be fixed" << std::endl;
    }
}

template <typename T>
void LinkedList<T>::dequeue()
{
    Node *second = this->first->next;
    this->first = second;
    delete this->first->previous;
}

template <typename T>
void LinkedList<T>::pop()
{
    Node *secondToLast = this->last->previous;
    delete this->last;
    this->last = secondToLast;
    this->last->next = nullptr;
}


// //FIXME: Incomplete
template <typename T>
void LinkedList<T>::clear()
{
    LinkedList<T>::Iterator iter = Iterator(this->first);
    
    Node *temp = nullptr;
    while(iter.currentNode->next)
    {
        temp = *(iter.currentNode);

        iter++;
    }

}

template <typename T>
void LinkedList<T>::remove(T element)
{     
    LinkedList<T>::Iterator iter = Iterator(this->first);

    while (iter.currentNode->data != element && iter.currentNode->next != nullptr)
    {
        if (iter.currentNode->data == element)
            iter.currentNode->previous->next = iter.currentNode->next;
            iter.currentNode->next->previous = iter.currentNode->previous;
            delete iter.currentNode;
            return;

        iter++;
    }
}

template <typename T>
void LinkedList<T>::iterTest() const
{
    Iterator iter = Iterator(this->first);

    std::cout<< "[ ";
    while(iter.currentNode->next != nullptr)
    {
        std::cout<< iter.currentNode->data << ", ";
        iter++;
    }
    
    std::cout << iter.currentNode->data << " ]";
}