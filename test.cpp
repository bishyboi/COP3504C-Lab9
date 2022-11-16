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
         << endl
         <<
    "Remove Test #1:" << endl;
    list.remove("alpha");
    list.iterTest();
    cout<< endl << endl <<
    
    "Remove Test #2:" << endl;
    list.remove("charlie");
    list.iterTest();
    cout<< endl << endl <<
    
    "Remove Test #3:" << endl;
    list.remove("golf");
    list.iterTest();
    
    return 0;
}