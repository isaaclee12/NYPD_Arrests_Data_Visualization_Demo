//
// Created by isaac on 10/23/2019.
//

#ifndef PROJECT_3_INTFILEMAKER_H
#define PROJECT_3_INTFILEMAKER_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class intFileMaker {
public:
    void makeInt1File(string filename) {
        ofstream file;
        file.open ("../" + filename);
        for (int i = 0; i < 1000; ++i) {
            file << i << endl;
        }
        file.close();
    }

    void makeInt2File(string filename) {
        vector<int> intVector;

        //make 0 - 1000 vector
        for (int i = 0; i < 1000; ++i) {
            cout << i << endl;
            intVector.push_back(i);
        }

        //shuffle it
        random_shuffle( intVector.begin(), intVector.end());

        //write to file
        ofstream file;
        file.open ("../" + filename);
            for (int i = 0; i < 1000; ++i) {
                file << intVector[i] << endl;
            }
        file.close();
    }

    void makeInt3File(string filename) {
        ofstream file;
        file.open ("../" + filename);
        for (int i = 0; i < 1000; ++i) {
            for (int j = 0; j < 5; ++j) {
                file << i << endl;
            }
        }
        file.close();
    }

};


#endif //PROJECT_3_INTFILEMAKER_H
