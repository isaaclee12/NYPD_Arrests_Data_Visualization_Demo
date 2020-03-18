//
// Created by isaac on 9/9/2019.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

template<typename Object>
class Stack {
private:
    Node<Object>* top; //pointer to top of stack w/ template bc node is not built in
public:
    //Constructor
    Stack() { //O(C)
        top = nullptr;
    }

    // Deconstructor aka DESTRUCTORRRRRRRRRRR      WRYYYYYYYYYYYYYYYYYYYYYYYYYYYY
    // Automatically called when the Stack object is destroyed
    //It removes excess memory to prevent memory leaks
    ~Stack() { //TILDA IS IMPORTANT - makes a thing into a destructor
        // O(N)
        while (top != nullptr) { //while we have at least one node...
            pop(); //...delete the remaining nodes in the stack.
        }
    }

    //Push
    void push(Object item) { //O(C)
        // Create a node that stores an item
        // Have that node point to the top Node, and update what's at top
        // Top points at this new node (Top is just a null concept that points downward first,
        //Forcing the other parts to point down, too
        if (top != nullptr) {

            /* ALLOCATION:
             * Allocates heap memory to store the Node */
            Node<Object>* newNode = new Node<Object>(item, *top); //here dat node, with a null pointer
            // THIS POINTER IS ALLOCATION TOP TO THE LATEST ITEM IN THE STACK
            //the * in *top dereferences (removes memory address?) "top" to get the node it points to

            //If we *top to nullptr, we die so imma make another ifelse right quick
            top = newNode; //Assign memory address of new top to var "top"

        } else {
            Node<Object>* newNode = new Node<Object>(item);
            top = newNode; //set the pointer to the mem adress of where that node is
        }
    }

    //Pop
    Object pop() { //Returns/tells user the top item, then removes it
        //O(C)
        //Check is node to pop
        if (top != nullptr) {
            //Make a reference Node that stores the top that is going to be popped into a node

            Node<Object>* returnVal = top; //Establish node w/ address of the last pushed node from push()

            //Update top to the node after the one to be removed/node below the one being popped
            top = top->getNext(); //getNext returns the pointer of the one below it, somehow ???
            //i.e. moves "top" assignment to the next top. This is the part which "pops" the top off the stack.

            /* DEALLOCATION */
            Object returnObject = returnVal->getItem();
            //delete keyword is used /w pointer to DEALLOCATE the heap memeory it points to
            delete returnVal;

            //AS OF NOW THERE COULD STILL BE MEM LEAKSADJADOSADJASOIDJ yeet


            //Return the Object from the previous top of Stack (the one being popped)
            return returnObject;
            //returnVal->getItem(); //Return the top that was just popped off
        } else {
            //If it is nullptr, return this so the code doesn't explode and die
            // TODO: Fix this to not return an object
            return Object(); //"Stack is empty, Return Default Object just so the code flows"
        }
    }

    //isThere: SEARCH: Return true if the item is in the Stack; Return false if otherwise.
    bool isThere(Object item) {
        //O(N)
        //Iterate through each node to find the thing
        //Start with a copy of top so we don't change it
        Node<Object>* topCopy = top;
        while (topCopy != nullptr ) { //So long as we haven't looked through all our nodes...
            if (topCopy->getItem() == item) { //If the thing in the node is what we're looking for
                return true; //lADIES AND GEnTLEE MNA we got teem
            }
            topCopy = topCopy->getNext(); //Alright, check the next one
        }
        return false; //If we looked through the nodes and didn't find the item, return false
    }

    //TODO: peek (AKA return the top node), getSize
};

#endif //STACK_STACK_H
