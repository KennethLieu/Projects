/*
 Battleship gameplay:
 Welcome to Battleship gameplay! Compete in a 1v1 battle where the objective is to be the first player to knock down all of your opponent's ships. To start, you need to place all of your ships as appropriate. Then, you need to choose positions one by one, and you will either HIT or MISS your opponent's ships. If you HIT, you get an extra turn, if you MISS, your opponent gets a turn.
 
 Game development log:
 
 Update 2/9/2020:
 1. Successful creation of Battleship, where you can play 2v2 match.

*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
bool isNumber(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}
class Position {
public:
    Position() {
        x = 0;
        y = 0;
    }
    Position(int x1, int y1) {
        x = x1;
        y = y1;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    bool matchedPositions(Position b) {
        return x == b.getX() and y == b.getY();
    }
private:
    int x;
    int y;
};
class Component {
public:
    Component(Position p) {
        pos = p;
    }
    Position getPosition() {
        return pos;
    }
    void setPosition(Position po) {
        pos = po;
    }
private:
    Position pos;
};
class Ship {
public:
    Ship(int l) {
        length = l;
    }
    int getLength() {
        return length;
    }
    void addComponent(Component a) {
        comp.push_back(a);
    }
    std::vector<Component> getComponents() {
        return comp;
    }
    unsigned int getNumberOfComponents() {
        return comp.size();
    }
    Component getComponentAtPos(int i) {
        return comp[i];
    }
private:
    std::vector<Component> comp;
    int length;
    Position posStern;
    std::string direction;
};
class Player {
public:
    Player() {
        
    }
    Player(int t) {
        token = t;
    }
    void addShip(Ship a) {
        ships.push_back(a);
    }
    std::vector<Ship> getShips() {
        return ships;
    }
    unsigned int getNumberOfShips() {
        return ships.size();
    }
    Ship getShipAtPos(int i) {
        return i;
    }
    int getToken() {
        return token;
    }
private:
    std::vector<Ship> ships;
    int token;
};
class BattleShipBoard {
public:
    BattleShipBoard() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                positionsNotUsed.push_back(Position(i,j));
            }
        }
        std::vector<std::string> board;
        int c = 0;
        for (int i = 0; i < 20; i++) {
            if (i%2 == 0) {
                board.push_back(" ");
            } else {
                board.push_back(std::to_string(c));
                c++;
            }
        }
        boardDisplay.push_back(board);
        for (int i = 0; i < 10; i++) {
            std::vector<std::string> rows;
            for (int j = 0; j < 20; j++) {
                if (j == 0) {
                    rows.push_back(std::to_string(i));
                } else if (j%2 == 0) {
                    rows.push_back(" ");
                } else {
                    rows.push_back("*");
                }
            }
            boardDisplay.push_back(rows);
        }
    }
    BattleShipBoard(Player p) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                positionsNotUsed.push_back(Position(i,j));
            }
        }
        std::vector<std::string> board;
        int c = 0;
        for (int i = 0; i < 20; i++) {
            if (i%2 == 0) {
                board.push_back(" ");
            } else {
                board.push_back(std::to_string(c));
                c++;
            }
        }
        boardDisplay.push_back(board);
        for (int i = 0; i < 10; i++) {
            std::vector<std::string> rows;
            for (int j = 0; j < 20; j++) {
                if (j == 0) {
                    rows.push_back(std::to_string(i));
                } else if (j%2 == 0) {
                    rows.push_back(" ");
                } else {
                    rows.push_back("*");
                }
            }
            boardDisplay.push_back(rows);
        }
        play = p;
    }
    void occupySpace(Ship a, Player p) {
        for (unsigned int i = 0; i < a.getNumberOfComponents(); i++) {
            for (unsigned int j = 0; j < positionsNotUsed.size(); j++) {
                if (positionsNotUsed[j].matchedPositions(a.getComponentAtPos(i).getPosition()) == true) {
                    positionsNotUsed.erase(positionsNotUsed.begin()+j);
                    Position pos = a.getComponentAtPos(i).getPosition();
                    int r = pos.getY()+1;
                    std::vector<std::string> rows = boardDisplay[r];
                    for (unsigned int k = 0; k < rows.size(); k++) {
                        if (k%2 == 1 and k == pos.getX()*2+1) {
                            rows[k] = std::to_string(p.getToken());
                        }
                    }
                    boardDisplay[r] = rows;
                }
            }
        }
    }
    bool isValidSpot(Ship a) {
        int counter = 0;
        for (unsigned int i = 0; i < a.getNumberOfComponents(); i++) {
            for (unsigned int k = 0; k < positionsNotUsed.size(); k++) {
                if (positionsNotUsed[k].matchedPositions(a.getComponentAtPos(i).getPosition()) == true) {
                    counter++;
                    break;
                }
            }
        }
        return a.getNumberOfComponents() == counter;
    }
    void printBoard() {
        for (unsigned int i = 0; i < boardDisplay.size(); i++) {
            std::vector<std::string> rows = boardDisplay[i];
            for (unsigned int j = 0; j < rows.size(); j++) {
                std::cout << rows[j] << " ";
            }
            std::cout << std::endl;
        }
    }
    bool allShipsSunk() {
        for (unsigned int i = 1; i < boardDisplay.size(); i++) {
            std::vector<std::string> rows = boardDisplay[i];
            for (unsigned int j = 1; j < rows.size(); j++) {
                if (isNumber(rows[j]) == true) {
                    return false;
                }
            }
        }
        return true;
    }
    bool hitComponent(Position p, BattleShipBoard b2) {
        int x = p.getX();
        int y = p.getY();
        std::vector<std::string> row = b2.getRowAtPos(y+1);
        std::string a = row[x*2+1];
        return a.compare(std::to_string(b2.getPlayer().getToken())) == 0;
    }
    void attack(Position p, BattleShipBoard b2) {
        int x = p.getX();
        int y = p.getY();
        std::vector<std::string> row1 = boardDisplay[y+1];
        if (hitComponent(p,b2) == true) {
            row1[x*2+1] = "X";
            boardDisplay[y+1] = row1;
        } else {
            row1[x*2+1] = "O";
            boardDisplay[y+1] = row1;
        }
    }
    void attack1(Position p, BattleShipBoard b2) {
        int x = p.getX();
        int y = p.getY();
        std::vector<std::string> row1 = boardDisplay[y+1];
        if (hitComponent(p,b2) == true) {
            row1[x*2+1] = "X";
            boardDisplay[y+1] = row1;
        } else {
            row1[x*2+1] = "O";
            boardDisplay[y+1] = row1;
        }
    }
    void changeRow(std::vector<std::string> a, int ind) {
        boardDisplay[ind] = a;
    }
    std::vector<std::vector<std::string> > getBoard() {
        return boardDisplay;
    }
    std::vector<std::string> getRowAtPos(int i) {
        return boardDisplay[i];
    }
    Player getPlayer() {
        return play;
    }
private:
    std::vector<Position> positionsNotUsed;
    Player play;
    std::vector<std::vector<std::string> > boardDisplay;
};
void newLine() {
    for (int i = 0; i < 30; i++) {
        std::cout << std::endl;
    }
}
int main(int argc, char** argv) {
    std::string c = "";
    std::cout << "Welcome to Battleship! Play in a 1v1 match where your objective is to be the first one knock down all 5 of your opponents ship, before they knock all 5 of your ships down!" << std::endl;
    while (c.compare("C") != 0) {
        std::cout << "Type C to continue. ";
        std::cin >> c;
    }
    Player p1(1);
    BattleShipBoard board1(p1);
    Player p2(2);
    BattleShipBoard board2(p2);
    newLine();
    std::cout << "Player 1's board: " << std::endl;
    board1.printBoard();
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            bool valid = false;
            while (valid == false) {
                std::cout << "Player 1, please enter x and y coordinates for the stern of your length 2 ship: ";
                std::string coord;
                std::cin >> coord;
                if(coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    newLine();
                    std::cout << "Cannot process output. " << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                int x = std::stoi(coord.substr(0,1));
                int y = std::stoi(coord.substr(2,1));
                std::cout << "Type V for vertical, H for horizontal: ";
                std::string positioning = "";
                std::cin >> positioning;
                if ((y+1 >= 9 and positioning.compare("V") == 0) or (x+1 >= 9 and positioning.compare("H") == 0)) {
                    newLine();
                    std::cout << "Invalid placement. Out of bounds!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                } else if (positioning.compare("H") != 0 and positioning.compare("V") != 0) {
                    std::cout << "Invalid placement. Must select H or V!" << std::endl;
                    newLine();
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                Ship sh(2);
                sh.addComponent(Component(Position(x,y)));
                if (positioning.compare("V") == 0) {
                    sh.addComponent(Component(Position(x,y+1)));
                } else {
                    sh.addComponent(Component(Position(x+1,y)));
                }
                if (board1.isValidSpot(sh) == true) {
                    valid = true;
                    p1.addShip(sh);
                    board1.occupySpace(sh,p1);
                } else {
                    newLine();
                    std::cout << "Invalid placement!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
            }
        } else if (i == 1 or i == 2) {
            bool valid = false;
            while (valid == false) {
                std::cout << "Player 1, please enter x and y coordinates for the stern of your length 3 ship: ";
                std::string coord = "";
                std::cin >> coord;
                if(coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    newLine();
                    std::cout << "Cannot process output. " << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                int x = std::stoi(coord.substr(0,1));
                int y = std::stoi(coord.substr(2,3));
                std::cout << "Type V for vertical, H for horizontal: ";
                std::string positioning = "";
                std::cin >> positioning;
                if ((y+2 >= 9 and positioning.compare("V") == 0) or (x+2 >= 9 and positioning.compare("H") == 0)) {
                    newLine();
                    std::cout << "Invalid placement. Out of bounds!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                } else if (positioning.compare("H") != 0 and positioning.compare("V") != 0) {
                    newLine();
                    std::cout << "Invalid placement. Must select H or V!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                Ship sh(3);
                sh.addComponent(Component(Position(x,y)));
                if (positioning.compare("V") == 0) {
                    for (int i = 1; i < 3; i++) {
                        sh.addComponent(Component(Position(x,y+i)));
                    }
                } else {
                    for (int i = 1; i < 3; i++) {
                        sh.addComponent(Component(Position(x+i,y)));
                    }
                }
                if (board1.isValidSpot(sh) == true) {
                    valid = true;
                    p1.addShip(sh);
                    board1.occupySpace(sh,p1);
                } else {
                    newLine();
                    std::cout << "Invalid placement!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
            }
        } else if (i == 3) {
            bool valid = false;
            while (valid == false) {
                std::cout << "Player 1, please enter x and y coordinates for the stern of your length 4 ship: ";
                std::string coord = "";
                std::cin >> coord;
                if(coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    newLine();
                    std::cout << "Cannot process output. " << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                int x = std::stoi(coord.substr(0,1));
                int y = std::stoi(coord.substr(2,3));
                std::cout << "Type V for vertical, H for horizontal: ";
                std::string positioning = "";
                std::cin >> positioning;
                if ((y+3 >= 9 and positioning.compare("V") == 0) or (x+3 >= 9 and positioning.compare("H") == 0)) {
                    newLine();
                    std::cout << "Invalid placement. Out of bounds!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                } else if (positioning.compare("H") != 0 and positioning.compare("V") != 0) {
                    newLine();
                    std::cout << "Invalid placement. Must select H or V!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                Ship sh(4);
                sh.addComponent(Component(Position(x,y)));
                if (positioning.compare("V") == 0) {
                    for (int i = 1; i < 4; i++) {
                        sh.addComponent(Component(Position(x,y+i)));
                    }
                } else {
                    for (int i = 1; i < 4; i++) {
                        sh.addComponent(Component(Position(x+i,y)));
                    }
                }
                if (board1.isValidSpot(sh) == true) {
                    valid = true;
                    p1.addShip(sh);
                    board1.occupySpace(sh,p1);
                } else {
                    newLine();
                    std::cout << "Invalid placement!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
            }
        } else {
            bool valid = false;
            while (valid == false) {
                std::cout << "Player 1, please enter x and y coordinates for the stern of your length 5 ship: ";
                std::string coord = "";
                std::cin >> coord;
                if(coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    newLine();
                    std::cout << "Cannot process output. " << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                int x = std::stoi(coord.substr(0,1));
                int y = std::stoi(coord.substr(2,3));
                std::cout << "Type V for vertical, H for horizontal: ";
                std::string positioning = "";
                std::cin >> positioning;
                if ((y+4 >= 9 and positioning.compare("V") == 0) or (x+4 >= 9 and positioning.compare("H") == 0)) {
                    newLine();
                    std::cout << "Invalid placement. Out of bounds!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                } else if (positioning.compare("H") != 0 and positioning.compare("V") != 0) {
                    newLine();
                    std::cout << "Invalid placement. Must select H or V!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                Ship sh(5);
                sh.addComponent(Component(Position(x,y)));
                if (positioning.compare("V") == 0) {
                    for (int i = 1; i < 5; i++) {
                        sh.addComponent(Component(Position(x,y+i)));
                    }
                } else {
                    for (int i = 1; i < 5; i++) {
                        sh.addComponent(Component(Position(x+i,y)));
                    }
                }
                if (board1.isValidSpot(sh) == true) {
                    valid = true;
                    p1.addShip(sh);
                    board1.occupySpace(sh,p1);
                } else {
                    newLine();
                    std::cout << "Invalid placement!" << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
            }
        }
        newLine();
        std::cout << "Player 1's board: " << std::endl;
        board1.printBoard();
    }
    newLine();
    std::cout << "Player 2's board: " << std::endl;
    board2.printBoard();
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            bool valid = false;
            while (valid == false) {
                std::cout << "Player 2, please enter x and y coordinates for the stern of your length 2 ship: ";
                std::string coord;
                std::cin >> coord;
                if(coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    newLine();
                    std::cout << "Cannot process output. " << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                int x = std::stoi(coord.substr(0,1));
                int y = std::stoi(coord.substr(2,1));
                std::cout << "Type V for vertical, H for horizontal: ";
                std::string positioning = "";
                std::cin >> positioning;
                if ((y+1 >= 9 and positioning.compare("V") == 0) or (x+1 >= 9 and positioning.compare("H") == 0)) {
                    newLine();
                    std::cout << "Invalid placement. Out of bounds!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                } else if (positioning.compare("H") != 0 and positioning.compare("V") != 0) {
                    newLine();
                    std::cout << "Invalid placement. Must select H or V!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                }
                Ship sh(2);
                sh.addComponent(Component(Position(x,y)));
                if (positioning.compare("V") == 0) {
                    sh.addComponent(Component(Position(x,y+1)));
                } else {
                    sh.addComponent(Component(Position(x+1,y)));
                }
                if (board2.isValidSpot(sh) == true) {
                    valid = true;
                    p2.addShip(sh);
                    board2.occupySpace(sh,p2);
                } else {
                    newLine();
                    std::cout << "Invalid placement!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                }
            }
        } else if (i == 1 or i == 2) {
            bool valid = false;
            while (valid == false) {
                std::cout << "Player 2, please enter x and y coordinates for the stern of your length 3 ship: ";
                std::string coord = "";
                std::cin >> coord;
                if(coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    newLine();
                    std::cout << "Cannot process output. " << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                int x = std::stoi(coord.substr(0,1));
                int y = std::stoi(coord.substr(2,3));
                std::cout << "Type V for vertical, H for horizontal: ";
                std::string positioning = "";
                std::cin >> positioning;
                if ((y+2 >= 9 and positioning.compare("V") == 0) or (x+2 >= 9 and positioning.compare("H") == 0)) {
                    newLine();
                    std::cout << "Invalid placement. Out of bounds!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                } else if (positioning.compare("H") != 0 and positioning.compare("V") != 0) {
                    newLine();
                    std::cout << "Invalid placement. Must select H or V!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                }
                Ship sh(3);
                sh.addComponent(Component(Position(x,y)));
                if (positioning.compare("V") == 0) {
                    for (int i = 1; i < 3; i++) {
                        sh.addComponent(Component(Position(x,y+i)));
                    }
                } else {
                    for (int i = 1; i < 3; i++) {
                        sh.addComponent(Component(Position(x+i,y)));
                    }
                }
                if (board2.isValidSpot(sh) == true) {
                    valid = true;
                    p2.addShip(sh);
                    board2.occupySpace(sh,p2);
                } else {
                    newLine();
                    std::cout << "Invalid placement!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                }
            }
        } else if (i == 3) {
            bool valid = false;
            while (valid == false) {
                std::cout << "Player 2, please enter x and y coordinates for the stern of your length 4 ship: ";
                std::string coord = "";
                std::cin >> coord;
                if(coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    newLine();
                    std::cout << "Cannot process output. " << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                int x = std::stoi(coord.substr(0,1));
                int y = std::stoi(coord.substr(2,3));
                std::cout << "Type V for vertical, H for horizontal: ";
                std::string positioning = "";
                std::cin >> positioning;
                if ((y+3 >= 9 and positioning.compare("V") == 0) or (x+3 >= 9 and positioning.compare("H") == 0)) {
                    newLine();
                    std::cout << "Invalid placement. Out of bounds!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                } else if (positioning.compare("H") != 0 and positioning.compare("V") != 0) {
                    newLine();
                    std::cout << "Invalid placement. Must select H or V!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                }
                Ship sh(4);
                sh.addComponent(Component(Position(x,y)));
                if (positioning.compare("V") == 0) {
                    for (int i = 1; i < 4; i++) {
                        sh.addComponent(Component(Position(x,y+i)));
                    }
                } else {
                    for (int i = 1; i < 4; i++) {
                        sh.addComponent(Component(Position(x+i,y)));
                    }
                }
                if (board2.isValidSpot(sh) == true) {
                    valid = true;
                    p2.addShip(sh);
                    board2.occupySpace(sh,p2);
                } else {
                    newLine();
                    std::cout << "Invalid placement!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                }
            }
        } else {
            bool valid = false;
            while (valid == false) {
                std::cout << "Player 2, please enter x and y coordinates for the stern of your length 5 ship: ";
                std::string coord = "";
                std::cin >> coord;
                if(coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    newLine();
                    std::cout << "Cannot process output. " << std::endl;
                    std::cout << "Player 1's board: " << std::endl;
                    board1.printBoard();
                    continue;
                }
                int x = std::stoi(coord.substr(0,1));
                int y = std::stoi(coord.substr(2,3));
                std::cout << "Type V for vertical, H for horizontal: ";
                std::string positioning = "";
                std::cin >> positioning;
                if ((y+4 >= 9 and positioning.compare("V") == 0) or (x+4 >= 9 and positioning.compare("H") == 0)) {
                    newLine();
                    std::cout << "Invalid placement. Out of bounds!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                } else if (positioning.compare("H") != 0 and positioning.compare("V") != 0) {
                    newLine();
                    std::cout << "Invalid placement. Must select H or V!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                }
                Ship sh(5);
                sh.addComponent(Component(Position(x,y)));
                if (positioning.compare("V") == 0) {
                    for (int i = 1; i < 5; i++) {
                        sh.addComponent(Component(Position(x,y+i)));
                    }
                } else {
                    for (int i = 1; i < 5; i++) {
                        sh.addComponent(Component(Position(x+i,y)));
                    }
                }
                if (board2.isValidSpot(sh) == true) {
                    valid = true;
                    p2.addShip(sh);
                    board2.occupySpace(sh,p2);
                } else {
                    newLine();
                    std::cout << "Invalid placement!" << std::endl;
                    std::cout << "Player 2's board: " << std::endl;
                    board2.printBoard();
                    continue;
                }
            }
        }
        newLine();
        std::cout << "Player 2's board: " << std::endl;
        board2.printBoard();
    }
    int turn = 1;
    BattleShipBoard b1Attack;
    BattleShipBoard b2Attack;
    newLine();
    while (board1.allShipsSunk() == false and board2.allShipsSunk() == false) {
        if (turn == 1) {
            std::cout << "Player 1 attack board: " << std::endl;
            b1Attack.printBoard();
            std::string coord = "";
            while (coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                std::cout << "Player 1, please enter coordinates to shoot: ";
                std::cin >> coord;
                if (coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    std::cout << "Invalid coordinates!" << std::endl;
                    std::cout << "Player 1 attack board: " << std::endl;
                    b1Attack.printBoard();
                }
            }
            int x = std::stoi(coord.substr(0,1));
            int y = std::stoi(coord.substr(2,3));
            if (x < 0 or y < 0 or x > 9 or y > 9) {
                std::cout << "Error. Invalid coordinates for shooting!" << std::endl;
                continue;
            }
            newLine();
            if (b1Attack.hitComponent(Position(x,y),board2) == false) {
                turn = 2;
                std::cout << "Player 1: MISS!" << std::endl;
            } else {
                std::cout << "Player 1: HIT!" << std::endl;
            }
            b1Attack.attack(Position(x,y),board2);
            board2.attack1(Position(x,y),board2);
        } else {
            std::cout << "Player 2 attack board: " << std::endl;
            b2Attack.printBoard();
            std::string coord = "";
            while (coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                std::cout << "Player 2, please enter coordinates to shoot: ";
                std::cin >> coord;
                if (coord.size() != 3 or isNumber(coord.substr(0,1)) == false or isNumber(coord.substr(2,1)) == false) {
                    std::cout << "Invalid coordinates!" << std::endl;
                    std::cout << "Player 2 attack board: " << std::endl;
                    b2Attack.printBoard();
                }
            }
            int x = std::stoi(coord.substr(0,1));
            int y = std::stoi(coord.substr(2,3));
            if (x < 0 or y < 0 or x > 9 or y > 9) {
                std::cout << "Error. Invalid coordinates for shooting!" << std::endl;
                continue;
            }
            newLine();
            if (b2Attack.hitComponent(Position(x,y),board1) == false) {
                turn = 1;
                std::cout << "Player 2: MISS!" << std::endl;
            } else {
                std::cout << "Player 2: HIT!" << std::endl;
            }
            b2Attack.attack(Position(x,y),board1);
            board1.attack1(Position(x,y),board1);
        }
    }
    if (board1.allShipsSunk() == true) {
        std::cout << "Player 2 wins! " << std::endl;
    } else {
        std::cout << "Player 1 wins! " << std::endl;
    }
}
