#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

/* represents the possible colors of playing cards when playing UNO */
class Color { 
public:
    Color() {
        color = "";
    }
    Color(std::string c) {
        color = c;
    }
    std::string getColor() {
        return color;
    }
private:
    std::string color; //represents the color of a card
};

/* represents the possible face values of playing cards when playing UNO */
class Face { 
public:
    Face() {
        face = "";
    }
    Face(std::string f) {
        face = f;
    }
    std::string getFace() {
        return face;
    }
private:
    std::string face; //representing the face of a card
};

/* Represents the possible cards when playing UNO */
class Card { 
public:
    Card() {
        std::vector<Color> colors; //list of suits a card can have
        std::vector<Face> faces; //list of faces a card can have
        for (int i = 0; i < 15; i++) {
            switch(i) {
                case 0:
                    colors.push_back(Color("red"));
                    faces.push_back(Face("0"));
                    break;
                case 1:
                    colors.push_back(Color("yellow"));
                    faces.push_back(Face("1"));
                    break;
                case 2:
                    colors.push_back(Color("green"));
                    faces.push_back(Face("2"));
                    break;
                case 3:
                    colors.push_back(Color("blue"));
                    faces.push_back(Face("3"));
                    break;
                case 4:
                    faces.push_back(Face("4"));
                    break;
                case 5:
                    faces.push_back(Face("5"));
                    break;
                case 6:
                    faces.push_back(Face("6"));
                    break;
                case 7:
                    faces.push_back(Face("7"));
                    break;
                case 8:
                    faces.push_back(Face("8"));
                    break;
                case 9:
                    faces.push_back(Face("9"));
                    break;
                case 10:
                    faces.push_back(Face("SKIP"));
                    break;
                case 11:
                    faces.push_back(Face("REVERSE"));
                    break;
                case 12:
                    faces.push_back(Face("DRAW2"));
                    break;
                case 13:
                    faces.push_back(Face("DRAW4WILD"));
                    break;
                default:
                    faces.push_back(Face("WILD"));
                }
            }
        int x = rand()%15;
        face = faces[x]; //randomly chosen face
        if (face.getFace().compare("WILD") == 0 or face.getFace().compare("DRAW4WILD") == 0) {
            color = Color(""); //no viable color for wild
        } else {
            color = colors[rand()%4];
        }
        if (face.getFace().compare("WILD") == 0 or face.getFace().compare("DRAW4WILD") == 0) {
            category = "WILD";
        } else if (face.getFace().compare("SKIP") == 0 or face.getFace().compare("REVERSE") == 0 or face.getFace().compare("DRAW2") == 0) {
            category = "ACTION";
        } else {
            category = "NUMBER";
        }
        if (category.compare("WILD") == 0) {
            value = 50;
        } else if (category.compare("ACTION") == 0) {
            value = 20;
        } else {
            value = std::stoi(face.getFace());
        }
    }
    Face getFaceCard() {
        return face; //returns Face object of a card
    }
    Color getColorCard() {
        return color; //returns Suit object of a card
    }
    void printCard1() {
        std::cout << color.getColor() << " " << face.getFace() << " (" << getValue() << " points) " << std::endl; //displays each card by their color, face, and points
    }
    void printCard() {
        std::cout << color.getColor() << " " << face.getFace() << std::endl; //displays each card by their color and face
    }
    void changeFaceCard(Face b) {
        face = b; //allows changing the Face
    }
    void changeColorCard(Color b) {
        color = b; //allows changing the Color
    }

    //checks if this particular card can be played, given the most recent card that is played, or Card a
    bool isPlayable(Card a) { 
        if (face.getFace().compare("WILD") == 0 or face.getFace().compare("DRAW4WILD") == 0 or face.getFace().compare("WILDTWIST") == 0) {
            return true;
        } else if (color.getColor().compare(a.getColorCard().getColor()) == 0 or face.getFace().compare(a.getFaceCard().getFace()) == 0) {
            return true;
        }
        return false;
    }

    //returns the point value of this card object
    int getValue() { 
        return value;
    }
private:
    Face face; //face of card
    Color color; //color of card
    int value; //point value associated with card
    std::string category; //category of card (number, action, wild)
};

/* Represents deck of cards presented by a player */
class Deck {
public:
    Deck() {
        
    }
    Deck(std::vector<Card>a) {
        cards = a;
    }
    void addCard() {
        Card c;
        cards.push_back(c); //adds a Card object to the deck
    }
    void printDeck() {
        for (unsigned int i = 0; i < cards.size(); i++) {
            std::cout << (i+1) << ". ";
            cards[i].printCard(); //prints out each card of the deck
        }
    }
    void printDeck1() {
        for (unsigned int i = 0; i < cards.size(); i++) {
            std::cout << (i+1) << ". ";
            cards[i].printCard1(); //prints out each card of the deck
        }
    }
    Card getCardAtPos(int i) {
        return cards[i]; //gets the Card at position i of the deck
    }
    void removeCard(int i) {
        cards.erase(cards.begin()+i); //removes Card at index i from the Deck
    }
    unsigned int getNumberOfCards() {
        return cards.size(); //returns number of cards
    }
    bool hasPlayableCard(Card a) { //checks if the Deck has a playable card
        for (unsigned int i = 0; i < cards.size(); i++) {
            if (cards[i].isPlayable(a) == true) {
                return true;
            }
        }
        return false;
    }
    bool hasColor(Color col) {
        for (unsigned int i = 0; i < cards.size(); i++) {
            if (cards[i].getColorCard().getColor().compare(col.getColor()) == 0) {
                return true;
            }
        }
        return false;
    }
    std::vector<Card> getCards() { //return the Deck of cards
        return cards;
    }
    int valueOfColor(Color a) { //returns the value of the specified color
        int v = 0;
        for (unsigned int i = 0; i < cards.size(); i++) {
            if (cards[i].getColorCard().getColor().compare(a.getColor()) == 0) {
                v += cards[i].getValue();
            }
        }
        return v;
    }
    int valueOfDeck() {
        int v = 0;
        for (unsigned int i = 0; i < cards.size(); i++) {
            v += cards[i].getValue();
        }
        return v;
    }
    void changeCards(std::vector<Card>a) {
        cards = a;
    }
private:
    std::vector<Card> cards;
};

/* Can be a human player or CPU */
class Player {
public:
    Player(Deck a, int t, int pt, int r) {
        d = a;
        token = t;
        pointV = pt;
        rounds = r;
    }
    Deck getDeck() {
        return d;
    }
    int getToken() {
        return token;
    }
    int getPoints() {
        return pointV;
    }
    int getRounds() {
        return rounds;
    }
    void revealHand() {
        d.printDeck();
    }
    void revealHand1() {
        d.printDeck1();
    }
    void incrementPoints(int pts) {
        pointV += pts;
    }
    void drawCard() {
        d.addCard();
    }
    void placeCard(int i) {
        d.removeCard(i);
    }
private:
    Deck d;
    int pointV;
    int token;
    int rounds;
};

/* Method to print to screen all valid cards that can be played by position of deck */
void printPlayableCards(std::vector<Card> a, std::vector<int> b) {
    std::cout << "Playable cards: " << std::endl;
    for (unsigned int i = 0; i < a.size(); i++) {
        std::cout << b[i] << ". ";
        a[i].printCard();
    }
}

/* Algorithm that will determine the position of card that CPU will be removing, depending on number of cards of opponent */
int positionToRemoveCard(Player a, std::vector<int> play, Player b) { //algorithm to remove cards for CPU
    std::vector<int> posDraw4; //position of draw4s (CASE 1 + 2)
    std::vector<int> posWild; //position of wilds (CASE 1 + 2)
    std::vector<int> posWildTwist;
    std::vector<int> otherCards; //position of other cards (CASE 1 ONLY)
    std::vector<int> draw2; //positions of draw2s (CASE 2 ONLY)
    std::vector<int> skips; //positions of SKIP/REVERSE cards (CASE 2 ONLY)
    std::vector<int> numbers; //positions of NUMBER cards (CASE 2 ONLY)
    if (b.getDeck().getNumberOfCards() >= 4) { //CASE 1: if opponent's deck has 4 or more cards
        for (unsigned int i = 0; i < play.size(); i++) {
            if (a.getDeck().getCardAtPos(play[i]-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) { //checks for +4 cards
                posDraw4.push_back(play[i]);
            } else if (a.getDeck().getCardAtPos(play[i]-1).getFaceCard().getFace().compare("WILD") == 0) { //checks for normal WILD cards
                posWild.push_back(play[i]);
            } else if (a.getDeck().getCardAtPos(play[i]-1).getFaceCard().getFace().compare("WILDTWIST") == 0) {
                posWildTwist.push_back(play[i]);
            } else { //else, other cards are present
                otherCards.push_back(play[i]); //adds the remaining cards (nonWILD cards)
            }
        } //plays by priority: other cards, WILD cards, then +4 cards.
        if (otherCards.size() != 0) {
            return otherCards[rand()%(otherCards.size())]; //removes other (nonWILD) cards
        } else if (posWild.size() != 0) {
            return posWild[rand()%(posWild.size())]; //removes WILD, if any
        }
        return posDraw4[rand()%(posDraw4.size())]; //removes +4 otherwise
    } //CASE 2: opponent with 3 or fewer cards
    for (unsigned int i = 0; i < play.size(); i++) {
        if (a.getDeck().getCardAtPos(play[i]-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {//checks for +4 cards
            posDraw4.push_back(play[i]);
        } else if (a.getDeck().getCardAtPos(play[i]-1).getFaceCard().getFace().compare("WILD") == 0) { //checks for normal WILD cards
            posWild.push_back(play[i]);
        } else if (a.getDeck().getCardAtPos(play[i]-1).getFaceCard().getFace().compare("DRAW2") == 0){ //checks for +2 cards
            draw2.push_back(play[i]);
        } else if (a.getDeck().getCardAtPos(play[i]-1).getFaceCard().getFace().compare("REVERSE") == 0 or a.getDeck().getCardAtPos(play[i]-1).getFaceCard().getFace().compare("SKIP") == 0) { //checks for SKIP/REVERSE cards
            skips.push_back(play[i]);
        } else { //adds number cards
            numbers.push_back(play[i]);
        }
    } //plays by priority: +2 cards, +4 cards, SKIP/REVERSE cards, WILD cards, then number cards.
    if (draw2.size() != 0) {
        return draw2[rand()%(draw2.size())];
    } else if (posDraw4.size() != 0) {
        return posDraw4[rand()%(posDraw4.size())];
    } else if (skips.size() != 0) {
        return skips[rand()%(skips.size())];
    } else if (posWild.size() != 0) {
        return posWild[rand()%(posWild.size())];
    }
    return numbers[rand()%(numbers.size())];
}
int max(int a, int b, int c, int d) {
    if (a < c and b < c and d < c) {
        return c;
    } else if (d > c and d > b and d > a) {
        return d;
    } else if (b > d and b > a and b > c) {
        return b;
    }
    return a;
}

int min (int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

/* Algorithm that will choose the color of WILD card for the CPU player */
Color chooseColor(Player a) { 
    std::string colors[4] = {"green", "red", "yellow", "blue"};
    std::vector<std::string> color;
    std::vector<int> values;
    for (int i = 0; i < 4; i++) {
        color.push_back(colors[i]);
        values.push_back(a.getDeck().valueOfColor(Color(colors[i])));
    }
    int maximum = max(values[0],values[1],values[2],values[3]);
    int x = -1;
    for (int i = 0; i < 4; i++) {
        if (maximum == a.getDeck().valueOfColor(Color(colors[i]))) {
            x = i;
            break;
        }
    }
    return Color(color[x]);
}

//returns the list of cards that can be played, if any
std::vector<Card> getPlayableCards(Deck a, Card start) { 
    std::vector<Card> cards;
    for (unsigned int i = 0; i < a.getNumberOfCards(); i++) {
        if (a.getCards()[i].isPlayable(start) == true) {
            cards.push_back(a.getCards()[i]);
        }
    }
    return cards;
}

//returns the associated position of cards that can be played, if any
std::vector<int> getPlayablePositions(Deck a, Card start) { 
    std::vector<int> pos;
    for (unsigned int i = 0; i < a.getNumberOfCards(); i++) {
        if (a.getCards()[i].isPlayable(start) == true) {
            pos.push_back(i+1);
            
        }
    }
    return pos;
}

//displays effect of CPU or Player, if applicable
void displayEffect(int token, Card start, bool successful = true) { 
    if (start.getFaceCard().getFace().compare("DRAW4WILD") == 0) {
        if (token == 1) {
            if (successful) {
                std::cout << "Player 1: DRAW 4 CARDS!" << std::endl;
            } else {
                std::cout << "Player 1: DRAW 6 CARDS!" << std::endl;
            }  
        } else {
            if (successful) {
                std::cout << "CPU " << token << ": DRAW 4 CARDS!" << std::endl;
            } else {
                std::cout << "CPU " << token << ": DRAW 6 CARDS!" << std::endl;
            }
        }
    } else if (start.getFaceCard().getFace().compare("DRAW2") == 0) {
        if (token == 1) {
            std::cout << "Player 1: DRAW 2 CARDS!" << std::endl;
        } else {
            std::cout << "CPU " << token << ": DRAW 2 CARDS!" << std::endl;
        }
    } else if (start.getFaceCard().getFace().compare("SKIP") == 0) {
        if (token == 1) {
            std::cout << "Player 1: LOST TURN!" << std::endl;
        } else {
            std::cout << "CPU " << token << ": LOST TURN!" << std::endl;
        }
    } else if (start.getFaceCard().getFace().compare("REVERSE") == 0) {
        std::cout << "GAMEPLAY REVERSED! " << std::endl;
    }

}

//creates whitespace
void makeWhiteSpace() { 
    for (int i = 0; i < 30; i++) {
        std::cout << std::endl;
    }
}

//returns if the string is a number
bool isNumber(std::string s) { 
    for (unsigned int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}

//sorts the cards by ascending point value
std::vector<Card> sort(std::vector<Card> a) { 
    for(unsigned int i = 0; i < a.size(); i++)
    {
        for(unsigned int j = i+1; j < a.size(); j++)
        {
            if(a[i].getValue() > a[j].getValue())
            {
                Card temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a;
}

//finds the minimum of three numbers
int min(int a, int b, int c) { 
    if (a < b and a < c) {
        return a;
    } else if (b < a and b < c) {
        return b;
    }
    return c;
}

//drawing cards when applicable for Player and CPUs
void drawCards(Player &a, unsigned int amount) {
    for (unsigned int i = 0; i < amount; i++) {
        a.drawCard();
    }
}

//determines whether CPU challenges DRAW 4 card or not
bool challengeDraw4(int opponentNumCards) {
    int randNum = rand()%10;
    if (opponentNumCards > 7) {
        return true;
    } else if (opponentNumCards <= 7 and opponentNumCards >= 4) {
        return randNum > 5;
    }
    return randNum <= 1;
}

//determines turn after a challenge has been taken or not taken
int getTurn(int numPlay, int challengedToken, int challengerToken) {
    if (challengedToken == 2) {
        if (numPlay == 2 or challengerToken == 3) {
            return 1;
        } else {
            return 3;
        }
    } else if (challengedToken == 3) {
        if (challengerToken == 2) {
            return 4;
        } else {
            return 2;
        }
    } else {
        if (challengerToken == 1) {
            return 3;
        } else {
            return 1;
        }
    }
}

//Process when a CPU has been challenged by a draw4
void cpuChallengeDraw4Process(Player &challenger, Player &challenged, Card startingCard, int &turn, int numPlay, Color startColor) {
   std::cout << "CPU " << challenged.getToken() << " awaiting decision: challenge DRAW 4 or not?" << std::endl;
   sleep_for(seconds(5));
   int challenge = challengeDraw4(challenger.getDeck().getNumberOfCards());
   if (challenge == 0) {
        std::cout << "CPU " << challenged.getToken() << " didn't take the challenge." << std::endl;
        drawCards(challenged,4);
        displayEffect(challenged.getToken(),startingCard,true);
        turn = getTurn(numPlay,challenged.getToken(),challenger.getToken());
   } else {
        if (challenger.getDeck().hasColor(startColor)) {
            std::cout << "CPU " << challenged.getToken() << " took take the challenge and was SUCCESSFUL!" << std::endl;
            drawCards(challenger,4);
            displayEffect(challenger.getToken(),startingCard,true);
            turn = challenged.getToken();
        } else {
            std::cout << "CPU 2 took take the challenge and was UNSUCCESSFUL!" << std::endl;
            drawCards(challenged,6);   
            displayEffect(challenged.getToken(),startingCard,false);
            turn = getTurn(numPlay,challenged.getToken(),challenger.getToken());
        }
   }
}

//Determine who's turn it is after player gets hit with draw4 card
int getTurnAfterPlayer(int challengerToken, int numPlay) {
    if (numPlay == 2 || challengerToken == 4) {
        return 2;
    }
    return 4;
}

//Process when a Player has been challenged by a draw4
void playerChallengeDraw4Process(Player &challenger, Player &challenged, Card startingCard, int &turn, int numPlay, Color startColor) {
    std::string challenging = "x";
    while (challenging != "Y" and challenging != "N") {
        std::cout << "Previous color was " << startColor.getColor() <<", do you think CPU " << challenger.getToken() << " has a " << startColor.getColor() << " (Y/N)? ";
        std::cin >> challenging;
    }
    if (challenging.compare("N") == 0) {
        std::cout << "Player 1 didn't take the challenge." << std::endl;
        drawCards(challenged,4);
        displayEffect(challenged.getToken(),startingCard);
        turn = getTurnAfterPlayer(challenger.getToken(),numPlay);
    } else {
        std::cout << "Player 1 took the challenge..." << std::endl;
        sleep_for(seconds(3));
        if (challenger.getDeck().hasColor(startColor) == true) {
            std::cout << "and was SUCCESSFUL!" << std::endl;
            drawCards(challenger,4);
            displayEffect(challenger.getToken(),startingCard, true);
            turn = 1;   
        } else {
            std::cout << "and was UNSUCCESSFUL!" << std::endl;
            drawCards(challenged,6);
            displayEffect(challenged.getToken(),startingCard,false);
            turn = getTurnAfterPlayer(challenger.getToken(),numPlay);
        }
    }
}

//Verify UNOs for player and CPUs
void verifyUNOs(bool shoutUNO1, bool shoutUNO2, bool shoutUNO3, bool shoutUNO4, int &c1, int &c2, int &c3, int &c4, Player &p1) {
    if (shoutUNO1 == true and p1.getDeck().getNumberOfCards() == 1 and c1 == 0) {
        std::cout << "Player 1: UNO!" << std::endl;
        c1++;
    } else if (p1.getDeck().getNumberOfCards() == 1 and shoutUNO1 == false) {
        std::cout << "Player 1: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
        drawCards(p1,2);
    }
    if (shoutUNO2 == true and c2 == 0) {
        std::cout << "CPU 2: UNO!" << std::endl;
        c2++;
    }
    if (shoutUNO3 == true and c3 == 0) {
        std::cout << "CPU 3: UNO!" << std::endl;
        c3++;
    } 
    if (shoutUNO4 == true and c4 == 0) {
        std::cout << "CPU 4: UNO!" << std::endl;
        c4++;
    } 
    
}

//Process when player changes color through wild or draw 4
void playerChangesColor(Card &startingCard) {
    std::string chosen = "";
    while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
        std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
        std::cin >> chosen;
        if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
            std::cout << "Invalid choice! ";
        }
    }
    makeWhiteSpace();
    if(chosen.compare("R") == 0) {
        startingCard.changeColorCard(Color("red"));
    } else if (chosen.compare("Y") == 0) {
        startingCard.changeColorCard(Color("yellow"));
    } else if (chosen.compare("G") == 0) {
        startingCard.changeColorCard(Color("green"));
    } else {
        startingCard.changeColorCard(Color("blue"));
    }
    std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
}

//main application of UNO game
int main() {
    srand(time(0));
    std::string play1 = "";
    std::string play2 = "";
    std::string play3 = "";
    std::string play4 = "";
    int pt1 = 0;
    int pt2 = 0;
    int pt3 = 0;
    int pt4 = 0;
    std::string deci = "";
    std::string deci2 = "";
    std::string chosen = "";
    std::string deci3 = "";
    std::string pos = "";
    int dec = -1;
    int rounds1 = 0;
    int rounds2 = 0;
    int rounds3 = 0;
    int rounds4 = 0;
    int rounds = 0;
    std::vector<Card> playableCards1;
    std::vector<Card> playableCards2;
    std::vector<Card> playableCards3;
    std::vector<Card> playableCards4;
    std::vector<Card> cards1;
    std::vector<Card> cards2;
    std::vector<Card> cards3;
    std::vector<Card> cards4;
    std::vector<int> winnings;
    std::cout << "Welcome to UNO Classic! Play in an UNO Classic match where the goal is to be the first player to remove their card. Please make sure all of your inputs are in ALL CAPS or your input will NOT be processed!" << std::endl;
    std::string optionChosen = "s";
    bool validChoice = false;

    //choose how to compete in the game
    while (isNumber(optionChosen) == false or validChoice == false) {
        std::cout << "Now, choose from the following options: " << std::endl;
        std::cout << "1. Compete for 500 points" << std::endl;
        std::cout << "2. Compete for 1000 points" << std::endl;
        std::cout << "3. Compete for 2000 points" << std::endl;
        std::cout << "4. Compete relentlessly (until one player chooses to quit)" << std::endl;
        std::cout << "Chosen choice: ";
        std::cin >> optionChosen;
        if(isNumber(optionChosen) == false) {
            std::cout << "Invalid choice! Choice cannot involve nonnumeric characters! cannot process choice!" << std::endl;
        } else if (isNumber(optionChosen) == true and (std::stoi(optionChosen) > 4 or std::stoi(optionChosen) < 1)) {
            std::cout << "Invalid choice! Choice number MUST be 1, 2, 3, or 4! Cannot process choice!" << std::endl;
        } else {
            validChoice = true;
        }
    }
    std::string players = "";

    //2 player mode vs 4 player mode
    while (isNumber(players) == false or (players.compare("2") != 0 and players.compare("4") != 0)) {
        std::cout << "Choose between 2 player mode or 4 player mode: ";
        std::cin >> players;
        if (isNumber(players) == false) {
            std::cout << "Invalid input! Cannot process non number input!" << std::endl;
        } else if (std::stoi(players) != 2 and std::stoi(players) != 4) {
            std::cout << "Invalid input! Number MUST be 2 or 4!" << std::endl;
        }
    }
    makeWhiteSpace();
    int numPlay = std::stoi(players);
    int opt = std::stoi(optionChosen);
    bool playedAgain = false;
    int ptG = 500;
    if (opt == 4) {
        playedAgain = play1.compare("N") != 0 and play2.compare("N") != 0;
    } else {
        if (opt == 1 or opt == 2) {
            ptG *= opt;
        } else {
            ptG = 2000;
        }
        playedAgain = pt1 < ptG and pt2 < ptG;
    }

    while (playedAgain == true) {
        rounds++;
        bool clockwise = true;
        Player p1(Deck(),1,pt1,rounds1);
        Player p2(Deck(),2,pt2,rounds2);
        Player p3(Deck(),3,pt3,rounds3);
        Player p4(Deck(),4,pt4,rounds4);
        std::cout << "Distributing cards.. Please wait!" << std::endl;
        sleep_for(seconds(5));
        //game setup
        drawCards(p1,7);
        drawCards(p2,7);
        drawCards(p3,7);
        drawCards(p4,7);
        int turn = -1;
        if (numPlay == 2) {
            turn = (rand()%2)+1;
        } else {
            turn = (rand()%4)+1;
        }
        Card startingCard;

        //starting card is action card, take appropriate actions on first player
        if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0 or startingCard.getFaceCard().getFace().compare("SKIP") == 0 or startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
            if (turn == 1) {
                displayEffect(p1.getToken(),startingCard);
            } else if (turn == 2) {
                displayEffect(p2.getToken(),startingCard);
            } else if (turn == 3) {
                displayEffect(p3.getToken(),startingCard);
            } else {
                displayEffect(p4.getToken(),startingCard);
            }
            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                if (turn == 1) {
                    drawCards(p1,2);
                } else if (turn == 2) {
                    drawCards(p2,2);
                } else if (turn == 3) {
                    drawCards(p3,2);
                } else {
                    drawCards(p4,2);
                }
            }
            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0 or startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                if (turn == 4 or (turn == 2 and numPlay == 2)) {
                    turn = 1;
                } else {
                    turn++;
                }
            } else {
                clockwise = false;
            }
        //take appropriate action for wild/draw 4
        } else if (startingCard.getFaceCard().getFace().compare("WILD") == 0 or startingCard.getFaceCard().getFace().compare("DRAW4WILD") == 0 or startingCard.getFaceCard().getFace().compare("WILDTWIST") == 0) {
            std::cout << "Starting color chosen by random!" << std::endl;
            dec = rand()%4;
            switch(dec) {
                case 0:
                    std::cout << "Color: Red!" << std::endl;
                    startingCard.changeColorCard(Color("red"));
                    break;
                case 1:
                    std::cout << "Color: Yellow!" << std::endl;
                    startingCard.changeColorCard(Color("yellow"));
                    break;
                case 2:
                    std::cout << "Color: Green!" << std::endl;
                    startingCard.changeColorCard(Color("green"));
                    break;
                default:
                    std::cout << "Color: Blue!" << std::endl;
                    startingCard.changeColorCard(Color("blue"));
            }
        }
        std::cout << "Starting card: ";
        std::vector<Card> playableCards1 = getPlayableCards(p1.getDeck(),startingCard); //playable cards for player 1
        std::vector<int> positions1 = getPlayablePositions(p1.getDeck(),startingCard);
        std::vector<Card> playableCards2 = getPlayableCards(p2.getDeck(),startingCard); //playable cards for CPU 2
        std::vector<int> positions2 = getPlayablePositions(p2.getDeck(),startingCard);
        std::vector<Card> playableCards3 = getPlayableCards(p3.getDeck(),startingCard); //playable cards for CPU 3
        std::vector<int> positions3 = getPlayablePositions(p3.getDeck(),startingCard);
        std::vector<Card> playableCards4 = getPlayableCards(p4.getDeck(),startingCard); //playable cards for CPU 4
        std::vector<int> positions4 = getPlayablePositions(p4.getDeck(),startingCard);
        startingCard.printCard();
        bool shoutedUno1 = false;
        bool shoutedUno2 = false;
        bool shoutedUno3 = false;
        bool shoutedUno4 = false;
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c4 = 0;
        bool actioned = false;
        bool playedDrew = true;

        //runs UNO game until one person runs out of cards
        while (p1.getDeck().getNumberOfCards() != 0 and p2.getDeck().getNumberOfCards() != 0 and p3.getDeck().getNumberOfCards() != 0 and p4.getDeck().getNumberOfCards() != 0) {
            //Player 1 turn
            if (turn == 1) {
                p1 = Player(Deck(sort(p1.getDeck().getCards())),1,pt1,rounds1);
                p2 = Player(Deck(sort(p2.getDeck().getCards())),2,pt2,rounds2);
                p3 = Player(Deck(sort(p3.getDeck().getCards())),3,pt3,rounds3);
                p4 = Player(Deck(sort(p4.getDeck().getCards())),4,pt4,rounds4);
                verifyUNOs(shoutedUno1,shoutedUno2,shoutedUno3,shoutedUno4,c1,c2,c3,c4,p1); 
                playableCards1 = getPlayableCards(p1.getDeck(),startingCard);
                positions1 = getPlayablePositions(p1.getDeck(),startingCard);
                std::cout << "Player 1's turn!" << std::endl;
                p1.revealHand();

                //displays number of cards each oppoent(s) has
                std::cout << "Number of cards in CPU 2's hand: " << p2.getDeck().getNumberOfCards() << std::endl;
                if (numPlay == 4) {
                    std::cout << "Number of cards in CPU 3's hand: " << p3.getDeck().getNumberOfCards() << std::endl;
                    std::cout << "Number of cards in CPU 4's hand: " << p4.getDeck().getNumberOfCards() << std::endl;
                }  

                //checks if player 1 has a playable card
                if (p1.getDeck().hasPlayableCard(startingCard) == true) {
                    printPlayableCards(playableCards1,positions1);
                    if (p1.getDeck().getNumberOfCards() == 2) {
                        std::cout << "Tip: Now would be a good time to shout UNO." << std::endl;
                    }
                    deci = "";

                    //player makes decision to play, draw, or shout UNO when they have 2 cards left
                    while ((deci.compare("U") == 0 and p1.getDeck().getNumberOfCards() != 2) or (deci.compare("D") != 0 and deci.compare("P") != 0)) {
                        std::cout << "Type in D to draw, or P to play (Type U to shout UNO when you play second to last card): ";
                        std::cin >> deci;
                        if ((deci.compare("U") == 0 and p1.getDeck().getNumberOfCards() != 2)) {
                            std::cout << "Tip: Type U to shout UNO when you play your second to last card. " << std::endl;
                        } else if (deci.compare("P") != 0 and deci.compare("D") != 0 and p1.getDeck().getNumberOfCards() != 2) {
                            std::cout << "Invalid choice made!" << std::endl;
                        } else {
                            break;
                        }
                    }
                    if (deci.compare("U") == 0) {
                        shoutedUno1 = true;
                        while (deci.compare("D") != 0 and deci.compare("P") != 0) {
                            std::cout << "Type in D to draw, or P to play: ";
                            std::cin >> deci;
                            if (deci.compare("D") != 0 and deci.compare("P") != 0) {
                                std::cout << "Invalid choice! ";
                            }
                        }
                    }
                    if (deci.compare("D") == 0) {
                        p1.drawCard();
                        std::cout << "Card drew: ";
                        p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).printCard();
                        shoutedUno1 = false;
                        c1 = 0;
                        if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                            if (p1.getDeck().getNumberOfCards() == 2) {
                                //shouts UNO automatically when player draws and plays second to last card
                                std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                            }
                            deci2 = "";

                            //if card drew is playable, you can play card or keep it
                            while (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                std::cout << "Type in PL to play, or PA to pass: ";
                                std::cin >> deci2;
                                makeWhiteSpace();
                                if (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                    std::cout << "Invalid choice! ";
                                }
                            }
                            if (deci2.compare("PL") == 0) {
                                if (p1.getDeck().getNumberOfCards() == 2) {
                                    shoutedUno1 = true;
                                }
                                //card is wild or draw4
                                if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                    Color startColor = startingCard.getColorCard();
                                    playerChangesColor(startingCard);
                                    if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                        startingCard.changeFaceCard(Face("DRAW4WILD"));
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                if (p1.getDeck().getNumberOfCards() == 1) {
                                                    drawCards(p2,4);
                                                    displayEffect(p2.getToken(),startingCard);
                                                } else {
                                                    cpuChallengeDraw4Process(p1,p2,startingCard,turn,numPlay,startColor);
                                                }
                                            } else {
                                                if (p1.getDeck().getNumberOfCards() == 1) {
                                                    drawCards(p4,4);
                                                    displayEffect(p4.getToken(),startingCard);
                                                } else {
                                                    cpuChallengeDraw4Process(p1,p4,startingCard,turn,numPlay,startColor);
                                                }
                                            }
                                        } else {
                                            if (p1.getDeck().getNumberOfCards() == 1) {
                                                drawCards(p2,4);
                                                displayEffect(p2.getToken(),startingCard);
                                            } else {
                                                cpuChallengeDraw4Process(p1,p2,startingCard,turn,numPlay,startColor);
                                            }
                                        }
                                    } else {
                                        startingCard.changeFaceCard(Face("WILD"));
                                        actioned = true;
                                        if (clockwise == true or numPlay == 2) {
                                            turn = 2;
                                        } else {
                                            turn = 4;
                                        }
                                    }
                                //card is any action card (+2, reverse, SKIP)
                                } else if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                    startingCard.changeColorCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getColorCard());
                                    startingCard.changeFaceCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard());
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            displayEffect(p2.getToken(),startingCard);
                                        } else {
                                            displayEffect(p4.getToken(),startingCard);
                                        }
                                        turn = 3;
                                    } else {
                                        displayEffect(p2.getToken(),startingCard);
                                    }
                                    if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                drawCards(p2,2);
                                            } else {
                                                drawCards(p4,2);
                                            }
                                            turn = 3;
                                        } else {
                                            drawCards(p2,2);
                                        }
                                    } else if (startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
                                        clockwise = !clockwise;
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                turn = 2;
                                            } else {
                                                turn = 4;
                                            }
                                        }
                                    } else if (startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                                        if (numPlay == 4) {
                                            turn = 3;
                                        }
                                    }
                                //number card
                                } else {
                                    startingCard.changeColorCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getColorCard());
                                    startingCard.changeFaceCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard());
                                    actioned = true;
                                    if (numPlay == 2 or clockwise == true) {
                                        turn = 2;
                                    } else {
                                        turn = 4;
                                    }
                                }
                                p1.placeCard(p1.getDeck().getNumberOfCards()-1);
                            } else {
                                makeWhiteSpace();
                                actioned = true;
                                if (numPlay == 2 or clockwise == true) {
                                    turn = 2;
                                } else {
                                    turn = 4;
                                }
                            }
                        } else {
                            makeWhiteSpace();
                            actioned = true;
                            playedDrew = false;
                            if (numPlay == 2 or clockwise == true) {
                                turn = 2;
                            } else {
                                turn = 4;
                            }
                        }
                    } else {
                        bool valid = false;
                        pos = "s";
                        //player has at least one playable card and chooses to play
                        while(isNumber(pos) == false or valid == false) {
                            std::cout << "Choose position of valid card to remove: ";
                            std::cin >> pos;
                            if (isNumber(pos) == false) {
                                continue;
                            } else {
                                int a = std::stoi(pos);
                                if (p1.getDeck().getCardAtPos(a-1).isPlayable(startingCard) == true) {
                                    valid = true;
                                } else {
                                    continue;
                                }
                            }
                        }
                        int pos1 = std::stoi(pos);
                        //wild or +4 card
                        if (p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("WILD") == 0) {
                            Color startColor = startingCard.getColorCard();
                            playerChangesColor(startingCard);
                            if (p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                startingCard.changeFaceCard(Face("DRAW4WILD"));
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        if (p1.getDeck().getNumberOfCards() == 1) {
                                            drawCards(p2,4);
                                            displayEffect(p2.getToken(),startingCard);
                                        } else {
                                            cpuChallengeDraw4Process(p1,p2,startingCard,turn,numPlay,startColor);
                                        }
                                    } else {
                                        if (p1.getDeck().getNumberOfCards() == 1) {
                                            drawCards(p4,4);
                                            displayEffect(p4.getToken(),startingCard);
                                        } else {
                                            cpuChallengeDraw4Process(p1,p4,startingCard,turn,numPlay,startColor);
                                        }   
                                    }
                                } else {
                                    if (p1.getDeck().getNumberOfCards() == 1) {
                                        drawCards(p2,4);
                                        displayEffect(p2.getToken(),startingCard);
                                    } else {
                                        cpuChallengeDraw4Process(p1,p2,startingCard,turn,numPlay,startColor);
                                    }  
                                }
                            } else {
                                startingCard.changeFaceCard(Face("WILD"));
                                actioned = true;
                                if (clockwise == true or numPlay == 2) {
                                    turn = 2;
                                } else {
                                    turn = 4;
                                }
                            }
                            std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                        //action card (SKIP, REVERSE, +2)
                        } else if (p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW2") == 0 or p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("SKIP") == 0 or p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                            startingCard.changeColorCard(p1.getDeck().getCardAtPos(pos1-1).getColorCard());
                            startingCard.changeFaceCard(p1.getDeck().getCardAtPos(pos1-1).getFaceCard());
                            makeWhiteSpace();
                            if (numPlay == 4) {
                                if (clockwise == true) {
                                    displayEffect(p2.getToken(),startingCard);
                                } else {
                                    displayEffect(p4.getToken(),startingCard);
                                }
                                turn = 3;
                            } else {
                                displayEffect(p2.getToken(),startingCard);
                            }
                            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        drawCards(p2,2);
                                    } else {
                                        drawCards(p4,2);
                                    }
                                    turn = 3;
                                } else {
                                    drawCards(p2,2);
                                }
                            } else if (startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
                                if (numPlay == 4) {
                                    clockwise = !clockwise;
                                    if (clockwise == true) {
                                        turn = 2;
                                    } else {
                                        turn = 4;
                                    }
                                }
                            } else if (startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                                if (numPlay == 4) {
                                    turn = 3;
                                }
                            }
                        //number card
                        } else {
                            actioned = true;
                            if (numPlay == 2 or clockwise == true) {
                                turn = 2;
                            } else {
                                turn = 4;
                            }
                            startingCard.changeColorCard(p1.getDeck().getCardAtPos(pos1-1).getColorCard());
                            startingCard.changeFaceCard(p1.getDeck().getCardAtPos(pos1-1).getFaceCard());
                            makeWhiteSpace();
                        }
                        p1.placeCard(pos1-1);
                    }
                } else {
                    deci3 = "";
                    //has NO playable card, must DRAW
                    while (deci3.compare("D") != 0) {
                        std::cout << "Type D to draw. ";
                        std::cin >> deci3;
                        if (deci3.compare("D") != 0) {
                            std::cout << "Invalid choice! ";
                        }
                    }
                    shoutedUno1 = false;
                    c1 = 0;
                    p1.drawCard();
                    //card drew is PLAYABLE
                    if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                        std::cout << "Card drew: ";
                        p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).printCard();
                        if (p1.getDeck().getNumberOfCards() == 2) {
                            std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                        }
                        deci2 = "";
                        //choose to PLAY the card or PASS 
                        while (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                            std::cout << "Type in PL to play, or PA to pass: ";
                            std::cin >> deci2;
                            if (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                std::cout << "Invalid choice! ";
                            }
                        }
                        //choose to PLAY card
                        if (deci2.compare("PL") == 0) {
                            if (p1.getDeck().getNumberOfCards() == 2) {
                                shoutedUno1 = true;
                            }
                            //WILD or +4
                            if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                Color startColor = startingCard.getColorCard();
                                playerChangesColor(startingCard);
                                if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                    startingCard.changeFaceCard(Face("DRAW4WILD"));
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            if (p1.getDeck().getNumberOfCards() == 1) {
                                                drawCards(p2,4);
                                                displayEffect(p2.getToken(),startingCard);
                                            } else {
                                                cpuChallengeDraw4Process(p1,p2,startingCard,turn,numPlay,startColor);
                                            }
                                        } else {
                                            if (p1.getDeck().getNumberOfCards() == 1) {
                                                drawCards(p4,4);
                                                displayEffect(p4.getToken(),startingCard);
                                            } else {
                                                cpuChallengeDraw4Process(p1,p4,startingCard,turn,numPlay,startColor);
                                            }
                                        }
                                    } else {
                                        if (p1.getDeck().getNumberOfCards() == 1) {
                                            drawCards(p2,4);
                                            displayEffect(p2.getToken(),startingCard);
                                        } else {
                                            cpuChallengeDraw4Process(p1,p2,startingCard,turn,numPlay,startColor);
                                        }
                                    }
                                } else {
                                    startingCard.changeFaceCard(Face("WILD"));
                                    actioned = true;
                                    if (clockwise == true or numPlay == 2) {
                                        turn = 2;
                                    } else {
                                        turn = 4;
                                    }
                                }
                            //ACTION cards (SKIP, REVERSE, +2)
                            } else if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                startingCard.changeColorCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getColorCard());
                                startingCard.changeFaceCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard());
                                makeWhiteSpace();
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        displayEffect(p2.getToken(),startingCard);
                                    } else {
                                        displayEffect(p4.getToken(),startingCard);
                                    }
                                    turn = 3;
                                } else {
                                    displayEffect(p2.getToken(),startingCard);
                                }
                                if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            drawCards(p2,2);
                                        } else {
                                            drawCards(p4,2);
                                        }
                                        turn = 3;
                                    } else {
                                        drawCards(p2,2);
                                    }
                                } else if (startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
                                    if (numPlay == 4) {
                                        clockwise = !clockwise;
                                        if (clockwise == true) {
                                            turn = 2;
                                        } else {
                                            turn = 4;
                                        }
                                    }
                                } else if (startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                                    if (numPlay == 4) {
                                        turn = 3;
                                    }
                                }
                            //NUMBER cards
                            } else {
                                startingCard.changeColorCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getColorCard());
                                startingCard.changeFaceCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard());
                                actioned = true;
                                makeWhiteSpace();
                                if (numPlay == 2 or clockwise == true) {
                                    turn = 2;
                                } else {
                                    turn = 4;
                                }
                            }
                            p1.placeCard(p1.getDeck().getNumberOfCards()-1);
                        } else {
                            actioned = true;
                            playedDrew = false;
                            if (numPlay == 2 or clockwise == true) {
                                turn = 2;
                            } else {
                                turn = 4;
                            }
                            makeWhiteSpace();
                        }
                    //No playable card
                    } else {
                        makeWhiteSpace();
                        std::cout << "Card drew: ";
                        p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).printCard();
                        actioned = true;
                        playedDrew = false;
                        if (numPlay == 2 or clockwise == true) {
                            turn = 2;
                        } else {
                            turn = 4;
                        }
                    }
                }
                if (playedDrew == true) {
                    std::cout << "Card played: ";
                    startingCard.printCard();
                } else {
                    std::cout << "Current card: ";
                    startingCard.printCard();
                    playedDrew = true;
                }
                sleep_for(seconds(2));
            //CPU 2's turn
            } else if (turn == 2){
                verifyUNOs(shoutedUno1,shoutedUno2,shoutedUno3,shoutedUno4,c1,c2,c3,c4,p1);
                actioned = false;
                p1 = Player(Deck(sort(p1.getDeck().getCards())),1,pt1,rounds1);
                p2 = Player(Deck(sort(p2.getDeck().getCards())),2,pt2,rounds2);
                p3 = Player(Deck(sort(p3.getDeck().getCards())),3,pt3,rounds3);
                p4 = Player(Deck(sort(p4.getDeck().getCards())),4,pt4,rounds4);
                playableCards2 = getPlayableCards(p2.getDeck(),startingCard);
                positions2 = getPlayablePositions(p2.getDeck(),startingCard);
                std::cout << "CPU 2's turn! " << std::endl;
                int positioned = -1;
                //CPU 2 has a playable card
                if (p2.getDeck().hasPlayableCard(startingCard) == true) {
                    if (p2.getDeck().getNumberOfCards() == 2) {
                        shoutedUno2 = true;
                    }
                    sleep_for(seconds(3));

                    //determines position of card to remove for CPU depending on opponent's number of cards
                    if (numPlay == 2 or clockwise == false) {
                        positioned = positionToRemoveCard(p2,positions2,p1);
                    } else {
                        positioned = positionToRemoveCard(p2,positions2,p3);
                    }

                    //DRAW 4 or WILD
                    if (p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("WILD") == 0) {
                        Color startColor = startingCard.getColorCard();
                        startingCard.changeColorCard(chooseColor(p2));
                        std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                        if (p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                            startingCard.changeFaceCard(Face("DRAW4WILD"));
                            if (numPlay == 4) {
                                if (clockwise == true) {
                                    if (p2.getDeck().getNumberOfCards() == 1) {
                                        drawCards(p3,4);
                                        displayEffect(p3.getToken(),startingCard);
                                    } else {
                                        cpuChallengeDraw4Process(p2,p3,startingCard,turn,numPlay,startColor);
                                    }
                                } else {
                                    if (p2.getDeck().getNumberOfCards() == 1) {
                                        drawCards(p1,4);
                                        displayEffect(p1.getToken(),startingCard);
                                    } else {
                                        playerChallengeDraw4Process(p2,p1,startingCard,turn,numPlay,startColor);
                                    }
                                }
                            } else {
                                if (p2.getDeck().getNumberOfCards() == 1) {
                                    drawCards(p1,4);
                                    displayEffect(p1.getToken(),startingCard);
                                } else {
                                    playerChallengeDraw4Process(p2,p1,startingCard,turn,numPlay,startColor);
                                }
                            }
                        } else {
                            startingCard.changeFaceCard(Face("WILD"));
                            if (numPlay == 2 or clockwise == false) {
                                turn = 1;
                            } else {
                                turn = 3;
                            }
                        }
                    //ACTION CARDS (SKIP, REVERSE, +2)
                    } else if (p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW2") == 0 or p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("SKIP") == 0 or p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                        startingCard.changeColorCard(p2.getDeck().getCardAtPos(positioned-1).getColorCard());
                        startingCard.changeFaceCard(p2.getDeck().getCardAtPos(positioned-1).getFaceCard());
                        if (numPlay == 4) {
                            if (clockwise == true) {
                                displayEffect(p3.getToken(),startingCard);
                            } else {
                                displayEffect(p1.getToken(),startingCard);
                            }
                            turn = 4;
                        } else {
                            displayEffect(p1.getToken(),startingCard);
                        }
                        if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                            if (numPlay == 4) {
                                if (clockwise == true) {
                                    drawCards(p3,2);
                                } else {
                                    drawCards(p1,2);
                                }
                                turn = 4;
                            } else {
                                drawCards(p1,2);
                            }
                        } else if (startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
                            if (numPlay == 4) {
                                clockwise = !clockwise;
                                if (clockwise == true) {
                                    turn = 3;
                                } else {
                                    turn = 1;
                                }
                            }
                        } else if (startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                            if (numPlay == 4) {
                                turn = 4;
                            }
                        }
                    //NUMBER CARDS
                    } else {
                        startingCard.changeColorCard(p2.getDeck().getCardAtPos(positioned-1).getColorCard());
                        startingCard.changeFaceCard(p2.getDeck().getCardAtPos(positioned-1).getFaceCard());
                        if (numPlay == 4 and clockwise == true) {
                            turn = 3;
                        } else {
                            turn = 1;
                        }
                    }
                    p2.placeCard(positioned-1);
                //No playable card
                } else {
                    sleep_for(seconds(3));
                    p2.drawCard();
                    c2 = 0;
                    std::cout << "CPU 2 drew a card." << std::endl;
                    shoutedUno2 = false;
                    //Draws playable card
                    if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                        sleep_for(seconds(5));
                        if (p2.getDeck().getNumberOfCards() == 2) {
                            shoutedUno2 = true;
                        }
                        //+4 or wild
                        if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                            Color startColor = startingCard.getColorCard();
                            startingCard.changeColorCard(chooseColor(p2));
                            std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                            if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                startingCard.changeFaceCard(Face("DRAW4WILD"));
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        if (p2.getDeck().getNumberOfCards() == 1) {
                                            drawCards(p3,4);
                                            displayEffect(p3.getToken(),startingCard);
                                        } else {
                                            cpuChallengeDraw4Process(p2,p3,startingCard,turn,numPlay,startColor);
                                        }
                                    } else {
                                        playerChallengeDraw4Process(p2,p1,startingCard,turn,numPlay,startColor);
                                    }
                                } else {
                                    if (p2.getDeck().getNumberOfCards() == 1) {
                                        drawCards(p1,4);
                                        displayEffect(p1.getToken(),startingCard);
                                    } else {
                                        playerChallengeDraw4Process(p2,p1,startingCard,turn,numPlay,startColor);
                                    }
                                }
                            } else {
                                startingCard.changeFaceCard(Face("WILD"));
                                if (clockwise == true and numPlay == 4) {
                                    turn = 3;
                                } else {
                                    turn = 1;
                                }
                            }
                        //Action cards (SKIP, REVERSE, +2)
                        } else if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                            startingCard.changeColorCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getColorCard());
                            startingCard.changeFaceCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard());
                            if (numPlay == 4) {
                                if (clockwise == true) {
                                    displayEffect(p3.getToken(),startingCard);
                                } else {
                                    displayEffect(p1.getToken(),startingCard);
                                }
                                turn = 4;
                            } else {
                                displayEffect(p1.getToken(),startingCard);
                            }
                            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        drawCards(p3,2);
                                    } else {
                                        drawCards(p1,2);
                                    }
                                    turn = 4;
                                } else {
                                    drawCards(p1,2);
                                }
                            } else if (startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
                                if (numPlay == 4) {
                                    clockwise = !clockwise;
                                    if (clockwise == true) {
                                        turn = 3;
                                    } else {
                                        turn = 1;
                                    }
                                }
                            } else if (startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                                if (numPlay == 4) {
                                    turn = 4;
                                }
                            }
                        //Number card
                        } else {
                            startingCard.changeColorCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getColorCard());
                            startingCard.changeFaceCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard());
                            if (clockwise == true and numPlay == 4) {
                                turn = 3;
                            } else {
                                turn = 1;
                            }
                        }
                        p2.placeCard(p2.getDeck().getNumberOfCards()-1);
                    } else {
                        if (clockwise == true and numPlay == 4) {
                            turn = 3;
                        } else {
                            turn = 1;
                        }
                        playedDrew = false;
                    }
                }
                if (playedDrew == true) {
                    std::cout << "Card played: ";
                    startingCard.printCard();
                } else {
                    std::cout << "Current card: ";
                    startingCard.printCard();
                    playedDrew = true;
                }
                sleep_for(seconds(2));
            //CPU 3's turn
            } else if (turn == 3) {
                if (actioned == true) {
                    makeWhiteSpace();
                }
                verifyUNOs(shoutedUno1,shoutedUno2,shoutedUno3,shoutedUno4,c1,c2,c3,c4,p1); 
                actioned = false;
                p1 = Player(Deck(sort(p1.getDeck().getCards())),1,pt1,rounds1);
                p2 = Player(Deck(sort(p2.getDeck().getCards())),2,pt2,rounds2);
                p3 = Player(Deck(sort(p3.getDeck().getCards())),3,pt3,rounds3);
                p4 = Player(Deck(sort(p4.getDeck().getCards())),4,pt4,rounds4);
                playableCards3 = getPlayableCards(p3.getDeck(),startingCard);
                positions3 = getPlayablePositions(p3.getDeck(),startingCard);
                std::cout << "CPU 3's turn! " << std::endl;
                sleep_for(seconds(3));
                //CPU 3 has playable card
                if (p3.getDeck().hasPlayableCard(startingCard) == true) {
                    if (p3.getDeck().getNumberOfCards() == 2) {
                        shoutedUno3 = true;
                    }
                    int positioned = -1;
                    if (clockwise == true) {
                        positioned = positionToRemoveCard(p3,positions3,p4);
                    } else {
                        positioned = positionToRemoveCard(p3,positions3,p2);
                    }
                    //+4 or wild
                    if (p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("WILD") == 0) {
                        Color startColor = startingCard.getColorCard();
                        startingCard.changeColorCard(chooseColor(p3));
                        std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                        if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                            startingCard.changeFaceCard(Face("DRAW4WILD"));
                            if (clockwise == true) {
                                if (p3.getDeck().getNumberOfCards() == 1) {
                                    drawCards(p4,4);
                                    displayEffect(p4.getToken(),startingCard);
                                } else {
                                    cpuChallengeDraw4Process(p3,p4,startingCard,turn,numPlay,startColor);
                                }
                            } else {
                                if (p3.getDeck().getNumberOfCards() == 1) {
                                    drawCards(p2,4);
                                    displayEffect(p2.getToken(),startingCard);
                                } else {
                                    cpuChallengeDraw4Process(p3,p2,startingCard,turn,numPlay,startColor);
                                }
                            }
                        } else {
                            startingCard.changeFaceCard(Face("WILD"));
                            if (clockwise == false) {
                                turn = 2;
                            } else {
                                turn = 4;
                            }
                        }
                    //ACTION CARDS
                    } else if (p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW2") == 0 or p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("SKIP") == 0 or p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                        startingCard.changeColorCard(p3.getDeck().getCardAtPos(positioned-1).getColorCard());
                        startingCard.changeFaceCard(p3.getDeck().getCardAtPos(positioned-1).getFaceCard());
                        if (clockwise == true) {
                            displayEffect(p4.getToken(),startingCard);
                        } else {
                            displayEffect(p2.getToken(),startingCard);
                        }
                        if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                            if (clockwise == true) {
                                drawCards(p4,2);
                            } else {
                                drawCards(p2,2);
                            }
                            turn = 1;
                        } else if (startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
                            if (numPlay == 4) {
                                clockwise = !clockwise;
                                if (clockwise == true) {
                                    turn = 4;
                                } else {
                                    turn = 2;
                                }
                            }
                        } else if (startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                            turn = 1;
                        }
                    //NUMBER CARDS
                    } else {
                        startingCard.changeColorCard(p3.getDeck().getCardAtPos(positioned-1).getColorCard());
                        startingCard.changeFaceCard(p3.getDeck().getCardAtPos(positioned-1).getFaceCard());
                        if (clockwise == false) {
                            turn = 2;
                        } else {
                            turn = 4;
                        }
                    }
                    p3.placeCard(positioned-1);
                //No playable card
                } else {
                    p3.drawCard();
                    c3 = 0;
                    std::cout << "CPU 3 drew a card." << std::endl;
                    shoutedUno3 = false;
                    //draw a playable card
                    if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                        sleep_for(seconds(5));
                        if (p3.getDeck().getNumberOfCards() == 2) {
                            shoutedUno3 = true;
                        }
                        //+4 or wild
                        if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                            Color startColor = startingCard.getColorCard();
                            startingCard.changeColorCard(chooseColor(p3));
                            std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                            if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                startingCard.changeFaceCard(Face("DRAW4WILD"));
                                if (clockwise == true) {
                                    if (p3.getDeck().getNumberOfCards() == 1) {
                                        drawCards(p4,4);
                                        displayEffect(p4.getToken(),startingCard);
                                    } else {
                                        cpuChallengeDraw4Process(p3,p4,startingCard,turn,numPlay,startColor);
                                    }
                                } else {
                                    if (p3.getDeck().getNumberOfCards() == 1) {
                                        drawCards(p2,4);
                                        displayEffect(p2.getToken(),startingCard);
                                    } else {
                                        cpuChallengeDraw4Process(p3,p2,startingCard,turn,numPlay,startColor);
                                    }
                                }
                            } else {
                                startingCard.changeFaceCard(Face("WILD"));
                                if (clockwise == false) {
                                    turn = 2;
                                } else {
                                    turn = 4;
                                }
                            }
                        //action cards
                        } else if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                            startingCard.changeColorCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getColorCard());
                            startingCard.changeFaceCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard());
                            if (clockwise == true) {
                                displayEffect(p4.getToken(),startingCard);
                            } else {
                                displayEffect(p2.getToken(),startingCard);
                            }
                            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                if (clockwise == true) {
                                    drawCards(p4,2);
                                } else {
                                    drawCards(p2,2);
                                }
                                turn = 1;
                            } else if (startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
                                clockwise = !clockwise;
                                if (clockwise == true) {
                                    turn = 4;
                                } else {
                                    turn = 2;
                                }
                            } else if (startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                                turn = 1;
                            }
                        //number cards
                        } else {
                            startingCard.changeColorCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getColorCard());
                            startingCard.changeFaceCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard());
                            if (clockwise == true) {
                                turn = 4;
                            } else {
                                turn = 2;
                            }
                        }
                        p3.placeCard(p3.getDeck().getNumberOfCards()-1);
                    } else {
                        if (clockwise == true) {
                            turn = 4;
                        } else {
                            turn = 2;
                        }
                        playedDrew = false;
                    }
                }
                if (playedDrew == true) {
                    std::cout << "Card played: ";
                    startingCard.printCard();
                } else {
                    std::cout << "Current card: ";
                    startingCard.printCard();
                    playedDrew = true;
                }
                sleep_for(seconds(2));
            //CPU 4 turn
            } else {
                verifyUNOs(shoutedUno1,shoutedUno2,shoutedUno3,shoutedUno4,c1,c2,c3,c4,p1); 
                actioned = false;
                p1 = Player(Deck(sort(p1.getDeck().getCards())),1,pt1,rounds1);
                p2 = Player(Deck(sort(p2.getDeck().getCards())),2,pt2,rounds2);
                p3 = Player(Deck(sort(p3.getDeck().getCards())),3,pt3,rounds3);
                p4 = Player(Deck(sort(p4.getDeck().getCards())),4,pt4,rounds4);
                playableCards4 = getPlayableCards(p4.getDeck(),startingCard);
                positions4 = getPlayablePositions(p4.getDeck(),startingCard);
                std::cout << "CPU 4's turn! " << std::endl;
                sleep_for(seconds(3));
                if (p4.getDeck().hasPlayableCard(startingCard) == true) {
                    if (p4.getDeck().getNumberOfCards() == 2) {
                        shoutedUno4 = true;
                    }
                    int positioned = -1;
                    if (clockwise == true) {
                        positioned = positionToRemoveCard(p4,positions4,p1);
                    } else {
                        positioned = positionToRemoveCard(p4,positions4,p3);
                    }
                    //+4 and wild
                    if (p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("WILD") == 0) {
                        Color startColor = startingCard.getColorCard();
                        startingCard.changeColorCard(chooseColor(p4));
                        std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                        if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                            startingCard.changeFaceCard(Face("DRAW4WILD"));
                            if (clockwise == true) {
                                if (p4.getDeck().getNumberOfCards() == 1) {
                                    drawCards(p1,4);
                                    displayEffect(p1.getToken(),startingCard);
                                } else {
                                    playerChallengeDraw4Process(p4,p1,startingCard,turn,numPlay,startColor);
                                }
                            } else {
                                if (p4.getDeck().getNumberOfCards() == 1) {
                                    drawCards(p3,4);
                                    displayEffect(p3.getToken(),startingCard);
                                } else {
                                    cpuChallengeDraw4Process(p4,p3,startingCard,turn,numPlay,startColor);
                                }
                            }
                        } else {
                            startingCard.changeFaceCard(Face("WILD"));
                            if (clockwise == true) {
                                turn = 1;
                            } else {
                                turn = 3;
                            }
                        }
                    //action
                    } else if (p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW2") == 0 or p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("SKIP") == 0 or p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                        startingCard.changeColorCard(p4.getDeck().getCardAtPos(positioned-1).getColorCard());
                        startingCard.changeFaceCard(p4.getDeck().getCardAtPos(positioned-1).getFaceCard());
                        if (clockwise == true) {
                            displayEffect(p1.getToken(),startingCard);
                        } else {
                            displayEffect(p3.getToken(),startingCard);
                        }
                        if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                            if (clockwise == true) {
                                drawCards(p1,2);
                            } else {
                                drawCards(p3,2);
                            }
                            turn = 2;
                        } else if (startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
                            clockwise = !clockwise;
                            if (clockwise == true) {
                                turn = 1;
                            } else {
                                turn = 3;
                            }
                        } else if (startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                            turn = 2;
                        }
                    //number card
                    } else {
                        startingCard.changeColorCard(p4.getDeck().getCardAtPos(positioned-1).getColorCard());
                        startingCard.changeFaceCard(p4.getDeck().getCardAtPos(positioned-1).getFaceCard());
                        if (clockwise == false) {
                            turn = 3;
                        } else {
                            turn = 1;
                        }
                    }
                    p4.placeCard(positioned-1);
                //draw a card
                } else {
                    p4.drawCard();
                    c4 = 0;
                    std::cout << "CPU 4 drew a card." << std::endl;
                    shoutedUno4 = false;
                    //draw a playable card
                    if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                        sleep_for(seconds(5));
                        if (p4.getDeck().getNumberOfCards() == 2) {
                            shoutedUno4 = true;
                        }
                        //draw 4 and wild
                        if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                            Color startColor = startingCard.getColorCard();
                            startingCard.changeColorCard(chooseColor(p4));
                            std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                            if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                startingCard.changeFaceCard(Face("DRAW4WILD"));
                                if (clockwise == true) {
                                    if (p4.getDeck().getNumberOfCards() == 1) {
                                        drawCards(p1,4);
                                        displayEffect(p1.getToken(),startingCard);
                                    } else {
                                        playerChallengeDraw4Process(p4,p1,startingCard,turn,numPlay,startColor);
                                    }
                                } else {
                                    if (p4.getDeck().getNumberOfCards() == 1) {
                                        drawCards(p3,4);
                                        displayEffect(p3.getToken(),startingCard);
                                    } else {
                                        cpuChallengeDraw4Process(p4,p3,startingCard,turn,numPlay,startColor);
                                    }
                                }
                            } else {
                                startingCard.changeFaceCard(Face("WILD"));
                                if (clockwise == true) {
                                    turn = 1;
                                } else {
                                    turn = 3;
                                }
                            }
                            //action
                        } else if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                            startingCard.changeColorCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getColorCard());
                            startingCard.changeFaceCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard());
                            if (clockwise == true) {
                                displayEffect(p1.getToken(),startingCard);
                            } else {
                                displayEffect(p3.getToken(),startingCard);
                            }
                            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                if (clockwise == true) {
                                    drawCards(p1,2);
                                } else {
                                    drawCards(p3,2);
                                }
                                turn = 2;
                            } else if (startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
                                clockwise = !clockwise;
                                if (clockwise == true) {
                                    turn = 1;
                                } else {
                                    turn = 3;
                                }
                            } else if (startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                                turn = 2;
                            }
                            //number
                        } else {
                            startingCard.changeColorCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getColorCard());
                            startingCard.changeFaceCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard());
                            if (clockwise == true) {
                                turn = 1;
                            } else {
                                turn = 3;
                            }
                        }
                        p4.placeCard(p4.getDeck().getNumberOfCards()-1);
                    } else {
                        if (clockwise == true) {
                            turn = 1;
                        } else {
                            turn = 3;
                        }
                        playedDrew = false;
                    }
                }
                if (playedDrew == true) {
                    std::cout << "Card played: ";
                    startingCard.printCard();
                } else {
                    std::cout << "Current card: ";
                    startingCard.printCard();
                    playedDrew = true;
                }
                sleep_for(seconds(2));
            }
        }
        int won1 = 0;
        int won2 = 0;
        int won3 = 0;
        int won4 = 0;
        p1 = Player(Deck(sort(p1.getDeck().getCards())),1,pt1,rounds1);
        p2 = Player(Deck(sort(p2.getDeck().getCards())),2,pt2,rounds2);
        p3 = Player(Deck(sort(p3.getDeck().getCards())),3,pt3,rounds3);
        p4 = Player(Deck(sort(p1.getDeck().getCards())),4,pt4,rounds4);
        //display winner
        if (p1.getDeck().getNumberOfCards() == 0) {
            won1 = p2.getDeck().valueOfDeck();
            std::cout << "Player 1 wins!" << std::endl;
            pt1 += p2.getDeck().valueOfDeck();
            if (numPlay == 4) {
                pt1 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                won1 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
            }
            rounds1++;
        } else if (p2.getDeck().getNumberOfCards() == 0){
            std::cout << "CPU 2 wins!" << std::endl;
            pt2 += p1.getDeck().valueOfDeck();
            won2 = p1.getDeck().valueOfDeck();
            if (numPlay == 4) {
                pt2 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                won2 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
            }
            rounds2++;
        } else if (p3.getDeck().getNumberOfCards() == 0) {
            std::cout << "CPU 3 wins!" << std::endl;
            pt3 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
            won3 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
            rounds3++;
        } else {
            std::cout << "CPU 4 wins!" << std::endl;
            pt4 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck() + p3.getDeck().valueOfDeck());
            won4 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck() + p3.getDeck().valueOfDeck());
            rounds4++;
        }
        std::string cont = "";
        //displays ranks
        while (cont.compare("C") != 0) {
            std::cout << "1st: ";
            if (p1.getDeck().getNumberOfCards() == 0) {
                std::cout << "Player 1" << std::endl;
                winnings.push_back(1);
            } else {
                if (p2.getDeck().getNumberOfCards() == 0) {
                    std::cout << "CPU 2" << std::endl;
                    winnings.push_back(2);
                } else if (p3.getDeck().getNumberOfCards() == 0) {
                    std::cout << "CPU 3" << std::endl;
                    winnings.push_back(3);
                } else {
                    std::cout << "CPU 4" << std::endl;
                    winnings.push_back(4);
                }
            }
            std::cout << "2nd: ";
            if (p1.getDeck().getNumberOfCards() == 0) {
                if (numPlay == 2) {
                    std::cout << "CPU 2" << std::endl;
                    winnings.push_back(2);
                } else {
                    if (min(p2.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                        std::cout << "CPU 2" << std::endl;
                        pt2 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                        won2 = p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                        winnings.push_back(2);
                        if (min(p3.getDeck().valueOfDeck(),p4.getDeck().valueOfDeck()) == p3.getDeck().valueOfDeck()) {
                            std::cout << "3rd: CPU 3" << std::endl;
                            std::cout << "4th: CPU 4" << std::endl;
                            winnings.push_back(3);
                            winnings.push_back(4);
                            pt3 += p4.getDeck().valueOfDeck();
                            won3 = p4.getDeck().valueOfDeck();            
                        } else {
                            std::cout << "3rd: CPU 4" << std::endl;
                            std::cout << "4th: CPU 3" << std::endl;
                            winnings.push_back(4);
                            winnings.push_back(3);
                            pt4 += p3.getDeck().valueOfDeck();
                            won4 = p3.getDeck().valueOfDeck();
                        }
                    } else if (min(p2.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p3.getDeck().valueOfDeck()) {
                        std::cout << "CPU 3" << std::endl;
                        pt3 += (p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                        won3 = p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                        winnings.push_back(3);
                        if (min(p2.getDeck().valueOfDeck(),p4.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                            std::cout << "3rd: CPU 2" << std::endl;
                            std::cout << "4th: CPU 4" << std::endl;
                            winnings.push_back(2);
                            winnings.push_back(4);
                            pt2 += p4.getDeck().valueOfDeck();
                            won2 = p4.getDeck().valueOfDeck();
                        } else {
                            std::cout << "3rd: CPU 4" << std::endl;
                            std::cout << "4th: CPU 2" << std::endl;
                            winnings.push_back(4);
                            winnings.push_back(2);
                            pt4 += p2.getDeck().valueOfDeck();
                            won4 = p2.getDeck().valueOfDeck();
                        }
                    } else {
                        std::cout << "CPU 4" << std::endl;
                        pt4 += (p3.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck());
                        won4 = p3.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck();
                        winnings.push_back(4);
                        if (min(p2.getDeck().valueOfDeck(),p3.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                            std::cout << "3rd: CPU 2" << std::endl;
                            std::cout << "4th: CPU 3" << std::endl;
                            winnings.push_back(2);
                            winnings.push_back(3);
                            pt2 += p3.getDeck().valueOfDeck();
                            won2 = p3.getDeck().valueOfDeck();
                        } else {
                            std::cout << "3rd: CPU 3" << std::endl;
                            std::cout << "4th: CPU 2" << std::endl;
                            winnings.push_back(3);
                            winnings.push_back(2);
                            pt3 += p2.getDeck().valueOfDeck();
                            won3 = p2.getDeck().valueOfDeck();
                        }
                    }
                }
            } else if (p2.getDeck().getNumberOfCards() == 0) {
                if (numPlay == 2) {
                    std::cout << "Player 1" << std::endl;
                    winnings.push_back(1);
                } else {
                    if (min(p1.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                        std::cout << "Player 1" << std::endl;
                            pt1 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                            won1 = p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                            winnings.push_back(1);
                        if (min(p3.getDeck().valueOfDeck(),p4.getDeck().valueOfDeck()) == p3.getDeck().valueOfDeck()) {
                            std::cout << "3rd: CPU 3" << std::endl;
                            std::cout << "4th: CPU 4" << std::endl;
                            winnings.push_back(3);
                            winnings.push_back(4);
                            pt3 += p4.getDeck().valueOfDeck();
                            won3 = p4.getDeck().valueOfDeck();
                        } else {
                            std::cout << "3rd: CPU 4" << std::endl;
                            std::cout << "4th: CPU 3" << std::endl;
                            winnings.push_back(4);
                            winnings.push_back(3);
                            pt4 += p3.getDeck().valueOfDeck();
                            won4 = p3.getDeck().valueOfDeck();
                        }
                    } else if (min(p1.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p3.getDeck().valueOfDeck()) {
                        std::cout << "CPU 3" << std::endl;
                        pt3 += (p4.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck());
                        won3 = p4.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck();
                        winnings.push_back(3);
                        if (min(p2.getDeck().valueOfDeck(),p4.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) { 
                            std::cout << "3rd: Player 1" << std::endl;
                            std::cout << "4th: CPU 4" << std::endl;           
                            winnings.push_back(1);
                            winnings.push_back(4);
                            pt1 += p4.getDeck().valueOfDeck();
                            won1 = p4.getDeck().valueOfDeck();
                        } else {
                            std::cout << "3rd: CPU 4" << std::endl;
                            std::cout << "4th: Player 1" << std::endl;
                            winnings.push_back(4);
                            winnings.push_back(1);
                            pt4 += p1.getDeck().valueOfDeck();
                            won4 = p1.getDeck().valueOfDeck();
                        }
                    } else {
                        std::cout << "CPU 4" << std::endl;
                        pt4 += (p3.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck());
                        won4 = p3.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck();
                        winnings.push_back(4);
                        if (min(p1.getDeck().valueOfDeck(),p3.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                            std::cout << "3rd: Player 1" << std::endl;
                            std::cout << "4th: CPU 3" << std::endl;
                            winnings.push_back(1);
                            winnings.push_back(3);
                            pt1 += p3.getDeck().valueOfDeck();
                            won1 = p3.getDeck().valueOfDeck();
                        } else {
                            std::cout << "3rd: CPU 3" << std::endl;
                            std::cout << "4th: Player 1" << std::endl;
                            winnings.push_back(3);
                            winnings.push_back(1);
                            pt3 += p1.getDeck().valueOfDeck();
                            won3 = p1.getDeck().valueOfDeck();
                        }
                    }
                }
            } else if (p3.getDeck().getNumberOfCards() == 0) {
                if (min(p1.getDeck().valueOfDeck(), p2.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                    std::cout << "Player 1" << std::endl;
                        pt1 += (p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                        won1 = p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                        winnings.push_back(1);
                    if (min(p2.getDeck().valueOfDeck(),p4.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                        std::cout << "3rd: CPU 2" << std::endl;
                        std::cout << "4th: CPU 4" << std::endl;
                        winnings.push_back(2);
                        winnings.push_back(4);
                        pt2 += p4.getDeck().valueOfDeck();
                        won2 = p4.getDeck().valueOfDeck();
                        } else {
                            std::cout << "3rd: CPU 4" << std::endl;
                            std::cout << "4th: CPU 2" << std::endl;
                            winnings.push_back(4);
                            winnings.push_back(2);
                            pt4 += p2.getDeck().valueOfDeck();
                            won4 = p2.getDeck().valueOfDeck();
                        }
                } else if (min(p1.getDeck().valueOfDeck(), p2.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                    std::cout << "CPU 2" << std::endl;
                    pt2 += (p1.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                    won2 = p1.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                    winnings.push_back(2);
                    if (min(p1.getDeck().valueOfDeck(),p4.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                        std::cout << "3rd: Player 1" << std::endl;
                        std::cout << "4th: CPU 4" << std::endl;
                        winnings.push_back(1);
                        winnings.push_back(4);
                        pt1 += p4.getDeck().valueOfDeck();
                        won1 = p4.getDeck().valueOfDeck();
                        } else {
                            std::cout << "3rd: CPU 4" << std::endl;
                            std::cout << "4th: Player 1" << std::endl;
                            winnings.push_back(4);
                            winnings.push_back(1);
                            pt4 += p1.getDeck().valueOfDeck();
                            won4 = p1.getDeck().valueOfDeck();
                        }
                } else {
                    std::cout << "CPU 4" << std::endl;
                    pt4 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck());
                    won4 = p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck();
                    winnings.push_back(4);
                    if (min(p1.getDeck().valueOfDeck(),p2.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                        std::cout << "3rd: Player 1" << std::endl;
                        std::cout << "4th: CPU 2" << std::endl;
                        winnings.push_back(1);
                        winnings.push_back(2);
                        pt1 += p2.getDeck().valueOfDeck();
                        won1 = p2.getDeck().valueOfDeck();
                    } else {
                        std::cout << "3rd: CPU 2" << std::endl;
                        std::cout << "4th: Player 1" << std::endl;
                        winnings.push_back(2);
                        winnings.push_back(1);
                        pt2 += p1.getDeck().valueOfDeck();
                        won2 = p1.getDeck().valueOfDeck();
                    }
                }
            } else {
                if (min(p1.getDeck().valueOfDeck(), p2.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                    std::cout << "Player 1" << std::endl;
                    pt1 += (p3.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck());
                    won1 = p3.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck();
                    winnings.push_back(1);
                    if (min(p2.getDeck().valueOfDeck(),p3.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                        std::cout << "3rd: CPU 2" << std::endl;
                        std::cout << "4th: CPU 3" << std::endl;
                        winnings.push_back(2);
                        winnings.push_back(3);
                        pt2 += p3.getDeck().valueOfDeck();
                        won2 = p3.getDeck().valueOfDeck();
                    } else {
                        std::cout << "3rd: CPU 3" << std::endl;
                        std::cout << "4th: CPU 2" << std::endl;
                        winnings.push_back(3);
                        winnings.push_back(2);
                        pt3 += p2.getDeck().valueOfDeck();
                        won3 = p2.getDeck().valueOfDeck();
                    }
                } else if (min(p1.getDeck().valueOfDeck(), p2.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                    std::cout << "CPU 2" << std::endl;
                    pt2 += (p3.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck());
                    won2 = p3.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck();
                    winnings.push_back(2);
                    if (min(p1.getDeck().valueOfDeck(),p3.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                        std::cout << "3rd: Player 1" << std::endl;
                        std::cout << "4th: CPU 3" << std::endl;
                        winnings.push_back(1);
                        winnings.push_back(3);
                        pt1 += p3.getDeck().valueOfDeck();
                        won1 = p3.getDeck().valueOfDeck();
                    } else {
                        std::cout << "3rd: CPU 3" << std::endl;
                        std::cout << "4th: Player 1" << std::endl;
                        winnings.push_back(3);
                        winnings.push_back(1);
                        pt3 += p1.getDeck().valueOfDeck();
                        won3 = p1.getDeck().valueOfDeck();
                    }
                } else {
                    std::cout << "CPU 3" << std::endl;
                    pt3 += (p2.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck());
                    won3 = p2.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck();
                    winnings.push_back(3);
                    if (min(p1.getDeck().valueOfDeck(),p2.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                        std::cout << "3rd: Player 1" << std::endl;
                        std::cout << "4th: CPU 2" << std::endl;
                        winnings.push_back(1);
                        winnings.push_back(2);
                        pt1 += p2.getDeck().valueOfDeck();
                        won1 = p2.getDeck().valueOfDeck();
                    } else {
                        std::cout << "3rd: CPU 2" << std::endl;
                        std::cout << "4th: Player 1" << std::endl;
                        winnings.push_back(2);
                        winnings.push_back(1);
                        pt2 += p1.getDeck().valueOfDeck();
                        won2 = p1.getDeck().valueOfDeck();
                    }
                }
            }
            bool validMove = false;
            int count = 0;
            //display ranks and statistics 
            while ((isNumber(cont) == false and cont.compare("C") != 0) or validMove == false) {
                if (count == 1) {
                    for (unsigned int i = 0; i < winnings.size(); i++) {
                        switch(i) {
                            case 0:
                                std::cout << "1st: ";
                                if (winnings[i] > 1) {
                                    std::cout << "CPU " << winnings[i] << std::endl;
                                } else {
                                    std::cout << "Player 1" << std::endl;
                                }
                                break;
                            case 1:
                                std::cout << "2nd: ";
                                if (winnings[i] > 1) {
                                    std::cout << "CPU " << winnings[i] << std::endl;
                                } else {
                                    std::cout << "Player 1" << std::endl;
                                }
                                break;
                            case 2:
                                if (numPlay == 4) {
                                    std::cout << "3rd: ";
                                    if (winnings[i] > 1) {
                                        std::cout << "CPU " << winnings[i] << std::endl;
                                    } else {
                                        std::cout << "Player 1" << std::endl;
                                    }
                                    break;
                                }
                            case 3:
                                if (numPlay == 4) {
                                    std::cout << "4th: ";
                                    if (winnings[i] > 1) {
                                        std::cout << "CPU " << winnings[i] << std::endl;
                                    } else {
                                        std::cout << "Player 1" << std::endl;
                                    }
                                }
                        }
                    }
                }
                std::cout << "Choose from the following options: " << std::endl;
                std::cout << "Type 1 to see Player 1's statistics (owned cards, value of deck, points won). " << std::endl;
                std::cout << "Type 2 to see CPU 2's statistics (owned cards, value of deck, points won). " << std::endl;
                if (numPlay == 4) {
                    std::cout << "Type 3 to see CPU 3's statistics (owned cards, value of deck, points won). " << std::endl;
                    std::cout << "Type 4 to see CPU 4's statistics (owned cards, value of deck, points won). " << std::endl;
                }
                std::cout << "Type C to continue." << std::endl;
                std::cout << "Chosen option: ";
                std::cin >> cont;
                if (isNumber(cont) == false and cont.compare("C") != 0) {
                    std::cout << "Invalid input! Input cannot be processed! MUST be an integer number (between 1 and 4) or C!" << std::endl;
                    makeWhiteSpace();
                    continue;
                } else if (isNumber(cont) == true and (std::stoi(cont) > numPlay or std::stoi(cont) < 1)) {
                    std::cout << "Invalid input! MUST be an integer number between 1 and " << numPlay << "!" << std::endl;
                    makeWhiteSpace();
                    continue;
                }
                int sample = -1;
                if (isNumber(cont) == true) {
                    sample = std::stoi(cont);
                } else if (cont.compare("C") == 0) {
                    validMove = true;
                }
                makeWhiteSpace();
                switch(sample) {
                    case 1:
                        std::cout << "Player 1's hand: " << std::endl;
                        std::cout << "Player 1 deck value: " << p1.getDeck().valueOfDeck() << std::endl;
                        p1.revealHand1();
                        std::cout << "Player 1 has earned a total of: " << won1 << " points!" << std::endl;
                        break;
                    case 2:
                        std::cout << "CPU 2's hand:" << std::endl;
                        std::cout << "CPU 2 deck value: ";
                        std::cout << p2.getDeck().valueOfDeck() << std::endl;
                        p2.revealHand1();
                        std::cout << "CPU 2";
                        std::cout << " has earned a total of: " << won2 << " points! " << std::endl;
                        break;
                    case 3:
                        std::cout << "CPU 3's hand:" << std::endl;
                        std::cout << "CPU 3 deck value: ";
                        std::cout << p3.getDeck().valueOfDeck() << std::endl;
                        p3.revealHand1();
                        std::cout << "CPU 3";
                        std::cout << " has earned a total of: " << won3 << " points!" << std::endl;
                        break;
                    case 4:
                        std::cout << "CPU 4's hand:" << std::endl;
                        std::cout << "CPU 4 deck value: ";
                        std::cout << p4.getDeck().valueOfDeck() << std::endl;
                        p4.revealHand1();
                        std::cout << "CPU 4";
                        std::cout << " has earned a total of: " << won4 << " points! " << std::endl;
                }
                count = 1;
            }
        }
        if (opt != 4) {
            std::cout << "Goal: " << ptG << std::endl;
        }
        //display scores
        std::cout << "Player 1 score: " << pt1 << std::endl;
        std::cout << "Player 1 rounds won: " << rounds1 << std::endl;
        std::cout << "CPU 2 score: " << pt2 << std::endl;
        std::cout << "CPU 2 rounds won: " << rounds2 << std::endl;
        if (numPlay == 4) {
            std::cout << "CPU 3 score: " << pt3 << std::endl;
            std::cout << "CPU 3 rounds won: " << rounds3 << std::endl;
            std::cout << "CPU 4 score: " << pt4 << std::endl;
            std::cout << "CPU 4 rounds won: " << rounds4 << std::endl;
        }
        winnings.clear();
        std::string continuing = "";
        while (continuing.compare("C") != 0) {
            std::cout << "Type C to continue. ";
            std::cin >> continuing;
            if (continuing.compare("C") != 0) {
                std::cout << "Invalid input! Input value MUST be C to be valid." << std::endl;
            }
        }
        //play again option (if relentless is chosen)
        if (opt == 4) {
            play1 = "";
            while (play1.compare("Y") != 0 and play1.compare("N") != 0) {
                std::cout << "Player 1, do you wish to play again? Type Y for yes or N for no. ";
                std::cin >> play1;
                if (play1.compare("Y") != 0 and play1.compare("N") != 0) {
                    std::cout << "Invalid choice! ";
                }
            }
            play2 = "Y";
            play3 = "Y";
            play4 = "Y";
            playedAgain = play1.compare("Y") == 0;
        } else {
            playedAgain = pt1 < ptG and pt2 < ptG and pt3 < ptG and pt4 < ptG;
        }
        c1 = 0;
        c2 = 0;
        c3 = 0;
        c4 = 0;
        makeWhiteSpace();
    }

    //overall statistics
    std::cout << std::endl;
    std::cout << "Statistics: " << std::endl;
    std::cout << "Player 1 score: " << pt1 << std::endl;
    std::cout << "Player 1 rounds won: " << rounds1 << std::endl;
    std::cout << std::endl;
    std::cout << "CPU 2 score: " << pt2 << std::endl;
    std::cout << "CPU 2 rounds won: " << rounds2 << std::endl;
    std::cout << std::endl;
    if (numPlay == 4) {
        std::cout << "CPU 3 score: " << pt3 << std::endl;
        std::cout << "CPU 3 rounds won: " << rounds3 << std::endl;
        std::cout << std::endl;
        std::cout << "CPU 4 score: " << pt4 << std::endl;
        std::cout << "CPU 4 rounds won: " << rounds4 << std::endl;
    }
    //winner determination (based on points)
    if (pt1 > pt2 and pt1 > pt3 and pt1 > pt4) {
        std::cout << "Player 1 wins after " << rounds << " rounds!" << std::endl;
    } else if (pt2 > pt1 and pt2 > pt3 and pt2 > pt4) {
        std::cout << "CPU 2 wins after " << rounds << " rounds!" << std::endl;
    } else if (pt3 > pt1 and pt3 > pt2 and pt3 > pt4) {
        std::cout << "CPU 3 wins after " << rounds << " rounds!" << std::endl;
    } else if (pt4 > pt1 and pt4 > pt2 and pt4 > pt3) {
        std::cout << "CPU 4 wins after " << rounds << " rounds!" << std::endl;
    } else {
        //winner determination (based on rounds won)
        std::cout << "Tied points. Winner is determined by rounds won!" << std::endl;
        int maximum = max(pt1,pt2,pt3,pt4);
        std::vector<int> pointings;
        std::vector<int> tiedExists;
        std::vector<int> roundsWon;
        std::vector<int> tiedExistsAgain;
        pointings.push_back(pt1);
        pointings.push_back(pt2);
        pointings.push_back(pt3);
        pointings.push_back(pt4);
        for (unsigned int i = 0; i < pointings.size(); i++) {
            if (pointings[i] == maximum) {
                tiedExists.push_back(i+1);
            }
        }
        int maxRound = -1;
        int maxToken = -1;
        for (unsigned int i = 0; i < tiedExists.size(); i++) {
            if (tiedExists[i] == 1) {
                roundsWon.push_back(rounds1);
                if (rounds1 > maxRound) {
                    maxRound = rounds1;
                    maxToken = 1;
                }
            } else if (tiedExists[i] == 2) {
                roundsWon.push_back(rounds2);
                if (rounds2 > maxRound) {
                    maxRound = rounds2;
                    maxToken = 2;
                }
            } else if (tiedExists[i] == 3) {
                roundsWon.push_back(rounds3);
                if (rounds3 > maxRound) {
                    maxRound = rounds3;
                    maxToken = 3;
                }
            } else {
                roundsWon.push_back(rounds4);
                if (rounds4 > maxRound) {
                    maxRound = rounds4;
                    maxToken = 4;
                }
            }
        }
        for (unsigned int i = 0; i < roundsWon.size(); i++) {
            if (roundsWon[i] == maxRound) {
                tiedExistsAgain.push_back(i+1);
            }
        }
        if (tiedExistsAgain.size() == 1) {
            if (tiedExistsAgain[0] == 1) {
                std::cout << "Player 1 wins after " << rounds << " rounds!" << std::endl;
            } else {
                std::cout << "CPU " << tiedExistsAgain[0] << " wins after" << maxRound << " rounds!" << std::endl;
            }
        } else {
            //winner determination by random draw
            std::cout << "Tied points won and rounds won! Winner will be determined by random!" << std::endl;
            for (unsigned int i = 0; i < tiedExistsAgain.size(); i++) {
                if (tiedExistsAgain[i] == 1) {
                    std::cout << i << "= Player 1 victory" << std::endl;
                } else {
                    std::cout << i << "= CPU " << tiedExistsAgain[i] << " victory" << std::endl;
                }
            }
            int winner = rand()%(tiedExistsAgain.size());
            if (tiedExistsAgain[winner] == 1) {
                std::cout << "Player 1 wins by random draw!" << std::endl;
            } else {
                std::cout << "CPU " << tiedExistsAgain[winner] << " wins by random draw!" << std::endl;
            }
        }
    }
}
