#pragma once
#include <iostream>
#include <string>
#include <cstring>

class ExtremeLong
{
private:
    int sign;
    int digit;
    int *ptr;
    long long lim;
    int string_err;

    // 内部辅助函数
    void add(ExtremeLong &, const ExtremeLong &, const ExtremeLong &);

public:
    // 静态常量替代宏定义，避免全局污染
    static const int DEFAULT_CAPACITY = 10000;

    ExtremeLong(int = 0, int = DEFAULT_CAPACITY);
    ExtremeLong(long, int = DEFAULT_CAPACITY);
    ExtremeLong(long long, int = DEFAULT_CAPACITY);
    ExtremeLong(const char *);
    ExtremeLong(const std::string &);
    ExtremeLong(const ExtremeLong &);
    ~ExtremeLong();
    ExtremeLong(ExtremeLong &&); // 移动构造

    // 输入输出流重载
    friend std::istream &operator>>(std::istream &, ExtremeLong &);
    friend std::ostream &operator<<(std::ostream &, const ExtremeLong &);

    // 赋值与复合赋值运算符
    ExtremeLong &operator=(const ExtremeLong &);
    ExtremeLong &operator=(ExtremeLong &&); // 移动赋值
    ExtremeLong &operator=(long long);
    ExtremeLong &operator*=(const ExtremeLong &);
    ExtremeLong &operator+=(const ExtremeLong &);

    // 状态查询与其他操作
    int digits() const;
    int signs() const;
    int operator[](const int) const;
    void resize(long long);
    void carry();
    ExtremeLong abs() const;
};

// 全局运算符重载声明
ExtremeLong operator*(const ExtremeLong &, const ExtremeLong &);
ExtremeLong operator+(const ExtremeLong &, const ExtremeLong &);
ExtremeLong operator^(const ExtremeLong &, const ExtremeLong &);

ExtremeLong operator""_xl(const char *);
ExtremeLong operator""_XL(const char *);

// 比较运算符
bool operator>(const ExtremeLong &, const ExtremeLong &);
bool operator<(const ExtremeLong &, const ExtremeLong &);
bool operator==(const ExtremeLong &, const ExtremeLong &);
bool operator>=(const ExtremeLong &, const ExtremeLong &);
bool operator<=(const ExtremeLong &, const ExtremeLong &);
bool operator!=(const ExtremeLong &, const ExtremeLong &);