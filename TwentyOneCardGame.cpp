/*
Game Rules:
Game is simulated by having Player 1 (you) against Player 2 (CPU). Each of you will be given 2 cards at the beginning, you can decide to hit (by using H) or stand (by using S). The winner is determined by whoever reaches closest to 21 (if both of you end up with less than 21 or both of you end up with over 21, which is considered a bust), or to the other player whoever didn't get a bust (if one player ends up with a bust), or determined by random (if both of you end up with the same value at the end of the round). Note that a blackjack hand (2 cards dealt resulting in a 21) will beat any other hand (even a normal hand of 3 or more cards resulting in 21), and the only way to tie is with another blackjack hand.
Points distribution:
 The victor of each round will receive points in the following ways:
 Victory point(s), where the winner of each round will always receive at the very least 1 point for being the victor, 2 if the winner has a blackjack.
 Bonus point(s), where the amount of bonus point(s) won is determined in the 3 ways:
 1. if you both end up having over 21 or under 21, the amount of bonus points won by the victor would be the absolute value difference between the 2 players. Say you got 23 but your opponent got 25, your bonus points would be 25-23 = 2 bonus points won.
 2. if either of you two get a bust (but not the other), the amount of bonus points won by the victor will be the absolute value difference between the value of the player's hand who ended up with a bust and the value 21. Say you ended up with 16 and the opponent ended up with 23, your bonus points would be 23-21 = 2 bonus points won.
 3. if you both ended up with the same value (whether bust or not), no bonus points will be awarded, but the victor of the round (determined by random) will only receive 1 victory point.
 NOTE: In the case that the winner has a blackjack, then the amount of bonus points awarded will be doubled.
 BlackJack multiplier, where if either player receives a blackjack (21 on their first 2 cards), then the amount of points awarded would be doubled. Keep in mind that a blackjack would be an almost instant win for the player who has it, even beating someone who has a normal 21 (with 3 or more cards resulting in 21). If both players have a blackjack, then the winner will then be determined by random, where the winner will receive 2 victory points rather than 1 (due to the x2 multiplier in effect).
 Replay opportunity/ winner of game determination:
 You can decide to play again with a Y, or not with an N. After the game ends, whoever accumlated the most points is considered the winner. If there is a tie in points, whoever wins the most rounds would be the winner. If both players win the same points and same number of rounds, the winner will then be decided by random.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
class Suit {
public:
    Suit() {
        suit = "";
    }
    Suit(std::string s) {
        suit = s;
    }
    std::string getSuit() {
        return suit;
    }
private:
    std::string suit; //representing the suit of a card
};
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
    std::string face; //representing the face of a card, which can be a letter or a number
};
class Card {
public:
    Card() {
        std::vector<Suit> suits; //list of suits a card can have
        std::vector<Face> faces; //list of faces a card can have
        for (int i = 0; i < 13; i++) {
            switch(i) {
                case 0:
                    suits.push_back(Suit("diamonds"));
                    faces.push_back(Face("A"));
                    break;
                case 1:
                    suits.push_back(Suit("clubs"));
                    faces.push_back(Face("2"));
                    break;
                case 2:
                    suits.push_back(Suit("hearts"));
                    faces.push_back(Face("3"));
                    break;
                case 3:
                    suits.push_back(Suit("spades"));
                    faces.push_back(Face("4"));
                    break;
                case 4:
                    faces.push_back(Face("5"));
                    break;
                case 5:
                    faces.push_back(Face("6"));
                    break;
                case 6:
                    faces.push_back(Face("7"));
                    break;
                case 7:
                    faces.push_back(Face("8"));
                    break;
                case 8:
                    faces.push_back(Face("9"));
                    break;
                case 9:
                    faces.push_back(Face("10"));
                    break;
                case 10:
                    faces.push_back(Face("J"));
                    break;
                case 11:
                    faces.push_back(Face("Q"));
                    break;
                default:
                    faces.push_back(Face("K"));
            }
        }
        suit = suits[rand()%4]; //randomly chosen suit
        face = faces[rand()%13]; //randomly chosen face
    }
    Face getFaceCard() {
        return face; //returns Face object of a card
    }
    Suit getSuitCard() {
        return suit; //returns Suit object of a card
    }
    void printCard() {
        std::cout << "Card displayed: " << face.getFace() << " of " << suit.getSuit() << std::endl; //displays each card by their face and suit
    }
private:
    Face face;
    Suit suit;
};
class Deck {
public:
    void addCard() {
        Card c;
        cards.push_back(c);
    }
    void printDeck() {
        for (unsigned int i = 0; i < cards.size(); i++) {
            cards[i].printCard(); //prints out each card of the deck
        }
    }
    Card getCardAtPos(int i) {
        return cards[i]; //gets the Card at position i of the deck
    }
    bool isBlackJack(int totalV) {
        return totalV == 21 and cards.size() == 2;
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
        roundsWon = r;
    }
    Deck getDeck() {
        return d;
    }
    int getToken() {
        return token;
    }
    int getRoundsWon() {
        return roundsWon;
    }
    int getPoints() {
        return pointV;
    }
    void revealHand() {
        d.printDeck();
    }
    void incrementPoints(int pts) {
        pointV += pts;
    }
    void incrementRoundsWon() {
        roundsWon++;
    }
    void drawCard() {
        d.addCard();
    }
private:
    Deck d;
    int pointV;
    int token;
    int roundsWon;
};
class KeyPair {
public:
    KeyPair() {
        value1 = 1;
        value2 = 11;
    }
    int getVal1() {
        return value1;
    }
    int getVal2() {
        return value2;
    }
private:
    int value1;
    int value2;
};
int getValue(Card a, int p, int tv) {
    int v = 0;
    if (a.getFaceCard().getFace().compare("A") == 0) {
        KeyPair keys;
        int choose = 0;
        if (p == 1) {
            while (choose != 1 and choose != 11) {
                std::cout << "Player " << p << ": use 1 or 11 for value? ";
                std::cin >> choose;
                if (choose != 1 and choose != 11) {
                    std::cout << "Invalid choice! Please enter a valid value!" << std::endl;
                }
            }
        } else {
            int n = rand()%2;
            if (tv + 11 > 21) {
                choose = 1;
            } else if (tv + 11 >= 18) {
                choose = 11;
            } else {
                if (n == 0) {
                    choose = 1;
                } else {
                    choose = 11;
                }
            }
        }
        v = choose;
        
    } else {
        if (a.getFaceCard().getFace().compare("J") == 0 or a.getFaceCard().getFace().compare("Q") == 0 or a.getFaceCard().getFace().compare("K") == 0) {
            v = 10;
        } else {
            v = std::stoi(a.getFaceCard().getFace());
        }
    }
    return v;
}
int main(int argc, char** argv) {
    srand(time(0));
    int pt1 = 0;
    int pt2 = 0;
    int round = 0;
    int r = 0;
    int r1W = 0;
    int r2W = 0;
    std::string play1 = "";
    std::string play2 = "";
    std::cout << std::endl;
    std::string t = "";
    while (play1.compare("N") != 0 and play2.compare("N") != 0)
    {
        Deck deckOfCards;
        Deck deckOfCards2;
        Player p1(deckOfCards,1,pt1,r1W);
        Player p2(deckOfCards2,2,pt2,r2W);
        int v1 = 0;
        int v2 = 0;
        int i = 0;
        int k = 0;
        int j = 2;
        round++;
        for (int i = 0; i < 2; i++) {
            p1.drawCard();
            p2.drawCard();
        }
        std::string dec1 = "";
        std::string dec2 = "";
        std::cout << "Round " << round << std::endl;
        while (dec1.compare("S") != 0 or dec2.compare("S") != 0) {
            p1.revealHand();
            if (i == 0) {
                for (i = 0; i < 2; i++) {
                    v1 += getValue(p1.getDeck().getCardAtPos(i),p1.getToken(),v1);
                }
            }
            while (dec1.compare("S") != 0) {
                std::cout << "Value for player " << p1.getToken() << ": " << v1 << std::endl;
                std::cout << "Player " << p1.getToken() << ", enter S for stand, or H for hit: ";
                std::cin >> dec1;
                if (dec1.compare("H") == 0) {
                    p1.drawCard();
                    v1 += getValue(p1.getDeck().getCardAtPos(j),p1.getToken(),v1);
                }
                j++;
            }
            j = 2;
            std::cout << std::endl;
            /*
            for (int i = 0; i < 30; i++) {
                std::cout << std::endl;
            }
            p2.revealHand();
            */
            if (k == 0) {
                for (k = 0; k < 2; k++) {
                    v2 += getValue(p2.getDeck().getCardAtPos(k),p2.getToken(),v2);
                }
            }
            while (dec2.compare("S") != 0) {
                std::cout << "Value for player " << p2.getToken() << "(CPU): " << v2 << std::endl;
                if (v2 < 17) {
                    dec2 = "H";
                } else if (v2 > 17) {
                    dec2 = "S";
                } else {
                    int a = rand()%2;
                    if (a == 0) {
                        dec2 = "S";
                    } else {
                        dec2 = "H";
                    }
                }
                /*
                std::cout << "Player " << p2.getToken() << ", enter S for stand, or H for hit: ";
                std::cin >> dec2;
                */
                if (dec2.compare("H") == 0) {
                    p2.drawCard();
                    v2 += getValue(p2.getDeck().getCardAtPos(j),p2.getToken(),v2);
                }
                j++;
            }
        }
        std::cout << std::endl;
        std::cout << "Player " << p1.getToken() << "'s hand: " << std::endl;
        p1.revealHand();
        std::cout << std::endl;
        std::cout << "Player " << p2.getToken() << "'s (CPU) hand: " << std::endl;
        p2.revealHand();
        std::cout << std::endl;
        std::cout << "Value for player " << p1.getToken() << ": " << v1 << std::endl;
        std::cout << "Value for player " << p2.getToken() << " (CPU): " << v2 << std::endl;
        int bonusPoints = -1;
        int multiplier = 1;
        int pointsWon = 0;
        int victoryPoint = 1;
        if ((v1 > 21 and v2 <= 21) or (v1 > v2 and v2 > 21) or (v1 < v2 and v2 <= 21)) {
            if (p2.getDeck().isBlackJack(v2) == true) {
                multiplier = 2;
            }
            std::cout << "Player " << p2.getToken() << " (CPU) wins round " << round << "! " << std::endl;
            pointsWon++;
            if ((v1 > 21 and v2 <= 21)) {
                pointsWon += (v1-21);
            } else if (v1 > v2 and v2 > 21) {
                pointsWon += (v1-v2);
            } else {
                pointsWon += (v2-v1);
            }
            pointsWon *= multiplier;
            victoryPoint *= multiplier;
            pt2 += pointsWon;
            bonusPoints = pointsWon - victoryPoint;
            p2.incrementRoundsWon();
            r2W++;
        } else if ((v2 > 21 and v1 <= 21) or (v2 > v1 and v1 > 21) or (v2 < v1 and v1 <= 21)) {
            if (p1.getDeck().isBlackJack(v1) == true) {
                multiplier = 2;
            }
            std::cout << "Player " << p1.getToken() << " wins round " << round << "! " << std::endl;
            pointsWon++;
            if ((v2 > 21 and v1 <= 21)) {
                pointsWon += (v2-21);
            } else if (v2 > v1 and v1 > 21) {
                pointsWon += (v2-v1);
            } else {
                pointsWon += (v1-v2);
            }
            pointsWon *= multiplier;
            victoryPoint *= multiplier;
            pt1 += pointsWon;
            bonusPoints = pointsWon - victoryPoint;
            p1.incrementRoundsWon();
            r1W++;
        } else {
            if (p1.getDeck().isBlackJack(v1) == true or p2.getDeck().isBlackJack(v2) == true) {
                multiplier = 2;
            }
            if (p1.getDeck().isBlackJack(v1) == true and p2.getDeck().isBlackJack(v2) == false) {
                std::cout << "Player " << p1.getToken() << " wins round " << round << "! " << std::endl;
                pointsWon++;
                victoryPoint *= multiplier;
                pointsWon *= multiplier;
                pt1 += pointsWon;
                p1.incrementRoundsWon();
                r1W++;
            } else if (p1.getDeck().isBlackJack(v1) == false and p2.getDeck().isBlackJack(v2) == true) {
                std::cout << "Player " << p2.getToken() << " (CPU) wins round " << round << "! " << std::endl;
                pointsWon++;
                victoryPoint *= multiplier;
                pointsWon *= multiplier;
                pt2 += pointsWon;
                p2.incrementRoundsWon();
                r2W++;
            } else {
                std::cout << "Tied! Winner of round " << round << " determined by random (1 = player 1, 2 = player 2 (CPU))..." << std::endl;
                r = (rand()%2)+1;
                std::cout << "Chosen: " << r << std::endl;
                if (r == 1) {
                    std::cout << "Player 1 wins round " << round << "!" << std::endl;
                    pointsWon++;
                    victoryPoint *= multiplier;
                    pointsWon *= multiplier;
                    pt1 += pointsWon;
                    p1.incrementRoundsWon();
                    r1W++;
                } else {
                    std::cout << "Player 2 (CPU) wins round " << round << "!" << std::endl;
                    pointsWon++;
                    victoryPoint *= multiplier;
                    pointsWon *= multiplier;
                    pt2 += pointsWon;
                    p2.incrementRoundsWon();
                    r2W++;
                }
            }
            bonusPoints = 0;
        }
        if (multiplier == 2) {
            std::cout << "x2 multiplier applied!" << std::endl;
        }
        std::cout << "+" << victoryPoint << " (victory point(s))" << std::endl;
        std::cout << "+" << bonusPoints << " (bonus point(s))" << std::endl;
        std::cout << std::endl;
        std::cout << "Player " << p1.getToken() << " score: " << pt1 << std::endl;
        std::cout << "Player " << p1.getToken() << " rounds won: " << r1W << std::endl;
        std::cout << "Player " << p2.getToken() << " (CPU) score: " << pt2 << std::endl;
        std::cout << "Player " << p2.getToken() << " (CPU) rounds won: " << r2W << std::endl;
        std::cout << "Player " << p1.getToken() << ", do you wish to play again? (Enter Y for yes, or N for no): ";
        std::cin >> play1;
        /*
        std::cout << "Player " << p2.getToken() << ", do you wish to play again? (Enter Y for yes, or N for no): ";
        std::cin >> play2;
        */
        play2 = "Y";
        std::cout << std::endl;
    }
    if (round > 1) {
        t += "s";
    }
    std::cout << "Overall stats: " << std::endl;
    std::cout << std::endl;
    std::cout << "Player 1: " << std::endl;
    std::cout << "Points: " << pt1 << std::endl;
    std::cout << "Rounds won: " << r1W << std::endl;
    std::cout << std::endl;
    std::cout << "Player 2 (CPU): " << std::endl;
    std::cout << "Points: " << pt2 << std::endl;
    std::cout << "Rounds won: " << r2W << std::endl;
    std::cout << std::endl;
    if (pt1 > pt2) {
        std::cout << "Player 1 wins the game after " << round << (" round" + t) << "!" << std::endl;
    } else if(pt1 < pt2) {
        std::cout << "Player 2 (CPU) wins the game after " << round << (" round" + t) << "!" << std::endl;
    } else {
        std::cout << "Tied points! Winner is determined by most rounds won!" << std::endl;
        if (r1W > r2W) {
            std::cout << "Player 1 wins the game after " << round << (" round" + t) << "!" << std::endl;
        } else if (r2W > r1W) {
            std::cout << "Player 2 (CPU) wins the game after " << round << (" round" + t) << "!" << std::endl;
        } else {
            std::cout << "Tied points and rounds won! Winner of the game will be determined by random (1 = player 1, 2 = player 2 (CPU))..." << std::endl;
            r = (rand()%2)+1;
            std::cout << "Chosen: " << r << std::endl;
            if (r == 1) {
                std::cout << "Player 1 wins the game after " << round << (" round" + t) << "!" << std::endl;
            } else {
                std::cout << "Player 2 (CPU) wins the game after " << round << (" round" + t) << "!" << std::endl;
            }
        }
    }
}

