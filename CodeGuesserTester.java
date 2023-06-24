import java.util.*;
/**
 * Write a description of class CodeGuesserTester here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
class CodeGuesser
{
    private int actual;
    private int numOfGuesses;
    private int numOfHints;
    private int guess;
    private boolean forfeitted;
    private List<Integer> guessed;
    private int pointsAway;
    public CodeGuesser(int value)
    {
        actual = value;
        numOfHints = 1;
        numOfGuesses = 20;
        guessed = new ArrayList<Integer>();
        forfeitted = false;
        pointsAway = 1000;
    }
    
    /**
     * method to allow player 2 to make a guess and return
     * appropriate message based on remaining guesses, and
     * whether the guess is correct or not
     * @param the guess made
     * @return an appropriate message based on guess made
     */
    public String guess(int a)
    {
        guess = a;
        guessed.add(guess);
        numOfGuesses--;
        if (Math.abs(guess-actual) < pointsAway) {
            System.out.println("You're getting warmer...");
            pointsAway = Math.abs(guess-actual);
        } else if (Math.abs(guess-actual) > pointsAway){
            System.out.println("You're getting colder...");
        } else {
            System.out.println("You're getting neither colder nor warmer...");
        }
        if(actual!=guess)
        {
            if(numOfGuesses==0)
            {
                return "Incorrect code! You lose! You have ran out of guesses!";
            }
            return "Incorrect code! Try again!";
        }
        return "Correct! You win!";
    }
    
    /**
     * method to return the list of codes already guessed
     * @return arraylist of guessed codes
     */
    public List<Integer> getGuessed()
    {
        return guessed;
    }
    
    
    /**
     * method to find the best guess, or a guess within the 
     * codes already guessed that is the closest to the actual
     * code
     * @return the code guessed that is closest to the actual
     * code
     */
    public int findBestGuess()
    {
        if(guessed.size()==0)
        {
            return -1;
        }
        int diff = findLowestDifference(actual);
        int[] differences = new int[guessed.size()];
        for(int i = 0; i < differences.length; i++)
        {
            differences[i] = Math.abs(guessed.get(i)-actual);
        }
        int ind = -1;
        for(int i = 0; i < differences.length; i++)
        {
            if(differences[i] == diff)
            {
                ind = i;
            }
        }
        return guessed.get(ind);
    }
    
    /**
     * method that generates an appropriate message when 
     * using up a hint, which consumes 10 of the 20 guesses
     * in the process.
     * If guesses are 10 or less when using hint, player 2 will
     * lose by default after consuming such hint
     * @return appropriate message based on the number of hints
     * 
     */
    public String useHint()
    {
        if(numOfHints == 0)
        {
            return "You have used up your hints!";
        }
        else
        {
            numOfGuesses-=10;
            numOfHints--;
            return "Your hint is: " + actual/100;
        }
    }
    
    /**
     * method to allow player 2 to forfeit the game if they 
     * want to, but doing so will give player 1 victory by
     * default
     */
    public void forfeit()
    {
        numOfGuesses = 0;
        forfeitted = true;
    }
    
    /**
     * method that checks if player 2 actually did forfeit
     * @return whether player 2 forfeit
     */
    public boolean didForfeit()
    {
        return forfeitted;
    }
    
    /**
     * returns number of guesses player 2 has remaining
     * @return the number of guesses
     */
    public int getGuesses()
    {
        return numOfGuesses;
    }
    
    /**
     * method that checks if player 1 wins, based on whether 
     * player 2 runs out of guesses and doesn't guess
     * correct code
     * @return whether player 1 wins
     */
    public boolean player1Wins()
    {
        return numOfGuesses == 0 && guess != actual;
    }
    
    /**
     * method that checks if player 2 wins, based on whether 
     * player 2 guesses correct code
     * @return whether player 2 wins
     */
    public boolean player2Wins()
    {
        return guess == actual;
    }
    
    /**
     * method that determines the multiplier, which is 
     * determined based on whether the hint is used up
     * if the hint is used up, multiplier is 5, if it isn't
     * used up, the multiplier is 10
     * @return points multiplier
     */
    public int getMultiplier()
    {
        if(numOfHints == 1)
        {
            return 10;
        }
        return 5;
    }
    
    /**
     * method that determines the number of points based on who
     * wins the round. player 1's points will be based on the
     * difference between best guess and actual code, and player
     * 2's points will be based on number of guesses, and whether
     * a hint is consumed
     * the victor will ALWAYS earn at least 1 victory point!
     * @return number of points earned
     */
    public int determinePoints()
    {
        if(player1Wins()==true)
        {
            if(forfeitted == true)
            {
                return 1 + findLowestDifference(actual) + numOfGuesses;
            }
            return 1 + findLowestDifference(actual);
        }
        return 1 + getMultiplier();
    }
    
    /**
     * method that returns the number of hints player 2 has
     * @return number of hints
     */
    public int getHints()
    {
        return numOfHints;
    }
    
    /**
     * method that returns the actual code player 1 enters
     * @return actual code
     */
    public int getActual()
    {
        return actual;
    }
    
    /**
     * method that finds the lowest difference of all the 
     * guesses made from the actual code
     * @param the actual code
     * @return the difference
     */
    public int findLowestDifference(int a)
    {
        int diff = 1000000;
        for(int i = 0; i < guessed.size(); i++)
        {
            if(Math.abs(a-guessed.get(i))<diff)
            {
                diff = Math.abs(a-guessed.get(i));
            }
        }
        return diff;
    }
    
    /**
     * method that determines whether the game plays again
     * based on the decisions of player 1 and player 2
     * @param the decisions made by those players
     * @return whether game plays again
     */
    public boolean playAgain(String dec, String dec1)
    {
        return dec.equalsIgnoreCase("yes") && dec1.equalsIgnoreCase("yes");
    }

}



public class CodeGuesserTester {

    public static void timeDelay(long s) {
        try {
            Thread.sleep(s*1000);
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }
    }

    public static void printLines() {
        for (int i = 0; i < 30; i++) {
            System.out.println();
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        String d2 = "";
        CodeGuesser d = null;
        int player1Points = 0;
        int player2Points = 0;
        printLines();
        System.out.println("Code Guesser v1.0.0 (a Java Development)");
        System.out.println("Developed by: Kenneth Lieu");
        timeDelay(10);
        printLines();
        String x = "";
        do {
            System.out.print("Welcome to the CodeGuesser game! We are happy to see you here! Are you familiar with the rules? (Type R to see rules, or P to play): ");
            x = in.nextLine();
        } while (!x.equals("R") && !x.equals("P"));

        if (x.equals("R")) {
            printLines();
            System.out.println("Below are the rules for the Code Guesser game: ");
            timeDelay(5);
            System.out.println("The CPU will generate a random 3 digit code from 1 to 999 ");
            timeDelay(5);
            System.out.println("Your goal is to guess the code using as few guesses as possible, with only 20 guesses! ");
            timeDelay(5);
            System.out.println("You can use a hint, which consumes 10 guesses and provides digit in hundreds place ");
            timeDelay(5);
            System.out.println("Game will end when you run out of guesses or guess the correct code ");
            timeDelay(5);
            System.out.println("After the round, you will be given an option to play again or not ");
            timeDelay(5);
            System.out.println("After game ends, whoever wins most points win the game. If tie, tiebreaker will be a random draw! ");
            timeDelay(5);
            x = "";
            do {
                System.out.print("Type S to see scoring, or Type P to play the game: ");
                x = in.nextLine();
            } while (!x.equals("S") && !x.equals("P"));
            if (x.equals("S")) {
                printLines();
                System.out.println("Scoring for Code Guesser: ");
                System.out.println();
                System.out.println("CPU score: proximity your guess is from actual guess + 1 victory point");
                System.out.println("Your score = number of guesses * (5 if hint is used, 10 if NOT used) + 1 victory point");
                System.out.println();
                timeDelay(5);
                x = "";
                do {
                    System.out.print("Type P to play the Code Guesser game: ");
                    x = in.nextLine();
                } while (!x.equals("P"));
            }
        }
        do
        {
            int a = (int)((Math.random()*999)+1);
            d = new CodeGuesser(a);
            for(int i = 0; i < 300; i++)
            {
                System.out.println();
            }
            do
            {
                System.out.println("Number of guesses: " + d.getGuesses());
                System.out.println("Number of hints: " + d.getHints());
                System.out.println("Already guessed: " + d.getGuessed());
                if (d.getGuesses() > 10) {
                    System.out.print("Enter the code(-1 to forfeit, -2 to grab hint): ");
                }   else {
                    System.out.print("Enter the code(-1 to forfeit): ");
                }
                int guess = in.nextInt();
                System.out.println();
                switch(guess)
                {
                    case -1: 
                        System.out.print("Are you sure you want to quit? ");
                        String dec = in.next();
                        if(dec.equalsIgnoreCase("yes"))
                        {
                            d.forfeit();
                            System.out.println("Game forfeitted! Player 2 loses by default!");
                        }
                    break;
                    case -2:
                        if (d.getGuesses() > 10) {
                            System.out.println(d.useHint());
                        } else {
                            System.out.println("You have too few guesses to take on a hint! ");
                        }
                        break;
                    default:
                        System.out.println(d.guess(guess));
                }
                System.out.println();
            }while(d.player1Wins()==false&&d.player2Wins()==false);
            if(d.player1Wins()==true)
            {
                System.out.println("CPU victory!");
                System.out.println("Actual code: " + d.getActual());
                System.out.println("Number of guesses: " + d.getGuesses());
                try
                {
                    if(d.findBestGuess()==0)
                    {
                        throw new Exception("No best guess available!");
                    }
                    System.out.println("Best guess: " + d.findBestGuess());
                }
                catch(Exception e)
                {
                    System.out.println(e.getMessage());
                }
                System.out.println("Points earned: " + d.determinePoints());
                player1Points+=d.determinePoints();
            }
            else
            {
                System.out.println("Your victory!");
                System.out.println("Number of guesses: " + d.getGuesses());
                System.out.println("Number of hints: " + d.getHints());
                System.out.println("Multiplier: " + d.getMultiplier());
                System.out.println("Points earned: " + d.determinePoints());
                player2Points+=d.determinePoints();
            }
            System.out.println();
            System.out.println("CPU points: " + player1Points);
            System.out.println("Your points: " + player2Points);
            System.out.print("Dp you, do you want to play again? ");
            d2 = in.next();
        }while(d.playAgain("yes",d2));
        if(player1Points>player2Points)
        {
            System.out.println("CPU Wins!");
        }
        else if(player1Points<player2Points)
        {
            System.out.println("Player 2 Wins!");
        }
        else
        {
            System.out.println("Tied! Winner will be decided at random!");
            System.out.println("1 = CPU victory, 2 = Your victory! ");
            int fate = (int)(Math.random()*2)+1;
            System.out.println("Fate: " + fate);
            switch(fate)
            {
                case 1: 
                System.out.println("CPU Wins!");
                break;
                default:
                System.out.println("Player 2 Wins!");
            }
        }
        in.close();
    }
}
