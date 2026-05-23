#pragma once
#include <iostream>

class iSet
{
private:
    int *ptr;        // 指向动态数组的指针
    int _capacity;   // 集合的最大容量
    int _size;       // 集合当前元素个数
    void uni_sort(); // 内部排序工具函数

public:
    // 异常处理结构体
    struct bad_iSet
    {
        int errnum;
        bad_iSet(int e) : errnum(e) {}
    };

    // 构造与析构
    iSet(int cap = 100);
    iSet(const iSet &other); // 拷贝构造
    ~iSet();                 // 析构函数

    // 集合运算
    iSet setUnion(const iSet &other) const;
    iSet setIntersection(const iSet &other) const;
    iSet setDifference(const iSet &other) const;
    iSet setSymmetricDifference(const iSet &other) const;

    // 元素操作
    void insert(int val);
    void erase(int val);

    // 状态查询
    bool isSubset(const iSet &other) const;
    bool contains(int val) const;
    void print() const;
    int size() const;
    int capacity() const;
    bool isEmpty() const;
    bool isFull() const;
    void clear();

    // 运算符重载与其他
    iSet &operator=(const iSet &other);
    int find(int val, int start, int end) const;
};