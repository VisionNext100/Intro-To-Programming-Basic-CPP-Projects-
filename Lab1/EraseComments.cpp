#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        cerr << "Example: ./Lab1 ProgWithComments.cpp CleanedCode.cpp" << endl;
        return 1; // Exception
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    // Check if files are opened successfully
    if (!fin.is_open())
    {
        cerr << "Error: Cannot open input file: " << argv[1] << endl;
        return 1;
    }
    if (!fout.is_open())
    {
        cerr << "Error: Cannot open output file: " << argv[2] << endl;
        return 1;
    }

    char temp1{}, temp2{}, temp3{};

    // Handle comments and write to output file
    while (fin.get(temp1))
    {
        bool checkStatus = false;

        if (temp1 == '/')
        {
            checkStatus = true;
            fin.get(temp2);

            if (temp2 == '/')
            {
                checkStatus = false;
                while (fin.get(temp2))
                {
                    if (temp2 == '\n')
                        break;
                }
                fin.putback('\n');
                continue;
            }
            else if (temp2 == '*')
            {
                checkStatus = true;
                while (fin.get(temp2))
                {
                    if (temp2 == '*')
                    {
                        fin.get(temp3);
                        if (temp3 == '/')
                        {
                            checkStatus = false;
                            break;
                        }
                        else
                        {
                            fin.putback(temp3);
                            continue;
                        }
                    }
                }
                continue;
            }
            else
            {
                checkStatus = false;
                fin.putback(temp2);
            }
        }

        // For handling escape characters to ensure they are not misinterpreted as comment delimiters
        if (temp1 == '\\')
        {
            checkStatus = true;
            fout << temp1;
            if (fin.get(temp2))
            {
                fout << temp2;
                checkStatus = false;
            }
            continue;
        }

        // For handling string literals (comments within strings should not be removed)
        if (temp1 == '\"')
        {
            fout << temp1;
            checkStatus = true;
            while (fin.get(temp2))
            {
                fout << temp2;
                if (temp2 == '\\')
                {
                    if (fin.get(temp3))
                        fout << temp3;
                    continue;
                }
                if (temp2 == '\"')
                {
                    checkStatus = false;
                    break;
                }
            }
            continue;
        }

        fout << temp1;
    }

    fin.close();
    fout.close();

    return 0;
}