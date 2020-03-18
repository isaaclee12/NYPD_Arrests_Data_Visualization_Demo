//
// Created by isaac on 10/23/2019.
//

#ifndef PROJECT_3_FILEREADER_H
#define PROJECT_3_FILEREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class intFileReader {
private:
    int item;

public:
    int getItem() {
        return item;
    }

    void readFromFile(string filename, vector<int> &intVector) {
        //Establish File Object, open file w/ "filename"
        ifstream F_In;
        F_In.open("../" + filename);

        //Skip the first line/header
        if (F_In) {
            string header = "";
            getline(F_In, header);
        }


        //Loop through each row until end of file
        while (F_In && F_In.peek() != EOF) {
            //Establish vars to push into vector, these also reset the values with each loop
            int item;

            F_In >> item;
            /*if (!F_In) { //If the data is bad/not a double...
                item = 0; // ..set it to 0
                F_In.clear(); //And clear the data
            }*/

            intVector.push_back(int(item));
        }

        //Close file after loop
        F_In.close();
    }

};

#endif //PROJECT_3_FILEREADER_H
