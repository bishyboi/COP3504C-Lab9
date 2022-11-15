#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

int main()
{
    std::vector<int> vec = {3, 5, 3, 6, 7};
    LinkedList<int> list;

    for (int x : vec)
    {
        cout << x << endl ;
        list.enqueue(x);
    }

    cout << endl
         << endl
         << "Iterator Test:" << endl;
    list.iterTest();

    cout << endl;
    cout << "contains(): Test #1: " << list.contains(5) ? "Pass" : "Fail";
    cout << "contains(): Test #2: " << list.contains(6) ? "Pass" : "Fail";
    cout << "contains(): Test #3: " << !list.contains(1) ? "Pass" : "Fail";

    return 0;
}