#include <iostream>
#include <vector>
#include <limits>
using namespace std;



class PlayerList {
    public:
        PlayerList(void);
        int getValidJersey(void);
        int getValidRating(void);
        int getMemberJersey(int);
        void printAboveRating(int);
        void printRoster(void);
        void addPlayer(int, int);
        void advAddPlayer(void);
        void addNumPlayers(int);
        void removePlayer(int);
        void updatePlayer(void);
        void runMenu(void);
    
    private:
        vector<int> jerseyNumbers;
        vector<int> ratingValues;
    
};
/* DOC(Clears cin until newline) */
void clearIn(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
/* DOC(Constructs a PlayerList with empty vecotrs) */
PlayerList::PlayerList(){
    vector<int> jerseyNumbers(0);
    vector<int> ratingValues(0);
}
/* DOC(Takes user input and prompts of invalid
       @return valid jersey number) */
int PlayerList::getValidJersey(){
    int inInt;
    cin >> inInt;
    while(cin.fail() || (inInt > 99 || inInt < 0)){
        clearIn();
        cout << "Please enter a valid jersey number (00-99): ";
        cin >> inInt;
    }
    return inInt;
}
/* DOC(Takes user input and prompts if invalid
       @return valid rating value) */
int PlayerList::getValidRating(){
    int inInt;
    cin >> inInt;
    while(cin.fail() || (inInt > 9 || inInt < 1)){
        clearIn();
        cout << "Please enter a valid rating (1-9): ";
        cin >> inInt;
    }
    return inInt;
}
/* DOC(finds and returns the index of the jersey number given
       @param fndJerseyNumber the jersey number to search for
       @return index of searched jersey or -1 if not find) */
int PlayerList::getMemberJersey(int fndJerseyNumber){
    int retIndex = -1;
    int i = 0;
    while(i < jerseyNumbers.size() && fndJerseyNumber != PlayerList::jerseyNumbers.at(i)){
        ++i;
    }
    if(i < jerseyNumbers.size()){
        retIndex = i;
    }
    
    return retIndex;
}
/* DOC(Prints the roster containing players with ratings above ratingAbove
       @param ratingAbove the exclusive minimum rating to be printed) */
void PlayerList::printAboveRating(int ratingAbove){
    int i = 0;
    cout << "  === Roster ===" << endl;
    for (i = 0; i < jerseyNumbers.size(); ++i){
        if(ratingValues.at(i) > ratingAbove){
            cout << "Player " << i + 1 << "\'s Jersey: "
                << (jerseyNumbers.at(i) < 10 ? "0" : "")  
                << jerseyNumbers.at(i) << "\tRating: " 
                << ratingValues.at(i) << endl;
        }
    }
}
/* DOC(Prints the roster) */
void PlayerList::printRoster(){
    int i = 0;
    cout << "  === Roster ===" << endl;
    for (i = 0; i < jerseyNumbers.size(); ++i){
        cout << "Player " << i + 1 << "\'s Jersey: " 
            << (jerseyNumbers.at(i) < 10 ? "0" : "") 
            << jerseyNumbers.at(i) << "\tRating: "  << ratingValues.at(i) 
            << endl;
    }
}
/* DOC(Adds a player to player list
       @param newJerseyNumber jersey number to be added
       @param newRatingValue rating value to be added) */
void PlayerList::addPlayer(int newJerseyNumber, int newRatingValue){
    jerseyNumbers.push_back(newJerseyNumber);
    ratingValues.push_back(newRatingValue);
}
/* DOC(removes player with input jersey number from list and prints 
       success or failure message.
       @param delJerseyNumber jersey number to be removed) */
void PlayerList::removePlayer(int delJerseyNumber){
    int index = getMemberJersey(delJerseyNumber);
    if(index> 0){
        jerseyNumbers.erase(jerseyNumbers.begin() + index);
        ratingValues.erase(ratingValues.begin() + index);
        cout << "Player with jersey: " << delJerseyNumber << " removed."<< endl;
    }
    else
        cout << "No player had jersey number: "<< delJerseyNumber << "." << endl;
    
}
/* DOC(Updates a player's rating from input specified by input jersey number) */
void PlayerList::updatePlayer(){
    cout << "Enter Jersey number to be updated: ";
    
    int inJersey = getValidJersey();
    int index = getMemberJersey(inJersey);
    while(index < 0){
        printRoster();
        cout << "Please enter a Jersey number on the team: ";
        inJersey = getValidJersey();
        index = getMemberJersey(inJersey);
    }
    cout << "Enter the new rating for " << inJersey << ": ";
    int inRating = getValidRating();
    ratingValues.at(index) = inRating;
}
/* DOC(Prompts the user for how many players to add then adds 
       number of players to list) */
void PlayerList::advAddPlayer(){
    cout << "How many players would you like add to your team? " << endl;
    int numInit = -1;
    cin >> numInit;
    while(cin.fail() || (numInit < 0 || numInit > 20)){
        clearIn();
        cout << "Please enter a valid and reasonable number (0-20): ";
        cin >> numInit;
    }
    addNumPlayers(numInit);
}
/* DOC(adds input number of players to list
       @param numAddPlayers number of players to add) */
void PlayerList::addNumPlayers(int numAddPlayers){
    
    for(int i = 0; i < numAddPlayers; ++i){
        cout << "Enter New Player " << i + 1 << "\'s Jersey Number: ";
        int tmpJersey = getValidJersey();
        cout << "Enter New Player " << i + 1 << "\'s Rating: ";
        int tmpRating = getValidRating();
        addPlayer(tmpJersey, tmpRating);
    }
}
/* DOC(Prompts user to add initial players then prints menu and 
       handles input to requisite functions) */
void PlayerList::runMenu(){
    advAddPlayer();
    printRoster();
    char inChoice;
    do{
        cout << endl 
            << "    ====MENU====" << endl
            << " a - Add player" << endl
            << " m - Add multiple players" << endl
            << " d - Remove player" << endl 
            << " u - Update player rating" << endl
            << " r - Output players above a rating" << endl 
            << " o - Output roster" << endl
            << " q - Quit" << endl
            << "Choose an option:";
        
        cin >> inChoice;    
        //takes first character then clears until newline to prevent
        //unexpected future menu choices
        clearIn(); 
        
        switch(inChoice){
            case 'A':
            case 'a':
            addNumPlayers(1);break;
            case 'd':
            case 'D':
            cout << "Enter a jersey number to remove: ";
            removePlayer(getValidJersey()); break;
            case 'u':
            case 'U':
            updatePlayer(); break;
            case 'r':
            case 'R':
            cout << "Enter a rating value to see players above: ";
            printAboveRating(getValidRating()); break;
            case 'o':
            case 'O':
            printRoster(); break;
            case 'm':
            case 'M':
            advAddPlayer(); break;
        }
    } while (inChoice != 'q' && inChoice != 'Q');
}