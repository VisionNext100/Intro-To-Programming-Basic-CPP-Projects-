#include <iostream>
#include "iSet.h"

using namespace std;

int main()
{
    cout << "=== Testing iSet (Set Operations) ===" << endl;

    iSet setA(20);
    iSet setB(20);

    // Initialize Set A = {1, 2, 3, 4, 5}
    for (int i = 1; i <= 5; i++)
        setA.insert(i);

    // Initialize Set B = {4, 5, 6, 7, 8}
    for (int i = 4; i <= 8; i++)
        setB.insert(i);

    cout << "Set A: ";
    setA.print();
    cout << "Set B: ";
    setB.print();

    cout << "\n--- Operations ---" << endl;

    iSet uSet = setA.setUnion(setB);
    cout << "Union (A U B): ";
    uSet.print();

    iSet iSet_res = setA.setIntersection(setB);
    cout << "Intersection (A * B): ";
    iSet_res.print();

    iSet dSet = setA.setDifference(setB);
    cout << "Difference (A - B): ";
    dSet.print();

    iSet symSet = setA.setSymmetricDifference(setB);
    cout << "Symmetric Difference: ";
    symSet.print();

    return 0;
}