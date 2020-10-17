#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <tuple>

void printBoard(std::vector<std::tuple<int,int> > x) {
    for (unsigned int i = 0; i < x.size(); i++) {
        int trying = std::get<0>(x[i]);
        int num = std::get<1>(x[i]);
        std::cout << "Case #" << trying << ", Val = $" << num << std::endl; 
    }
}

bool comparing(const std::tuple<int,int> &l, const std::tuple<int,int> &r) {
    return std::get<0>(l) < std::get<0>(r);
}

void printAvailableCash(std::vector<int> x) {
    std::cout << "Cash amounts available: " << std::endl;
    for (unsigned int i = 0; i < x.size(); i++) {
        std::cout << "$" << x[i] << std::endl;
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
    return (int)(total/availables.size());
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
        std::cout << c[i] << " ";
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

int main() {
    srand(time(0));
    std::cout << "Welcome to deal or no deal!" << std::endl;
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
    int round = 0;
    int caseN = -1;
    int moneyEarned = 0;

    //bool gameEnd = false;
    while(true) {
        if (round == 0) {
            while(true) {
                std::cout << "Player 1, please choose a case # from 1-20: ";
                std::cin >> caseN;
                if (caseN > 20 or caseN < 1) {
                    std::cout << "Invalid case number!" << std::endl;
                } else {
                    removeCaseNum(availableCaseNums,caseN);
                    break;
                }
            }
        }
        round++;
        switch(round) {
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
        if (round != 8) {
            while (c < casestoEliminate) {
                printAvailableCash(availableCash);
                printCasesEliminated(eliminatedCases);
                printAvailableCases(availableCaseNums);
                std::cout << "Your case# is: " << caseN << std::endl;
                std::cout << "Player 1, please choose " << casestoEliminate-c << " more cases to kill: ";
                std::cin >> cased;
                if (cased > 20 or cased < 1 or cased == caseN or caseNumberEliminated(eliminatedCases,cased) == true) {
                    std::cout << "Invalid case number!" << std::endl;
                } else {
                    std::cout << "Case eliminated: #" << cased << ", which corresponds to $" << getValueOfCase(tup,cased) << std::endl;
                    c++;
                    eliminatedCases.push_back(cased);
                    removeCaseNum(availableCaseNums,cased);
                    removeAvailableCash(availableCash,getValueOfCase(tup,cased));
                }
            }
            bankAmount = getBankAmount(availableCash);
            std::cout << "*Telephone ring*" << std::endl;
            std::cout << "It's the banker, let's see what he can offer you." << std::endl;
            std::string decision;
            while (true) {
                printAvailableCash(availableCash);
                std::cout << "The banker will offer you $" << bankAmount << " for your case." << std::endl;
                std::cout << "Player 1, deal or no deal?(D/ND) ";
                std::cin >> decision;
                if (decision.compare("D") == 0 or decision.compare("ND") == 0) {
                    break;
                } else {
                    std::cout << "Invalid input. Please type D if you want the deal, or ND if you don't want the deal." << std::endl;
                }
            }
            if (decision.compare("D") == 0) {
                moneyEarned = bankAmount;
                std::cout << "Deal! Congrats, you have earned a total of $" << bankAmount << "!" << std::endl;
                std::cout << "Your case is case #" << caseN << ", which would've gotten you $" << getValueOfCase(tup,caseN) << std::endl;
                break;
            } else {
                std::cout << "No deal! Let the next round begin!" << std::endl;
            }
        } else {
            std::cout << "Alright final round!" << std::endl;
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
            }
            std::cout << "Your remaining case is case#" << caseN << ", which is worth: " << getValueOfCase(tup,caseN) << std::endl;
            moneyEarned = getValueOfCase(tup,caseN);
            break;
        }
    }
    int getCase = rand()%2;
    if (getCase == 0) {
        std::cout << "Your total amount earned is $" << moneyEarned << std::endl;
    } else {
        std::cout << "Feeling lucky? Try out the mystery case, free of charge. When opened, your profit will be given a random multiplier." << std::endl;
        std::cout << "Multipliers u can receive are: x4, x2, x1, x0.5, or x0. Take the gamble, if you dare!" << std::endl;
        std::cout << "If you take the gamble, your profits will either increase, decrease, or stay the same." << std::endl;
        std::cout << "If you don't take the gamble, your profits will stay the same." << std::endl;
        std::string gamble;
        while(true) {
            std::cout << "This is a once in a lifetime chance! Do u want to take the mystery case? (yes/no) ";
            std::cin >> gamble;
            if (gamble.compare("yes") == 0 or gamble.compare("no") == 0) {
                break;
            } else {
                std::cout << "Invalid input. Please enter yes to take the mystery case, or no to not take it." << std::endl;
                std::cout << "Remember: " << std::endl;
                std::cout << "If you take the gamble, your profitswill either increase, decrease, or stay the same." << std::endl;
                std::cout << "If you don't take the gamble, your profits will stay the same." << std::endl;
            }
        }
        double mult = -1;
        if (gamble.compare("no") == 0) {
            std::cout << "Your total amount earned is $" << moneyEarned << std::endl;
        } else {
            int gambling = rand()%100;
            if (gambling >= 0 and gambling <= 24) {
                std::cout << "Oooooooof.... How unfortunate... Your multiplier is x0, making you bankrupt... Thats gotta hurt bad!" << std::endl;
                mult = 0;
            } else if(gambling >= 25 and gambling <= 44) {
                std::cout << "Oof, that's gotta hurt. Your multiplier is x0.5, reducing your profits by half. Better luck next time!" << std::endl;
                mult = 0.5;
            } else if(gambling >= 45 and gambling <= 79) {
                std::cout << "You have earned a x1 multiplier. Not good, not bad, your profits remain unaffected." << std::endl;
                mult = 1;
            } else if(gambling == 80) {
                std::cout << "Wow, you hit the jackpot!! A x4 multiplier, quadripling your profits!! How lucky is that?!?" << std::endl;
                mult = 4;
            } else {
                std::cout << "Ooh, that's pretty lucky! You got a x2 multiplier, doubling your profits! Make of it what you will!" << std::endl;
                mult = 2;
            }
        }
        moneyEarned = (int)(moneyEarned * mult);
        std::cout << "Your total amount earned is $" << moneyEarned << std::endl;
    }
}