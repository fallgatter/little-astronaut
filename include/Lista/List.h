
#pragma once

//feita baseada nos slides que o professor fez uma lista duplamente encadeada
//Standard Libraries:
#include<iostream>

namespace Lists{
   template <typename T>
struct Node {
  T data;
  Node *next;
};

template <typename T> class List{
private:
    Node<T> *head;
public:
    List(){
        head = NULL;
    }

    void push(T val){
        Node<T> *n = new Node<T>();   
        n->data = val;             
        n->next = head;        
        head = n;              
    }

    T pop(){
      if(head) {
        T p = head->data;
        head = head->next;
        return p;
      }
    }
    
    bool search(T val) {
      Node<T> *temp = head;
      while(temp->next) {
        if(temp->data == val) return true;
        else temp = temp->next;
      }
      delete temp;
      return false;
    }

    int get_size(){
        Node<T> *temp = head;
        int i;
        if(temp)
            i = 1;
        else return 0;
        while(temp->next){
            temp = temp->next;
            i++;
        }
        return i;
    }
    T operator[] (int idx){
      if(idx < get_size()){
        int i=0;
        Node<T> *temp = head;
        while(i < idx){
          temp = temp->next;
          i++;
        }
        return temp->data;
      }
      else  
        exit;
    } 
};
} using namespace Lists;