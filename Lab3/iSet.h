#pragma once
#include <iostream>
class iSet
{
private:
    int *ptr;
    int capability;
    int element;
    void uni_sort();

public:
    struct bad_iSet
    {
        int errnum;
    };
    iSet(int);
    iSet(const iSet &);
    ~iSet();
//定义集合运算
    iSet setUnion(iSet&)const;
    iSet setIntsection(iSet&)const;
    iSet setDifference(iSet&)const;
    iSet setSymmetricDifference(iSet&)const;
    void insert(int);
    void erase(int);

    bool isSubset(iSet&)const;
    bool contains(int)const;
    void print()const;
    int size()const;
    int capacity()const;
    bool isEmpty()const;
    bool isFull()const;
    void clear();

    iSet& operator=(const iSet&);
    int find(int,int,int)const;
};
