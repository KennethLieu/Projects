/*
 
UNO TWIST Game Rules:
 
 Welcome to UNO TWIST Game! Compete in a 1v1 battle where the objective is to be the first player to remove all their cards. To start, you can choose whether to compete with another player or with a CPU. Afterwards, you can choose whether to compete for 500 points, 1000 points, 2000 points, or relentlessly (until one player chooses to not play again). Please be sure that CAPS LOCK are ON to ensure that input can be processed and to progress with the game. Afterwards, each player will begin with 7 cards, and try to be the first one to remove all their cards. Type P to play a card(provided you can play a card legally), D to draw a card, or U to type UNO when your turn arrives. Please note that you MUST type U to shout UNO when you are about to remove your second to last card, as the system will end up catching you otherwise and force you to draw 2 cards. Each card will be splitted into the following categories:

     1. Number cards (0-9)
 
     2. Action cards (DRAW2, SKIP, REVERSE)
 
     3. Wild cards (WILD, DRAW4WILD, WILD TWISTER)
 
     Placing a DRAW2 will force the next player to draw 2 cards and loses their turn, SKIP and REVERSE will force the next player to lose their turn. Placing a WILD card will allow you to choose the color of the card, and placing a DRAW4WILD is the same as a WILD, but will also force the next player to draw 4 cards and loses their turn.
 
 Points distribution:
     1. Number cards are worth their face values each (0 for 0 points, 1 for 1 point, ... ,9 for 9 points)
     2. Action cards (REVERSE, DRAW2, SKIP) are worth 20 points each
     3. WILD cards (traditional wilds and wild +4s) are worth 50 points each
     4. WILD Twister cards are worth 60 points each
 
 UNO TWIST game development history log:
 
 Game project started on: 11/25/2019
 
 Update 11/27/2019:
 1. Allows playing UNO, for now only 2 player UNO is available and you MUST have another player present. *MAJOR UPDATE!*
 
 Update 11/30/2019:
 1. Now displays the cards that you can play, in addition to your current hand.
 
 Update 12/15/2019:
 1. Allows playing with CPU *MAJOR UPDATE!*
 2. Players can choose to compete for 500, 1000, 2000 points, or relentlessly (until 1 player quits)
 3. Players can also choose to play with CPU or play with another player
 
 Update 12/19/2019:
 1. Improved AI of CPU
 2. UNO feature added so players MUST shout UNO or draw 2 cards (CPUs will shout UNO automatically by default).
 
 Update 1/14/2020:
 1. All cards appear sorted order (based on card value only)
 2. Now displays consequence properly for Player 2 and CPU.
 3. Now displays number of points that each card in the losing player's hand is worth after the end of each round.
 4. Now displays rounds, rounds won WILL be tiebreaker if points tied. If tied points and rounds won tie, then winner will be determined by RANDOM!
 
 Update 1/24/2020:
 1. Now allows players to choose to either play in 2 player gamemode or 4 player gamemode. *MAJOR UPDATE!*
 2. At the end of each round, there are major changes to the displaying of winning statistics, where you can type 1 to see your cards and points won, 2 to see Player/CPU 2's cards and points won, 3 to see Player/CPU 3's cards and points won, and 4 to see Player/CPU 4's cards and points won. Initially it will display the ranks according to the value of the cards remaining and also displays the ranks of each player. Afterwards, press C to continue and move onto the overall statistics in terms of total points and rounds won. *MAJOR UPDATE!*
 
 Update 1/30/2020:
 1. Fixed some bugs in the design of the gameplay:
    a) Failure of reshuffling cards for all players when they draw cards and the game ends
    b) Displaying player 3/4 despite playing only a 2 player game.
 
 Update 2/6/2020:
 1. Fixed more bugs in gameplay:
    a) Fixed bug where you can enter in any number input for choosing how many points to compete for.
    b) Now added in the total value of the remaining cards in deck when displaying player statistics at the end of each round.
 
 Update 2/11/2020:
 1. Fixed a bug where when a CPU plays an action card after drawing, that the turn will go back to the CPU.
 
 Update 2/25/2020:
 1. Added the feature for players so that when they are about to go, that they are prompted to type CONT to continue to their turn, to prevent opponents from being able to see other people's cards.
 
 Future Update(s) (TBA):
 1. Introduces the Wild Twister Gamemode *MAJOR UPDATE!* (TBA)
    a) In this gamemode, a new card: WildTwister, will be available! Use this to sweeten the gameplay and punish drawing players with bombardment of cards!
    b) The WildTwister card will begin the WildTwist effect by starting off the total draw amount to 2, and the next player either plays a card or draw 2 cards. This card behaves like a normal wild card in which you can choose the color to benefit your gameplay.
    c) From here onwards, each card played afterwards (excluding any draw cards and other WildTwister cards), will add 1 to the total draw amount for the player who draws.
    d) If the card played is a +2 or a +4, it will add 2 or 4 to the total draw amount, and the two cases will follow for the next player:
        1. The next player will draw the total draw amount if they do NOT have another +2 or +4. For a +2 card, you MUST play a +2 or +4 (if you do NOT have a +2). For a +4 card, you MUST play a +4. If you don't possess the appropriate cards, you WILL draw the total draw amount and the WildTwist effect will end.
        2. The next player will play one (+2 or +4 depending on the scenario) of the cards as listed.
    e) If the card played is another Wild Twister during Wild Twister effect, it will add 2 to the total draw amount (similar to playing a +2 card), except the next player need not a +2 nor a +4 in order to avoid drawing the total draw amount and it allows the holder to change the color in hopes to making the next player draw.
    f) If the WildTwister card is the last card played, it will act as a +2 card and WILL make the next player draw the total draw amount.
    g) BEWARE when you play the WildTwiser card, as it will begin the WildTwist effect and you can be the person who draws the total draw amount if you do NOT have any playable cards left, so be cautious in playing it.
    h) When the player draws the total draw amount, they will draw the total amount AND their turn WILL be skipped in the process, ending the WildTwist effect.
    i) If the starting card is a Wild Twister card, the color will be selected by random and the Wild Twister effect will NOT occur!
 2. Now players will be able to choose between Classic Gamemode and Wild Twister Gamemode (TBA)
 3. Now when placing +4 cards, you will have the option to challenge the +4, whether the previous opponent actually has a playable color card. If you succeed in your guess, they draw 4 and you received your turn, otherwise you draw 6 and your turn in skipped. (TBA) *MAJOR UPDATE!*
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
class Color { /* represents the possible colors of playing cards when playing UNO */
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
class Face { /* represents the possible face values of playing cards when playing UNO */
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
class Card { /* Represents the possible cards when playing UNO */
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
    bool isPlayable(Card a) { //checks if this particular card can be played, given the most recent card that is played, or Card a
        if (face.getFace().compare("WILD") == 0 or face.getFace().compare("DRAW4WILD") == 0 or face.getFace().compare("WILDTWIST") == 0) {
            return true;
        } else if (color.getColor().compare(a.getColorCard().getColor()) == 0 or face.getFace().compare(a.getFaceCard().getFace()) == 0) {
            return true;
        }
        return false;
    }
    int getValue() { //returns the point value of this card object
        return value;
    }
private:
    Face face; //face of card
    Color color; //color of card
    int value; //point value associated with card
    std::string category; //category of card (number, action, wild)
};
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
void printPlayableCards(std::vector<Card> a, std::vector<int> b) {
    std::cout << "Playable cards: " << std::endl;
    for (unsigned int i = 0; i < a.size(); i++) {
        std::cout << b[i] << ". ";
        a[i].printCard();
    }
}
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
Color chooseColor(Player a, Card start) { //algorithm to choose color of card for CPU
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
std::vector<Card> getPlayableCards(Deck a, Card start) { //returns the list of cards that can be played, if any
    std::vector<Card> cards;
    for (int i = 0; i < a.getNumberOfCards(); i++) {
        if (a.getCards()[i].isPlayable(start) == true) {
            cards.push_back(a.getCards()[i]);
        }
    }
    return cards;
}
std::vector<int> getPlayablePositions(Deck a, Card start) { //returns the associated position of cards that can be played, if any
    std::vector<int> pos;
    for (int i = 0; i < a.getNumberOfCards(); i++) {
        if (a.getCards()[i].isPlayable(start) == true) {
            pos.push_back(i+1);
            
        }
    }
    return pos;
}
void displayEffect(Player a, int token, Card start, std::string playWith) { //displays effect of CPU or Player, if applicable.
        if (start.getFaceCard().getFace().compare("DRAW4WILD") == 0) {
            if (playWith.compare("C") == 0 and (token == 2 or token == 3 or token == 4)) {
                std::cout << "CPU " << token << ": DRAW 4 CARDS!" << std::endl;
            } else {
                std::cout << "Player " << token << ": DRAW 4 CARDS!" << std::endl;
            }
        } else if (start.getFaceCard().getFace().compare("DRAW2") == 0) {
            if (playWith.compare("C") == 0 and (token == 2 or token == 3 or token == 4)) {
                std::cout << "CPU " << token << ": DRAW 2 CARDS!" << std::endl;
            } else {
                std::cout << "Player " << token << ": DRAW 2 CARDS!" << std::endl;
            }
        } else if (start.getFaceCard().getFace().compare("SKIP") == 0) {
            if (playWith.compare("C") == 0 and (token == 2 or token == 3 or token == 4)) {
                std::cout << "CPU " << token << ": LOST TURN!" << std::endl;
            } else {
                std::cout << "Player " << token << ": LOST TURN!" << std::endl;
            }
        } else if (start.getFaceCard().getFace().compare("REVERSE") == 0) {
            std::cout << "Gameplay reversed! " << std::endl;
        }

}
void makeWhiteSpace() { //creates whitespace
    for (int i = 0; i < 30; i++) {
        std::cout << std::endl;
    }
}
bool isNumber(std::string s) { //returns if the string is a number
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}
std::vector<Card> sort(std::vector<Card> a) { //sorts the cards by ascending point value
    for(unsigned int i = 0; i < a.size(); i++)
    {
        for(int j = i+1; j < a.size(); j++)
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
int min(int a, int b, int c) { //finds the minimum of three numbers
    if (a < b and a < c) {
        return a;
    } else if (b < a and b < c) {
        return b;
    }
    return c;
}
int main(int argc, char** argv) {
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
    std::string playWith = "";
    while (playWith.compare("C") != 0 and playWith.compare("P") != 0) {
        std::cout << "Welcome to UNO TWIST! Play in an UNO TWIST match where the goal is to be the first player to remove their card. Please make sure all of your inputs are in ALL CAPS or your input will NOT be processed! Type C to play with a CPU, or P to play with another player: ";
        std::cin >> playWith;
        if (playWith.compare("C") != 0 and playWith.compare("P") != 0) {
            std::cout << "Invalid choice! Please enter either values C to play with CPU or P to play with another player!" << std::endl;
        }
    }
    std::string optionChosen = "s";
    bool validChoice = false;
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
        Deck deckOfCards;
        Deck deckOfCards2;
        Deck deckOfCards3;
        Deck deckOfCards4;
        Player p1(deckOfCards,1,pt1,rounds1);
        Player p2(deckOfCards2,2,pt2,rounds2);
        Player p3(deckOfCards3,3,pt3,rounds3);
        Player p4(deckOfCards4,4,pt4,rounds4);
        for (int i = 0; i < 7; i++) {
            p1.drawCard();
            p2.drawCard();
            p3.drawCard();
            p4.drawCard();
        }
        cards1 = p1.getDeck().getCards();
        cards2 = p2.getDeck().getCards();
        cards1 = sort(cards1);
        cards2 = sort(cards2);
        Deck rep1(cards2);
        Player pl1(rep1,1,pt1,rounds1);
        Deck rep2(cards2);
        Player pl2(rep2,1,pt2,rounds2);
        p1 = pl1;
        p2 = pl2;
        int turn = 1;
        Card startingCard;
        if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0 or startingCard.getFaceCard().getFace().compare("SKIP") == 0 or startingCard.getFaceCard().getFace().compare("REVERSE") == 0) {
            displayEffect(p1,p1.getToken(),startingCard,playWith);
            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                for (int i = 0; i < 2; i++) {
                    p1.drawCard();
                }
            }
            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0 or startingCard.getFaceCard().getFace().compare("SKIP") == 0) {
                turn = 2;
            } else {
                clockwise = false;
            }
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
        bool wildTwistingMode = false;
        std::vector<Card> playableCards1 = getPlayableCards(p1.getDeck(),startingCard); //playable cards for player 1
        std::vector<int> positions1 = getPlayablePositions(p1.getDeck(),startingCard);
        std::vector<Card> playableCards2 = getPlayableCards(p2.getDeck(),startingCard); //playable cards for player 2
        std::vector<int> positions2 = getPlayablePositions(p2.getDeck(),startingCard);
        std::vector<Card> playableCards3 = getPlayableCards(p3.getDeck(),startingCard); //playable cards for player 3
        std::vector<int> positions3 = getPlayablePositions(p3.getDeck(),startingCard);
        std::vector<Card> playableCards4 = getPlayableCards(p4.getDeck(),startingCard); //playable cards for player 4
        std::vector<int> positions4 = getPlayablePositions(p4.getDeck(),startingCard);
        startingCard.printCard();
        bool shoutedUno1 = false;
        bool shoutedUno2 = false;
        bool shoutedUno3 = false;
        bool shoutedUno4 = false;
        int drawAmount = 0;
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c4 = 0;
        bool actioned = false;
        bool playedDrew = true;
        while (p1.getDeck().getNumberOfCards() != 0 and p2.getDeck().getNumberOfCards() != 0 and p3.getDeck().getNumberOfCards() != 0 and p4.getDeck().getNumberOfCards() != 0) {
            if (turn == 1) {
                cards1 = p1.getDeck().getCards();
                cards2 = p2.getDeck().getCards();
                cards3 = p3.getDeck().getCards();
                cards4 = p4.getDeck().getCards();
                cards1 = sort(cards1);
                cards2 = sort(cards2);
                cards3 = sort(cards3);
                cards4 = sort(cards4);
                Deck rep1(cards1);
                Player pla1(rep1,1,pt1,rounds1);
                Deck rep2(cards2);
                Player pla2(rep2,2,pt2,rounds2);
                Deck rep3(cards3);
                Player pla3(rep3,3,pt3,rounds3);
                Deck rep4(cards4);
                Player pla4(rep4,4,pt4,rounds4);
                p1 = pla1;
                p2 = pla2;
                p3 = pla3;
                p4 = pla4;
                if (shoutedUno1 == true and c1 == 0) {
                    std::cout << "Player 1: UNO!" << std::endl;
                    c1++;
                } else if (p1.getDeck().getNumberOfCards() == 1 and shoutedUno1 == false) {
                    std::cout << "Player 1: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    for (int i = 0; i < 2; i++) {
                        p1.drawCard();
                    }
                }
                if (shoutedUno2 == true and c2 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 2: UNO!" << std::endl;
                    }
                    c2++;
                } else if (p2.getDeck().getNumberOfCards() == 1 and shoutedUno2 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 2: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p2.drawCard();
                    }
                }
                if (shoutedUno3 == true and c3 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 3: UNO!" << std::endl;
                    }
                    c3++;
                } else if (p3.getDeck().getNumberOfCards() == 1 and shoutedUno3 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 3: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p3.drawCard();
                    }
                }
                if (shoutedUno4 == true and c4 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 4: UNO!" << std::endl;
                    }
                    c4++;
                } else if (p4.getDeck().getNumberOfCards() == 1 and shoutedUno4 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 4: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p4.drawCard();
                    }
                }
                playableCards1 = getPlayableCards(p1.getDeck(),startingCard);
                positions1 = getPlayablePositions(p1.getDeck(),startingCard);
                std::cout << "Player 1's turn!" << std::endl;
                if (playWith.compare("C") != 0) {
                    while(true) {
                        std::cout << "Type CONT to continue. ";
                        std::string decision1 = "";
                        std::cin >> decision1;
                        if (decision1.compare("CONT") == 0) {
                            break;
                        }
                    }
                }
                p1.revealHand();
                if (playWith.compare("C") == 0) {
                    std::cout << "Number of cards in CPU 2's hand: " << p2.getDeck().getNumberOfCards() << std::endl;
                    if (numPlay == 4) {
                        std::cout << "Number of cards in CPU 3's hand: " << p3.getDeck().getNumberOfCards() << std::endl;
                        std::cout << "Number of cards in CPU 4's hand: " << p4.getDeck().getNumberOfCards() << std::endl;
                    }
                } else {
                    std::cout << "Number of cards in Player 2's hand: " << p2.getDeck().getNumberOfCards() << std::endl;
                    if (numPlay == 4) {
                        std::cout << "Number of cards in Player 3's hand: " << p3.getDeck().getNumberOfCards() << std::endl;
                        std::cout << "Number of cards in Player 4's hand: " << p4.getDeck().getNumberOfCards() << std::endl;
                    }
                }
                if (p1.getDeck().hasPlayableCard(startingCard) == true) {
                    printPlayableCards(playableCards1,positions1);
                    if (p1.getDeck().getNumberOfCards() == 2) {
                        std::cout << "Tip: Now would be a good time to shout UNO." << std::endl;
                    }
                    deci = "";
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
                                std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                            }
                            deci2 = "";
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
                                if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILDTWISTER")) {
                                    chosen = "";
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
                                    if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                        startingCard.changeFaceCard(Face("DRAW4WILD"));
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                for (int i = 0; i < 4; i++) {
                                                    p2.drawCard();
                                                }
                                                displayEffect(p2,p2.getToken(),startingCard,playWith);
                                            } else {
                                                for (int i = 0; i < 4; i++) {
                                                    p4.drawCard();
                                                }
                                                displayEffect(p4,p4.getToken(),startingCard,playWith);
                                            }
                                            turn = 3;
                                        } else {
                                            for (int i = 0; i < 4; i++) {
                                                p2.drawCard();
                                            }
                                            displayEffect(p2,p2.getToken(),startingCard,playWith);
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
                                } else if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                    startingCard.changeColorCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getColorCard());
                                    startingCard.changeFaceCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard());
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            displayEffect(p2,p2.getToken(),startingCard,playWith);
                                        } else {
                                            displayEffect(p4,p4.getToken(),startingCard,playWith);
                                        }
                                        turn = 3;
                                    }
                                    if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                for (int i = 0; i < 2; i++) {
                                                    p2.drawCard();
                                                }
                                            } else {
                                                for (int i = 0; i < 2; i++) {
                                                    p4.drawCard();
                                                }
                                            }
                                            turn = 3;
                                        } else {
                                            for (int i = 0; i < 2; i++) {
                                                p2.drawCard();
                                            }
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
                        if (p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("WILD") == 0) {
                            chosen = "";
                            while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                std::cin >> chosen;
                                if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                    std::cout << "Invalid choice! ";
                                }
                            }
                            if(chosen.compare("R") == 0) {
                                startingCard.changeColorCard(Color("red"));
                            } else if (chosen.compare("Y") == 0) {
                                startingCard.changeColorCard(Color("yellow"));
                            } else if (chosen.compare("G") == 0) {
                                startingCard.changeColorCard(Color("green"));
                            } else {
                                startingCard.changeColorCard(Color("blue"));
                            }
                            makeWhiteSpace();
                            if (p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                startingCard.changeFaceCard(Face("DRAW4WILD"));
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        for (int i = 0; i < 4; i++) {
                                            p2.drawCard();
                                        }
                                        displayEffect(p2,p2.getToken(),startingCard,playWith);
                                    } else {
                                        for (int i = 0; i < 4; i++) {
                                            p4.drawCard();
                                        }
                                        displayEffect(p4,p4.getToken(),startingCard,playWith);
                                    }
                                    turn = 3;
                                } else {
                                    for (int i = 0; i < 4; i++) {
                                        p2.drawCard();
                                    }
                                    displayEffect(p2,p2.getToken(),startingCard,playWith);
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
                        } else if (p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW2") == 0 or p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("SKIP") == 0 or p1.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                            startingCard.changeColorCard(p1.getDeck().getCardAtPos(pos1-1).getColorCard());
                            startingCard.changeFaceCard(p1.getDeck().getCardAtPos(pos1-1).getFaceCard());
                            makeWhiteSpace();
                            if (numPlay == 4) {
                                if (clockwise == true) {
                                    displayEffect(p2,p2.getToken(),startingCard,playWith);
                                } else {
                                    displayEffect(p4,p4.getToken(),startingCard,playWith);
                                }
                                turn = 3;
                            }
                            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        for (int i = 0; i < 2; i++) {
                                            p2.drawCard();
                                        }
                                    } else {
                                        for (int i = 0; i < 2; i++) {
                                            p4.drawCard();
                                        }
                                    }
                                    turn = 3;
                                } else {
                                    for (int i = 0; i < 2; i++) {
                                        p2.drawCard();
                                    }
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
                    std::cout << "Card drew: ";
                    p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).printCard();
                    if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                        if (p1.getDeck().getNumberOfCards() == 2) {
                            std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                        }
                        deci2 = "";
                        while (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                            std::cout << "Type in PL to play, or PA to pass: ";
                            std::cin >> deci2;
                            if (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                std::cout << "Invalid choice! ";
                            }
                        }
                        if (deci2.compare("PL") == 0) {
                            if (p1.getDeck().getNumberOfCards() == 2) {
                                shoutedUno1 = true;
                            }
                            if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                chosen = "";
                                while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                    std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                    std::cin >> chosen;
                                    if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                        std::cout << "Invalid choice! ";
                                    }
                                }
                                if(chosen.compare("R") == 0) {
                                    startingCard.changeColorCard(Color("red"));
                                } else if (chosen.compare("Y") == 0) {
                                    startingCard.changeColorCard(Color("yellow"));
                                } else if (chosen.compare("G") == 0) {
                                    startingCard.changeColorCard(Color("green"));
                                } else {
                                    startingCard.changeColorCard(Color("blue"));
                                }
                                makeWhiteSpace();
                                std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                    startingCard.changeFaceCard(Face("DRAW4WILD"));
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            for (int i = 0; i < 4; i++) {
                                                p2.drawCard();
                                            }
                                            displayEffect(p2,p2.getToken(),startingCard,playWith);
                                        } else {
                                            for (int i = 0; i < 4; i++) {
                                                p4.drawCard();
                                            }
                                            displayEffect(p4,p4.getToken(),startingCard,playWith);
                                        }
                                        turn = 3;
                                    } else {
                                        for (int i = 0; i < 4; i++) {
                                            p2.drawCard();
                                        }
                                        displayEffect(p2,p2.getToken(),startingCard,playWith);
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
                            } else if (p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                startingCard.changeColorCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getColorCard());
                                startingCard.changeFaceCard(p1.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard());
                                makeWhiteSpace();
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        displayEffect(p2,p2.getToken(),startingCard,playWith);
                                    } else {
                                        displayEffect(p4,p4.getToken(),startingCard,playWith);
                                    }
                                    turn = 3;
                                }
                                if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            for (int i = 0; i < 2; i++) {
                                                p2.drawCard();
                                            }
                                        } else {
                                            for (int i = 0; i < 2; i++) {
                                                p4.drawCard();
                                            }
                                        }
                                        turn = 3;
                                    } else {
                                        for (int i = 0; i < 2; i++) {
                                            p2.drawCard();
                                        }
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
                }
                if (playedDrew == true) {
                    std::cout << "Card played: ";
                    startingCard.printCard();
                } else {
                    std::cout << "Current card: ";
                    startingCard.printCard();
                    playedDrew = true;
                }
            } else if (turn == 2){
                if (shoutedUno1 == true and c1 == 0) {
                    std::cout << "Player 1: UNO!" << std::endl;
                    c1++;
                } else if (p1.getDeck().getNumberOfCards() == 1 and shoutedUno1 == false) {
                    std::cout << "Player 1: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    for (int i = 0; i < 2; i++) {
                        p1.drawCard();
                    }
                }
                if (shoutedUno2 == true and c2 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 2: UNO!" << std::endl;
                    }
                    c2++;
                } else if (p2.getDeck().getNumberOfCards() == 1 and shoutedUno2 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 2: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p2.drawCard();
                    }
                }
                if (shoutedUno3 == true and c3 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 3: UNO!" << std::endl;
                    }
                    c3++;
                } else if (p3.getDeck().getNumberOfCards() == 1 and shoutedUno3 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 3: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p3.drawCard();
                    }
                }
                if (shoutedUno4 == true and c4 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 4: UNO!" << std::endl;
                    }
                    c4++;
                } else if (p4.getDeck().getNumberOfCards() == 1 and shoutedUno4 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 4: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p4.drawCard();
                    }
                }
                actioned = false;
                playableCards2 = getPlayableCards(p2.getDeck(),startingCard);
                positions2 = getPlayablePositions(p2.getDeck(),startingCard);
                cards1 = p1.getDeck().getCards();
                cards2 = p2.getDeck().getCards();
                cards3 = p3.getDeck().getCards();
                cards4 = p4.getDeck().getCards();
                cards1 = sort(cards1);
                cards2 = sort(cards2);
                cards3 = sort(cards3);
                cards4 = sort(cards4);
                Deck rep1(cards1);
                Player pla1(rep1,1,pt1,rounds1);
                Deck rep2(cards2);
                Player pla2(rep2,2,pt2,rounds2);
                Deck rep3(cards3);
                Player pla3(rep3,3,pt3,rounds3);
                Deck rep4(cards4);
                Player pla4(rep4,4,pt4,rounds4);
                p1 = pla1;
                p2 = pla2;
                p3 = pla3;
                p4 = pla4;
                if (playWith.compare("C") == 0) {
                    std::cout << "CPU 2's turn! " << std::endl;
                    if (p2.getDeck().hasPlayableCard(startingCard) == true) {
                        if (p2.getDeck().getNumberOfCards() == 2) {
                            shoutedUno2 = true;
                            c2 = 0;
                        }
                        int positioned = positionToRemoveCard(p2,positions2,p1);
                        if (p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("WILD") == 0) {
                            startingCard.changeColorCard(chooseColor(p2,startingCard));
                            if (p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                startingCard.changeFaceCard(Face("DRAW4WILD"));
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        for (int i = 0; i < 4; i++) {
                                            p3.drawCard();
                                        }
                                        displayEffect(p3,p3.getToken(),startingCard,playWith);
                                    } else {
                                        for (int i = 0; i < 4; i++) {
                                            p1.drawCard();
                                        }
                                        displayEffect(p1,p1.getToken(),startingCard,playWith);
                                    }
                                    turn = 4;
                                } else {
                                    for (int i = 0; i < 4; i++) {
                                        p1.drawCard();
                                    }
                                    displayEffect(p1,p1.getToken(),startingCard,playWith);
                                }
                            } else {
                                startingCard.changeFaceCard(Face("WILD"));
                                if (numPlay == 2 or clockwise == false) {
                                    turn = 1;
                                } else {
                                    turn = 3;
                                }
                            }
                            std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                        } else if (p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW2") == 0 or p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("SKIP") == 0 or p2.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                            startingCard.changeColorCard(p2.getDeck().getCardAtPos(positioned-1).getColorCard());
                            startingCard.changeFaceCard(p2.getDeck().getCardAtPos(positioned-1).getFaceCard());
                            if (numPlay == 4) {
                                if (clockwise == true) {
                                    displayEffect(p3,p3.getToken(),startingCard,playWith);
                                } else {
                                    displayEffect(p1,p1.getToken(),startingCard,playWith);
                                }
                                turn = 4;
                            }
                            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        for (int i = 0; i < 2; i++) {
                                            p3.drawCard();
                                        }
                                    } else {
                                        for (int i = 0; i < 2; i++) {
                                            p1.drawCard();
                                        }
                                    }
                                    turn = 4;
                                } else {
                                    for (int i = 0; i < 2; i++) {
                                        p1.drawCard();
                                    }
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
                    } else {
                        p2.drawCard();
                        c2++;
                        std::cout << "CPU 2 drew a card." << std::endl;
                        shoutedUno2 = false;
                        if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                            if (p2.getDeck().getNumberOfCards() == 2) {
                                shoutedUno2 = true;
                                c2 = 0;
                            }
                            if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                startingCard.changeColorCard(chooseColor(p2,startingCard));
                                std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                    startingCard.changeFaceCard(Face("DRAW4WILD"));
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            for (int i = 0; i < 4; i++) {
                                                p3.drawCard();
                                            }
                                            displayEffect(p3,p3.getToken(),startingCard,playWith);
                                        } else {
                                            for (int i = 0; i < 4; i++) {
                                                p1.drawCard();
                                            }
                                            displayEffect(p1,p1.getToken(),startingCard,playWith);
                                        }
                                        turn = 4;
                                    } else {
                                        for (int i = 0; i < 4; i++) {
                                            p1.drawCard();
                                        }
                                        displayEffect(p1,p1.getToken(),startingCard,playWith);
                                    }
                                } else {
                                    startingCard.changeFaceCard(Face("WILD"));
                                    if (clockwise == true and numPlay == 4) {
                                        turn = 3;
                                    } else {
                                        turn = 1;
                                    }
                                }
                            } else if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                startingCard.changeColorCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getColorCard());
                                startingCard.changeFaceCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard());
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        displayEffect(p3,p3.getToken(),startingCard,playWith);
                                    } else {
                                        displayEffect(p1,p1.getToken(),startingCard,playWith);
                                    }
                                    turn = 4;
                                }
                                if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            for (int i = 0; i < 2; i++) {
                                                p3.drawCard();
                                            }
                                        } else {
                                            for (int i = 0; i < 2; i++) {
                                                p1.drawCard();
                                            }
                                        }
                                        turn = 4;
                                    } else {
                                        for (int i = 0; i < 2; i++) {
                                            p1.drawCard();
                                        }
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
                } else {
                    std::cout << "Player 2's turn! " << std::endl;
                    while(true) {
                        std::cout << "Type CONT to continue. ";
                        std::string decision1 = "";
                        std::cin >> decision1;
                        if (decision1.compare("CONT") == 0) {
                            break;
                        }
                    }
                    p2.revealHand();
                    std::cout << "Number of cards in Player 1's hand: " << p1.getDeck().getNumberOfCards() << std::endl;
                    if (numPlay == 4) {
                        std::cout << "Number of cards in Player 3's hand: " << p3.getDeck().getNumberOfCards() << std::endl;
                        std::cout << "Number of cards in Player 4's hand: " << p4.getDeck().getNumberOfCards() << std::endl;
                    }
                    if (p2.getDeck().hasPlayableCard(startingCard) == true) {
                        printPlayableCards(playableCards2,positions2);
                        if (p2.getDeck().getNumberOfCards() == 2) {
                            std::cout << "Tip: Now would be a good time to shout UNO." << std::endl;
                        }
                        deci = "";
                        while ((deci.compare("U") == 0 and p1.getDeck().getNumberOfCards() != 2) or (deci.compare("D") != 0 and deci.compare("P") != 0)) {
                            std::cout << "Type in D to draw, or P to play (Type U to shout UNO when you play second to last card): ";
                            std::cin >> deci;
                            if ((deci.compare("U") == 0 and p1.getDeck().getNumberOfCards() != 2)) {
                                std::cout << "Tip: Type U to shout UNO when you play your second to last card. " << std::endl;
                            } else if (deci.compare("P") != 0 and deci.compare("D") != 0) {
                                std::cout << "Invalid choice made!" << std::endl;
                            }
                        }
                        if (deci.compare("U") == 0) {
                            shoutedUno2 = true;
                            while (deci.compare("D") != 0 and deci.compare("P") != 0) {
                                std::cout << "Type in D to draw, or P to play: ";
                                std::cin >> deci;
                                if (deci.compare("D") != 0 and deci.compare("P") != 0) {
                                    std::cout << "Invalid choice! ";
                                }
                            }
                        }
                        if (deci.compare("D") == 0) {
                            p2.drawCard();
                            std::cout << "Card drew: ";
                            shoutedUno2 = false;
                            c2 = 0;
                            p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).printCard();
                            if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                                if (p2.getDeck().getNumberOfCards() == 2) {
                                    std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                                }
                                deci2 = "";
                                while (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                    std::cout << "Type in PL to play, or PA to pass: ";
                                    std::cin >> deci2;
                                    if (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                        std::cout << "Invalid choice! ";
                                    }
                                }
                                if (deci2.compare("PL") == 0) {
                                    if (p2.getDeck().getNumberOfCards() == 2) {
                                        shoutedUno2 = true;
                                    }
                                    if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                        chosen = "";
                                        while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                            std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                            std::cin >> chosen;
                                            if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                                std::cout << "Invalid choice! ";
                                            }
                                        }
                                        if(chosen.compare("R") == 0) {
                                            startingCard.changeColorCard(Color("red"));
                                        } else if (chosen.compare("Y") == 0) {
                                            startingCard.changeColorCard(Color("yellow"));
                                        } else if (chosen.compare("G") == 0) {
                                            startingCard.changeColorCard(Color("green"));
                                        } else {
                                            startingCard.changeColorCard(Color("blue"));
                                        }
                                        makeWhiteSpace();
                                        if (p2.getDeck().getCardAtPos(p1.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                            startingCard.changeFaceCard(Face("DRAW4WILD"));
                                            if (numPlay == 4) {
                                                if (clockwise == true) {
                                                    for (int i = 0; i < 4; i++) {
                                                        p3.drawCard();
                                                    }
                                                    displayEffect(p3,p3.getToken(),startingCard,playWith);
                                                } else {
                                                    for (int i = 0; i < 4; i++) {
                                                        p1.drawCard();
                                                    }
                                                    displayEffect(p1,p1.getToken(),startingCard,playWith);
                                                }
                                                turn = 4;
                                            } else {
                                                for (int i = 0; i < 4; i++) {
                                                    p1.drawCard();
                                                }
                                                displayEffect(p1,p1.getToken(),startingCard,playWith);
                                            }
                                        } else {
                                            startingCard.changeFaceCard(Face("WILD"));
                                            if (clockwise == true or numPlay == 2) {
                                                turn = 3;
                                            } else {
                                                turn = 1;
                                            }
                                        }
                                        std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                    } else if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                        startingCard.changeColorCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getColorCard());
                                        startingCard.changeFaceCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard());
                                        makeWhiteSpace();
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                displayEffect(p3,p3.getToken(),startingCard,playWith);
                                            } else {
                                                displayEffect(p1,p1.getToken(),startingCard,playWith);
                                            }
                                            turn = 4;
                                        }
                                        if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                            if (numPlay == 4) {
                                                if (clockwise == true) {
                                                    for (int i = 0; i < 2; i++) {
                                                        p3.drawCard();
                                                    }
                                                } else {
                                                    for (int i = 0; i < 2; i++) {
                                                        p1.drawCard();
                                                    }
                                                }
                                                turn = 4;
                                            } else {
                                                for (int i = 0; i < 2; i++) {
                                                    p1.drawCard();
                                                }
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
                                    } else {
                                        startingCard.changeColorCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getColorCard());
                                        startingCard.changeFaceCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard());
                                        makeWhiteSpace();
                                        if (clockwise == false or numPlay == 2) {
                                            turn = 1;
                                        } else {
                                            turn = 3;
                                        }
                                    }
                                    p2.placeCard(p1.getDeck().getNumberOfCards()-1);
                                } else {
                                    makeWhiteSpace();
                                    if (clockwise == false or numPlay == 2) {
                                        turn = 1;
                                    } else {
                                        turn = 3;
                                    }
                                }
                            } else {
                                makeWhiteSpace();
                                if (clockwise == false or numPlay == 2) {
                                    turn = 1;
                                } else {
                                    turn = 3;
                                }
                            }
                        } else {
                            bool valid = false;
                            pos = "s";
                            while(isNumber(pos) == false or valid == false) {
                                std::cout << "Choose position of valid card to remove: ";
                                std::cin >> pos;
                                if (isNumber(pos) == false) {
                                    continue;
                                } else {
                                    int a = std::stoi(pos);
                                    if (p2.getDeck().getCardAtPos(a-1).isPlayable(startingCard) == true) {
                                        valid = true;
                                    } else {
                                        continue;
                                    }
                                }
                            }
                            int pos1 = std::stoi(pos);
                            if (p2.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p2.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("WILD") == 0) {
                                chosen = "";
                                while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                    std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                    std::cin >> chosen;
                                    if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                        std::cout << "Invalid choice! ";
                                    }
                                }
                                if(chosen.compare("R") == 0) {
                                    startingCard.changeColorCard(Color("red"));
                                } else if (chosen.compare("Y") == 0) {
                                    startingCard.changeColorCard(Color("yellow"));
                                } else if (chosen.compare("G") == 0) {
                                    startingCard.changeColorCard(Color("green"));
                                } else {
                                    startingCard.changeColorCard(Color("blue"));
                                }
                                makeWhiteSpace();
                                std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                if (p2.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                    startingCard.changeFaceCard(Face("DRAW4WILD"));
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            for (int i = 0; i < 4; i++) {
                                                p3.drawCard();
                                            }
                                            displayEffect(p3,p3.getToken(),startingCard,playWith);
                                        } else {
                                            for (int i = 0; i < 4; i++) {
                                                p1.drawCard();
                                            }
                                            displayEffect(p1,p1.getToken(),startingCard,playWith);
                                        }
                                        turn = 4;
                                    } else {
                                        for (int i = 0; i < 4; i++) {
                                            p1.drawCard();
                                        }
                                        displayEffect(p1,p1.getToken(),startingCard,playWith);
                                    }
                                } else {
                                    startingCard.changeFaceCard(Face("WILD"));
                                    if (clockwise == false or numPlay == 2) {
                                        turn = 1;
                                    } else {
                                        turn = 3;
                                    }
                                }
                            } else if (p2.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW2") == 0 or p2.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("SKIP") == 0 or p2.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                startingCard.changeColorCard(p2.getDeck().getCardAtPos(pos1-1).getColorCard());
                                startingCard.changeFaceCard(p2.getDeck().getCardAtPos(pos1-1).getFaceCard());
                                makeWhiteSpace();
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        displayEffect(p3,p3.getToken(),startingCard,playWith);
                                    } else {
                                        displayEffect(p1,p1.getToken(),startingCard,playWith);
                                    }
                                    turn = 4;
                                }
                                if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            for (int i = 0; i < 2; i++) {
                                                p3.drawCard();
                                            }
                                        } else {
                                            for (int i = 0; i < 2; i++) {
                                                p1.drawCard();
                                            }
                                        }
                                        turn = 4;
                                    } else {
                                        for (int i = 0; i < 2; i++) {
                                            p1.drawCard();
                                        }
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
                            } else {
                                if (clockwise == false or numPlay == 2) {
                                    turn = 1;
                                } else {
                                    turn = 3;
                                }
                                startingCard.changeColorCard(p2.getDeck().getCardAtPos(pos1-1).getColorCard());
                                startingCard.changeFaceCard(p2.getDeck().getCardAtPos(pos1-1).getFaceCard());
                                makeWhiteSpace();
                            }
                            p2.placeCard(pos1-1);
                        }
                    } else {
                        deci3 = "";
                        while (deci3.compare("D") != 0) {
                            std::cout << "Type D to draw. ";
                            std::cin >> deci3;
                            if (deci3.compare("D") != 0) {
                                std::cout << "Invalid choice! ";
                            }
                        }
                        p2.drawCard();
                        shoutedUno2 = false;
                        c2 = 0;
                        std::cout << "Card drew: ";
                        p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).printCard();
                        if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                            if (p2.getDeck().getNumberOfCards() == 2) {
                                std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                            }
                            deci2 = "";
                            while (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                std::cout << "Type in PL to play, or PA to pass: ";
                                std::cin >> deci2;
                                if (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                    std::cout << "Invalid choice! ";
                                }
                            }
                            if (deci2.compare("PL") == 0) {
                                if (p2.getDeck().getNumberOfCards() == 2) {
                                    shoutedUno2 = true;
                                }
                                if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                    chosen = "";
                                    while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                        std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                        std::cin >> chosen;
                                        if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                            std::cout << "Invalid choice! ";
                                        }
                                    }
                                    if(chosen.compare("R") == 0) {
                                        startingCard.changeColorCard(Color("red"));
                                    } else if (chosen.compare("Y") == 0) {
                                        startingCard.changeColorCard(Color("yellow"));
                                    } else if (chosen.compare("G") == 0) {
                                        startingCard.changeColorCard(Color("green"));
                                    } else {
                                        startingCard.changeColorCard(Color("blue"));
                                    }
                                    makeWhiteSpace();
                                    std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                    if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                        startingCard.changeFaceCard(Face("DRAW4WILD"));
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                for (int i = 0; i < 4; i++) {
                                                    p3.drawCard();
                                                }
                                                displayEffect(p3,p3.getToken(),startingCard,playWith);
                                            } else {
                                                for (int i = 0; i < 4; i++) {
                                                    p1.drawCard();
                                                }
                                                displayEffect(p1,p1.getToken(),startingCard,playWith);
                                            }
                                            turn = 4;
                                        } else {
                                            for (int i = 0; i < 4; i++) {
                                                p1.drawCard();
                                            }
                                            displayEffect(p1,p1.getToken(),startingCard,playWith);
                                        }
                                    } else {
                                        startingCard.changeFaceCard(Face("WILD"));
                                        if (numPlay == 2 or clockwise == false) {
                                            turn = 1;
                                        } else {
                                            turn = 3;
                                        }
                                    }
                                } else if (p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                    startingCard.changeColorCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getColorCard());
                                    startingCard.changeFaceCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard());
                                    makeWhiteSpace();
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            displayEffect(p3,p3.getToken(),startingCard,playWith);
                                        } else {
                                            displayEffect(p1,p1.getToken(),startingCard,playWith);
                                        }
                                        turn = 4;
                                    }
                                    if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                for (int i = 0; i < 2; i++) {
                                                    p3.drawCard();
                                                }
                                            } else {
                                                for (int i = 0; i < 2; i++) {
                                                    p1.drawCard();
                                                }
                                            }
                                            turn = 4;
                                        } else {
                                            for (int i = 0; i < 2; i++) {
                                                p1.drawCard();
                                            }
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
                                } else {
                                    makeWhiteSpace();
                                    startingCard.changeColorCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getColorCard());
                                    startingCard.changeFaceCard(p2.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).getFaceCard());
                                    if (clockwise == false or numPlay == 2) {
                                        turn = 1;
                                    } else {
                                        turn = 3;
                                    }
                                }
                                p2.placeCard(p2.getDeck().getNumberOfCards()-1);
                            } else {
                                makeWhiteSpace();
                                if (clockwise == false or numPlay == 2) {
                                    turn = 1;
                                } else {
                                    turn = 3;
                                }
                            }
                        } else {
                            makeWhiteSpace();
                            if (clockwise == false or numPlay == 2) {
                                turn = 1;
                            } else {
                                turn = 3;
                            }
                        }
                    }
                    if ((turn == 1 and p2.getDeck().getNumberOfCards() != 0) or turn != 2) {
                        makeWhiteSpace();
                        std::cout << "Card played: ";
                        startingCard.printCard();
                    }
                    if (turn == 2 and p2.getDeck().getNumberOfCards() != 0) {
                        makeWhiteSpace();
                    }
                }
            } else if (turn == 3) {
                if (actioned == true) {
                    makeWhiteSpace();
                }
                if (shoutedUno1 == true and c1 == 0) {
                    std::cout << "Player 1: UNO!" << std::endl;
                    c1++;
                } else if (p1.getDeck().getNumberOfCards() == 1 and shoutedUno1 == false) {
                    std::cout << "Player 1: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    for (int i = 0; i < 2; i++) {
                        p1.drawCard();
                    }
                }
                if (shoutedUno2 == true and c2 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 2: UNO!" << std::endl;
                    }
                    c2++;
                } else if (p2.getDeck().getNumberOfCards() == 1 and shoutedUno2 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 2: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p2.drawCard();
                    }
                }
                if (shoutedUno3 == true and c3 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 3: UNO!" << std::endl;
                    }
                    c3++;
                } else if (p3.getDeck().getNumberOfCards() == 1 and shoutedUno3 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 3: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p3.drawCard();
                    }
                }
                if (shoutedUno4 == true and c4 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 4: UNO!" << std::endl;
                    }
                    c4++;
                } else if (p4.getDeck().getNumberOfCards() == 1 and shoutedUno4 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 4: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p4.drawCard();
                    }
                }
                actioned = false;
                playableCards3 = getPlayableCards(p3.getDeck(),startingCard);
                positions3 = getPlayablePositions(p3.getDeck(),startingCard);
                cards1 = p1.getDeck().getCards();
                cards2 = p2.getDeck().getCards();
                cards3 = p3.getDeck().getCards();
                cards4 = p4.getDeck().getCards();
                cards1 = sort(cards1);
                cards2 = sort(cards2);
                cards3 = sort(cards3);
                cards4 = sort(cards4);
                Deck rep1(cards1);
                Player pla1(rep1,1,pt1,rounds1);
                Deck rep2(cards2);
                Player pla2(rep2,2,pt2,rounds2);
                Deck rep3(cards3);
                Player pla3(rep3,3,pt3,rounds3);
                Deck rep4(cards4);
                Player pla4(rep4,4,pt4,rounds4);
                p1 = pla1;
                p2 = pla2;
                p3 = pla3;
                p4 = pla4;
                if (playWith.compare("C") == 0) {
                    std::cout << "CPU 3's turn! " << std::endl;
                    if (p3.getDeck().hasPlayableCard(startingCard) == true) {
                        if (p3.getDeck().getNumberOfCards() == 2) {
                            shoutedUno3 = true;
                            c3 = 0;
                        }
                        int positioned = -1;
                        if (clockwise == true) {
                            positioned = positionToRemoveCard(p3,positions3,p4);
                        } else {
                            positioned = positionToRemoveCard(p3,positions3,p2);
                        }
                        if (p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("WILD") == 0) {
                            startingCard.changeColorCard(chooseColor(p3,startingCard));
                            if (p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                startingCard.changeFaceCard(Face("DRAW4WILD"));
                                if (clockwise == true) {
                                    for (int i = 0; i < 4; i++) {
                                        p4.drawCard();
                                    }
                                    displayEffect(p4,p4.getToken(),startingCard,playWith);
                                } else {
                                    for (int i = 0; i < 4; i++) {
                                        p2.drawCard();
                                    }
                                    displayEffect(p2,p2.getToken(),startingCard,playWith);
                                }
                                turn = 1;
                            } else {
                                startingCard.changeFaceCard(Face("WILD"));
                                if (clockwise == true) {
                                    turn = 4;
                                } else {
                                    turn = 2;
                                }
                            }
                            std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                        } else if (p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW2") == 0 or p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("SKIP") == 0 or p3.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                            startingCard.changeColorCard(p3.getDeck().getCardAtPos(positioned-1).getColorCard());
                            startingCard.changeFaceCard(p3.getDeck().getCardAtPos(positioned-1).getFaceCard());
                            if (clockwise == true) {
                                displayEffect(p4,p4.getToken(),startingCard,playWith);
                            } else {
                                displayEffect(p2,p2.getToken(),startingCard,playWith);
                            }
                            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                if (clockwise == true) {
                                    for (int i = 0; i < 2; i++) {
                                        p4.drawCard();
                                    }
                                } else {
                                    for (int i = 0; i < 2; i++) {
                                        p2.drawCard();
                                    }
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
                    } else {
                        p3.drawCard();
                        c3++;
                        std::cout << "CPU 3 drew a card." << std::endl;
                        shoutedUno2 = false;
                        if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                            if (p3.getDeck().getNumberOfCards() == 2) {
                                shoutedUno3 = true;
                                c3 = 0;
                            }
                            if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                startingCard.changeColorCard(chooseColor(p3,startingCard));
                                std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                    startingCard.changeFaceCard(Face("DRAW4WILD"));
                                    if (clockwise == true) {
                                        for (int i = 0; i < 4; i++) {
                                            p4.drawCard();
                                        }
                                        displayEffect(p4,p4.getToken(),startingCard,playWith);
                                    } else {
                                        for (int i = 0; i < 4; i++) {
                                            p2.drawCard();
                                        }
                                        displayEffect(p2,p2.getToken(),startingCard,playWith);
                                    }
                                    turn = 1;
                                } else {
                                    startingCard.changeFaceCard(Face("WILD"));
                                    if (clockwise == true) {
                                        turn = 4;
                                    } else {
                                        turn = 2;
                                    }
                                }
                            } else if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                startingCard.changeColorCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getColorCard());
                                startingCard.changeFaceCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard());
                                if (clockwise == true) {
                                    displayEffect(p4,p4.getToken(),startingCard,playWith);
                                } else {
                                    displayEffect(p2,p2.getToken(),startingCard,playWith);
                                }
                                if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                    if (clockwise == true) {
                                        for (int i = 0; i < 2; i++) {
                                            p4.drawCard();
                                        }
                                    } else {
                                        for (int i = 0; i < 2; i++) {
                                            p2.drawCard();
                                        }
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
                } else {
                    std::cout << "Player 3's turn! " << std::endl;
                    while(true) {
                        std::cout << "Type CONT to continue. ";
                        std::string decision1 = "";
                        std::cin >> decision1;
                        if (decision1.compare("CONT") == 0) {
                            break;
                        }
                    }
                    p1.revealHand();
                    std::cout << "Number of cards in Player 1's hand: " << p1.getDeck().getNumberOfCards() << std::endl;
                    p2.revealHand();
                    std::cout << "Number of cards in Player 2's hand: " << p2.getDeck().getNumberOfCards() << std::endl;
                    p4.revealHand();
                    std::cout << "Number of cards in Player 4's hand: " << p4.getDeck().getNumberOfCards() << std::endl;
                    if (p3.getDeck().hasPlayableCard(startingCard) == true) {
                        printPlayableCards(playableCards3,positions3);
                        if (p3.getDeck().getNumberOfCards() == 2) {
                            std::cout << "Tip: Now would be a good time to shout UNO." << std::endl;
                        }
                        deci = "";
                        while ((deci.compare("U") == 0 and p3.getDeck().getNumberOfCards() != 2) or (deci.compare("D") != 0 and deci.compare("P") != 0)) {
                            std::cout << "Type in D to draw, or P to play (Type U to shout UNO when you play second to last card): ";
                            std::cin >> deci;
                            if ((deci.compare("U") == 0 and p3.getDeck().getNumberOfCards() != 2)) {
                                std::cout << "Tip: Type U to shout UNO when you play your second to last card. " << std::endl;
                            } else if (deci.compare("P") != 0 and deci.compare("D") != 0) {
                                std::cout << "Invalid choice made!" << std::endl;
                            }
                        }
                        if (deci.compare("U") == 0) {
                            shoutedUno3 = true;
                            while (deci.compare("D") != 0 and deci.compare("P") != 0) {
                                std::cout << "Type in D to draw, or P to play: ";
                                std::cin >> deci;
                                if (deci.compare("D") != 0 and deci.compare("P") != 0) {
                                    std::cout << "Invalid choice! ";
                                }
                            }
                        }
                        if (deci.compare("D") == 0) {
                            p3.drawCard();
                            std::cout << "Card drew: ";
                            shoutedUno3 = false;
                            c3 = 0;
                            p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).printCard();
                            if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                                if (p3.getDeck().getNumberOfCards() == 2) {
                                    std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                                }
                                deci2 = "";
                                while (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                    std::cout << "Type in PL to play, or PA to pass: ";
                                    std::cin >> deci2;
                                    if (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                        std::cout << "Invalid choice! ";
                                    }
                                }
                                if (deci2.compare("PL") == 0) {
                                    if (p3.getDeck().getNumberOfCards() == 2) {
                                        shoutedUno3 = true;
                                    }
                                    if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                        chosen = "";
                                        while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                            std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                            std::cin >> chosen;
                                            if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                                std::cout << "Invalid choice! ";
                                            }
                                        }
                                        if(chosen.compare("R") == 0) {
                                            startingCard.changeColorCard(Color("red"));
                                        } else if (chosen.compare("Y") == 0) {
                                            startingCard.changeColorCard(Color("yellow"));
                                        } else if (chosen.compare("G") == 0) {
                                            startingCard.changeColorCard(Color("green"));
                                        } else {
                                            startingCard.changeColorCard(Color("blue"));
                                        }
                                        makeWhiteSpace();
                                        if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                            startingCard.changeFaceCard(Face("DRAW4WILD"));
                                            if (clockwise == true) {
                                                for (int i = 0; i < 4; i++) {
                                                    p4.drawCard();
                                                }
                                                displayEffect(p4,p4.getToken(),startingCard,playWith);
                                            } else {
                                                for (int i = 0; i < 4; i++) {
                                                    p2.drawCard();
                                                }
                                                displayEffect(p2,p2.getToken(),startingCard,playWith);
                                            }
                                            turn = 1;
                                        } else {
                                            startingCard.changeFaceCard(Face("WILD"));
                                            if (clockwise == true) {
                                                turn = 4;
                                            } else {
                                                turn = 2;
                                            }
                                        }
                                        std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                    } else if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                        startingCard.changeColorCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getColorCard());
                                        startingCard.changeFaceCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard());
                                        makeWhiteSpace();
                                            if (clockwise == true) {
                                                displayEffect(p4,p4.getToken(),startingCard,playWith);
                                            } else {
                                                displayEffect(p2,p2.getToken(),startingCard,playWith);
                                            }
                                        if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                            if (clockwise == true) {
                                                for (int i = 0; i < 2; i++) {
                                                    p4.drawCard();
                                                }
                                            } else {
                                                for (int i = 0; i < 2; i++) {
                                                    p2.drawCard();
                                                }
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
                                    } else {
                                        startingCard.changeColorCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getColorCard());
                                        startingCard.changeFaceCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard());
                                        makeWhiteSpace();
                                        if (clockwise == false) {
                                            turn = 2;
                                        } else {
                                            turn = 4;
                                        }
                                    }
                                    p3.placeCard(p3.getDeck().getNumberOfCards()-1);
                                } else {
                                    makeWhiteSpace();
                                    if (clockwise == false) {
                                        turn = 2;
                                    } else {
                                        turn = 4;
                                    }
                                }
                            } else {
                                makeWhiteSpace();
                                if (clockwise == false) {
                                    turn = 2;
                                } else {
                                    turn = 4;
                                }
                            }
                        } else {
                            bool valid = false;
                            pos = "s";
                            while(isNumber(pos) == false or valid == false) {
                                std::cout << "Choose position of valid card to remove: ";
                                std::cin >> pos;
                                if (isNumber(pos) == false) {
                                    continue;
                                } else {
                                    int a = std::stoi(pos);
                                    if (p3.getDeck().getCardAtPos(a-1).isPlayable(startingCard) == true) {
                                        valid = true;
                                    } else {
                                        continue;
                                    }
                                }
                            }
                            int pos1 = std::stoi(pos);
                            if (p3.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p3.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("WILD") == 0) {
                                chosen = "";
                                while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                    std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                    std::cin >> chosen;
                                    if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                        std::cout << "Invalid choice! ";
                                    }
                                }
                                if(chosen.compare("R") == 0) {
                                    startingCard.changeColorCard(Color("red"));
                                } else if (chosen.compare("Y") == 0) {
                                    startingCard.changeColorCard(Color("yellow"));
                                } else if (chosen.compare("G") == 0) {
                                    startingCard.changeColorCard(Color("green"));
                                } else {
                                    startingCard.changeColorCard(Color("blue"));
                                }
                                makeWhiteSpace();
                                std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                if (p3.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                    startingCard.changeFaceCard(Face("DRAW4WILD"));
                                    if (clockwise == true) {
                                        for (int i = 0; i < 4; i++) {
                                            p4.drawCard();
                                        }
                                        displayEffect(p4,p4.getToken(),startingCard,playWith);
                                    } else {
                                        for (int i = 0; i < 4; i++) {
                                            p2.drawCard();
                                        }
                                        displayEffect(p2,p2.getToken(),startingCard,playWith);
                                    }
                                } else {
                                    startingCard.changeFaceCard(Face("WILD"));
                                    if (clockwise == false) {
                                        turn = 2;
                                    } else {
                                        turn = 4;
                                    }
                                }
                            } else if (p3.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW2") == 0 or p3.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("SKIP") == 0 or p3.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                startingCard.changeColorCard(p3.getDeck().getCardAtPos(pos1-1).getColorCard());
                                startingCard.changeFaceCard(p3.getDeck().getCardAtPos(pos1-1).getFaceCard());
                                makeWhiteSpace();
                                if (clockwise == true) {
                                    displayEffect(p4,p4.getToken(),startingCard,playWith);
                                } else {
                                    displayEffect(p2,p2.getToken(),startingCard,playWith);
                                }
                                if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                    if (clockwise == true) {
                                        for (int i = 0; i < 2; i++) {
                                            p4.drawCard();
                                        }
                                    } else {
                                        for (int i = 0; i < 2; i++) {
                                            p2.drawCard();
                                        }
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
                            } else {
                                makeWhiteSpace();
                                if (clockwise == false) {
                                    turn = 2;
                                } else {
                                    turn = 4;
                                }
                                startingCard.changeColorCard(p3.getDeck().getCardAtPos(pos1-1).getColorCard());
                                startingCard.changeFaceCard(p3.getDeck().getCardAtPos(pos1-1).getFaceCard());
                            }
                            p3.placeCard(pos1-1);
                        }
                    } else {
                        deci3 = "";
                        while (deci3.compare("D") != 0) {
                            std::cout << "Type D to draw. ";
                            std::cin >> deci3;
                            if (deci3.compare("D") != 0) {
                                std::cout << "Invalid choice! ";
                            }
                        }
                        p3.drawCard();
                        shoutedUno3 = false;
                        c3 = 0;
                        std::cout << "Card drew: ";
                        p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).printCard();
                        if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                            if (p3.getDeck().getNumberOfCards() == 2) {
                                std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                            }
                            deci3 = "";
                            while (deci3.compare("PL") != 0 and deci3.compare("PA") != 0) {
                                std::cout << "Type in PL to play, or PA to pass: ";
                                std::cin >> deci3;
                                if (deci3.compare("PL") != 0 and deci3.compare("PA") != 0) {
                                    std::cout << "Invalid choice! ";
                                }
                            }
                            if (deci3.compare("PL") == 0) {
                                if (p3.getDeck().getNumberOfCards() == 2) {
                                    shoutedUno3 = true;
                                }
                                if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                    chosen = "";
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
                                    if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                        startingCard.changeFaceCard(Face("DRAW4WILD"));
                                        if (clockwise == true) {
                                            for (int i = 0; i < 4; i++) {
                                                p4.drawCard();
                                            }
                                            displayEffect(p4,p4.getToken(),startingCard,playWith);
                                        } else {
                                            for (int i = 0; i < 4; i++) {
                                                p2.drawCard();
                                            }
                                            displayEffect(p2,p2.getToken(),startingCard,playWith);
                                        }
                                        turn = 1;
                                    } else {
                                        startingCard.changeFaceCard(Face("WILD"));
                                        if (clockwise == false) {
                                            turn = 2;
                                        } else {
                                            turn = 4;
                                        }
                                    }
                                } else if (p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                    startingCard.changeColorCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getColorCard());
                                    startingCard.changeFaceCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard());
                                    makeWhiteSpace();
                                    if (clockwise == true) {
                                        displayEffect(p4,p4.getToken(),startingCard,playWith);
                                    } else {
                                        displayEffect(p2,p2.getToken(),startingCard,playWith);
                                    }
                                    if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                        if (clockwise == true) {
                                            for (int i = 0; i < 2; i++) {
                                                p4.drawCard();
                                            }
                                        } else {
                                            for (int i = 0; i < 2; i++) {
                                                p2.drawCard();
                                            }
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
                                } else {
                                    startingCard.changeColorCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getColorCard());
                                    startingCard.changeFaceCard(p3.getDeck().getCardAtPos(p3.getDeck().getNumberOfCards()-1).getFaceCard());
                                    makeWhiteSpace();
                                    if (clockwise == false) {
                                        turn = 2;
                                    } else {
                                        turn = 4;
                                    }
                                }
                                p3.placeCard(p3.getDeck().getNumberOfCards()-1);
                            } else {
                                makeWhiteSpace();
                                if (clockwise == false) {
                                    turn = 2;
                                } else {
                                    turn = 4;
                                }
                            }
                        } else {
                            makeWhiteSpace();
                            if (clockwise == false) {
                                turn = 2;
                            } else {
                                turn = 4;
                            }
                        }
                    }
                    if ((turn == 1 and p3.getDeck().getNumberOfCards() != 0) or turn != 3) {
                        makeWhiteSpace();
                        std::cout << "Card played: ";
                        startingCard.printCard();
                    }
                }
            } else {
                if (shoutedUno1 == true and c1 == 0) {
                    std::cout << "Player 1: UNO!" << std::endl;
                    c1++;
                } else if (p1.getDeck().getNumberOfCards() == 1 and shoutedUno1 == false) {
                    std::cout << "Player 1: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    for (int i = 0; i < 2; i++) {
                        p1.drawCard();
                    }
                }
                if (shoutedUno2 == true and c2 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 2: UNO!" << std::endl;
                    }
                    c2++;
                } else if (p2.getDeck().getNumberOfCards() == 1 and shoutedUno2 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 2: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p2.drawCard();
                    }
                }
                if (shoutedUno3 == true and c3 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 3: UNO!" << std::endl;
                    }
                    c3++;
                } else if (p3.getDeck().getNumberOfCards() == 1 and shoutedUno3 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 3: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p3.drawCard();
                    }
                }
                if (shoutedUno4 == true and c4 == 0) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4: UNO!" << std::endl;
                    } else {
                        std::cout << "Player 4: UNO!" << std::endl;
                    }
                    c4++;
                } else if (p4.getDeck().getNumberOfCards() == 1 and shoutedUno4 == false) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    } else {
                        std::cout << "Player 4: Missed UNO shout. DRAW 2 CARDS!" << std::endl;
                    }
                    for (int i = 0; i < 2; i++) {
                        p4.drawCard();
                    }
                }
                actioned = false;
                playableCards4 = getPlayableCards(p4.getDeck(),startingCard);
                positions4 = getPlayablePositions(p4.getDeck(),startingCard);
                cards1 = p1.getDeck().getCards();
                cards2 = p2.getDeck().getCards();
                cards3 = p3.getDeck().getCards();
                cards4 = p4.getDeck().getCards();
                cards1 = sort(cards1);
                cards2 = sort(cards2);
                cards3 = sort(cards3);
                cards4 = sort(cards4);
                Deck rep1(cards1);
                Player pla1(rep1,1,pt1,rounds1);
                Deck rep2(cards2);
                Player pla2(rep2,2,pt2,rounds2);
                Deck rep3(cards3);
                Player pla3(rep3,3,pt3,rounds3);
                Deck rep4(cards4);
                Player pla4(rep4,4,pt4,rounds4);
                p1 = pla1;
                p2 = pla2;
                p3 = pla3;
                p4 = pla4;
                if (playWith.compare("C") == 0) {
                    std::cout << "CPU 4's turn! " << std::endl;
                    if (p4.getDeck().hasPlayableCard(startingCard) == true) {
                        if (p4.getDeck().getNumberOfCards() == 2) {
                            shoutedUno4 = true;
                            c4 = 0;
                        }
                        int positioned = -1;
                        if (clockwise == true) {
                            positioned = positionToRemoveCard(p4,positions4,p1);
                        } else {
                            positioned = positionToRemoveCard(p4,positions4,p3);
                        }
                        if (p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("WILD") == 0) {
                            startingCard.changeColorCard(chooseColor(p2,startingCard));
                            if (p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                startingCard.changeFaceCard(Face("DRAW4WILD"));
                                if (clockwise == true) {
                                    for (int i = 0; i < 4; i++) {
                                        p1.drawCard();
                                    }
                                    displayEffect(p1,p1.getToken(),startingCard,playWith);
                                } else {
                                    for (int i = 0; i < 4; i++) {
                                        p3.drawCard();
                                    }
                                    displayEffect(p3,p3.getToken(),startingCard,playWith);
                                }
                                turn = 2;
                            } else {
                                startingCard.changeFaceCard(Face("WILD"));
                                if (clockwise == false) {
                                    turn = 3;
                                } else {
                                    turn = 1;
                                }
                            }
                            std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                        } else if (p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("DRAW2") == 0 or p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("SKIP") == 0 or p4.getDeck().getCardAtPos(positioned-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                            startingCard.changeColorCard(p4.getDeck().getCardAtPos(positioned-1).getColorCard());
                            startingCard.changeFaceCard(p4.getDeck().getCardAtPos(positioned-1).getFaceCard());
                            if (clockwise == true) {
                                displayEffect(p1,p1.getToken(),startingCard,playWith);
                            } else {
                                displayEffect(p3,p3.getToken(),startingCard,playWith);
                            }
                            if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                if (clockwise == true) {
                                    for (int i = 0; i < 2; i++) {
                                        p1.drawCard();
                                    }
                                } else {
                                    for (int i = 0; i < 2; i++) {
                                        p3.drawCard();
                                    }
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
                    } else {
                        p4.drawCard();
                        c4++;
                        std::cout << "CPU 4 drew a card." << std::endl;
                        shoutedUno4 = false;
                        if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                            if (p4.getDeck().getNumberOfCards() == 2) {
                                shoutedUno4 = true;
                                c4 = 0;
                            }
                            if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                startingCard.changeColorCard(chooseColor(p4,startingCard));
                                std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                    startingCard.changeFaceCard(Face("DRAW4WILD"));
                                    if (clockwise == true) {
                                        for (int i = 0; i < 4; i++) {
                                            p1.drawCard();
                                        }
                                        displayEffect(p1,p1.getToken(),startingCard,playWith);
                                    } else {
                                        for (int i = 0; i < 4; i++) {
                                            p3.drawCard();
                                        }
                                        displayEffect(p3,p3.getToken(),startingCard,playWith);
                                    }
                                    turn = 2;
                                } else {
                                    startingCard.changeFaceCard(Face("WILD"));
                                    if (clockwise == true) {
                                        turn = 1;
                                    } else {
                                        turn = 3;
                                    }
                                }
                            } else if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                startingCard.changeColorCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getColorCard());
                                startingCard.changeFaceCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard());
                                if (clockwise == true) {
                                    displayEffect(p1,p1.getToken(),startingCard,playWith);
                                } else {
                                    displayEffect(p4,p4.getToken(),startingCard,playWith);
                                }
                                if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                    if (clockwise == true) {
                                        for (int i = 0; i < 2; i++) {
                                            p1.drawCard();
                                        }
                                    } else {
                                        for (int i = 0; i < 2; i++) {
                                            p3.drawCard();
                                        }
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
                } else {
                    std::cout << "Player 4's turn! " << std::endl;
                    while(true) {
                        std::cout << "Type CONT to continue. ";
                        std::string decision1 = "";
                        std::cin >> decision1;
                        if (decision1.compare("CONT") == 0) {
                            break;
                        }
                    }
                    p1.revealHand();
                    std::cout << "Number of cards in Player 1's hand: " << p1.getDeck().getNumberOfCards() << std::endl;
                    p2.revealHand();
                    std::cout << "Number of cards in Player 2's hand: " << p2.getDeck().getNumberOfCards() << std::endl;
                    p3.revealHand();
                    std::cout << "Number of cards in Player 3's hand: " << p3.getDeck().getNumberOfCards() << std::endl;
                    if (p4.getDeck().hasPlayableCard(startingCard) == true) {
                        printPlayableCards(playableCards4,positions4);
                        if (p4.getDeck().getNumberOfCards() == 2) {
                            std::cout << "Tip: Now would be a good time to shout UNO." << std::endl;
                        }
                        deci = "";
                        while ((deci.compare("U") == 0 and p4.getDeck().getNumberOfCards() != 2) or (deci.compare("D") != 0 and deci.compare("P") != 0)) {
                            std::cout << "Type in D to draw, or P to play (Type U to shout UNO when you play second to last card): ";
                            std::cin >> deci;
                            if ((deci.compare("U") == 0 and p4.getDeck().getNumberOfCards() != 2)) {
                                std::cout << "Tip: Type U to shout UNO when you play your second to last card. " << std::endl;
                            } else if (deci.compare("P") != 0 and deci.compare("D") != 0) {
                                std::cout << "Invalid choice made!" << std::endl;
                            }
                        }
                        if (deci.compare("U") == 0) {
                            shoutedUno4 = true;
                            while (deci.compare("D") != 0 and deci.compare("P") != 0) {
                                std::cout << "Type in D to draw, or P to play: ";
                                std::cin >> deci;
                                if (deci.compare("D") != 0 and deci.compare("P") != 0) {
                                    std::cout << "Invalid choice! ";
                                }
                            }
                        }
                        if (deci.compare("D") == 0) {
                            p4.drawCard();
                            std::cout << "Card drew: ";
                            shoutedUno4 = false;
                            c4 = 0;
                            p4.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).printCard();
                            if (p4.getDeck().getCardAtPos(p2.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                                if (p4.getDeck().getNumberOfCards() == 2) {
                                    std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                                }
                                deci2 = "";
                                while (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                    std::cout << "Type in PL to play, or PA to pass: ";
                                    std::cin >> deci2;
                                    if (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                        std::cout << "Invalid choice! ";
                                    }
                                }
                                if (deci2.compare("PL") == 0) {
                                    if (p4.getDeck().getNumberOfCards() == 2) {
                                        shoutedUno2 = true;
                                    }
                                    if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                        chosen = "";
                                        while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                            std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                            std::cin >> chosen;
                                            if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                                std::cout << "Invalid choice! ";
                                            }
                                        }
                                        if(chosen.compare("R") == 0) {
                                            startingCard.changeColorCard(Color("red"));
                                        } else if (chosen.compare("Y") == 0) {
                                            startingCard.changeColorCard(Color("yellow"));
                                        } else if (chosen.compare("G") == 0) {
                                            startingCard.changeColorCard(Color("green"));
                                        } else {
                                            startingCard.changeColorCard(Color("blue"));
                                        }
                                        makeWhiteSpace();
                                        if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                            startingCard.changeFaceCard(Face("DRAW4WILD"));
                                            if (numPlay == 4) {
                                                if (clockwise == true) {
                                                    for (int i = 0; i < 4; i++) {
                                                        p3.drawCard();
                                                    }
                                                    displayEffect(p3,p3.getToken(),startingCard,playWith);
                                                } else {
                                                    for (int i = 0; i < 4; i++) {
                                                        p1.drawCard();
                                                    }
                                                    displayEffect(p1,p1.getToken(),startingCard,playWith);
                                                }
                                                turn = 2;
                                            } else {
                                                for (int i = 0; i < 4; i++) {
                                                    p1.drawCard();
                                                }
                                                displayEffect(p1,p1.getToken(),startingCard,playWith);
                                            }
                                        } else {
                                            startingCard.changeFaceCard(Face("WILD"));
                                            if (clockwise == true or numPlay == 2) {
                                                turn = 3;
                                            } else {
                                                turn = 1;
                                            }
                                        }
                                        std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                    } else if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                        makeWhiteSpace();
                                        startingCard.changeColorCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getColorCard());
                                        startingCard.changeFaceCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard());
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                displayEffect(p3,p3.getToken(),startingCard,playWith);
                                            } else {
                                                displayEffect(p1,p1.getToken(),startingCard,playWith);
                                            }
                                            turn = 4;
                                        }
                                        if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                            if (numPlay == 4) {
                                                if (clockwise == true) {
                                                    for (int i = 0; i < 2; i++) {
                                                        p3.drawCard();
                                                    }
                                                } else {
                                                    for (int i = 0; i < 2; i++) {
                                                        p1.drawCard();
                                                    }
                                                }
                                                turn = 2;
                                            } else {
                                                for (int i = 0; i < 2; i++) {
                                                    p1.drawCard();
                                                }
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
                                                turn = 2;
                                            }
                                        }
                                    } else {
                                        makeWhiteSpace();
                                        startingCard.changeColorCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getColorCard());
                                        startingCard.changeFaceCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard());
                                        if (clockwise == false or numPlay == 2) {
                                            turn = 1;
                                        } else {
                                            turn = 3;
                                        }
                                    }
                                    p4.placeCard(p4.getDeck().getNumberOfCards()-1);
                                } else {
                                    makeWhiteSpace();
                                    if (clockwise == false or numPlay == 2) {
                                        turn = 1;
                                    } else {
                                        turn = 3;
                                    }
                                }
                            } else {
                                makeWhiteSpace();
                                if (clockwise == false or numPlay == 2) {
                                    turn = 1;
                                } else {
                                    turn = 3;
                                }
                            }
                        } else {
                            bool valid = false;
                            pos = "s";
                            while(isNumber(pos) == false or valid == false) {
                                std::cout << "Choose position of valid card to remove: ";
                                std::cin >> pos;
                                if (isNumber(pos) == false) {
                                    continue;
                                } else {
                                    int a = std::stoi(pos);
                                    if (p4.getDeck().getCardAtPos(a-1).isPlayable(startingCard) == true) {
                                        valid = true;
                                    } else {
                                        continue;
                                    }
                                }
                            }
                            int pos1 = std::stoi(pos);
                            if (p4.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p4.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("WILD") == 0) {
                                chosen = "";
                                while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                    std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                    std::cin >> chosen;
                                    if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                        std::cout << "Invalid choice! ";
                                    }
                                }
                                if(chosen.compare("R") == 0) {
                                    startingCard.changeColorCard(Color("red"));
                                } else if (chosen.compare("Y") == 0) {
                                    startingCard.changeColorCard(Color("yellow"));
                                } else if (chosen.compare("G") == 0) {
                                    startingCard.changeColorCard(Color("green"));
                                } else {
                                    startingCard.changeColorCard(Color("blue"));
                                }
                                makeWhiteSpace();
                                std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                if (p4.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                    startingCard.changeFaceCard(Face("DRAW4WILD"));
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            for (int i = 0; i < 4; i++) {
                                                p3.drawCard();
                                            }
                                            displayEffect(p3,p3.getToken(),startingCard,playWith);
                                        } else {
                                            for (int i = 0; i < 4; i++) {
                                                p1.drawCard();
                                            }
                                            displayEffect(p1,p1.getToken(),startingCard,playWith);
                                        }
                                        turn = 2;
                                    } else {
                                        for (int i = 0; i < 4; i++) {
                                            p1.drawCard();
                                        }
                                        displayEffect(p1,p1.getToken(),startingCard,playWith);
                                    }
                                } else {
                                    startingCard.changeFaceCard(Face("WILD"));
                                    if (clockwise == false or numPlay == 2) {
                                        turn = 1;
                                    } else {
                                        turn = 3;
                                    }
                                }
                            } else if (p4.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("DRAW2") == 0 or p4.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("SKIP") == 0 or p4.getDeck().getCardAtPos(pos1-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                startingCard.changeColorCard(p4.getDeck().getCardAtPos(pos1-1).getColorCard());
                                startingCard.changeFaceCard(p4.getDeck().getCardAtPos(pos1-1).getFaceCard());
                                makeWhiteSpace();
                                if (numPlay == 4) {
                                    if (clockwise == true) {
                                        displayEffect(p3,p3.getToken(),startingCard,playWith);
                                    } else {
                                        displayEffect(p1,p1.getToken(),startingCard,playWith);
                                    }
                                    turn = 2;
                                }
                                if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            for (int i = 0; i < 2; i++) {
                                                p3.drawCard();
                                            }
                                        } else {
                                            for (int i = 0; i < 2; i++) {
                                                p1.drawCard();
                                            }
                                        }
                                        turn = 4;
                                    } else {
                                        for (int i = 0; i < 2; i++) {
                                            p1.drawCard();
                                        }
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
                            } else {
                                makeWhiteSpace();
                                if (clockwise == false or numPlay == 2) {
                                    turn = 1;
                                } else {
                                    turn = 3;
                                }
                                startingCard.changeColorCard(p4.getDeck().getCardAtPos(pos1-1).getColorCard());
                                startingCard.changeFaceCard(p4.getDeck().getCardAtPos(pos1-1).getFaceCard());
                            }
                            p4.placeCard(pos1-1);
                        }
                    } else {
                        deci3 = "";
                        while (deci3.compare("D") != 0) {
                            std::cout << "Type D to draw. ";
                            std::cin >> deci3;
                            if (deci3.compare("D") != 0) {
                                std::cout << "Invalid choice! ";
                            }
                        }
                        p4.drawCard();
                        shoutedUno4 = false;
                        c4 = 0;
                        std::cout << "Card drew: ";
                        p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).printCard();
                        if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).isPlayable(startingCard)) {
                            if (p4.getDeck().getNumberOfCards() == 2) {
                                std::cout << "Tip: Playing this card will shout UNO automatically for you. " << std::endl;
                            }
                            deci2 = "";
                            while (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                std::cout << "Type in PL to play, or PA to pass: ";
                                std::cin >> deci2;
                                if (deci2.compare("PL") != 0 and deci2.compare("PA") != 0) {
                                    std::cout << "Invalid choice! ";
                                }
                            }
                            if (deci2.compare("PL") == 0) {
                                if (p4.getDeck().getNumberOfCards() == 2) {
                                    shoutedUno2 = true;
                                }
                                if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("WILD") == 0) {
                                    chosen = "";
                                    while (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                        std::cout << "Please choose a color(R for red, Y for yellow, G for green, B for blue): ";
                                        std::cin >> chosen;
                                        if (chosen.compare("R") != 0 and chosen.compare("Y") != 0 and chosen.compare("G") != 0 and chosen.compare("B") != 0) {
                                            std::cout << "Invalid choice! ";
                                        }
                                    }
                                    if(chosen.compare("R") == 0) {
                                        startingCard.changeColorCard(Color("red"));
                                    } else if (chosen.compare("Y") == 0) {
                                        startingCard.changeColorCard(Color("yellow"));
                                    } else if (chosen.compare("G") == 0) {
                                        startingCard.changeColorCard(Color("green"));
                                    } else {
                                        startingCard.changeColorCard(Color("blue"));
                                    }
                                    makeWhiteSpace();
                                    std::cout << "Color changed to: " << startingCard.getColorCard().getColor() << std::endl;
                                    if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW4WILD") == 0) {
                                        startingCard.changeFaceCard(Face("DRAW4WILD"));
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                for (int i = 0; i < 4; i++) {
                                                    p3.drawCard();
                                                }
                                                displayEffect(p3,p3.getToken(),startingCard,playWith);
                                            } else {
                                                for (int i = 0; i < 4; i++) {
                                                    p1.drawCard();
                                                }
                                                displayEffect(p1,p1.getToken(),startingCard,playWith);
                                            }
                                            turn = 2;
                                        } else {
                                            for (int i = 0; i < 4; i++) {
                                                p1.drawCard();
                                            }
                                            displayEffect(p1,p1.getToken(),startingCard,playWith);
                                        }
                                    } else {
                                        startingCard.changeFaceCard(Face("WILD"));
                                        if (numPlay == 2 or clockwise == false) {
                                            turn = 1;
                                        } else {
                                            turn = 3;
                                        }
                                    }
                                } else if (p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("DRAW2") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("SKIP") == 0 or p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard().getFace().compare("REVERSE") == 0) {
                                    makeWhiteSpace();
                                    startingCard.changeColorCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getColorCard());
                                    startingCard.changeFaceCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard());
                                    if (numPlay == 4) {
                                        if (clockwise == true) {
                                            displayEffect(p3,p3.getToken(),startingCard,playWith);
                                        } else {
                                            displayEffect(p1,p1.getToken(),startingCard,playWith);
                                        }
                                    }
                                    if (startingCard.getFaceCard().getFace().compare("DRAW2") == 0) {
                                        if (numPlay == 4) {
                                            if (clockwise == true) {
                                                for (int i = 0; i < 2; i++) {
                                                    p3.drawCard();
                                                }
                                            } else {
                                                for (int i = 0; i < 2; i++) {
                                                    p1.drawCard();
                                                }
                                            }
                                            turn = 2;
                                        } else {
                                            for (int i = 0; i < 2; i++) {
                                                p1.drawCard();
                                            }
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
                                            turn = 2;
                                        }
                                    }
                                } else {
                                    startingCard.changeColorCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getColorCard());
                                    startingCard.changeFaceCard(p4.getDeck().getCardAtPos(p4.getDeck().getNumberOfCards()-1).getFaceCard());
                                    makeWhiteSpace();
                                    if (clockwise == false or numPlay == 2) {
                                        turn = 1;
                                    } else {
                                        turn = 3;
                                    }
                                }
                                p4.placeCard(p4.getDeck().getNumberOfCards()-1);
                            } else {
                                makeWhiteSpace();
                                if (clockwise == false or numPlay == 2) {
                                    turn = 1;
                                } else {
                                    turn = 3;
                                }
                            }
                        } else {
                            makeWhiteSpace();
                            if (clockwise == false or numPlay == 2) {
                                turn = 1;
                            } else {
                                turn = 3;
                            }
                        }
                    }
                    if ((turn == 1 and p4.getDeck().getNumberOfCards() != 0) or turn != 2) {
                        makeWhiteSpace();
                        std::cout << "Card played: ";
                        startingCard.printCard();
                    }
                    if (turn == 2 and p4.getDeck().getNumberOfCards() != 0) {
                        makeWhiteSpace();
                    }
                }
            }
        }
        int won1 = 0;
        int won2 = 0;
        int won3 = 0;
        int won4 = 0;
        bool winedF = false;
        bool wined2F = false;
        bool wined3F = false;
        bool wined4F = false;
        bool winedS = false;
        bool wined2S = false;
        bool wined3S = false;
        bool wined4S = false;
        bool winedT = false;
        bool wined2T = false;
        bool wined3T = false;
        bool wined4T = false;
        cards1 = p1.getDeck().getCards();
        cards2 = p2.getDeck().getCards();
        cards3 = p3.getDeck().getCards();
        cards4 = p4.getDeck().getCards();
        cards1 = sort(cards1);
        cards2 = sort(cards2);
        cards3 = sort(cards3);
        cards4 = sort(cards4);
        Deck rep11(cards1);
        Player pla11(rep11,1,pt1,rounds1);
        Deck rep21(cards2);
        Player pla21(rep21,2,pt2,rounds2);
        Deck rep31(cards3);
        Player pla31(rep31,3,pt3,rounds3);
        Deck rep41(cards4);
        Player pla41(rep41,4,pt4,rounds4);
        p1 = pla11;
        p2 = pla21;
        p3 = pla31;
        p4 = pla41;
        if (p1.getDeck().getNumberOfCards() == 0) {
            winedF = true;
            won1 = p2.getDeck().valueOfDeck();
            std::cout << "Player 1 wins!" << std::endl;
            pt1 += p2.getDeck().valueOfDeck();
            if (numPlay == 4) {
                pt1 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                won1 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
            }
            rounds1++;
        } else if (p2.getDeck().getNumberOfCards() == 0){
            wined2F = true;
            if (playWith.compare("C") == 0) {
                std::cout << "CPU 2 wins!" << std::endl;
            } else {
                std::cout << "Player 2 wins!" << std::endl;
            }
            pt2 += p1.getDeck().valueOfDeck();
            won2 = p1.getDeck().valueOfDeck();
            if (numPlay == 4) {
                pt2 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                won2 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
            }
            rounds2++;
        } else if (p3.getDeck().getNumberOfCards() == 0) {
            wined3F = true;
            if (playWith.compare("C") == 0) {
                std::cout << "CPU 3 wins!" << std::endl;
            } else {
                std::cout << "Player 3 wins!" << std::endl;
            }
            pt3 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
            won3 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
            rounds3++;
        } else {
            wined4F = true;
            if (playWith.compare("C") == 0) {
                std::cout << "CPU 4 wins!" << std::endl;
            } else {
                std::cout << "Player 4 wins!" << std::endl;
            }
            pt4 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck() + p3.getDeck().valueOfDeck());
            won4 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck() + p3.getDeck().valueOfDeck());
            rounds4++;
        }
        std::string cont = "";
        while (cont.compare("C") != 0) {
            std::cout << "1st: ";
            if (winedF == true) {
                std::cout << "Player 1" << std::endl;
                winnings.push_back(1);
            } else {
                if (wined2F == true) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2" << std::endl;
                    } else {
                        std::cout << "Player 2" << std::endl;
                    }
                    winnings.push_back(2);
                } else if (wined3F == true) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3" << std::endl;
                    } else {
                        std::cout << "Player 3" << std::endl;
                    }
                    winnings.push_back(3);
                } else {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4" << std::endl;
                    } else {
                        std::cout << "Player 4" << std::endl;
                    }
                    winnings.push_back(4);
                }
            }
            std::cout << "2nd: ";
            if (winedF == true) {
                if (numPlay == 2) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2" << std::endl;
                    } else {
                        std::cout << "Player 2" << std::endl;
                    }
                    winnings.push_back(2);
                } else {
                    if (min(p2.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 2" << std::endl;
                        } else {
                            std::cout << "Player 2" << std::endl;
                        }
                        wined2S = true;
                        pt2 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                        won2 = p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                        winnings.push_back(2);
                    } else if (min(p2.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p3.getDeck().valueOfDeck()) {
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 3" << std::endl;
                        } else {
                            std::cout << "Player 3" << std::endl;
                        }
                        pt3 += (p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                        won3 = p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                        wined3S = true;
                        winnings.push_back(3);
                    } else {
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 4" << std::endl;
                        } else {
                            std::cout << "Player 4" << std::endl;
                        }
                        pt4 += (p3.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck());
                        won4 = p3.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck();
                        wined4S = true;
                        winnings.push_back(4);
                    }
                }
            } else if (wined2F == true) {
                if (numPlay == 2) {
                    std::cout << "Player 1" << std::endl;
                    winnings.push_back(1);
                } else {
                    if (min(p1.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                        std::cout << "Player 1" << std::endl;
                        winedS = true;
                        pt1 += (p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                        won1 = p3.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                        winnings.push_back(1);
                    } else if (min(p1.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p3.getDeck().valueOfDeck()) {
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 3" << std::endl;
                        } else {
                            std::cout << "Player 3" << std::endl;
                        }
                        pt3 += (p4.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck());
                        won3 = p4.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck();
                        wined3S = true;
                        winnings.push_back(3);
                    } else {
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 4" << std::endl;
                        } else {
                            std::cout << "Player 4" << std::endl;
                        }
                        pt4 += (p3.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck());
                        won4 = p3.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck();
                        wined4S = true;
                        winnings.push_back(4);
                    }
                }
            } else if (wined3F == true) {
                if (min(p1.getDeck().valueOfDeck(), p2.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                    std::cout << "Player 1" << std::endl;
                    winedS = true;
                    pt1 += (p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                    won1 = p2.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                    winnings.push_back(1);
                } else if (min(p1.getDeck().valueOfDeck(), p2.getDeck().valueOfDeck(), p4.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2" << std::endl;
                    } else {
                        std::cout << "Player 2" << std::endl;
                    }
                    pt2 += (p1.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck());
                    won2 = p1.getDeck().valueOfDeck() + p4.getDeck().valueOfDeck();
                    wined2S = true;
                    winnings.push_back(2);
                } else {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 4" << std::endl;
                    } else {
                        std::cout << "Player 4" << std::endl;
                    }
                    wined4S = true;
                    pt4 += (p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck());
                    won4 = p1.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck();
                    winnings.push_back(4);
                }
            } else {
                if (min(p1.getDeck().valueOfDeck(), p2.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck()) == p1.getDeck().valueOfDeck()) {
                    std::cout << "Player 1" << std::endl;
                    winedS = true;
                    pt1 += (p3.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck());
                    won1 = p3.getDeck().valueOfDeck() + p2.getDeck().valueOfDeck();
                    winnings.push_back(1);
                } else if (min(p1.getDeck().valueOfDeck(), p2.getDeck().valueOfDeck(), p3.getDeck().valueOfDeck()) == p2.getDeck().valueOfDeck()) {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 2" << std::endl;
                    } else {
                        std::cout << "Player 2" << std::endl;
                    }
                    wined2S = true;
                    pt2 += (p3.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck());
                    won2 = p3.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck();
                    winnings.push_back(2);
                } else {
                    if (playWith.compare("C") == 0) {
                        std::cout << "CPU 3" << std::endl;
                    } else {
                        std::cout << "Player 3" << std::endl;
                    }
                    wined3S = true;
                    pt3 += (p2.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck());
                    won3 = p2.getDeck().valueOfDeck() + p1.getDeck().valueOfDeck();
                    winnings.push_back(3);
                }
            }
            if (numPlay == 4) {
                std::cout << "3rd: ";
                if (winedF == true) {
                    if (wined2S == true) {
                        if (p3.getDeck().valueOfDeck() > p4.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            pt4 += (p3.getDeck().valueOfDeck());
                            won4 = p3.getDeck().valueOfDeck();
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            winnings.push_back(4);
                            winnings.push_back(3);
                        } else {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            pt3 += (p4.getDeck().valueOfDeck());
                            won3 = p4.getDeck().valueOfDeck();
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            winnings.push_back(3);
                            winnings.push_back(4);
                        }
                    } else if (wined3S == true) {
                        if (p2.getDeck().valueOfDeck() > p4.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            pt4 += (p2.getDeck().valueOfDeck());
                            won4 = p2.getDeck().valueOfDeck();
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            winnings.push_back(4);
                            winnings.push_back(2);
                        } else {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            pt2 += (p4.getDeck().valueOfDeck());
                            won2 = p4.getDeck().valueOfDeck();
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            winnings.push_back(2);
                            winnings.push_back(4);
                        }
                    } else {
                        if (p3.getDeck().valueOfDeck() > p2.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            std::cout << "4th: ";
                            pt2 += (p3.getDeck().valueOfDeck());
                            won2 = p3.getDeck().valueOfDeck();
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            winnings.push_back(2);
                            winnings.push_back(3);
                        } else {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            std::cout << "4th: ";
                            pt3 += (p2.getDeck().valueOfDeck());
                            won3 = p2.getDeck().valueOfDeck();
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            winnings.push_back(3);
                            winnings.push_back(2);
                        }
                    }
                } else if (wined2F == true) {
                    if (winedS == true) {
                        if (p3.getDeck().valueOfDeck() > p4.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            std::cout << "4th: ";
                            pt4 += (p3.getDeck().valueOfDeck());
                            won4 = p3.getDeck().valueOfDeck();
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            winnings.push_back(4);
                            winnings.push_back(3);
                        } else {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            std::cout << "4th: ";
                            pt3 += (p4.getDeck().valueOfDeck());
                            won3 = p4.getDeck().valueOfDeck();
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            winnings.push_back(3);
                            winnings.push_back(4);
                        }
                    } else if (wined3S == true) {
                        if (p1.getDeck().valueOfDeck() > p4.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            pt4 += (p1.getDeck().valueOfDeck());
                            won4 = p1.getDeck().valueOfDeck();
                            std::cout << "4th: ";
                            std::cout << "Player 1" << std::endl;
                            winnings.push_back(4);
                            winnings.push_back(1);
                        } else {
                            std::cout << "Player 1" << std::endl;
                            pt1 += (p4.getDeck().valueOfDeck());
                            won1 = p4.getDeck().valueOfDeck();
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            winnings.push_back(1);
                            winnings.push_back(4);
                        }
                    } else {
                        if (p3.getDeck().valueOfDeck() > p1.getDeck().valueOfDeck()) {
                            std::cout << "Player 1" << std::endl;
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            pt1 += (p3.getDeck().valueOfDeck());
                            won1 = p3.getDeck().valueOfDeck();
                            winnings.push_back(1);
                            winnings.push_back(3);
                        } else {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            std::cout << "4th: ";
                            std::cout << "Player 1" << std::endl;
                            pt3 += (p1.getDeck().valueOfDeck());
                            won3 = p1.getDeck().valueOfDeck();
                            winnings.push_back(3);
                            winnings.push_back(1);
                        }
                    }
                } else if (wined3F == true) {
                    if (winedS == true) {
                        if (p2.getDeck().valueOfDeck() > p4.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            pt4 += (p2.getDeck().valueOfDeck());
                            won4 = p2.getDeck().valueOfDeck();
                            winnings.push_back(4);
                            winnings.push_back(2);
                        } else {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            pt2 += (p4.getDeck().valueOfDeck());
                            won2 = p4.getDeck().valueOfDeck();
                            winnings.push_back(2);
                            winnings.push_back(4);
                        }
                    } else if (wined2S == true) {
                        if (p1.getDeck().valueOfDeck() > p4.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            std::cout << "4th: ";
                            std::cout << "Player 1" << std::endl;
                            pt4 += (p1.getDeck().valueOfDeck());
                            won4 = p1.getDeck().valueOfDeck();
                            winnings.push_back(4);
                            winnings.push_back(1);
                        } else {
                            std::cout << "Player 1" << std::endl;
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 4" << std::endl;
                            } else {
                                std::cout << "Player 4" << std::endl;
                            }
                            pt1 += (p4.getDeck().valueOfDeck());
                            won1 = p4.getDeck().valueOfDeck();
                            winnings.push_back(1);
                            winnings.push_back(4);
                        }
                    } else {
                        if (p1.getDeck().valueOfDeck() > p2.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            std::cout << "4th: ";
                            std::cout << "Player 1" << std::endl;
                            pt2 += (p1.getDeck().valueOfDeck());
                            won2 = p1.getDeck().valueOfDeck();
                            winnings.push_back(2);
                            winnings.push_back(1);
                        } else {
                            std::cout << "Player 1" << std::endl;
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            pt1 += (p2.getDeck().valueOfDeck());
                            won1 = p2.getDeck().valueOfDeck();
                            winnings.push_back(1);
                            winnings.push_back(2);
                        }
                    }
                } else {
                    if (winedS == true) {
                        if (p3.getDeck().valueOfDeck() > p2.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            pt2 += (p3.getDeck().valueOfDeck());
                            won2 = p3.getDeck().valueOfDeck();
                            winnings.push_back(2);
                            winnings.push_back(3);
                        } else {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            pt3 += (p2.getDeck().valueOfDeck());
                            won3 = p2.getDeck().valueOfDeck();
                            winnings.push_back(3);
                            winnings.push_back(2);
                        }
                    } else if (wined2S == true) {
                        if (p3.getDeck().valueOfDeck() > p1.getDeck().valueOfDeck()) {
                            std::cout << "Player 1" << std::endl;
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            pt1 += (p3.getDeck().valueOfDeck());
                            won1 = p3.getDeck().valueOfDeck();
                            winnings.push_back(1);
                            winnings.push_back(3);
                        } else {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 3" << std::endl;
                            } else {
                                std::cout << "Player 3" << std::endl;
                            }
                            std::cout << "4th: ";
                            std::cout << "Player 1" << std::endl;
                            pt3 += (p1.getDeck().valueOfDeck());
                            won3 = p1.getDeck().valueOfDeck();
                            winnings.push_back(3);
                            winnings.push_back(1);
                        }
                    } else {
                        if (p1.getDeck().valueOfDeck() > p2.getDeck().valueOfDeck()) {
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            std::cout << "4th: ";
                            std::cout << "Player 1" << std::endl;
                            pt2 += (p1.getDeck().valueOfDeck());
                            won2 = p1.getDeck().valueOfDeck();
                            winnings.push_back(2);
                            winnings.push_back(1);
                        } else {
                            std::cout << "Player 1" << std::endl;
                            std::cout << "4th: ";
                            if (playWith.compare("C") == 0) {
                                std::cout << "CPU 2" << std::endl;
                            } else {
                                std::cout << "Player 2" << std::endl;
                            }
                            pt1 += (p2.getDeck().valueOfDeck());
                            won1 = p2.getDeck().valueOfDeck();
                            winnings.push_back(1);
                            winnings.push_back(2);
                        }
                    }
                }
            }
            bool validMove = false;
            int count = 0;
            while ((isNumber(cont) == false and cont.compare("C") != 0) or validMove == false) {
                if (count > 0) {
                    for (int i = 0; i < winnings.size(); i++) {
                        switch(i) {
                            case 0:
                                std::cout << "1st: ";
                                if (winnings[i] > 1) {
                                    if (playWith.compare("C") == 0) {
                                        std::cout << "CPU " << winnings[i] << std::endl;
                                    } else {
                                        std::cout << "Player " << winnings[i] << std::endl;
                                    }
                                } else {
                                    std::cout << "Player 1" << std::endl;
                                }
                                break;
                            case 1:
                                std::cout << "2nd: ";
                                if (winnings[i] > 1) {
                                    if (playWith.compare("C") == 0) {
                                        std::cout << "CPU " << winnings[i] << std::endl;
                                    } else {
                                        std::cout << "Player " << winnings[i] << std::endl;
                                    }
                                } else {
                                    std::cout << "Player 1" << std::endl;
                                }
                                break;
                            case 2:
                                std::cout << "3rd: ";
                                if (winnings[i] > 1) {
                                    if (playWith.compare("C") == 0) {
                                        std::cout << "CPU " << winnings[i] << std::endl;
                                    } else {
                                        std::cout << "Player " << winnings[i] << std::endl;
                                    }
                                } else {
                                    std::cout << "Player 1" << std::endl;
                                }
                                break;
                            case 3:
                                std::cout << "4th: ";
                                if (winnings[i] > 1) {
                                    if (playWith.compare("C") == 0) {
                                        std::cout << "CPU " << winnings[i] << std::endl;
                                    } else {
                                        std::cout << "Player " << winnings[i] << std::endl;
                                    }
                                } else {
                                    std::cout << "Player 1" << std::endl;
                                }
                        }
                    }
                }
                std::cout << "Choose from the following options: " << std::endl;
                std::cout << "Type 1 to see Player 1's statistics (owned cards, value of deck, points won). " << std::endl;
                std::cout << "Type 2 to see Player/CPU 2's statistics (owned cards, value of deck, points won). " << std::endl;
                if (numPlay == 4) {
                    std::cout << "Type 3 to see Player/CPU 3's statistics (owned cards, value of deck, points won). " << std::endl;
                    std::cout << "Type 4 to see Player/CPU 4's statistics (owned cards, value of deck, points won). " << std::endl;
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
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 2's hand:" << std::endl;
                            std::cout << "CPU 2 deck value: ";
                        } else {
                            std::cout << "Player 2's hand:" << std::endl;
                            std::cout << "Player 2 deck value: ";
                        }
                        std::cout << p2.getDeck().valueOfDeck() << std::endl;
                        p2.revealHand1();
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 2";
                        } else {
                            std::cout << "Player 2";
                        }
                        std::cout << " has earned a total of: " << won2 << " points! " << std::endl;
                        break;
                    case 3:
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 3's hand:" << std::endl;
                            std::cout << "CPU 3 deck value: ";
                        } else {
                            std::cout << "Player 3's hand:" << std::endl;
                            std::cout << "Player 3 deck value: ";
                        }
                        std::cout << p3.getDeck().valueOfDeck() << std::endl;
                        p3.revealHand1();
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 3";
                        } else {
                            std::cout << "Player 3";
                        }
                        std::cout << " has earned a total of: " << won3 << " points!" << std::endl;
                        break;
                    case 4:
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 4's hand:" << std::endl;
                            std::cout << "CPU 4 deck value: ";
                        } else {
                            std::cout << "Player 4's hand:" << std::endl;
                            std::cout << "Player 4 deck value: ";
                        }
                        std::cout << p4.getDeck().valueOfDeck() << std::endl;
                        p4.revealHand1();
                        if (playWith.compare("C") == 0) {
                            std::cout << "CPU 4";
                        } else {
                            std::cout << "Player 4";
                        }
                        std::cout << " has earned a total of: " << won4 << " points! " << std::endl;
                }
                count++;
            }
        }
        if (opt != 4) {
            std::cout << "Goal: " << ptG << std::endl;
        }
        std::cout << "Player 1 score: " << pt1 << std::endl;
        std::cout << "Player 1 rounds won: " << rounds1 << std::endl;
        if (playWith.compare("C") == 0) {
            std::cout << "CPU 2 score: " << pt2 << std::endl;
            std::cout << "CPU 2 rounds won: " << rounds2 << std::endl;
        } else {
            std::cout << "Player 2 score: " << pt2 << std::endl;
            std::cout << "Player 2 rounds won: " << rounds2 << std::endl;
        }
        if (numPlay == 4) {
            if (playWith.compare("C") == 0) {
                std::cout << "CPU 3 score: " << pt3 << std::endl;
                std::cout << "CPU 3 rounds won: " << rounds3 << std::endl;
            } else {
                std::cout << "Player 3 score: " << pt3 << std::endl;
                std::cout << "Player 3 rounds won: " << rounds3 << std::endl;
            }
            if (playWith.compare("C") == 0) {
                std::cout << "CPU 4 score: " << pt4 << std::endl;
                std::cout << "CPU 4 rounds won: " << rounds4 << std::endl;
            } else {
                std::cout << "Player 4 score: " << pt4 << std::endl;
                std::cout << "Player 4 rounds won: " << rounds4 << std::endl;
            }
        }
        std::string continuing = "";
        while (continuing.compare("C") != 0) {
            std::cout << "Type C to continue. ";
            std::cin >> continuing;
            if (continuing.compare("C") != 0) {
                std::cout << "Invalid input! Input value MUST be C to be valid." << std::endl;
            }
        }
        if (opt == 4) {
            play1 = "";
            while (play1.compare("Y") != 0 and play1.compare("N") != 0) {
                std::cout << "Player 1, do you wish to play again? Type Y for yes or N for no. ";
                std::cin >> play1;
                if (play1.compare("Y") != 0 and play1.compare("N") != 0) {
                    std::cout << "Invalid choice! ";
                }
            }
            if (playWith.compare("P") == 0) {
                play2 = "";
                while (play2.compare("Y") != 0 and play2.compare("N") != 0) {
                    std::cout << "Player 2, do you wish to play again? Type Y for yes or N for no. ";
                    std::cin >> play2;
                    if (play2.compare("Y") != 0 and play2.compare("N") != 0) {
                        std::cout << "Invalid choice! ";
                    }
                }
                if (numPlay == 4) {
                    play3 = "";
                    while (play3.compare("Y") != 0 and play3.compare("N") != 0) {
                        std::cout << "Player 3, do you wish to play again? Type Y for yes or N for no. ";
                        std::cin >> play3;
                        if (play3.compare("Y") != 0 and play3.compare("N") != 0) {
                            std::cout << "Invalid choice! ";
                        }
                    }
                    play4 = "";
                    while (play4.compare("Y") != 0 and play4.compare("N") != 0) {
                        std::cout << "Player 4, do you wish to play again? Type Y for yes or N for no. ";
                        std::cin >> play4;
                        if (play4.compare("Y") != 0 and play4.compare("N") != 0) {
                            std::cout << "Invalid choice! ";
                        }
                    }
                }
            } else {
                play2 = "Y";
                play3 = "Y";
                play4 = "Y";
            }
            playedAgain = play1.compare("Y") == 0 and play2.compare("Y") == 0 and play3.compare("Y") == 0 and play4.compare("Y") == 0;
        } else {
            playedAgain = pt1 < ptG and pt2 < ptG and pt3 < ptG and pt4 < ptG;
        }
        makeWhiteSpace();
    }
    std::cout << std::endl;
    std::cout << "Statistics: " << std::endl;
    std::cout << "Player 1 score: " << pt1 << std::endl;
    std::cout << "Player 1 rounds won: " << rounds1 << std::endl;
    std::cout << std::endl;
    if (playWith.compare("C") == 0) {
        std::cout << "CPU 2 score: " << pt2 << std::endl;
        std::cout << "CPU 2 rounds won: " << rounds2 << std::endl;
    } else {
        std::cout << "Player 2 score: " << pt2 << std::endl;
        std::cout << "Player 2 rounds won: " << rounds2 << std::endl;
    }
    std::cout << std::endl;
    if (numPlay == 4) {
        if (playWith.compare("C") == 0) {
            std::cout << "CPU 3 score: " << pt3 << std::endl;
            std::cout << "CPU 3 rounds won: " << rounds3 << std::endl;
        } else {
            std::cout << "Player 3 score: " << pt3 << std::endl;
            std::cout << "Player 3 rounds won: " << rounds3 << std::endl;
        }
        std::cout << std::endl;
        if (playWith.compare("C") == 0) {
            std::cout << "CPU 4 score: " << pt4 << std::endl;
            std::cout << "CPU 4 rounds won: " << rounds4 << std::endl;
        } else {
            std::cout << "Player 4 score: " << pt4 << std::endl;
            std::cout << "Player 4 rounds won: " << rounds4 << std::endl;
        }
    }
    if (pt1 > pt2 and pt1 > pt3 and pt1 > pt4) {
        std::cout << "Player 1 wins after " << rounds << " rounds!" << std::endl;
    } else if (pt2 > pt1 and pt2 > pt3 and pt2 > pt4) {
        if (playWith.compare("C") == 0) {
            std::cout << "CPU 2 wins after " << rounds << " rounds!" << std::endl;
        } else {
            std::cout << "Player 2 wins after " << rounds << " rounds!" << std::endl;
        }
    } else if (pt3 > pt1 and pt3 > pt2 and pt3 > pt4) {
        if (playWith.compare("C") == 0) {
            std::cout << "CPU 3 wins after " << rounds << " rounds!" << std::endl;
        } else {
            std::cout << "Player 3 wins after " << rounds << " rounds!" << std::endl;
        }
    } else if (pt4 > pt1 and pt4 > pt2 and pt4 > pt3) {
        if (playWith.compare("C") == 0) {
            std::cout << "CPU 4 wins after " << rounds << " rounds!" << std::endl;
        } else {
            std::cout << "Player 4 wins after " << rounds << " rounds!" << std::endl;
        }
    } else {
        std::cout << "Tied points. Winner is determined by rounds won!" << std::endl;
        if (rounds1 > rounds2 and rounds1 > rounds3 and rounds1 > rounds4) {
            std::cout << "Player 1 wins after " << rounds << " rounds!" << std::endl;
        } else if (rounds2 > rounds1 and rounds2 > rounds3 and rounds2 > rounds4) {
            if (playWith.compare("C") == 0) {
                std::cout << "CPU 2 wins after " << rounds << " rounds!" << std::endl;
            } else {
                std::cout << "Player 2 wins after " << rounds << " rounds!" << std::endl;
            }
        } else if (rounds3 > rounds1 and rounds3 > rounds2 and rounds3 > rounds4) {
            if (playWith.compare("C") == 0) {
                std::cout << "CPU 3 wins after " << rounds << " rounds!" << std::endl;
            } else {
                std::cout << "Player 3 after " << rounds << " rounds!" << std::endl;
            }
        } else if (rounds4 > rounds1 and rounds4 > rounds3 and rounds4 > rounds2) {
            if (playWith.compare("C") == 0) {
                std::cout << "CPU 3 wins after" << rounds << " rounds!" << std::endl;
            } else {
                std::cout << "Player 3 wins after" << rounds << " rounds!" << std::endl;
            }
        } else {
            std::cout << "Tied points won and rounds won! Winner will be determined by random! (1 = Player 1 victory, 2 = ";
            if (playWith.compare("C") == 0) {
                std::cout << "CPU 2 victory";
            } else {
                std::cout << "Player 2 victory";
            }
            if (numPlay == 4) {
                std::cout << ", 3 = ";
                if (playWith.compare("C") == 0) {
                    std::cout << "CPU 3 victory" << std::endl;
                } else {
                    std::cout << "Player 3 victory" << std::endl;
                }
                std::cout << ", 4 = ";
                if (playWith.compare("C") == 0) {
                    std::cout << "CPU 4 victory) " << std::endl;
                } else {
                    std::cout << "Player 4 victory) " << std::endl;
                }
            } else {
                std::cout << ")";
            }
            int r = (rand()%numPlay) + 1;
            if (r == 1) {
                std::cout << "Player 1 wins after" << rounds << " rounds!" << std::endl;
            } else if (r == 2) {
                if (playWith.compare("C") == 0) {
                    std::cout << "CPU 2 wins after" << rounds << " rounds!" << std::endl;
                } else {
                    std::cout << "Player 2 victory! " << std::endl;
                }
            } else if (r == 3) {
                if (playWith.compare("C") == 0) {
                    std::cout << "CPU 3 wins after" << rounds << " rounds!" << std::endl;
                } else {
                    std::cout << "Player 3 victory! " << std::endl;
                }
            } else {
                if (playWith.compare("C") == 0) {
                    std::cout << "CPU 4 wins after " << rounds << " rounds!" << std::endl;
                } else {
                    std::cout << "Player 4 victory! " << std::endl;
                }
            }
        }
    }
}
