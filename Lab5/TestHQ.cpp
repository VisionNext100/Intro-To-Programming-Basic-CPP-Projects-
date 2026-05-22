//----------------------------------------------------------------------
//
// Test Program for Lab13.
// Jan. 2, 2025 
//
//----------------------------------------------------------------------

#include <iostream>
using  namespace std;

#include "heteroQueue.h"
/* Specify 5 types: Base, Hqueue, INT, CHAR and PhoneNumber in heteroQueue.h
   Implement these types in heteroQueue.cpp
*/

int main(int argc,char** argv)
{   char c{}; Hqueue hq;
    while (c!='Q'&&c!='q'&&cin)
    {   cout <<"INT, CHAR, PhoneNumber or Quit (I/C/P | Q): ";
        cin >> c;
        if (c=='I'||c=='i')
        { int i; cout << "Enter an integer: "; cin >> i;
          hq.enqueue(new INT(i));
        }
        else if (c=='C'||c=='c')
        { char c; cout << "Enter a character: "; cin >> c;
          hq.enqueue(new CHAR(c));
        }
        else if (c=='P'||c=='p')
        { PhoneNumber* ii{new PhoneNumber};
          cout << "Enter a PhoneNumber(Format: a string and a number): "; cin >> *ii;
          hq.enqueue(ii);
        }
        else if (c!='Q'&&c!='q') cout << "Wrong Selection, Retry. ";
    }
    if (cin)
      try
      { cout << endl << "Dequeue:" << endl;
        while (!hq.isEmpty()) hq.dequeue(); cout << endl; 
      }
      catch(Hqueue::bad_op bi)
      {  cerr << bi.type <<", exit " << endl;  } 
    return 0;
}
