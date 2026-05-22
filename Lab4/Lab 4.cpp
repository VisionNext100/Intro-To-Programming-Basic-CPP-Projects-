#include "ExtremeLong.h"
#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <climits>
using namespace std;

void ExtremeLong::add(ExtremeLong& t,const ExtremeLong& ADD ,const ExtremeLong& SUB){
    for(int i = 0; i < SUB.digit; i++)  t.ptr[i] -= SUB.ptr[i];
    for(int i = 0; i < ADD.digit; i++)  t.ptr[i] += ADD.ptr[i];
}

ExtremeLong::ExtremeLong(int a = 0, int size = 50)
{
    ptr = new int[size];
    memset(ptr,0,size * sizeof(int));
    lim = size;
    sign = 1;
    bool flag = false;
    if(a < 0 && a != INT_MIN){
        a = -a;
        sign = -1;
    }
    else if(a == INT_MIN){
        sign = -1;
        a = INT_MAX;
        flag = true;
    }
    if(flag){
        flag = false;
        ptr[0]+=1;
    }
    digit = 0;
    while(a){
        ptr[digit++] = a % 10;
        a/=10;
    }
    digit++;
    carry();
}

ExtremeLong::ExtremeLong(long a, int size = 50){
    ptr = new int[size];
    memset(ptr,0,size * sizeof(int));
    lim = size;
    sign = 1;
    bool flag = false;
    if(a < 0 && a != LONG_MIN){
        a = -a;
        sign = -1;
    }
    else if(a == LONG_MIN){
        sign = -1;
        a = LONG_MAX;
        flag = true;
    }
    if(flag){
        flag = false;
        ptr[0]+=1;
    }
    digit = 0;
    while(a){
        ptr[digit++] = a % 10;
        a/=10;
    }
    digit++;
    carry();
}

ExtremeLong::ExtremeLong(long long a, int size = 50){
    ptr = new int[size];
    memset(ptr,0,size * sizeof(int));
    lim = size;
    sign = 1;
    bool flag = false;
    if(a < 0 && a != LONG_LONG_MIN){
        a = -a;
        sign = -1;
    }
    else if(a == LONG_LONG_MIN){
        sign = -1;
        a = LONG_LONG_MAX;
        flag = true;
    }
    if(flag){
        flag = false;
        ptr[0]+=1;
    }
    digit = 0;
    while(a){
        ptr[digit++] = a % 10;
        a/=10;
    }
    digit++;
    carry();
}

ExtremeLong::ExtremeLong(const char* c)
{
    sign = 1;
    digit = 0;
    long long len = strlen(c);
    lim = len;
    ptr = new int[lim];
    memset(ptr,0,len * sizeof(int));
    bool flag = false;
    if(c[0] == '-'){
        sign = -1;
        flag = true;
    }
    for(int i = len - 1; i >= ((flag) ? 1 : 0) ;i--){
        if(!isdigit(c[i]))
            throw string_err;
        ptr[digit++] = c[i] - '0';
    }
    while(ptr[digit - 1] == 0)  digit--;
    if(digit == 0 && ptr[0] == 0){
        digit = 1;
        sign = 1;
    }
}

ExtremeLong::ExtremeLong(const string& s)
{
    sign = 1;
    digit = 0;
    long long len = s.length();
    lim = len;
    ptr = new int[lim];
    memset(ptr,0,len * sizeof(int));
    bool flag = false;
    if(s[0] == '-'){
        sign = -1;
        flag = true;
    }
    for(int i = len - 1; i >= ((flag) ? 1 : 0) ;i--){
        if(!isdigit(s[i]))  throw string_err;
        ptr[digit++] = s[i] - '0';
    }
    while(ptr[digit - 1] == 0)  digit--;
    if(digit == 0 && ptr[0] == 0){
        digit = 1;
        sign = 1;
    }
}

ExtremeLong::ExtremeLong(const ExtremeLong&E){
    lim = E.lim;
    digit = E.digit;
    sign = E.sign;
    ptr = new int [lim];
    memset(ptr,0,E.lim * sizeof(int));
    for(int i = 0; i < digit; i++)  ptr[i] = E.ptr[i];
}
ExtremeLong::~ExtremeLong(){
    delete[]ptr;
}

ExtremeLong::ExtremeLong(ExtremeLong&& E){
    this->digit = E.digit;
    this->sign = E.sign;
    this->ptr = E.ptr;
    this->lim = E.lim;
    E.ptr = NULL;
}

istream& operator>>(istream& input,ExtremeLong& E){
    string s;
    cin>>s;
    ExtremeLong E1{s};
    cout << E1 << endl;
    E = E1;
}

ostream& operator<<(ostream& out,const ExtremeLong& E){
    out << ((E.sign == 1) ? "" : "-");
    for(int i = E.digit - 1; i >= 0; i--)   out << E.ptr[i];
    return out;
}

ExtremeLong& ExtremeLong:: operator=(const ExtremeLong& E){
    lim = E.lim;
    digit = E.digit;
    sign = E.sign;
    int* temp = new int[lim];
    memset(temp,0,sizeof(temp));
    for(int i = 0; i < digit; i++)temp[i] = E.ptr[i];
    delete[] ptr;
    ptr = temp;
}

ExtremeLong& ExtremeLong::operator=(ExtremeLong&& E){
    this->ptr = E.ptr;
    this->digit = E.digit;
    this->lim = E.lim;
    this->sign = E.sign;
}

ExtremeLong& ExtremeLong ::operator=(long long a){
    delete[] ptr;
    ptr = new int[50];
    memset(ptr,0,50 * sizeof(int));
    lim = 50;
    sign = 1;
    bool flag = false;
    if(a < 0 && a != LONG_LONG_MIN){
        a = -a;
        sign = -1;
    }
    else if(a == LONG_LONG_MIN){
        sign = -1;
        a = LONG_LONG_MAX;
        flag = true;
    }
    if(flag){
        flag = false;
        ptr[0]+=1;
    }
    digit = 0;
    while(a){
        ptr[digit++] = a % 10;
        a/=10;
    }
    if(!digit)  digit++;
    carry();
}

ExtremeLong& ExtremeLong::operator*=(const ExtremeLong&E){
    ExtremeLong t;
    t.resize(lim + E.digit);
    t.digit = digit + E.digit;
    t.sign = sign * E.sign;
    for(int i = 0; i < digit; i++){
        for(int j = 0; j < E.digit; j++){
                t.ptr[i+j] +=  ptr[i] * E.ptr[j];
        }
    }
    t.carry();
    *this = t;
    return *this;
}

ExtremeLong& ExtremeLong::operator+=(const ExtremeLong& E){
    ExtremeLong t;
    t.resize((digit > E.digit) ? digit + 1 : E.digit + 1);
    t.digit = ((digit > E.digit) ? digit : E.digit);
    if(sign == E.sign){
        t.resize((E.lim > lim) ? E.lim + 2: lim + 2);
        for(int i = 0; i < digit; i++)  t.ptr[i] += ptr[i];
        for(int i = 0; i < E.digit; i++)    t.ptr[i] += E.ptr[i];

    }
    else{
        if(digit < E.digit){
            t.sign = E.sign;
            add(t,E,*this);
        }
        else if(digit > E.digit){
            t.sign = sign;
            add(t,*this,E);
        }
        else{
            int flag = 0;
            for(int i = digit - 1; i >= 0; i--){
                if(ptr[i] > E.ptr[i]){
                    flag = 1;
                    break;
                }
                else if(ptr[i] < E.ptr[i]){
                    flag = 2;
                    break;
                }
            }
            if(flag == 0){
                *this = 0;
            }
            else if(flag == 1){
                t.sign = sign;
                add(t,*this,E);
            }
            else if(flag == 2){
                t.sign = E.sign;
                add(t,E,*this);
            }
        }
    }
    t.carry();
    *this = t;
    return *this;
}

int ExtremeLong::digits()const{
    return digit;
}

int ExtremeLong::signs()const{
    return sign;
}

int ExtremeLong::operator[](const int a)const{
    return ptr[a];
}

void ExtremeLong::resize(long long a){
    int*temp = new int[a];
    memset(temp,0,a*sizeof(int));
    if(digit > a)   digit = a;
    for(int i = 0; i < digit; i++)  temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
    lim = a;
}

void ExtremeLong::carry(){
    digit = lim - 1;
    bool flag = false;
    while(ptr[digit] == 0 && digit >= 0){
        flag = true;
        digit--;
    }
    if(flag)    digit++;
    for(int i = 0; i < digit; i++){
        if(ptr[i] >= 10){
            if(i  == lim - 1){
                resize(2*lim);
            }
            if(i == digit - 1){
                digit++;
            }
            ptr[i + 1] += ptr[i] / 10;
            ptr[i] %= 10;
        }
    }
    for(int i = 0; i < digit; i++){
        if(ptr[i] < 0){
            ptr[i+1]--;
            ptr[i] += 10;
        }
    }
    flag = false;
    while(ptr[digit] == 0 && digit >= 0){
        flag = true;
        digit--;
    }
    if(flag)    digit++;
    if(!digit)  digit = 1;
}
ExtremeLong ExtremeLong::abs(){
    ExtremeLong E{*this};
    E.sign = 1;
    return E;
}

ExtremeLong operator*(const ExtremeLong& e1,const ExtremeLong& e2){
    ExtremeLong e3 = e1;
    e3 *= e2;
    return e3;
}

ExtremeLong operator+(const ExtremeLong& e1,const ExtremeLong& e2){
    ExtremeLong e3 = e1;
    e3 += e2;
    return e3;
}

ExtremeLong operator^(const ExtremeLong& e1,const ExtremeLong& e2){
    if(e2 == 0) return e1;
    else{
        ExtremeLong E{e1};
        for(ExtremeLong i{1}; i < e2; i += 1){
            E *= e1;
        }
        return E;
    }
}

ExtremeLong operator""xl(const char* c)
{
    return ExtremeLong(c);
}

ExtremeLong operator""XL(const char* c)
{
    return ExtremeLong(c);
}

bool operator>(const ExtremeLong& e1,const ExtremeLong& e2){
    if(e1.signs() > e2.signs()) return true;
    else if(e1.signs() < e2. signs())   return false;
    if(e1.signs() == 1){
        if(e1.digits() > e2.digits())   return true;
        else if(e1.digits() < e2.digits())  return false;
        for(int i = e1.digits() - 1; i >= 0; i--){
            if(e1[i] > e2[i])   return true;
            else if(e1[i] < e2[i])  return false;
        }
    }
    else if(e1.signs() == -1){
        if(e1.digits() > e2.digits())   return false;
        else if(e1.digits() < e2.digits())  return true;
        for(int i = e1.digits() - 1; i >= 0; i--){
            if(e1[i] > e2[i])   return false;
            else if(e1[i] < e2[i])  return true;
        }
    }
    return false;
}

bool operator<(const ExtremeLong& e1,const ExtremeLong& e2){
    if(e1.signs() > e2.signs()) return false;
    else if(e1.signs() < e2. signs())   return true;
    if(e1.signs() == 1){
        if(e1.digits() > e2.digits())   return false;
        else if(e1.digits() < e2.digits())  return true;
        for(int i = e1.digits() - 1; i >= 0; i--){
            if(e1[i] > e2[i])   return false;
            else if(e1[i] < e2[i])  return true;
        }
    }
    else if(e1.signs() == -1){
        if(e1.digits() > e2.digits())   return true;
        else if(e1.digits() < e2.digits())  return false;
        for(int i = e1.digits() - 1; i >= 0; i--){
            if(e1[i] > e2[i])   return true;
            else if(e1[i] < e2[i])  return false;
        }
    }
    return false;
}

bool operator==(const ExtremeLong&e1, const ExtremeLong&e2){
    if(e1.signs() != e2.signs())    return false;
    if(e1.digits() != e2.digits())  return false;
    for(int i = e1.digits() - 1; i >= 0; i--){
        if( e1[i] != e2[i] )
        return false;
    }
    return true;
}

bool operator>=(const ExtremeLong& e1, const ExtremeLong& e2){
    return (e1 > e2) || (e1 == e2);
}

bool operator<=(const ExtremeLong& e1, const ExtremeLong& e2){
    return (e1 < e2) || (e1 == e2);
}

bool operator!=(const ExtremeLong& e1, const ExtremeLong& e2){
    return !(e1 == e2);
}
