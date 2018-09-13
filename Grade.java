
/**
 * Write a description of class Grade here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Grade
{
    private double x;
    private double y;
    public Grade()
    {
        x = 1;
        y = 2;
    }
    
    public Grade(double x1, double y1)
    {
        x = x1;
        y = y1;
    }
    
    public double getPercent()
    {
        return Math.round((x/y)*100*100)/100.0;
    }
    
    public double getDecimal()
    {
        return x/y;
    }
    
    public void changeGrade(double z)
    {
        x = z;
    }
    
    public void convertTo100()
    {
        if(y!=100)
        {
            x = x * (100/y);
            y = y * (100/y);  
        }
    }
    
    public double n()
    {
        return x;
    }
    
    public double d()
    {
        return y;
    }
}
