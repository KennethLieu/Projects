import java.util.*;
/**
 * Write a description of class CodeGuesser here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class CodeGuesser
{
    private int actual;
    private int numOfGuesses;
    private int numOfHints;
    private int guess;
    private boolean forfeitted;
    private List<Integer> guessed;
    public CodeGuesser(int value)
    {
        actual = value;
        numOfHints = 1;
        numOfGuesses = 20;
        guessed = new ArrayList<Integer>();
        forfeitted = false;
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
            if(numOfGuesses<=10)
            {
                forfeit();
                return "Your hint is: " + actual/100 + ". You lose! You have no guesses remaining!";
            }
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
