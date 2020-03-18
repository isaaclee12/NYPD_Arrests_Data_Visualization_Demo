#include "Project.h"
#include <iostream>

using namespace std;

int main() {

    //Establish header class and vector
    Video_Game project;
    vector<Video_Game> video_games;

    //Read in file using read-function
    project.readGamesFromFile("vgsales.csv",video_games);

    //Test to ensure # elements in vector = #rows in .csv
    cout << "This number should be 16599: " << video_games.size() << endl; //Should be 16599


    //Data size
    int data_size = video_games.size();

    //Nintendo Vars
    string nintendo = "Nintendo";
    int nintendo_ct = 0;

    //Sales count vars
    string NA_Top = "", EU_Top = "", JP_Top = "";
    double NA_Max = 0, EU_Max = 0, JP_Max = 0;

    /*Analysis
     * 1. The number of times “Nintendo” appears as a publisher in this list
     * The best selling game in each region, and how many sales each region’s best selling game had
     * */

    //Loop through every element in the vector
    for (int i=0; i < data_size ; i++) {

        cout << video_games[i].getName() << endl;

        //This adds +1 to a counter every time "Nintendo" appears as a string in the publisher field
        string publisher = video_games[i].getPublisher();
        if (publisher==nintendo) {
            nintendo_ct += 1;
        }

        //This (and the next 3 code blocks) replaces the top selling game every time a game with a higher sales number appears.
        double NA_Sale = video_games[i].getNA_Sales();
        if (NA_Sale > NA_Max) {
            NA_Max = NA_Sale;
            NA_Top = video_games[i].getName();
            //Debug
            //cout << "NEW NA MAX: " << NA_Sale << " FROM GAME: " << video_games[i].getName() << endl;
        }

        //Same as above
        double EU_Sale = video_games[i].getJP_Sales();
        if (EU_Sale > EU_Max) {
            EU_Max = EU_Sale;
            EU_Top = video_games[i].getName();
            //Debug
            //cout << "NEW EU MAX: " << EU_Sale << " FROM GAME: " << video_games[i].getName() << endl;
        }

        //Same as above
        double JP_Sale = video_games[i].getJP_Sales();
        if (JP_Sale > JP_Max) {
            JP_Max = JP_Sale;
            JP_Top = video_games[i].getName();
            //Debug
            //cout << "NEW JP MAX: " << JP_Sale << " FROM GAME: " << video_games[i].getName() << endl;
        }

    }

    //Prints result of nintendo counter
    cout << "Nintendo appears as a publisher " << nintendo_ct << " times." << endl;

    //Prints best selling games w/ sales numbers
    cout << "NA BEST: " << NA_Top << " at " << NA_Max << " Sales, EU MAX: " << EU_Top << " at " << EU_Max
    << " Sales, JP BEST: " << JP_Top << " at " << JP_Max << " Sales." << endl;





    return 0;
}