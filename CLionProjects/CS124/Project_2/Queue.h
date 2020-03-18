//
// Created by isaac on 9/17/2019.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

template<typename Object>
class Queue {
private:
    Node<Object>* front; //First in, at front of the line, will be popped
    Node<Object>* back; //Last in, at the back of the line

public:
    //Constructor
    Queue() {
    //O(C)
        front = nullptr;
        back = nullptr;
    }

    //Destructor
    ~Queue() {
    //O(N)
        while (front != nullptr) {
            pop();
        }
    }

    //Push
    void push(Object item) {
    //O(C)
        //If there's something in the front, Send new nodes to the back
        if (front != nullptr) {
            Node<Object>* newNode = new Node<Object>(item); //Add on a new node
            back->setNext(*newNode); //Set the last node to point to what's behind it
            back = newNode; //Set new node as the new "back"


        } else {
            back = front = new Node<Object>(item); //1st item is FRONT and BACK
        }
    }

    //Pop
    Object pop() {
    //O(C)
        if (front != nullptr) {
            if (front == back) {
                back = nullptr; //if it's the last one, kill back
            }
            Node<Object> *popNode = front; //set a return value
            front = front->getNext(); //move front to the next in line behind it
            Object returnObject = popNode->getItem(); //Extract item to be returned from node into a var
            delete popNode; //Deallocate the pointer
            return returnObject;
        } else {
            // TODO: Fix this to not return an object
            return Object(); //"Stack is empty, Return Default Object just so the code flows"
        }
    }
};



#endif //QUEUE_QUEUE_H
