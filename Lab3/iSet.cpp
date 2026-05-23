#include "iSet.h"
#include <iostream>

using namespace std;

// 构造函数
iSet::iSet(int cap)
{
    if (cap < 1)
        throw bad_iSet(1);
    _capacity = cap;
    _size = 0;
    ptr = new int[_capacity];
}

// 拷贝构造函数
iSet::iSet(const iSet &other)
{
    _capacity = other._capacity;
    _size = other._size;
    ptr = new int[_capacity];
    for (int i = 0; i < _size; i++)
    {
        ptr[i] = other.ptr[i];
    }
}

// 析构函数
iSet::~iSet()
{
    delete[] ptr;
}

// 赋值运算符重载
iSet &iSet::operator=(const iSet &other)
{
    if (this == &other)
        return *this; // 防止自我赋值导致数据丢失

    delete[] ptr; // 释放原有内存
    _capacity = other._capacity;
    _size = other._size;
    ptr = new int[_capacity];

    for (int i = 0; i < _size; i++)
    {
        ptr[i] = other.ptr[i];
    }
    return *this;
}

// 内部排序函数 (冒泡排序简单实现)
void iSet::uni_sort()
{
    for (int i = 0; i < _size - 1; i++)
    {
        for (int j = 0; j < _size - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                int temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

int iSet::size() const { return _size; }
int iSet::capacity() const { return _capacity; }
bool iSet::isEmpty() const { return _size == 0; }
bool iSet::isFull() const { return _size == _capacity; }

bool iSet::contains(int val) const
{
    for (int i = 0; i < _size; i++)
    {
        if (ptr[i] == val)
            return true;
    }
    return false;
}

void iSet::clear()
{
    _size = 0; // 逻辑清空即可，不需要重新 new 内存
}

void iSet::insert(int val)
{
    if (contains(val))
        return; // 集合互异性，已有则不插入
    if (isFull())
        throw bad_iSet(2); // 容量溢出
    ptr[_size++] = val;
}

void iSet::erase(int val)
{
    for (int i = 0; i < _size; i++)
    {
        if (ptr[i] == val)
        {
            // 将后面的元素前移覆盖
            for (int j = i; j < _size - 1; j++)
            {
                ptr[j] = ptr[j + 1];
            }
            _size--;
            return;
        }
    }
}

// 并集
iSet iSet::setUnion(const iSet &other) const
{
    iSet result(_capacity + other._capacity); // 确保容量足够
    for (int i = 0; i < _size; i++)
        result.insert(ptr[i]);
    for (int i = 0; i < other._size; i++)
        result.insert(other.ptr[i]);
    return result;
}

// 交集
iSet iSet::setIntersection(const iSet &other) const
{
    iSet result(_capacity);
    for (int i = 0; i < _size; i++)
    {
        if (other.contains(ptr[i]))
        {
            result.insert(ptr[i]);
        }
    }
    return result;
}

// 差集
iSet iSet::setDifference(const iSet &other) const
{
    iSet result(_capacity);
    for (int i = 0; i < _size; i++)
    {
        if (!other.contains(ptr[i]))
        {
            result.insert(ptr[i]);
        }
    }
    return result;
}

// 对称差集
iSet iSet::setSymmetricDifference(const iSet &other) const
{
    iSet result(_capacity + other._capacity);
    for (int i = 0; i < _size; i++)
    {
        if (!other.contains(ptr[i]))
            result.insert(ptr[i]);
    }
    for (int i = 0; i < other._size; i++)
    {
        if (!contains(other.ptr[i]))
            result.insert(other.ptr[i]);
    }
    return result;
}

// 子集判断
bool iSet::isSubset(const iSet &other) const
{
    for (int i = 0; i < _size; i++)
    {
        if (!other.contains(ptr[i]))
            return false;
    }
    return true;
}

int iSet::find(int val, int start, int end) const
{
    for (int i = start; i <= end && i < _size; i++)
    {
        if (ptr[i] == val)
            return i;
    }
    return -1;
}

// 打印函数
void iSet::print() const
{
    if (isEmpty())
    {
        cout << "{}" << endl;
        return;
    }
    // 拷贝一份临时集合用于排序打印，保证不破坏原集合的数据顺序
    iSet temp(*this);
    temp.uni_sort();

    cout << "{";
    for (int i = 0; i < temp._size; i++)
    {
        cout << temp.ptr[i];
        if (i < temp._size - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}