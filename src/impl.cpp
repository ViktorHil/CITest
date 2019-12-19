/*
 * LinkedList.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#include "impl.h"
#include <exception>
#include <stdexcept>

using namespace Lab10;

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

 }
template<typename T>
 LinkedList<T>::LinkedList(const LinkedList &src) : _first(nullptr)
 {
 }

template<typename T>
 LinkedList<T>::LinkedList(LinkedList &&src)
 {
 }

template<typename T>
 LinkedList<T>::~LinkedList()
{
}
template<typename T>
 void LinkedList<T>::removeAt(int index)
 {
 }
template<typename T>
 void LinkedList<T>::insertAt(int index,T value)
 {
 }

template<typename T>
 int LinkedList<T>::getLength() const
 {
 return -1;
 }
template<typename T>
 void LinkedList<T>::sort(std::function<bool(T,T)> predicate)
 {
 }
template<typename T>
 bool operator==(const LinkedList<T>&op1,const LinkedList<T>&op2)
 {
 return false;
 }
template<typename T>
 std::ostream& operator<<(std::ostream& os,const LinkedList<T> &list)
 {
 return os;
 }
