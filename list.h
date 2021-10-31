#ifndef LIST_H
#define LIST_H
#include <fstream>
#include <iostream>
#include "node.h"

template <class T>
class List {

private:
    Node<T> first_node;

public:
    void add_node(T* value);

    void remove_node(string reference);

};


template <class T>
void List<T>::add_node(T* value){
  
  Node<T>* new_node = new Node<T>(value);

  new_node->set_next_node(first_node);

  first_node = new_node;
}

template <class T>
void List<T>::remove_node(string reference) {

    Node<T>* current_node = first_node;
    Node<T>* previous_node = 0;

    first_node = first_node->get_next_node();

    current_node->~Node();
    delete current_node;

}


#endif 