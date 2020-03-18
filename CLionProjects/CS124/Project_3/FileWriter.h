//
// Created by isaac on 10/23/2019.
//

#ifndef PROJECT_3_FILEWRITER_H
#define PROJECT_3_FILEWRITER_H
#include <iostream>
#include <fstream>
#include "Project.h"

using namespace std;

class FileWriter {
public:
    void writeToFile(string filename, vector<int> depths) {
        ofstream file;
        file.open ("../" + filename);
        for (int i=0; i < depths.size(); ++i){
            file << depths[i] <<endl;
        }
        file.close();
    }

};


#endif //PROJECT_3_FILEWRITER_H
