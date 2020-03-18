//
// Created by isaac on 8/28/2019.
//

//Lecturer Class
#ifndef LECTURER_LECTURER_H
#define LECTURER_LECTURER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Lecturer class
class Lecturer {
private:
    string name;
    string office;
    int class1;
    int class2;
    int class3;

public:
    // Constructors
    Lecturer() {
        name = "Jane Doe";
        office = "Innovation E200";
        class1 = class2 = class3 = 0;
    }
    Lecturer(string name, string office, int class1, int class2, int class3) {
        this->name = name;
        this->office = office;
        setClass1(class1);
        setClass2(class2);
        setClass3(class3);
    }

    // Getters
    // const means the method cannot modify fields of the class
    string getName() const {
        return name;
    }
    string getOffice() const {
        return office;
    }
    int getClass1() const {
        return class1;
    }
    int getClass2() const {
        return class2;
    }
    int getClass3() const {
        return class3;
    }

    // Setters
    void setName(string name) {
        this->name = name;
    }
    void setOffice(string office) {
        this->office = office;
    }
    void setClass1(int class1) {
        if (class1 < 0) {
            this->class1 = 0;
        } else {
            this->class1 = class1;
        }
    }
    void setClass2(int class2) {
        // ternary operator
        // Is class2 < 0? If so, set to 0; If not, set to class2.
        this->class2 = (class2 < 0) ? 0 : class2;
    }
    void setClass3(int class3) {
        // ternary operator
        this->class3 = (class3 < 0) ? 0 : class3;
    }

    //Overload == operator to compare lecturer
    friend bool operator == (const Lecturer &lhs, const Lecturer &rhs) {
        //Compare name atribute return bool
        return lhs.getName() == rhs.getName();
    }

    void readLecturersFromFile(string filename, vector<Lecturer> &lecturers) {
        ifstream fIn;
        // Open the CS_Lecturers.csv file from outside the cmake-build-debug folder
        fIn.open("../" + filename);

        // Loop while there are still rows in the file
        // Stop when we reach the end-of-file (EOF)
        while (fIn && fIn.peek() != EOF) {
            string name = "", office = "";
            int class1 = -1, class2 = -1, class3 = -1;
            char comma;

            // Read name
            // getline: for reading into strings. Stop at a comma.
            getline(fIn, name, ',');
            cout << name << endl;

            // Read class1
            fIn >> class1;
            cout << class1 << endl;
            fIn >> comma;

            // Read class2f there is one)
            fIn >> class2;
            fIn >> class2;
            cout << class2 << endl;
            fIn >> comma;

            // Read class3 (ilass3;
            if (!fIn) {
                // The file is not in a good state
                // That means there was no class3
                class3 = 0;
                fIn.clear();
            }
            cout << class3 << endl;
            fIn >> comma;

            // Read office
            // Read until the end of the line (because this is the last column)
            getline(fIn, office);
            cout << office << endl;

            // Add the Lecturer to the vector
            lecturers.push_back(Lecturer(name, office, class1, class2, class3));
            fIn.close();
        }
    }
};




#endif //LECTURER_LECTURER_H