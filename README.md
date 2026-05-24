# Intro-To-Programming-Basic-CPP-Projects
## Yehan WANG, ECNU

### Ⅰ Overview
This is a comprehensive collection of C++ projects covering comment removal, keywords counting, set operations, large number calculation, and heterogeneous queue. It serves as an excellent practical groundwork for C++ beginners to systematically solidify their understanding of core programming concepts, memory management, and object-oriented design. The specific task requirements for each of the five laboratory assignments are outlined in Part Ⅲ of this document, while this repository directly houses the fully implemented source code solutions and comprehensive test cases for verification.

### Ⅱ Project Structure
```
Intro-To-Programming-Basic-CPP-Projects/
├── README.md
├── LICENSE
├── .gitignore
├── Lab1/                      # comment removal
│   ├── EraseComments.cpp      # implementation
│   └── ProgWithComments.cpp   # test case
├── Lab2/                      # keywords counting
│   ├── KeywordsCounting.cpp   # implementation
│   ├── Keywords.txt           # key
│   └── Text2search.txt        # input file
├── Lab3/                      # set operations
│   ├── iSet.cpp               # implementation
│   ├── iSet.h                 # header file
│   └── TestISet.cpp           # test case
├── Lab4/                      # large number calculation
│   ├── ExtremeLong.cpp        # implementation
│   ├── ExtremeLong.h          # header file
│   └── TestExtremeLong.cpp    # test case
└── Lab5/                      # heterogeneous queue
    ├── heteroQueue.cpp        # implementation
    ├── heteroQueue.h          # header file
    └── TestHQ.cpp             # test case
```

### Ⅲ Details
**1. Lab 1: Comment Removal**  
- **Objective:** Design and implement a lexical preprocessor that reads a C/C++ source code file, strips out all single-line (`//`) and block (`/* ... */`) comments, and outputs the cleaned code to a new file. The program must accurately distinguish real comments from comment-like syntax embedded within string literals.
- **Implementation:** The core logic relies on a lightweight FSM. By reading the input file character by character using standard I/O streams (`std::ifstream::get`), the program continuously updates its state. It transitions between "normal code", "inside a string literal", "inside a single-line comment", and "inside a block comment". The `putback()` function is cleverly used to return characters to the stream when a potential comment marker (like a single `/`) turns out to be just a division operator.
- **Optimization:**
  - **Command-Line Flexibility:** Instead of hardcoding filenames in the source code, the tool uses `argc` and `argv` to accept input and output file paths dynamically from the terminal.
  - **Robust Parameter Validation:** The code checks if exactly three arguments are provided (`argc != 3`) and verifies the `is_open()` status of file streams, preventing segmentation faults and ensuring safe execution.
  - **Edge-Case Resilience:** The parsing logic safely handles escape characters (`\"` and `\\`), ensuring that strings like `"This is not a /* comment */"` are preserved entirely.
- **Compilation:**
```shell
# Compile the source code into an executable named 'EraseComments'
g++ -std=c++11 EraseComments.cpp -o EraseComments

# Run the tool, passing the test file as input an defining an output file
./EraseComments ProgWithComments.cpp CleanedCode.cpp
```

**2. Lab 2: keywords counting**  
- **Objective:** Design and implement a static text analysis tool that parses a text or source code file to compute and record the exact line numbers where designated C++ keywords appear. The results must be systematically output to a target file.
- **Implementation:** The program leverages C++ STL containers, specifically `std::map<std::string, std::vector<int>>`, to efficiently map each keyword to a list of its occurring line numbers. It reads the input file line by line using `getline()`, extracts individual words via `std::istringstream`, and checks for keyword matches using `std::find()` against a pre-loaded dictionary.
- **Optimization:**
  - **Punctuation Sanitization:** A naive `istringstream` fails when keywords are attached to symbols (e.g., `if(condition)`). The code pre-processes each line by replacing all non-alphabetic characters with spaces using `isalpha()`, ensuring tokenization and exact matching.
  - **Cross-Platform Compatibility:** When loading the keyword dictionary, the program safely strips potential trailing carriage returns, ensuring the tool functions correctly regardless of whether the text files were created on Windows or Linux/macOS.
- **Compilation:**
```shell
# Compile the source code into an executable named 'KeywordsCounting'
g++ -std=c++11 KeywordsCounting.cpp -o KeywordsCounting   
# Run the tool, passing the dictionary, target text, and output file path
./KeywordsCounting Keywords.txt Text2search.txt Result.txt
```

**3. Lab 3: Set Operations** 
- **Objective:** Design and implement a custom Integer Set Abstract Data Type from scratch using Object-Oriented Programming principles. The class must manage dynamic memory allocation and perform fundamental mathematical set operations, including Union, Intersection, Difference, and Symmetric Difference.
- **Implementation:** The set logic is encapsulated within the `iSet` class, utilizing a dynamically allocated integer array (`int* ptr`) for element storage. Mathematical operations traverse and compare elements between the calling set and a passed set, generating and returning a new `iSet` object containing the result. A driver program (`TestISet.cpp`) is provided to instantiate objects and verify the functional correctness of all operations.
- **Optimization:**
  - **Memory Management & Deep Copying:** Carefully managed dynamic memory to prevent leaks and dangling pointers. Implemented a custom destructor, a deep-copy constructor, and a robust assignment operator (`operator=`) that safeguards against self-assignment before reallocating memory.
  - **Const Correctness:** Enforced strict `const` correctness. Set operations utilize `const` references (`const iSet& other`) to eliminate unnecessary object copying overhead. Query methods (e.g., `isEmpty()`, `print()`) are qualified with `const` to guarantee they do not mutate the internal state.
  - **Non-Destructive Output:** To ensure elements are displayed in a clean, ascending mathematical format without altering the internal array's raw memory state, the `print()` function creates a localized temporary copy of the object, sorts it, and then outputs the result.
- **Compilation:**
```shell
# Compile the ADT implementation and the test driver together into one executable
g++ -std=c++11 iSet.cpp TestISet.cpp -o SetOperations

# Run the test demonstration
./SetOperations
```

**4. Lab 4: Large Number Calculation**
- **Objective:** Design and implement an arbitrary-precision integer class (`ExtremeLong`) to bypass standard 64-bit hardware limitations, enabling arithmetic and comparison operations on huge numbers with hundreds of digits.
- **Implementation:** The class manages a dynamically allocated integer array to store individual digits. It achieves native-like behavior by systematically overloading arithmetic (`+`, `*`), stream I/O (`<<`, `>>`), and relational (`>`, `==`, etc.) operators, alongside manual base-10 carry/borrow arithmetic algorithms.
- **Optimization:**
  - **Modern C++ Semantics:** Leveraged C++11 move constructors and move assignment operators (`&&`) to eliminate expensive memory copying when returning temporary objects. Implemented custom user-defined literals (`""_xl`) for intuitive object initialization.
  - **Header Hygiene & Safety:** Strictly adhered to C++ engineering standards by avoiding global namespace pollution (`using namespace std;` in headers), replacing compiler-specific headers (`<bits/stdc++.h>`) with standard libraries, and utilizing safe `static const` variables instead of global macros.
- **Compilation:**
```shell
# Compile the ExtremeLong class and the test driver
g++ -std=c++11 ExtremeLong.cpp TestExtremeLong.cpp -o BigIntCalc

# Run the test demonstration
./BigIntCalc
```

**5. Lab 5: Heterogeneous Queue**
- **Objective:** Design and implement a polymorphic heterogeneous queue (`Hqueue`) capable of storing and managing objects of different data types (e.g., integers, characters, and custom `PhoneNumber` objects) within a single unified data structure.
- **Implementation:** The architecture revolves around a `Base` class with a pure virtual `print()` interface, which is overridden by derived classes (`INT`, `CHAR`, `PhoneNumber`). The queue manages a dynamic array of base class pointers (`Base**`), leveraging runtime polymorphism to dispatch the correct derived-class behaviors dynamically.
- **Optimization:**
  - **Memory Leak Prevention:** Safely managed the lifecycle of polymorphic objects by enforcing a `virtual` destructor in the `Base` class. The queue's destructor strictly performs deep cleanup by iterating through and deleting individual objects before freeing the pointer array itself.
  - **Polymorphic Integrity:** Strictly adhered to C++ Object-Oriented Object rules, utilizing pointer containers to avoid object slicing and ensuring safe dynamic dispatch without undefined behaviors.
- **Compilation:**
```shell
# Compile the Heterogeneous Queue implementation and the test driver
g++ -std=c++11 heteroQueue.cpp TestHQ.cpp -o HeteroQueue

# Run the test demonstration
./HeteroQueue
```
