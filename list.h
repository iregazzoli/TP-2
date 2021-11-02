#ifndef LIST_H
#define LIST_H
#include <fstream>
#include <iostream>
#include "node.h"

template <class T>
class List {

private:
    Node<T>* first_node;
    Node<T>* current_node;
    Node<T>* previous_node;

public:
    List(){

      first_node = 0;
      current_node = 0;
      previous_node = 0;

    }

    ~List(){

      while(first_node != 0){

        Node<T>* aux = first_node->get_next_node();

        delete_current_node();

        first_node = aux;

        reset_current_node();

      }

    }

    void add_node(T* value);

    void reset_current_node();

    T* get_current_value();

    void next_node();

    void delete_current_node();

};


template <class T>
void List<T>::add_node(T* value) {

  Node<T>* new_node = new Node<T>(value);

  new_node->set_next_node(first_node);

  first_node = new_node;

}

template <class T>
void List<T>::reset_current_node() {

  previous_node = 0;
  current_node = first_node;

}

template <class T>
T* List<T>::get_current_value() {

  if(current_node != 0)
    return current_node->get_value();

  return 0;

}

template <class T>
void List<T>::next_node() {

  previous_node = current_node;
  current_node = current_node->get_next_node();

}


template <class T>
void List<T>::delete_current_node() {

  //node to delete is the first on of the list.
  if(current_node == first_node){

    first_node = first_node->get_next_node();

    delete current_node;

  }

  else{

    previous_node->set_next_node(current_node->get_next_node());

    delete current_node;

    reset_current_node();

  }

}


#endif
