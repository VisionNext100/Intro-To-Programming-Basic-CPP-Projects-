#ifndef HETEROQUEUE_H_INCLUDED
#define HETEROQUEUE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>

class Base{
private:
public:
    virtual void print()const=0;
};

class INT:public Base{
private:
    int num;
public:
    INT(int a);
    ~INT();
    void print()const;
};

class CHAR:public Base{
private:
    char c;
public:
    CHAR(char b);
    ~CHAR();
    void print()const;
};

class PhoneNumber:public Base{
private:
    std::string name;
    long long number;
public:
    PhoneNumber();
    ~PhoneNumber();
    void print()const;
    friend std::istream& operator>>(std::istream& in, PhoneNumber& P);
};

class hetroQueue{
private:
    Base** pb;
    int m_capability;
    int m_size;
public:
    hetroQueue(int = 10);
    ~hetroQueue();
    class bad_op{
    public:
        string type;
        bad_op();
    };
    bool isEmpty()const;
    void dequeue();
    void enqueue(Base*);
};

#endif // HETEROQUEUE_H_INCLUDED
