#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

int main()
{
    std::vector<int> vec = {3, 5, 3, 6, 7};
    LinkedList<int> list;

    list.enqueue(3);
    list.enqueue(4);
    list.enqueue(5);
    list.enqueue(6);
    list.enqueue(7);

    cout << endl
         << "Iterator Test:" << endl;

    list.iterTest();
    cout << endl;



    cout << endl;
    cout << "contains(): Test #1: " << ((list.contains(5)==true) ? "Pass" : "Fail") << endl;
    cout << "contains(): Test #2: " << ((list.contains(6)==true) ? "Pass" : "Fail") << endl;
    cout << "contains(): Test #3: " << ((list.contains(1)==false) ? "Pass" : "Fail")<< endl;

    return 0;
}