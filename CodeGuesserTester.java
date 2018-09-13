import java.util.*;
/**
 * Write a description of class CodeGuesserTester here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class CodeGuesserTester
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        String d1 = "";
        String d2 = "";
        CodeGuesser d = null;
        int player1Points = 0;
        int player2Points = 0;
        do
        {
            System.out.print("Player 1, enter a 3 digit code for player 2 to guess: ");
            int a = in.nextInt();
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
                System.out.print("Player 2, enter the code(-1 to forfeit, -2 to grab hint if available): ");
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
                    System.out.println(d.useHint());
                    break;
                    default:
                    System.out.println(d.guess(guess));
                }
                System.out.println();
            }while(d.player1Wins()==false&&d.player2Wins()==false);
            if(d.player1Wins()==true)
            {
                System.out.println("Player 1 victory!");
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
                System.out.println("Player 2 victory!");
                System.out.println("Number of guesses: " + d.getGuesses());
                System.out.println("Number of hints: " + d.getHints());
                System.out.println("Multiplier: " + d.getMultiplier());
                System.out.println("Points earned: " + d.determinePoints());
                player2Points+=d.determinePoints();
            }
            System.out.println();
            System.out.println("Player 1 points: " + player1Points);
            System.out.println("Player 2 points: " + player2Points);
            System.out.print("Player 1, do you want to play again? ");
            d1 = in.next();
            System.out.print("Player 2, do you want to play again? ");
            d2 = in.next();
        }while(d.playAgain(d1,d2));
        if(player1Points>player2Points)
        {
            System.out.println("Player 1 Wins!");
        }
        else if(player1Points<player2Points)
        {
            System.out.println("Player 2 Wins!");
        }
        else
        {
            System.out.println("Tied! Winner will be decided at random!");
            System.out.println("1 = Player 1 victory, 2 = Player 2 victory! ");
            int fate = (int)(Math.random()*2)+1;
            System.out.println("Fate: " + fate);
            switch(fate)
            {
                case 1: 
                System.out.println("Player 1 Wins!");
                break;
                default:
                System.out.println("Player 2 Wins!");
            }
        }
    }
}
