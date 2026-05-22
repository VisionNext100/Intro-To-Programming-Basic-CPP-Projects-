#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#define M 10000
using namespace std;

class ExtremeLong
{
    int sign;
    int digit;
    int *ptr;
    long long lim;
    int string_err;
    void add(ExtremeLong&,const ExtremeLong&, const ExtremeLong&);

public:
    ExtremeLong(int, int);
    ExtremeLong(long, int);
    ExtremeLong(long long, int);
    ExtremeLong(const char*);
    ExtremeLong(const string&);
    ExtremeLong(const ExtremeLong&);
    ~ExtremeLong();
    ExtremeLong(ExtremeLong&&);
    friend istream& operator>>(istream&,ExtremeLong&);
    friend ostream& operator<<(ostream&,const ExtremeLong&);
    ExtremeLong& operator=(const ExtremeLong&);
    ExtremeLong& operator=(ExtremeLong&&);
    ExtremeLong& operator=(long long);
    ExtremeLong& operator*=(const ExtremeLong&);
    ExtremeLong& operator+=(const ExtremeLong&);
    int digits()const;
    int signs()const;
    int operator[](const int)const;
    void resize(long long);
    void carry();
    ExtremeLong abs();
};

ExtremeLong operator*(const ExtremeLong&,const ExtremeLong&);
ExtremeLong operator+(const ExtremeLong&,const ExtremeLong&);
ExtremeLong operator^(const ExtremeLong&,const ExtremeLong&);
ExtremeLong operator""xl(const char*);
ExtremeLong operator""XL(const char*);
bool operator>(const ExtremeLong&,const ExtremeLong&);
bool operator<(const ExtremeLong&,const ExtremeLong&);
bool operator==(const ExtremeLong&,const ExtremeLong&);
bool operator>=(const ExtremeLong&,const ExtremeLong&);
bool operator<=(const ExtremeLong&,const ExtremeLong&);
bool operator!=(const ExtremeLong&,const ExtremeLong&);
