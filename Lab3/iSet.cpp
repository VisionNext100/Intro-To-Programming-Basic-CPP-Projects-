#include <iostream>
#include "iSet.h"
using namespace std;

void sorter(int a[],int m,int n) {
    if(m>n-1){
        return;}
    else{
        int i=m-1; int j=n+1;
        int temp=a[m+n>>1];
        while(i<j) {
            while(a[++i]<temp);
            while(a[--j]>temp);
            if(i<j) {
                int t=a[i]; //交换元素
                a[i]=a[j];
                a[j]=t;
            }
        }
        sorter(a,m,j);
        sorter(a,j+1,n);
    }
}

iSet::iSet(int c) {
    if(c<1) {  //报告异常
        throw iSet::bad_iSet(1);
    }
    setcapacity=c;
    setsize=0;
    setlist = new int[c];
}

iSet::~iSet() {
    if(setlist==nullptr) return;
    delete[] setlist;
}

void iSet::print() { //printing
    if(setsize==0) {
        cout<<"{}";
        return;
    }
    sorter(setlist,0,setsize-1);
    cout<<"{";
    for(int i=0;i<setsize;i++) {
        if(i==setsize-1) {
            cout<<setlist[i];
            break;
        }
        cout<<setlist[i]<<",";
    }
    cout<<"}";
}

int iSet::size() { //size
    return setsize;
}

int iSet::capacity() {
    return setcapacity;
}

bool iSet::contains(int n) {
    for(int i=0;i<setsize;i++) {
        if(setlist[i]==n) {
            return true;
        }
    }
    return false;
}

bool iSet::empty() {
    return setsize==0;
}

bool iSet::full() {
    return setsize==setcapacity;
}

void iSet::clear() {
   if(setlist != nullptr) {
        delete[] setlist;
   }
   setlist=new int[setcapacity];
   setsize=0;
}

void iSet::insert(int i) {
    if(this->full()) {
        throw iSet::bad_iSet(2);
    }
    if(contains(i)) return;
    setlist[setsize++] = i;
}

iSet iSet::setUnion(iSet& other) {
    iSet unionset(max(this->setcapacity,other.setcapacity));
    for(int i=0;i<this->setsize;i++) {
        unionset.insert(this->setlist[i]);
    }
    for(int i=0;i<other.setsize;i++) {
        unionset.insert(other.setlist[i]);
    }
    return unionset;
}

iSet iSet::setIntersection(iSet& other) {
    iSet intersectinoset(max(setcapacity,other.setcapacity));
    for(int i=0;i<setsize;i++) {
        if(other.contains(setlist[i])) {
            intersectinoset.insert(setlist[i]);
        }
    }
    return intersectinoset;
}

iSet iSet::setDifference(iSet& other) {
    iSet differenceset(max(setcapacity,other.setcapacity));
    for(int i=0;i<setsize;i++) {
        if(!other.contains(setlist[i])) {
            differenceset.insert(setlist[i]);
        }
    }
    return differenceset;
}

iSet iSet::setSymmetricDifference(iSet& other) {
    iSet symdiffset(max(setcapacity,other.setcapacity));
    for(int i=0;i<setsize;i++) {
        if(!other.contains(setlist[i])) {
            symdiffset.insert(setlist[i]);
        }
    }
    for(int i=0;i<other.setsize;i++) {
        if(!this->contains(other.setlist[i])) {
            symdiffset.insert(other.setlist[i]);
        }
    }
    return symdiffset;
}

iSet& iSet::operator=(iSet& other) {
    setsize=other.setsize;
    setcapacity=other.setcapacity;
    if(setlist!=nullptr) {
        delete[] setlist;
    }
    setlist = new int[other.setcapacity];
    for(int i=0;i<other.setsize;i++) {
        setlist[i]=other.setlist[i];
    }
    return *this;
}

void iSet::erase(int n) {
    if(!contains(n)) return;
    int *erased = new int[setcapacity];
    int pos=0;
    for(int i=0;i<setsize;i++) {
        if(setlist[i]==n) {
            continue;
        }
        erased[pos++]=setlist[i];
    }
    if(setlist!=nullptr) {
        delete[] setlist;
    }
    setlist = erased;
    setsize--;
}

bool iSet::isSubset(iSet& other) {
    if(other.empty()) {return true;}
    for(int i=0;i<setsize;i++) {
        if(!other.contains(setlist[i])) {
            return false;
        }
    }
    return true;
}

iSet::bad_iSet::bad_iSet(int i) {
    errnum=i;
}
