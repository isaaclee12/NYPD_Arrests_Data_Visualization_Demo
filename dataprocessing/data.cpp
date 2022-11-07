#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <ctime>
using namespace std;

int main() {
    
    string text;

    // file object
    ifstream readfile("../nypd_arrests_results.csv");

    // break int for testing
    int ct = 0;

/*

current_date = get date from first line
file_date = date string split at commas, new one from file

if current_date != file_date
    
*/

    while (getline(readfile, text)) {

        if (ct > 3) {
            break;
        }

        cout << text << endl;

        // iterate ct
        ct++;
    }

    
    return 0;
}