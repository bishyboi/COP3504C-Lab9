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

    cout << endl
         << "Iterator Test:" << endl;

    list.iterTest();
    cout << endl
         << endl;

    int *ptr = nullptr;


    cout << "Dequeue Test" << endl;
    list.dequeue();
    list.iterTest();

    cout << "Clear Test on full list" << endl;
    list.clear();
    list.iterTest();

    cout << endl << endl<< "Clear Test on empty list" << endl;
    list.clear();
    list.iterTest();
    
    return 0;
}