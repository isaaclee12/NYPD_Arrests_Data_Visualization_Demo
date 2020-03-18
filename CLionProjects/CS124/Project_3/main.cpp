#include <iostream>
#include "intFileMaker.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "Project.h"
#include <stdlib.h>
#include <algorithm>

//I hope you like spaghetti.

int main() {
    /* Code used to make int files
     * intFileMaker intFileMaker;
    intFileMaker.makeInt3File("int3.txt");*/

    //Establish header class and vector
    Video_Game project;
    vector<Video_Game> video_games1;
    vector<Video_Game> video_games2;
    vector<Video_Game> video_games3;

    //Read in file using read-function
    project.readGamesFromFile("vgsales.csv",video_games1);
    //Shuffle the first one
    random_shuffle(video_games1.begin(), video_games1.end());

    project.readGamesFromFile("vgsales.csv",video_games2);

    project.readGamesFromFile("vgsales.csv",video_games3);
    //Shuffle the third one
    random_shuffle(video_games3.begin(), video_games3.end());


    intFileReader intFileReader;
    FileWriter FileWriter;
    vector<int> int1Vector;
    vector<int> int2Vector;
    vector<int> int3Vector;
    vector<int> tempDepthVector;

    intFileReader.readFromFile("int1.txt",int1Vector);
    intFileReader.readFromFile("int2.txt",int2Vector);
    intFileReader.readFromFile("int3.txt",int3Vector);

    //depth
    int depth = 0;

/*
 * BST
 */
    BinarySearchTree<Video_Game> bst1, bst2, bst3;

    /*
     * BST 1
     */

    for (int i=0; i < int1Vector.size(); ++i) {
        bst1.add(video_games1[int1Vector[i]]);
    }

    for (int i=0; i < int1Vector.size(); ++i) {
        //For each found item, add its depth to depth vector
        if (bst1.find(video_games1[int1Vector[i]], depth)) {
            tempDepthVector.push_back(depth);
        }
        //Reset depth to for next loop
        depth = 0;
    }

    //Write out the found items' depths to a file for future analysis
    FileWriter.writeToFile("bst1depths.csv", tempDepthVector);

    //Clear vector for next analysis
    tempDepthVector.clear();

    /*
     * BST 2
     */

    for (int i=0; i < int2Vector.size(); ++i) {
        //cout << "GAME OF RANK: " << int2Vector[i] << " HAS GLOBAL SALES OF: " << video_games2[int2Vector[i]] << endl;
        bst2.add(video_games2[int2Vector[i]]);
    }



    for (int i=0; i < int2Vector.size(); ++i) {
        //For each found item, add to depth vector
        if (bst2.find(video_games2[int2Vector[i]], depth) == true) {
            tempDepthVector.push_back(depth);
        }
        //Reset depth to for next loop
        depth = 0;
    }

    //Write out the found items' depths to a file for future analysis
    FileWriter.writeToFile("bst2depths.csv", tempDepthVector);

    //Clear vector for next analysis
    tempDepthVector.clear();

    /*
     * BST 3
     */

    for (int i=0; i < int3Vector.size(); ++i) {
        //cout << "GAME OF RANK: " << int2Vector[i] << " HAS GLOBAL SALES OF: " << video_games2[int2Vector[i]] << endl;
        bst3.add(video_games3[int3Vector[i]]);
    }

    for (int i=0; i < int3Vector.size(); ++i) {
        //For each found item, add to depth vector
        if (bst3.find(video_games3[int3Vector[i]], depth) == true) {
            tempDepthVector.push_back(depth);
        }
        //Reset depth to for next loop
        depth = 0;
    }

    //Write out the found items' depths to a file for future analysis
    FileWriter.writeToFile("bst3depths.csv", tempDepthVector);

    //Clear vector for next analysis
    tempDepthVector.clear();

/*
 * AVL
 */
    AVLTree<Video_Game> avl1, avl2, avl3;

    for (int i=0; i < int1Vector.size(); ++i) {
        avl1.add(video_games1[int1Vector[i]]);
    }

    for (int i=0; i < int1Vector.size(); ++i) {
        //For each found item, add its depth to depth vector
        if (avl1.find(video_games1[int1Vector[i]], depth)) {
            tempDepthVector.push_back(depth);
        }
        //Reset depth to for next loop
        depth = 0;
    }

    //Write out the found items' depths to a file for future analysis
    FileWriter.writeToFile("avl1depths.csv", tempDepthVector);

    //Clear vector for next analysis
    tempDepthVector.clear();

    /*
     * avl 2
     */

    for (int i=0; i < int2Vector.size(); ++i) {
        //cout << "GAME OF RANK: " << int2Vector[i] << " HAS GLOBAL SALES OF: " << video_games2[int2Vector[i]] << endl;
        avl2.add(video_games2[int2Vector[i]]);
    }

    for (int i=0; i < int2Vector.size(); ++i) {
        //For each found item, add to depth vector
        if (avl2.find(video_games2[int2Vector[i]], depth) == true) {
            tempDepthVector.push_back(depth);
        }
        //Reset depth to for next loop
        depth = 0;
    }

    //Write out the found items' depths to a file for future analysis
    FileWriter.writeToFile("avl2depths.csv", tempDepthVector);

    //Clear vector for next analysis
    tempDepthVector.clear();

    /*
     * avl 3
     */

    for (int i=0; i < int3Vector.size(); ++i) {
        //cout << "GAME OF RANK: " << int2Vector[i] << " HAS GLOBAL SALES OF: " << video_games2[int2Vector[i]] << endl;
        avl3.add(video_games3[int3Vector[i]]);
    }

    for (int i=0; i < int3Vector.size(); ++i) {
        //For each found item, add to depth vector
        if (avl3.find(video_games3[int3Vector[i]], depth) == true) {
            tempDepthVector.push_back(depth);
        }
        //Reset depth to for next loop
        depth = 0;
    }

    //Write out the found items' depths to a file for future analysis
    FileWriter.writeToFile("avl3depths.csv", tempDepthVector);

    //Clear vector for next analysis
    tempDepthVector.clear();



/*
 * splay
 */
    SplayTree<Video_Game> splay1, splay2, splay3;

    for (int i=0; i < int1Vector.size(); ++i) {
        splay1.add(video_games1[int1Vector[i]]);
    }

    for (int i=0; i < int1Vector.size(); ++i) {
        //For each found item, add its depth to depth vector
        if (splay1.find(video_games1[int1Vector[i]], depth)) {
            tempDepthVector.push_back(depth);
        }
        //Reset depth to for next loop
        depth = 0;
    }

    //Write out the found items' depths to a file for future analysis
    FileWriter.writeToFile("splay1depths.csv", tempDepthVector);

    //Clear vector for next analysis
    tempDepthVector.clear();

    /*
     * splay 2
     */

    for (int i=0; i < int2Vector.size(); ++i) {
        //cout << "GAME OF RANK: " << int2Vector[i] << " HAS GLOBAL SALES OF: " << video_games2[int2Vector[i]] << endl;
        splay2.add(video_games2[int2Vector[i]]);
    }

    for (int i=0; i < int2Vector.size(); ++i) {
        //For each found item, add to depth vector
        if (splay2.find(video_games2[int2Vector[i]], depth) == true) {
            tempDepthVector.push_back(depth);
        }
        //Reset depth to for next loop
        depth = 0;
    }

    //Write out the found items' depths to a file for future analysis
    FileWriter.writeToFile("splay2depths.csv", tempDepthVector);

    //Clear vector for next analysis
    tempDepthVector.clear();

    /*
     * splay 3
     */

    for (int i=0; i < int3Vector.size(); ++i) {
        //cout << "GAME OF RANK: " << int2Vector[i] << " HAS GLOBAL SALES OF: " << video_games2[int2Vector[i]] << endl;
        splay3.add(video_games3[int3Vector[i]]);
    }

    for (int i=0; i < int3Vector.size(); ++i) {
        //For each found item, add to depth vector
        if (splay3.find(video_games3[int3Vector[i]], depth) == true) {
            tempDepthVector.push_back(depth);
        }
        //Reset depth to for next loop
        depth = 0;
    }

    //Write out the found items' depths to a file for future analysis
    FileWriter.writeToFile("splay3depths.csv", tempDepthVector);

    //Clear vector for next analysis
    tempDepthVector.clear();


    /*
     * Items to Not Be Found
     */

    //reset depth
    depth = 0;

    //index
    int notFoundIndex = 2000;

    //BST
    if (bst2.find(video_games2[notFoundIndex], depth)) {
        cout << "found at depth: " << depth << endl;
    } else {
        cout << "NOT found at depth: " << depth << endl;
    }
    //reset depth
    depth = 0;

    //AVL
    if (avl2.find(video_games2[notFoundIndex], depth)) {
        cout << "found at depth: " << depth << endl;
    } else {
        cout << "NOT found at depth: " << depth << endl;
    }
    //reset depth
    depth = 0;

    //Splay
    if (splay2.find(video_games2[notFoundIndex], depth)) {
        cout << "found at depth: " << depth << endl;
    } else {
        cout << "NOT found at depth: " << depth << endl;
    }

    return 0;
}