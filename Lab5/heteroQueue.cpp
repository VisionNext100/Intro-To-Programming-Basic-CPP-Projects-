#include "heteroQueue.h"
#include <iostream>

using namespace std;

// INT 类实现
INT::INT(int a) : num(a) {}
INT::~INT() {}
void INT::print() const { cout << num << endl; }

// CHAR 类实现
CHAR::CHAR(char c) : c(c) {}
CHAR::~CHAR() {}
void CHAR::print() const { cout << c << endl; }

// PhoneNumber 类实现
PhoneNumber::PhoneNumber() : name(""), number(0) {}
PhoneNumber::~PhoneNumber() {}
void PhoneNumber::print() const { cout << "(" << name << ", " << number << ")" << endl; }

istream &operator>>(istream &in, PhoneNumber &p)
{
    in >> p.number;
    cout << "Please enter the name: ";
    in >> p.name;
    return in;
}

// 异构队列实现
Hqueue::Hqueue(int cap)
{
    m_capability = cap;
    m_size = 0;
    pb = new Base *[m_capability]; // 动态分配指针数组
}

Hqueue::~Hqueue()
{
    // 先释放每一个具体的派生类对象
    for (int i = 0; i < m_size; i++)
    {
        delete pb[i];
    }
    // 再释放存放指针的数组
    delete[] pb;
}

bool Hqueue::isEmpty() const
{
    return m_size == 0;
}

void Hqueue::enqueue(Base *item)
{
    if (m_size == m_capability)
    {
        throw bad_op("Queue is full");
    }
    pb[m_size++] = item;
}

void Hqueue::dequeue()
{
    if (isEmpty())
    {
        throw bad_op("Queue is empty");
    }

    pb[0]->print(); // 打印队头
    delete pb[0];   // 释放队头对象占用的内存

    // 将剩余元素前移
    for (int i = 0; i < m_size - 1; i++)
    {
        pb[i] = pb[i + 1];
    }
    m_size--;
}