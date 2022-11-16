#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

int main()
{
    std::vector<string> vec = {"alpha", "bravo", "charlie", "charlie", "dog", "echo", "foxtrot", "golf"};
    LinkedList<string> list;

    list.enqueue("alpha");
    list.enqueue("bravo");
    list.enqueue("charlie");
    list.enqueue("charlie");
    list.enqueue("dog");
    list.enqueue("echo");
    list.enqueue("foxtrot");
    list.enqueue("golf");
    list.enqueue("far");
    list.enqueue("six");

    cout << endl
         << "Iterator Test:" << endl;

    list.iterTest();
    cout << endl
         << endl;

    int *ptr = nullptr;


    cout << "Dequeue Test" << endl;
    list.dequeue();
    list.iterTest();

    cout << endl << endl<< "Remove Test on first element" << endl;
    list.remove("bravo");
    list.iterTest();

    cout << endl << endl<< "Remove Test on last element" << endl;
    list.remove("six");
    list.iterTest();

    
    cout << endl << endl<< "Remove Test on middle element" << endl;
    list.remove("echo");
    list.iterTest();
        
    cout << endl << endl<< "Pop Test" << endl;
    list.pop();
    list.iterTest();

    cout << endl << endl<< "Clear Test on full list" << endl;
    list.clear();
    list.iterTest();

    cout << endl << endl<< "Clear Test on empty list" << endl;
    list.clear();
    list.iterTest();
    
    return 0;
}