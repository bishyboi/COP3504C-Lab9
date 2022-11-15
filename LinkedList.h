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

            if (this->previous != nullptr)
            {
                delete this->previous->next;
                this->previous->next = this->next;
            }

            if (this->next != nullptr)
            {
                delete this->next->previous;
                this->next->previous = this->previous;
            } 
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
            this->currentNode = currentNode->next;
            return *this;
        }

        Iterator& operator++(int)
        {
            this->currentNode = currentNode->next;
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
            return (this->currentNode == rhs->currentNode);
        }

        bool operator!=(Iterator const &rhs)
        {
            return (this->currentNode != rhs->currentNode);
        }
        
        friend class LinkedList;
    };

    Node *first = nullptr;
    Node *last = nullptr;

    LinkedList() {}
    // Iterator begin() const;
    // Iterator tail() const;
    // Iterator end() const;
    // bool isEmpty() const;
    // T getFront() const;
    // T getBack() const;
    bool contains(T element) const;
    void enqueue(T element);
    // void dequeue();
    // void pop();
    // void clear();
    // void remove(T element);

    void iterTest() const;
};

// template <typename T>
// typename LinkedList<T>::Iterator LinkedList<T>::begin() const
// {
//     return LinkedList<T>::Iterator(this->first);
// }

// template <typename T>
// typename LinkedList<T>::Iterator LinkedList<T>::tail() const
// {
//     return LinkedList<T>::Iterator(this->last);
// }

// template <typename T>
// typename LinkedList<T>::Iterator LinkedList<T>::end() const
// {
//     return LinkedList<T>::Iterator(nullptr);
// }

// template <typename T>
// bool LinkedList<T>::isEmpty() const
// {
//     return (this->first == nullptr);
// }

// template <typename T>
// T LinkedList<T>::getFront() const
// {
//     return (this->first->data);
// }

// template <typename T>
// T LinkedList<T>::getBack() const
// {
//     return *(this->last);
// }

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
    Node *newNode = new Node(element, this->last, nullptr);

    if (this->first == nullptr)
    {
        this->first = newNode;
    }
    
    this->last = newNode;   
}

// template <typename T>
// void LinkedList<T>::dequeue()
// {
//     Node *second = this->first->next;
//     delete this->first;
//     this->first = second;
// }

// template <typename T>
// void LinkedList<T>::pop()
// {
//     Node *secondToLast = this->last->previous;
//     delete this->last;
//     this->last = secondToLast;
// }


// //FIXME: Incomplete
// template <typename T>
// void LinkedList<T>::clear()
// {
//     LinkedList<T>::Iterator iter = Iterator(this->first);
//     Node *nextNode = nullptr;
    
// }

// template <typename T>
// void LinkedList<T>::remove(T element)
// {
//     // Iterate through list until first occurrence of data using iterator
//     LinkedList<T>::Iterator iter = Iterator(this->first);
//     // Delete using ~Node destructor
//     while(*(iter->currentNode->data) != element)
//     {
//         iter++;
//         if (*(iter->currentNode->data) == element)
//             delete iter->currentNode;
//     }
// }

template <typename T>
void LinkedList<T>::iterTest() const
{
    Iterator iter = Iterator(this->first);

    while(iter.currentNode->next != nullptr)
    {
        std::cout << iter.currentNode->data << "HI" << std::endl;
        iter++;
    }

    std::cout << iter.currentNode->data;
}