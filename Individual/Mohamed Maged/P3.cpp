#include <bits/stdc++.h>

using namespace std;

void add_player(vector<pair<int, string>>& scores, vector<pair<int, string>>& high_scores ,pair<int, string> player);
void print_scores(vector<pair<int, string>> high_scores);
void search(string name, vector <pair<int, string>> high_scores);

int main()
{
    int choice;
    vector <pair<int, string>> scores = {{100, "mohamed"}, {50, "ahmad"}, {70, "IbnMaged"}, {90, "DarthVader"}, {55, "mohamed"},
                                         {60, "yusuf"}, {75, "ahmad"}, {75, "mohamed"}, {80, "Naruto"}, {80, "Red"}};
    sort(scores.rbegin(), scores.rend());
    vector <pair<int, string>> high_scores(scores);
    while (true)
    {
        cout << "1- Add a Player." << '\n'
             << "2- Print High Scores. " << '\n'
             << "3- Search in High Scores." << '\n'
             << "0- Exit." << '\n';
        cin >> choice;
        if (choice == 1)
        {
            pair <int, string> player;
            cout << "Enter Player Score: ";
            cin >> player.first;
            cout << "Enter Player Name: ";
            cin >> player.second;
            add_player(scores, high_scores, player);
        }
        else if (choice == 2)
        {
            print_scores(high_scores);
        }
        else if (choice == 3)
        {
            string name;
            cout << "Enter your Name: ";
            cin >> name;
            search(name, high_scores);            
        }   
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice!" << '\n';
        }
    }

}


void add_player(vector<pair<int, string>>& scores, vector<pair<int, string>>& high_scores ,pair<int, string> player)
{
    scores.push_back(player);
    std::sort(scores.rbegin(), scores.rend());
    if (player.first > high_scores[high_scores.size() - 1].first) 
    {
        high_scores.push_back(player);
        sort(high_scores.rbegin(), high_scores.rend());
        high_scores.pop_back();
    }   
}

void print_scores(vector<pair<int, string>> high_scores)
{
    cout << "    Player" << std::setw(15) << '|' << "Score" << std::setw(6) << '|' << std::endl;
    for (int i = 0; i < 10; i++)
    {
        cout << std::setw(3) << i + 1 <<'|' << std::setw(20) << high_scores[i].second << std::setfill(' ') << '|';
        cout << std::setw(10) << high_scores[i].first << std::setfill(' ') << '|' << std::endl; 
    }
}

void search(string name, vector <pair<int, string>> high_scores)
{
    int count = 0;
    for (int i = 0; i < high_scores.size(); i++)
    {
        if (high_scores[i].second == name)
        {
            cout << "Name: " << high_scores[i].second << "    Position: " << i + 1 << "    score: " << high_scores[i].first << '\n';
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Not Found in High Scores!" << "\n\n" ;
    }
}
