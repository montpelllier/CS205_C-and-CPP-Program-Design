//
// Created by Think on 2021/5/6.
//

#ifndef LAB_STACK_H
#define LAB_STACK_H

typedef unsigned long Item;

class Stack{
private:
    enum {MAX = 10};
    Item * pitems;
    int size;
    int top;
public:
    Stack(int n = MAX);
    Stack(const Stack& st);
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Item& item);
    bool pop(Item& item);
    Stack& operator=(const Stack& st);
    void show();
};


#endif //LAB_STACK_H
