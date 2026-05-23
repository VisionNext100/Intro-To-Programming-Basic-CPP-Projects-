//----------------------------------------------------------------------
//
// TestISet.cpp : Test program for Lab3. 
// Dec,12,2024
//
//----------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "iSet.h"  // your header file for class iSet

int main(int argc, char** argv)
try
  {
    // ***** test for initialization *****

    iSet s1{100};  // an integer set with 100 maximum elements
    iSet s2{110};   // an integer set with 110 maximum elements

    // ***** test for printing *****

    cout << "Set s1 after initialization: " << endl;
    s1.print();     // display set
    cout << endl;

    // ***** test for size *****

    cout << "The number of elements in Set s1: " << s1.size() << endl;
    cout << "The capacity of Set s1: " << s1.capacity() <<endl;

    cout << endl << "Set s2 after initialization: " << endl;
    s2.print();     // display set
    cout << endl;
    cout << "The number of elements in Set s2: " << s2.size() << endl;
    cout << "The capacity of Set s2: " << s2.capacity() << endl;
    cout << endl;

    // ***** test for inserting *****

    for (int i{200};i<=210;i++)   s1.insert(i);        // insert 11 elements from 200 to 210
    for (int i{190};i<=215;i++)   s2.insert(i);        // insert 16 elements from 190 to 205

    cout << "Set s1 after inserting: " << endl;
    s1.print();   // display set
    cout << endl;
    cout << "The number of elements in Set s1: " << s1.size() << endl;
    cout << "The capacity of Set s1: " << s1.capacity() << endl;
    cout << endl << "Set s2 after inserting: " << endl;
    s2.print();     // display set
    cout << endl;
    cout << "The number of elements in Set s2: " << s2.size() << endl;
    cout << "The capacity of Set s2: " << s2.capacity() << endl;
    cout << endl;

    // ***** test for union *****

    cout << "Union of two integer sets s1 and s2: " << endl;
    s1.print();     // display set
    cout << " �� ";
    s2.print();    // display set
    cout << " = ";
    iSet r1{s1.setUnion(s2)};   // compute union of two integer sets
    r1.print();     // display union result
    cout << endl;
    cout << endl;

    // ***** test for intersection *****

    cout << "Intersection of two integer sets s1 and s2: " << endl;
    s1.print();
    cout << " �� ";
    s2.print();
    cout << " = ";
    iSet r2{s1.setIntersection(s2)};  // compute intersection of two integer sets
    r2.print();
    cout << endl;
    cout << endl;

    // ***** test for difference *****

    cout << "Difference of two integer sets s1 and s2: " << endl;
    s1.print();
    cout << " �� ";
    s2.print();
    cout << " = ";
    iSet r3{s1.setDifference(s2)};     // compute difference of two integer sets
    r3.print();
    cout << endl;
    cout << endl;

    cout << "Difference of two integer sets s2 and s1: " << endl;
    s2.print();
    cout << " �� ";
    s1.print();
    cout << " = ";
    iSet r4{s2.setDifference(s1)};     // compute difference of two integer sets
    r4.print();
    cout << endl;
    cout << endl;

    // ***** test for symmetric difference *****

    cout << "Symmetric difference of two integer sets s1 and s2: " << endl;
    s1.print();
    cout << " symmetric�� ";
    s2.print();
    cout << " = ";
    iSet r5{s1.setSymmetricDifference(s2)};   // compute symmetric difference of two integer sets
    r5.print();
    cout << endl;
    cout << endl;

    // ***** test for assignment *****

    cout << "Set s1 after assignment s1=s2: " << endl;
    s1=s2;
    s1.print();
    cout << endl;
    cout << endl;

    // ***** test for "clear" *****

    cout << "Set s2 after erasing all elements: " << endl;
    s2.clear();
    s2.print();
    cout << endl;
    cout << endl;

    // ***** test   "empty" *****

    if (s1.empty()) cout << "Set s1 is empty " << endl;
    else cout << "Set s1 is NOT empty " << endl;
    cout << endl;

    if (s2.empty()) cout << "Set s2 is empty " << endl;
    else cout << "Set s2 is NOT empty " << endl;
    cout << endl;

    // ***** test  "full" *****

    if (s1.full()) cout << "Set s1 is fully " << endl;
    else cout << "Set s1 is NOT full " << endl;
    cout << endl;

    if (s2.full()) cout << "Set s2 is full " << endl;
    else cout << "Set s2 is NOT full " << endl;
    cout << endl;

    // ***** test for "erase" *****

    cout << "Set s1 after erasing an element 202 : " << endl;
    s1.erase(202);
    s1.print();
    cout << endl;
    cout << endl;
    cout << "Set s1 after erasing an element 255 : " << endl;
    s1.erase(255);
    s1.print();
    cout << endl;
    cout << endl;

    // ***** test for "contains" *****
    int e{205};
    if (s1.contains(e)) cout << e << " is a member of s1" << endl;
    else cout << e << " is NOT a member of s1" << endl;
    cout << endl;
    e+=222;
    if (s1.contains(e)) cout << e << " is a member of s1" << endl;
    else cout << e << " is NOT a member of s1" << endl;
    cout << endl;


    // ***** test for "isSubset" *****

    if (s1.isSubset(s2)) cout << "Set s2 is a subset of s1" << endl;
    else cout << "Set s2 is NOT a subset of s1" << endl;
    cout << endl;

    cout << "Insert an element 666 into set s2 : " << endl;
    s2.insert(666);
    cout << "Set s2 : " << endl;
    s2.print();
    cout << endl;

    cout << endl;

    if (s1.isSubset(s2)) cout << "Set s2 is a subset of s1" << endl;
    else cout << "Set s2 is NOT a subset of s1" << endl;
    cout << endl;


    // ***** test for exception throwing *****

    cout << "insert 1000 elements from 1 to 999 into set s1 : " << endl;
    for (int i{1};i<1000;i++)
      s1.insert(i);        // insert 1000 elements from 1 to 999

    return 0;
  }

  // ***** exception handling *****

  catch(iSet::bad_iSet bi)     // catch exceptions related to integer set
  { switch (bi.errnum)         // # of exceptions
    { case 1: cerr << "*** bad iSet: constructor parameter<1 , exit " << endl;
                               // error of constructor parameter
              break;
      case 2: cerr << "*** bad iSet: maximum elements reached(is Full), exit " << endl;
                               // overflow of integer set
              break;
    }

    return 0;

 }
