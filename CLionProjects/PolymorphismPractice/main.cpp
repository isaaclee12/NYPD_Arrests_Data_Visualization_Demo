#include <iostream>
#include "Hat.h"

int main() {

    //COMPUPTER STUFF

    vector<unique_ptr<Computer>> computers;

    computers.push_back(make_unique<Windows>());
    computers.push_back(make_unique<Mac>());

    for (unique_ptr<Computer> &c : computers) {
        c->installCLion();
    }

    return 0;
}