#pragma once

#include <iostream>
#include <functional>

namespace Lab10
{
template <typename T>
class LinkedList {
private:
    struct Node
    {
        T value;
        Node *next {nullptr};
    };
Node* _first;

public:
    LinkedList();
    LinkedList(std::initializer_list<T> list);
    LinkedList(const LinkedList<T>& src);
    LinkedList(LinkedList &&src);
    virtual ~LinkedList();
    void insertAt(int index,T value);
    void removeAt(int index);
    int getLength() const;

    void sort(std::function<bool(T,T)>);

    template<typename M>
    friend bool operator==(const Lab10::LinkedList<M>&op1,const Lab10::LinkedList<M>&op2);
    template<typename M>
    friend std::ostream& operator<<(std::ostream& os,const Lab10::LinkedList<M> &list);
};

}; //namespace
