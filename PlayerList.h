#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class PlayerList {
    public:
        PlayerList(void);
        PlayerList(vector<int>&, vector<int>&);
        int getValidJersey(void);
        int getValidRating(void);
        int getMemberJersey(int);
        void printAboveRating(int);
        void printRoster(void);
        void addPlayer(int, int);
        void advAddPlayer(void);
        void removePlayer(int);
        void updatePlayer(int, int);
        void runMenu(void);
        void TestFunctions(void);
    
    private:
        vector<int> jerseyNumbers;
        vector<int> ratingValues;
    
};

PlayerList::PlayerList(){
    vector<int> jerseyNumbers(0);
    vector<int> ratingValues(0);
}
PlayerList::PlayerList(vector<int>& initJerseyNumbers, vector<int>& initRatingValues){
    vector<int> jerseyNumbers = initJerseyNumbers;
    vector<int> ratingValues = initRatingValues;
}
int PlayerList::getValidJersey(){
    int inInt;
    cin >> inInt;
    while(cin.fail() || (inInt > 99 || inInt < 0)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please enter a valid jersey number (00-99): ";
        cin >> inInt;
    }
    return inInt;
}
int PlayerList::getValidRating(){
    int inInt;
    cin >> inInt;
    while(cin.fail() || (inInt > 9 || inInt < 1)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please enter a valid rating (1-9): ";
        cin >> inInt;
    }
    return inInt;
    
}
int PlayerList::getMemberJersey(int fndJerseyNumber){
    int retIndex = -1;
    int i = 0;
    while(i < PlayerList::jerseyNumbers.size() && fndJerseyNumber != PlayerList::jerseyNumbers.at(i)){
        ++i;
    }
    if(i < PlayerList::jerseyNumbers.size()){
        retIndex = i;
    }
    
    return retIndex;
}
void PlayerList::printAboveRating(int ratingAbove){
    
}
void PlayerList::printRoster(){
    int i = 0;
    cout << "  === Roster ===" << endl;
    for (i = 0; i < jerseyNumbers.size(); ++i){
        cout << "Player " << i + 1 << "\'s Jersey: " << jerseyNumbers.at(i)
             << "\tRating: " << ratingValues.at(i) << endl;
    }
    
}
void PlayerList::addPlayer(int newJerseyNumber, int newRatingValue){
    jerseyNumbers.push_back(newJerseyNumber);
    ratingValues.push_back(newRatingValue);
    
}
void PlayerList::removePlayer(int delJerseyNumber){
    int index = getMemberJersey(delJerseyNumber);
    if(index> 0){
        jerseyNumbers.erase(index);
        ratingValues.erase(index);
        cout << "Player with jersey: " << delJerseyNumber << " removed."<< endl;
    }
    else
        cout << "No player had jersey number: "<< delJerseyNumber << "." << endl;
    
}
void PlayerList::updatePlayer(int jerseyNumber, int newRatingValue){
    
}
void PlayerList::advAddPlayer(){
    cout << "How many players would you like add to your team? " << endl;
    int numInit = -1;
    cin >> numInit;
    while(cin.fail() || (numInit < 0 || numInit > 20)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please enter a valid and reasonable number (0-20): ";
        cin >> numInit;
    }
    for(int i = 0; i < numInit; ++i){
        cout << "Enter Player " << i + 1 << "\'s Jersey Number: ";
        int tmpJersey = getValidJersey();
        cout << "Enter Player " << i + 1 << "\'s Rating: ";
        int tmpRating = getValidRating();
        addPlayer(tmpJersey, tmpRating);
    }
}
void PlayerList::runMenu(){
    advAddPlayer();
    printRoster();
    
    
}
void PlayerList::TestFunctions(){
    /*
    cout << "Enter Player Jersey Number: ";
    int jerseyNumber = getValidJersey();
    cout << "You entered: " << ((jerseyNumber < 10 ) ? "0": "") << jerseyNumber << endl;
    cout << "Enter Player rating: ";
    int rating = getValidRating();
    cout << "You entered: " << rating << endl;
    */
}