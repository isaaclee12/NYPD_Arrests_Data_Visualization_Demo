#include <iostream>

#include "Node.h"
#include "Stack.h"
#include "lecturer.h"
#include <iostream>
using namespace std;

int main() {

    // Use <> because Node class is a template. Specify the data type in <>.
    Node<int> node1(7);
    Node<int> node2(9, node1);
    cout << node1.getItem() << endl; // Should print 7
    cout << node2.getItem() << endl; // Should print 9
    // The arrow operator is used on pointers. It does two things:
    // 1. Dereferences the pointer (which goes to the memorty address the pointer stores)
    // 2. Uses the dot operator on the object found there.
    cout << node2.getNext()->getItem() << endl; // Should print 7


    /*
     * Stack class
     * push to top of Stack
     * pop from stop of Stack
     * keep track of the top Node with a pointer
     * Each Node points to the one below it.
     */

    Stack<int> stack1;
    stack1.push(7);
    stack1.push(8);
    stack1.push(99999999);
    stack1.push(874);
    stack1.push(823);
    cout << "Popping: " << stack1.pop() << endl;

    cout << boolalpha << stack1.isThere(78) << endl; //False
    cout << stack1.isThere(7) << endl; //True
    cout << stack1.isThere(823) << endl; //False b/c we popped it off

    vector<Lecturer> lecturers;
    /*readLecturersFromFile("CS_Lecturers.csv", lecturers);
    if (lecturers.size() > 5) {
        Stack<Lecturer lecStack;
        lecStack.push(lecturers(0));
        lecStack.push(lecturers[1]);
        //2
        cout << lecStack.isThere(lecturers[3]) << endl;
        //Same but [4]
    }*/


    return 0;
}