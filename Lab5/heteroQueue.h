#pragma once
#include <iostream>
#include <string>

// 基类：提供多态接口
class Base
{
public:
    virtual void print() const = 0;
    virtual ~Base() {}
};

class INT : public Base
{
private:
    int num;

public:
    INT(int a);
    ~INT() override;
    void print() const override;
};

class CHAR : public Base
{
private:
    char c;

public:
    CHAR(char b);
    ~CHAR() override;
    void print() const override;
};

class PhoneNumber : public Base
{
private:
    std::string name;
    long long number;

public:
    PhoneNumber();
    ~PhoneNumber() override;
    void print() const override;
    friend std::istream &operator>>(std::istream &in, PhoneNumber &P);
};

// 异构队列类
class Hqueue
{
private:
    Base **pb;        // 存放基类指针的动态数组
    int m_capability; // 最大容量
    int m_size;       // 当前元素个数
public:
    Hqueue(int cap = 10);
    ~Hqueue();

    // 异常类
    class bad_op
    {
    public:
        std::string type;
        bad_op(std::string t = "Queue Error") : type(t) {}
    };

    bool isEmpty() const;
    void dequeue();
    void enqueue(Base *item);
};