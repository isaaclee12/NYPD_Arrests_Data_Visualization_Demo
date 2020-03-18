#include <iostream>
#include <optional>
#include <string>
using namespace std;
//using optional;
//using nullopt;

typedef optional<string> OptString;

class Attributes {
private:
    string starburstFlavor;
    string animal;
    OptString color;

public:
    Attributes() {
        starburstFlavor = "pink";
        animal = "toucan";
        color = nullopt;
    }
    void setFavoriteColor(string color) {
        this->color = color;
    }
    void setColorNull() {
        this->color = nullopt;
    }
    OptString getFavoriteColor() const { //SET GETTERS CONST
        return color;
    }
};

int main() {
    // ISAAC LEE ATTEMPTS AN OPTIONAL
    Attributes a;
    if (a.getFavoriteColor()) { //IF IT GOT STUFF THEN YEET IT
        cout << "Has a favorite color!: " << *a.getFavoriteColor() << endl;
    } else {
        cout << "WE AINT FOUND poopoo" << endl;
    }
    a.setFavoriteColor("");
    if (a.getFavoriteColor()) { //IF IT GOT STUFF THEN YEET IT
        cout << "Has a favorite color!: " << *a.getFavoriteColor() << endl;
    } else {
        cout << "WE AINT FOUND poopoo" << endl;
    }

    unique_ptr<Attributes> my_ptr = make_unique<Attributes>();
    my_ptr->setFavoriteColor("Eggshell");
    if (my_ptr->getFavoriteColor()) {
        cout << *my_ptr->getFavoriteColor() << endl; //Need asterisk to get the value from the optional
    }
    //You cannot copy a unique pointer
    //unique_ptr<Attributes> my_ptr2 = my_ptr;

    shared_ptr<Attributes> my_ptr2 = make_shared<Attributes>();
    auto my_ptr3 = my_ptr2; // Makes a clone for the shared pointer :o
    if (my_ptr2->getFavoriteColor()) { //No value set, so this should return falseyou
        cout << "TRUE" << endl;
    } else {
        cout << "FOLS" << endl;
    }
    my_ptr3->setFavoriteColor("Blood Orange"); //Use shared pointer to set favorite color to a value
    if (my_ptr2->getFavoriteColor()) { //There is now a value, so this should return true
        cout << "TRUE" << endl;
    } else {
        cout << "FOLS" << endl;
    }

    return 0;
}