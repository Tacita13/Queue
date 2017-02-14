//Implementation/Specification file
//******************************************************************
//
//   Programador : Isamar López Rodríguez 
//   Archivo     : queue.h                Fecha : 10/11/16
//
//******************************************************************
//    Propósito :This file holds the class queue with its private
//      data members and functions that manage a list.
//
//******************************************************************
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<cassert>
using namespace std;

template <class type>
class Node{

public:
    type info;
    Node<type> * link;

    //Constructor
    Node(type item) : info(item),link(NULL) {}

}; //end of node class

template <class type>
class queue{

private:
    Node<type> * qFront;
    Node<type> * qRear;

public:
    //Constructor
    queue();

    //copy
    void copy(const queue<type>&);

    //copy constructor
    queue(const queue<type>&);

    //overloaded assingment operator
    queue<type>& operator=(const queue<type>&);

    //destroy queue
    void destroyQueue();

    //Destructor
    ~queue();

    //Observers
    int size() const;
    bool empty() const;
    type front() const;
    type back() const;
    void print() const;

    //Mutators
    void push(type);
    void pop();
    void moveToFront(int);
    void clear();


};//end of queue class

//Class implementation

//Constructor
    template <class type>
    queue<type>::queue() : qFront(NULL), qRear(NULL) {}

//destroy queue
    template <class type>
    void queue<type>::destroyQueue(){
        while(! empty())
            pop();
    }

//Destructor
    template <class type>
    queue<type>::~queue(){
        destroyQueue();
    }

//Observers
    template <class type>
    int queue<type>::size() const{
        int count=0;
        Node<type> * current = qFront;
        while(current!=NULL){
            count++;
            current=current->link;
        }//end while
        return count;
    }

    template <class type>
    bool queue<type>::empty() const{
        return qFront==NULL;
    }

    template <class type>
    type queue<type>::front() const{
             assert(!empty());
            return qFront->info;
    }


    template <class type>
    type queue<type>::back() const{
            assert(!empty());
            return qRear->info;
    }

    template <class type>
    void queue<type>::print() const{
        if(empty())
            cout<<"Empty list.\n";
        else{
            cout<<"The elements in the list are: \n";
            int limite= size();
            Node<type> * current=qFront;
            for(int i=1; i<=limite; i++){
                cout<<i<<") "<<current->info<<endl;
                current=current->link;
            }//end for
        }//end else
    }//end function

//Mutators
    template <class type>
    void queue<type>::push(type item){

        Node<type> * newNode= new Node<type>(item);
        if(empty()){
            qFront= newNode;
            qRear= newNode;
        }
        else{
            qRear->link= newNode;
            qRear = newNode;

        }
    }

    template <class type>
    void queue<type>::pop(){
        if(empty()){
            cout<<"Empty queue, cannot pop.\n";
        }
        else{
            Node<type>* kod = qFront;
            qFront= qFront->link;
            delete kod;
            //check if only one element in queue
            //adjust qRear
            if(qFront==NULL){
                qRear=NULL;
            }//end if
        }//end else

    }//end function

    template<class type>
    void queue<type>::copy(const queue<type>& other){
        if(other.empty()){
            qFront, qRear= NULL;
        }
        else{
            Node<type> * current= other.qFront;

            //Copy first node
            qFront = new Node<type>(current->info);
            qRear=qFront;
            //Update current
            current=current->link;

            while(current !=NULL){
                //copy/create node
                qRear->link= new Node<type>(current->info);

                //Update pointers
                current=current->link;
                qRear= qRear->link;
            }//end while
        }//end else
    }//end function

    //copy constructor
    template<class type>
    queue<type>::queue(const queue<type>& other){
        copy(other);

    }

    //overloaded assingment operator
    template<class type>
   queue<type>& queue<type>:: operator=(const queue<type>& other){
        if(this !=other){
            destroyQueue();
            copy(other);
        }//end if

        return * this;
    }

   template<class type>
   void queue<type>:: moveToFront(int position){

       if(empty()){
           cout<<"Empty list. Cannot remove.\n";
       }
       else{
           //check for valid position 2 - size
           if(position<=1 || position > size()){
               cout<<"Position = "<<position<<"not valid.\n";
           }
           else{
               //It has a minimum of 2 nodes
               Node<type> * current = qFront->link;
               Node<type> * previous = qFront;
               for(int i=2; i< position; i++){
                   previous=current;
                   current=current->link;

               }//end for
               //Adjust pointers
               previous->link=current->link;
               current->link=qFront;
               qFront=current;

               //check for last node, adjust qRear accordingly
               if(current==qRear){
                   qRear=previous;

               }//end if
           }//end else
       }//end else
   }//end function

   template<class type>
   void queue<type>:: clear(){
       destroyQueue();
   }

#endif // QUEUE_H
