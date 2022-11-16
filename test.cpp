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

    list.remove("alpha");
    list.iterTest();
    cout<< endl;
    list.remove("charlie");
    list.iterTest();
    cout<< endl;
    list.remove("golf");
    list.iterTest();
    
    return 0;
}