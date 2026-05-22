#include "heteroQueue.h"
#include <iostream>
using namespace std;

INT::INT(int a){
    num=a;
}

void INT::print()const{
    cout<<num<< endl;
}

CHAR::CHAR(char c){
    this->c=c;
}

void CHAR::print()const{
    cout<<c<< endl;
}

PhoneNumber::PhoneNumber(){
    name="";
    number=0;
}

void PhoneNumber::print()const{
    cout<<"("<<name<<","<<number<<")"<< endl;
}

istream& operator>>(istream&in, PhoneNumber &p){
    in>>p.number;
    cout<<"Please enter the name :"<<endl;
    in>>p.name;
    return in;
}

Hqueue::Hqueue(int a){
    m_capability = a;
    m_size = 0;
    pb=new Base*[a];
}

Hqueue::~Hqueue(){
    delete pb;
}

bool Hqueue::isEmpty()const{
    if(m_size==0)   return true;
    else    return false;
}

void Hqueue::dequeue(){
    if(m_size == 0)
        throw bad_op{};
    else if(m_size > 0){
        pb[0]->print();
        for(int i = 0; i < m_size-1; i++){
            pb[i]=pb[i+1];
        }
        m_size--;}
}

void Hqueue::enqueue(Base* b){
    if(m_size==m_capability){
        m_capability *=1.2;
        Base** temp=new Base*[m_capability];
        for(int i=0; i<m_size; i++){
            temp[i]=this->pb[i];
        }
        delete[] pb;
        pb=temp;}
    pb[m_size++]=b;
}

Hqueue::bad_op::bad_op(){
    type="The queue is empty";
}
