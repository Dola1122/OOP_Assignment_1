#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <vector>

using namespace std;

void scamScanner() {
    fstream File1;
    string line1;
    string message = "";

    File1.open("email.txt", ios::in | ios::out);

    while (!File1.eof()) {
        getline(File1, line1);
        message += line1;
        message += " ";
    }


    vector<string> words = {
            "bill",
            "free investment",
            "accept credit cards",
            "coupon",
            "access",
            "act now! Don’t hesitate!",
            "for free",
            "free trial",
            "profits",
            "risk free",
            "save up to",
            "this isn’t junk",
            "claims",
            "click here link",
            "click below",
            "won",
            "congratulations",
            "uS dollars",
            "free money",
            "winner",
            "winning",
            "will not believe your eyes",
            "what are you waiting for?",
            "we honor all",
            "this isn’t spam",
            "paid",
            "remove",
            "nigerian",
            "No cost",
            "win",
    };
    vector<int> wordsPoints = {1, 2, 3, 1, 2, 3, 2, 3, 1, 2, 1, 2, 3, 1, 2, 3, 2, 3, 1, 1, 2, 3, 2, 3, 1, 2, 1, 2, 3,
                               1,};

    vector<int> wordsScore(30, 0);

    int start = 0;

    while (start < message.length()) {
        for (int i = 0; i < words.size(); i++) {

            if (start + words[i].length() > message.length())
                continue;

            if (words[i] == message.substr(start, words[i].length())) {
                wordsScore[i] += wordsPoints[i];
            }
        }
        while (message[start++] != ' ') {}

    }

    int totalPoints = 0;

    for (int i = 0; i < wordsScore.size(); i++) {
        totalPoints += wordsScore[i];
        if (wordsScore[i] > 0) {
            cout << "phrase : " << words[i] << " ,number of occurrences : " << wordsScore[i] / wordsPoints[i]
                 << " ,point total : " << wordsScore[i] << endl;
        }
    }

    cout << "point total for the entire message : " << totalPoints;

}

int main()
{
    scamScanner();
}
