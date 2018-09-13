
/**
 * Write a description of class Gradebook here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Gradebook
{
    private Grade[] grades;
    
    public Gradebook()
    {
        grades = new Grade[10];
    }
    
    public Gradebook(Grade[]c)
    {
        grades = c;
    }
    
    public void displayPercent()
    {
        for(Grade a: grades)
        {
            System.out.print(a.getPercent() + "% ");
        }
    }
    
    public boolean hasPerfectScore()
    {
        for(Grade a: grades)
        {
            if(a.getPercent()==100)
            {
                return true;
            }
        }
        return false;
    }
    
    public double getAveragePercent()
    {
        double p = 0;
        for(Grade a: grades)
        {
            p += a.getPercent();
        }
        return Math.round((p/grades.length)*100)/100.0;
    }
    
    public void curve()
    {
        if(hasPerfectScore()==false&&getAveragePercent()<80)
        {
            double max = 0;
            for(Grade a: grades)
            {
                if(a.getPercent()>max)
                {
                    max = a.getPercent();
                }
            }
            double diff = 100 - max;
            for(int i = 0; i < grades.length; i++)
            {
                grades[i].convertTo100();
                grades[i].changeGrade(diff+grades[i].n());
            }
        }
    }
}
