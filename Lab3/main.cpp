#pragma once
#include<iostream>
class iSet
{
private:
    int * ptr;
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
//基本要求
    int size()const;
    int capacity()const;
    void print()const;
    void insert(int);

    void erase(int);
    void clear();

    bool isEmpty()const;
    bool isFull()const;
    bool contains(int)const;
    bool isSubset(iSet&)const;

//注意用引用减少内存开销
    iSet setUnion(iSet&)const;
    iSet setIntsection(iSet&)const;
    iSet setDifference(iSet&)const;
    iSet setSymmetricDifference(iSet&)const;

//补充
    iSet& operator=(const iSet&);
    int find(int,int,int)const;

};
