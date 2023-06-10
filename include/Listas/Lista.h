//Classe desenvolvida a partir dos slides pertencentes ao professor, no qual é desenvolvida uma lista duplamente encadeada
#pragma once

//Cabeçalhos Padrões:
#include<iostream>

namespace Listas{
    template <typename T>
      class Node {
        public:
          T data;
          Node *next;
          Node():
            data(NULL), next(NULL){}
          ~Node(){
            data=NULL;
            next=NULL;
          }
      };

  template <typename T> class Lista{
    private:
        Node<T> *head;
    public:
        Lista(){
          head = NULL;
        }

        ~Lista(){
          Node<T> *aux=head;

          while(aux!=NULL){
            head=head->next;
            delete aux;
            aux=head;
          }
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
        
        T* search(T val) {
          Node<T> *temp = head;
          while(temp->next) {
            if(temp->data == val) return temp;
            else temp = temp->next;
          }
          return NULL;
        }
        
        void destroy(T val){
          Node<T> *temp = head;
          Node<T> *aux;
          while(temp->data != val) {
            aux = temp;
            temp = temp->next;
          }
          aux->next = temp->next;
          destroy *temp;
        }

        int get_size(){
          if(head!=NULL){
            Node<T> *temp = head;
            int i;
            if(temp)
                i = 1;
            else return 0;
            while(temp->next!=NULL){
                temp = temp->next;
                i++;
            }
            return i;
          }
          return 0;
        }

        T operator[] (int idx){
          if(idx < get_size() && head!=NULL){
            int i=0;
            Node<T> *temp = head;
            while(i < idx && temp->next!=NULL){
              temp = temp->next;
              i++;
            }
            return temp->data;
          }
          else{
            return NULL;
          } 
        } 
  };
} using namespace Listas;