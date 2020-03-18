#include "Node.h"
#include "Stack.h"
#include "Project.h"
#include "Queue.h"
#include <iostream>

int main() {
    //Establish header class and vector
    Video_Game project;
    vector<Video_Game> video_games;

    //Read in file using read-function
    project.readGamesFromFile("vgsales.csv",video_games);

    //Test to ensure # elements in vector = #rows in .csv
    cout << "This number should be 16599: " << video_games.size() << endl; //Should be 16599

    cout << "INT QUEUE" << endl;
    Queue<int> intqueue;
    for (int i = 0; i < 10; i++) {
        intqueue.push(i);
        cout << "PUSHING INTO QUEUE: " << i << endl;
    }

    cout << "STRING QUEUE" << endl;
    Queue<string > stringqueue;
    for (int i = 0; i < 10; i++) {
        stringqueue.push(video_games[i].getName());
        cout << "" << video_games[i].getName() << endl;
    }

    cout << "STACK" << endl;
    Stack<Video_Game> vgstack;
    for (int i = 0; i < 10; i++) {
        vgstack.push(video_games[i]); //push
        cout << "PUSHING INTO STACK: " << video_games[i].getName() << endl;
    }
    for (int i = 0; i < 10; i++) {
        cout << "POPPED FROM STACK: " << vgstack.pop().getName() << endl; //pop
    }

    cout << "QUEUE" << endl;
    Queue<Video_Game> vgqueue;
    for (int i = 0; i < 10; i++) {
        vgqueue.push(video_games[i]); //push
        cout << "PUSHING INTO QUEUE: " << video_games[i].getName() << endl;
    }
    for (int i = 0; i < 10; i++) {
        cout << "POPPED FROM QUEUE: " << vgqueue.pop().getName() << endl; //pop
    }



}