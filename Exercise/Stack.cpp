//
// Created by Think on 2021/5/6.
//
#include <iostream>
#include "Stack.h"

Stack::Stack(int n) {
    pitems = new Item[n];
//    std::cout << "Please input " << n << " numbers\n";
//    for (int i = 0; i < n; ++i) std::cin >> pitems[i];
    size = n;
    top = -1;
}
Stack::Stack(const Stack& st){
    pitems = st.pitems;
    size = st.size;
    top = st.top;
}
Stack::~Stack(){
    delete[] pitems;
}
bool Stack::isEmpty() const{
    return (top+1) == 0;
}
bool Stack::isFull() const{
    return (top+1) == size;
}
bool Stack::push(const Item& item){
    if (!isFull()) pitems[++top] = item;
    return !isFull();
}
bool Stack::pop(Item& item){
    if (!isEmpty()) item = pitems[top--];
    return !isEmpty();
}
Stack& Stack::operator=(const Stack& st){
    if (this == &st) return *this;
    delete[] pitems;
    pitems = new Item[st.size];
    size = st.size;
    top = st.top;
    for (int i = 0; i < size; ++i) {
        pitems[i] = st.pitems[i];
    }
    return *this;
}
void Stack::show()
{
    for(int i=0; i<=top; i++)
        std::cout << pitems[i] << std::endl;
}