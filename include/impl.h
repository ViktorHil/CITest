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

template<typename T>
std::ostream& operator<<(std::ostream& os,const Lab10::LinkedList<T> &list);

template<typename T>
bool operator==(const Lab10::LinkedList<T>&op1,const Lab10::LinkedList<T>&op2);

template<typename T>
 LinkedList<T>::LinkedList(): _first(nullptr) {
}

template<typename T>
 LinkedList<T>::LinkedList(std::initializer_list<T> list): _first(nullptr)
 {
     Node** current_node = &_first;
     for( auto i : list) {
         *current_node = new Node { i, nullptr};
         current_node = &(*current_node)->next;
     }

 }
template<typename T>
 LinkedList<T>::LinkedList(const LinkedList &src) : _first(nullptr)
 {
     Node** node = &_first;
     for( Node* const* current_node = &list._first;
          *current_node != nullptr;
          current_node = &(*current_node)->next) {

         *node = new Node { (*current_node)->value, nullptr};
         node = &(*node)->next;
     }
 }

template<typename T>
 LinkedList<T>::LinkedList(LinkedList &&src)
 {
     _first = src._first;
     src._first = nullptr;

 }

template<typename T>
 LinkedList<T>::~LinkedList()
{
     while( nullptr != _first) {
         Node* current_node = _first;
         _first = current_node->next;
         delete current_node;
     }

}
template<typename T>
 void LinkedList<T>::removeAt(int index)
 {
     Node** current = &_first;
     for( int pos = 0; *current != nullptr; pos++) {
         if ( pos == index) {
             Node* for_delete = *current;
             *current = for_delete->next;
             delete for_delete;
             break;
         }
         current = &(*current)->next;
     }
 }
template<typename T>
 void LinkedList<T>::insertAt(int index,T value)
 {
     Node** current_node = &_first;
     int     position = 0;
     do {
         if ( index == position) {
             *current_node = new Node { value, *current_node};
             break;
         }
         current_node = &(*current_node)->next;
         position++;
     } while( nullptr != *current_node);
 }

template<typename T>
 int LinkedList<T>::getLength() const
 {
     Node* current = _first;
     for( int i = 0;; i++) {
         if ( nullptr == current) {
             return i;
         }
         current = current->next;
     }
     return 0;
 }
template<typename T>
 void LinkedList<T>::sort(std::function<bool(T,T)> predicate)
 {
 }
template<typename T>
 bool operator==(const LinkedList<T>&op1,const LinkedList<T>&op2)
 {
     LinkedList::Node* current1 = op1._first;
     LinkedList::Node* current2 = op2._first;
     bool res = false;
     while(( nullptr != current1)&&( nullptr != current2)) {
         if (( current1->value) == ( current2->value)) {
             res = true;
         } else {
             res = false;
             break;
         }
         current1 = current1->next;
         current2 = current2->next;
     }
     return res;
 }
template<typename T>
 std::ostream& operator<<(std::ostream& os,const LinkedList<T> &list)
 {
     LinkedList::Node* current_node = list._first;
     for( int i = 0; i < list.getLength(); i++ ) {
         os << "[" << i << "]" << current_node->value << std::endl;
     }
  return os;

 }



}; //namespace
