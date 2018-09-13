
/**
 * 
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Assignment
{
    private int x;
    private int y;
    private String name;
    
    public Assignment(int n, int d, String na)
    {
        x = n;
        y = d;
        name = na;
    }
    
    /**
     * method to get percent of an assignment
     * @return score of assignment in percent
     */
    public double getPercent()
    {
        return 100*(x/y);
    }
    
    /**
     * method to get points earned on assignment
     * @return points earned on assignment
     */
    public int getNumerator()
    {
        return x;
    }
    
    /**
     * method to get total points the assignment is worth
     * @return total points the assignment is worth
     */
    public int getDenominator()
    {
        return y;
    }
}
