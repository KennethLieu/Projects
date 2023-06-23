#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <cmath>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

std::string numToString(int x) {
    if (x >= 1000 and x < 1000000) {
        return std::to_string(x/1000) + "K";
    } else if (x >= 1000000) {
        return std::to_string(x/1000000) + "M";
    }
    return std::to_string(x);
}

std::string numToString1(int x) {
    if (x >= 1000 and x < 1000000) {
        return std::to_string(x/1000) + "K";
    } else if (x >= 1000000) {
        int y = (int)(x/1000);
        double z = y/1000.0;
        return std::to_string(z) + "M";
    }
    return std::to_string(x);
}

int stringToNum(std::string x) {
    if (x.substr(x.length()-1,1) == "K") {
        return std::stod(x.substr(0,x.length()-1)) * 1000;
    } else if (x.substr(x.length()-1,1) == "M") {
        return std::stod(x.substr(0,x.length()-1)) * 1000000;
    }
    return std::stod(x.substr(0,x.length()));
}

std::string removeTrailZeroes(std::string x) {
    int ind = 1000000;
    for (int i = x.length()-2; i >= 0; i--) {
        if (x.substr(i,1) != "0") {
            ind = i;
            break;
        }
    }
    return x.substr(0,ind+1) + x.substr(x.length()-1);

}


void printBoard(std::vector<std::tuple<int, int>> x) {
    for (unsigned int i = 0; i < x.size(); i++) {
        int trying = std::get<0>(x[i]);
        int num = std::get<1>(x[i]);
        std::cout << "Case #" << trying << ", Val = $" << numToString(num) << std::endl; 
    }
}

bool comparing(const std::tuple<int,int> &l, const std::tuple<int,int> &r) {
    return std::get<0>(l) < std::get<0>(r);
}

void printAvailableCash(std::vector<int> x) {
    std::cout << "Cash amounts available: " << std::endl;
    for (unsigned int i = 0; i < x.size(); i++) {
        std::cout << "$" << numToString(x[i]) << std::endl;
    }
}

int getValueOfCase(std::vector<std::tuple<int,int>> tup, int caseN) {
    for (unsigned int i = 0; i < tup.size(); i++) {
        if(std::get<0>(tup[i]) == caseN) {
            return std::get<1>(tup[i]);
        }
    }
    return -1;
}

bool caseNumberEliminated(std::vector<int> elim, int caseN) {
    for (unsigned int i = 0; i < elim.size(); i++) {
        if (elim[i] == caseN) {
            return true;
        }
    }
    return false;
}

int getBankAmount(std::vector<int> availables) {
    int total = 0;
    for (unsigned int i = 0; i < availables.size(); i++) {
        total += availables[i];
    }
    int x = (int)(total/availables.size());
    if (x%1000 >= 500) {
        return x - (x%1000) + 1000;
    }
    return x - (x%1000);
}

void removeCaseNum(std::vector<int> &x, int casen) {
    for (unsigned int i = 0; i < x.size(); i++) {
        if (casen == x[i]) {
            x.erase(x.begin()+i);
            break;
        }
    }
}

void printCasesEliminated(std::vector<int> c) {
    std::cout << "Cases eliminated: " << std::endl;
    if (c.size() == 0) {
        std::cout << "N/A";
    }
    for (unsigned int i = 0; i < c.size(); i++) {
        std::cout << numToString(c[i]) << " ";
    }
    std::cout << std::endl;
}

void removeAvailableCash(std::vector<int> &c, int cash) {
    for (unsigned int i = 0; i < c.size(); i++) {
        if (cash == c[i]) {
            c.erase(c.begin()+i);
            break;
        }
    }
}

void printAvailableCases(std::vector<int> c) {
    std::cout << "Cases remaining: " << std::endl;
    for (unsigned int i = 0; i < c.size(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

void printLines() {
    for (int i = 0; i < 30; i++) {
        std::cout << std::endl;
    }
}



int main() {
    srand(time(0));
    printLines();
    std::cout << "Deal or No Deal v1.0.0 (a C++ Development)" << std::endl;
    std::cout << "Developed by: Kenneth Lieu" << std::endl;
    sleep_for(seconds(10));
    printLines();
    std::string familiar;
    bool valid = false;
    while (valid == false) {
        std::cout << "Welcome to deal or no deal! We are excited to see you here! Are you familiar with the rules? (Type R to see rules, Type P to play): ";
        std::cin >> familiar;
        if (familiar == "R" or familiar == "P") {
            valid = true;
        } 
    }
    if (familiar == "R") {
        printLines();
        std::cout << "Below are the rules for the Deal or No Deal game: " << std::endl;
        sleep_for(seconds(5));
        std::cout << "The game will start off with 20 cases, ranging from $2 to $10 million " << std::endl;
        sleep_for(seconds(5));
        std::cout << "Your goal is to walk away with as much money as possible, and hopefully win the grand prize! " << std::endl;
        sleep_for(seconds(5));
        std::cout << "You will select one case, and that case is yours to keep" << std::endl;
        sleep_for(seconds(5));
        std::cout << "Along the way, you will eliminate the other cases, one by one, until either you sell your case to the banker or your case is the only case that remains: " << std::endl;
        sleep_for(seconds(5));
        std::cout << "After removing a certain number of cases, you will be offered a money amount from the banker for your case " << std::endl;
        sleep_for(seconds(5));
        std::cout << "You have a choice, Deal or No Deal? Take the deal, and you sell your case to the banker for the dollar amount they offer " << std::endl;
        sleep_for(seconds(5));
        std::cout << "Or NOT take the deal, and you will resume removing other cases! " << std::endl;
        sleep_for(seconds(5));
        std::cout << "After the round ends, you will be presented with a mystery case. If you choose to take it, will apply a random multiplier to your current total. " << std::endl;
        sleep_for(seconds(5));
        std::cout << "Random multipliers that could be applied: x0,x0.5,x1,x2,x4 " << std::endl;
        sleep_for(seconds(5));
        std::cout << "You can also choose NOT to take it, and whatever you left the game with is whatever you're walking away with! Take the gamble, if you dare!" << std::endl;
        sleep_for(seconds(5));
        familiar = "";
        while (true) {
            std::cout << "Type S to see scoring, or Type P to play the game: ";
            std::cin >> familiar;
            if (familiar == "S" or familiar == "P") {
                break;
            }
        }
        if (familiar == "S") {
            std::cout << "If you accept ANY deal from banker: your score = $ amount from banker" << std::endl;
            std::cout << "If you reject ALL deals from banker, but decide to switch your case with the last remaining case: your score = $ amount from other case" << std::endl;
            std::cout << "If you reject ALL deals from banker, but decide to keep your case: your score = $ amount from your case" << std::endl;

            std::cout << "If you decide to take mystery case: your score = $ amount from round * multiplier " << std::endl;
            std::cout << "If you decide NOT to take mystery case: your score = $ amount from round " << std::endl;
            sleep_for(seconds(5));
            while (true) {
                std::cout << "Type P to play: ";
                std::cin >> familiar;
                if (familiar == "P") {
                    break;
                }
            }
        }
    }
    std::vector<int> rep{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    std::vector<int> samp = rep;
    std::vector<int> cases;
    std::vector<int> availableCash;
    std::vector<int> eliminatedCases;
    std::vector<int> availableCaseNums;

    //all cases that are given
    cases.push_back(2);
    cases.push_back(1000);
    cases.push_back(2000);
    cases.push_back(4000);
    cases.push_back(5000);
    cases.push_back(10000);
    cases.push_back(20000);
    cases.push_back(40000);
    cases.push_back(50000);
    cases.push_back(75000);
    cases.push_back(100000);
    cases.push_back(200000);
    cases.push_back(400000);
    cases.push_back(500000);
    cases.push_back(750000);
    cases.push_back(1000000);
    cases.push_back(2000000);
    cases.push_back(4000000);
    cases.push_back(5000000);
    cases.push_back(10000000);

    //all cash amounts available that remain
    availableCash.push_back(2);
    availableCash.push_back(1000);
    availableCash.push_back(2000);
    availableCash.push_back(4000);
    availableCash.push_back(5000);
    availableCash.push_back(10000);
    availableCash.push_back(20000);
    availableCash.push_back(40000);
    availableCash.push_back(50000);
    availableCash.push_back(75000);
    availableCash.push_back(100000);
    availableCash.push_back(200000);
    availableCash.push_back(400000);
    availableCash.push_back(500000);
    availableCash.push_back(750000);
    availableCash.push_back(1000000);
    availableCash.push_back(2000000);
    availableCash.push_back(4000000);
    availableCash.push_back(5000000);
    availableCash.push_back(10000000);

    for (unsigned int i = 1; i <= 20; i++) {
        availableCaseNums.push_back(i);
    }


    std::vector<std::tuple<int,int>> tup; //vector of tuples (case#, cash)
    for (unsigned int i = 0; i < cases.size(); i++) {
        int x = rand()%(samp.size());
        std::tuple<int,int> tupl(samp[x],cases[i]);
        tup.push_back(tupl);
        samp.erase(samp.begin()+x);
    }
    std::sort(tup.begin(),tup.end(),&comparing);

    int bankAmount = -1;
    int casestoEliminate = -1;
    int rounded = 0;
    int caseN = -1;
    int moneyEarned = 0;

    //bool gameEnd = false;
    while(true) {
        if (rounded == 0) {
            while(true) {
                std::cout << "Please choose a case # from 1-20: ";
                std::cin >> caseN;
                if (caseN > 20 or caseN < 1) {
                    std::cout << "Invalid case number!" << std::endl;
                } else {
                    removeCaseNum(availableCaseNums,caseN);
                    break;
                }
            }
            printLines();
        }
        rounded++;
        switch(rounded) {
            case 1:
                casestoEliminate = 5;
                break;
            case 2:
                casestoEliminate = 4;
                break;
            case 3:
                casestoEliminate = 3;
                break;
            case 4:
                casestoEliminate = 2;
                break;
            case 5:
                casestoEliminate = 2;
                break;
            case 6:
                casestoEliminate = 1;
                break;
            case 7:
                casestoEliminate = 1;
                break;
        }
        int c = 0;
        int cased = -1;
        if (rounded != 8) {
            while (c < casestoEliminate) {
                printAvailableCash(availableCash);
                printCasesEliminated(eliminatedCases);
                printAvailableCases(availableCaseNums);
                std::cout << "Your case# is: " << caseN << std::endl;
                std::string fre = "cases";
                if (casestoEliminate-c == 1) {
                    fre = "case";
                }
                std::cout << "Please choose " << casestoEliminate-c << " more " << fre << " to eliminate: ";
                std::cin >> cased;
                if (cased > 20 or cased < 1 or cased == caseN or caseNumberEliminated(eliminatedCases,cased) == true) {
                    std::cout << "Invalid case number!" << std::endl;
                } else {
                    std::cout << "Opening case #" << cased << "... Please hold! " << std::endl;
                    sleep_for(seconds(3));
                    printLines();
                    std::cout << "Case eliminated: #" << cased << ", which corresponds to $" << numToString(getValueOfCase(tup,cased)) << std::endl;
                    sleep_for(seconds(5));
                    c++;
                    eliminatedCases.push_back(cased);
                    removeCaseNum(availableCaseNums,cased);
                    removeAvailableCash(availableCash,getValueOfCase(tup,cased));
                }
            }
            bankAmount = getBankAmount(availableCash);
            std::cout << "*Telephone ring*" << std::endl;
            sleep_for(seconds(2));
            std::cout << "It's the banker, let's see what he can offer you." << std::endl;
            sleep_for(seconds(5));
            std::string decision;
            std::string str = numToString1(bankAmount);
            while (true) {
                printAvailableCash(availableCash);
                if (str.substr(str.length()-1,1) == "M") {
                    str = removeTrailZeroes(str);
                }
                std::cout << "The banker will offer you $" << str << " for your case." << std::endl;
                sleep_for(seconds(5));
                std::cout << "Deal or no deal? (D/ND) ";
                std::cin >> decision;
                if (decision.compare("D") == 0 or decision.compare("ND") == 0) {
                    break;
                } else {
                    printLines();
                    std::cout << "Invalid input. Please type D if you want the deal, or ND if you don't want the deal." << std::endl;
                }
            }
            if (decision.compare("D") == 0) {
                moneyEarned = stringToNum(str);
                std::cout << "Deal! Congrats, you have earned a total of $" << str << "!" << std::endl;
                std::cout << "Let's see if you made a good deal or not... " << std::endl;
                sleep_for(seconds(5));
                std::cout << "Your case is case #" << caseN << ", which would've gotten you $" << numToString(getValueOfCase(tup,caseN)) << std::endl;
                if (moneyEarned >= stringToNum(numToString(getValueOfCase(tup,caseN)))) {
                    std::cout << "You have made a great deal!" << std::endl;
                } else {
                    std::cout << "You have NOT made a good deal..." << std::endl;
                }

                break;
            } else {
                std::cout << "No deal! " << std::endl;
                sleep_for(seconds(5));
                printLines();
            }
        } else {
            std::cout << "Alright, time for the FINAL round!" << std::endl;
            sleep_for(seconds(5));
            std::string dec;
            while (true) {
                printAvailableCash(availableCash);
                std::cout << "You have an option of whether to keep your case, or switch your case for the last remaining case. Switch, or keep? ";
                std::cin >> dec;
                if (dec.compare("switch") == 0 or dec.compare("keep") == 0) {
                    break;
                } else {
                    std::cout << "Invalid input. Please type keep to keep your case, or switch to switch your case with the other remaining case. " << std::endl;
                }
            }
            if (dec.compare("switch") == 0) {
                caseN = availableCaseNums[0];
                std::cout << "Switching the cases.. Your case # is now " << caseN << std::endl;
            }
            std::cout << "Let's see what your case holds..." << std::endl;
            sleep_for(seconds(5));
            std::cout << "Your remaining case is case #" << caseN << ", which is worth: $" << numToString(getValueOfCase(tup,caseN)) << std::endl;
            moneyEarned = getValueOfCase(tup,caseN);
            break;
        }
    }
    std::cout << "Feeling lucky? Try out the mystery case, free of charge. When opened, your profit will be given a random multiplier." << std::endl;
    sleep_for(seconds(5));
    std::cout << "Multipliers u can receive are: x4, x2, x1, x0.5, or x0. Take the gamble, if you dare!" << std::endl;
    sleep_for(seconds(5));
    std::cout << "If you take the gamble, your profits will either increase, decrease, or stay the same." << std::endl;
    sleep_for(seconds(5));
    std::cout << "If you don't take the gamble, your profits will stay the same." << std::endl;
    sleep_for(seconds(5));
    std::string gamble;
    while(true) {
        std::cout << "This is a once in a lifetime chance! Do u want to take the mystery case? (yes/no) ";
        std::cin >> gamble;
        if (gamble.compare("yes") == 0 or gamble.compare("no") == 0) {
            break;
        } else {
            printLines();
            std::cout << "Invalid input. Please enter yes to take the mystery case, or no to not take it." << std::endl;
            std::cout << "Remember: " << std::endl;
            std::cout << "If you take the gamble, your profits will either increase, decrease, or stay the same." << std::endl;
            std::cout << "If you don't take the gamble, your profits will stay the same." << std::endl;
        }
    }
    double mult = -1;
    std::string x = numToString1(moneyEarned);

    if (gamble.compare("no") == 0) {
        printLines();
        if (x.substr(x.length()-1,1) == "M") {
            x = removeTrailZeroes(x);
        }
        std::cout << "Your total amount earned is $" << x << std::endl;
    } else {
        printLines();
        std::cout << "You decided to take the gamble! Let's see if you made a wise decision! " << std::endl;
        sleep_for(seconds(5));
        int gambling = rand()%100;
        if (gambling >= 0 and gambling <= 24) {
            std::cout << "Well, that's unfortunate. Your multiplier is x0, making you bankrupt... What a shame! " << std::endl;
            mult = 0;
        } else if(gambling >= 25 and gambling <= 44) {
            std::cout << "Wow, that's got to hurt. Your multiplier is x0.5, cutting your total winnings in half. Better luck next time!" << std::endl;
            mult = 0.5;
        } else if(gambling >= 45 and gambling <= 79) {
            std::cout << "You have earned a x1 multiplier. Not good, not bad, your profits remain unaffected!" << std::endl;
            mult = 1;
        } else if(gambling == 80) {
            std::cout << "Wow, you hit the jackpot!! You have earned a x4 multiplier, quadripling your profits!! How lucky is that?!?" << std::endl;
            mult = 4;
        } else {
            std::cout << "That's pretty lucky! You got a x2 multiplier, doubling your profits! Make of it what you will!" << std::endl;
            mult = 2;
        }
    }
    moneyEarned = (int)round(moneyEarned * mult);
    std::string y = numToString1(moneyEarned);
    if (y.substr(y.length()-1,1) == "M") {
        y = removeTrailZeroes(y);
    }
    
    std::cout << "Your total amount earned is $" << y << std::endl;
    
}
