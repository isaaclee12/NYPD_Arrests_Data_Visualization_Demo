//
// Created by isaac on 3/2/2020.
//

#ifndef POLYMORPHISMPRACTICE_HAT_H
#define POLYMORPHISMPRACTICE_HAT_H

#include <iostream>
#include <string>
#include <vector>
#include std::iostream
#include std::string
#include std::vector
using namespace std;

enum size {small, medium, large};
enum type {baseball, winter, beret};

struct Hat {
    size hatSize;
    bool clean; //status
    type hatType;
    string color;
};

class HatStorage {
private:
    vector<Hat> hatVector;
public:
    HatStorage();

    int numHats(type t, bool clean);

    void addHat(Hat);
    int numHats(size s, bool clean, type t, string color);

    //B

};

#endif //POLYMORPHISMPRACTICE_HAT_H