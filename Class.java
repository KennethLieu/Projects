
/**
 * 
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Class
{
    private String name;
    private String classType;
    private String rigorType;
    private int period;
    private Assignment[] ass;

    public Class(String n, String t, String r, int p)
    {
        name = n;
        classType = t;
        rigorType = r;
        period = p;
        ass = new Assignment[15];
    }
    
    /**
     * Method to determine overall percentage of a given class
     * @return percentage of a given class
     */
    public double getOverallPercent()
    {
        double a = 0.0;
        double b = 0.0;
        for(Assignment d: ass)
        {
            a += d.getNumerator();
            b += d.getDenominator();
        }
        return 100*(a/b);
    }
    
    /**
     * Method to determine a letter grade for a given class
     * based on the percentage given
     * @param the given percentage
     * @return the letter grade
     */
    public String determineGrade(double p)
    {
        if(p>=90)
        {
            return "A";
        }
        else if(p>=80)
        {
            return "B";
        }
        else if(p>=70)
        {
            return "C";
        }
        else if(p>=60)
        {
            return "D";
        }
        else
        {
            return "F";
        }
    }
    
    /**
     * Determining the amount of quality points based on
     * course rigor and grades earned for a specified class
     * @return the amount of quality points earned
     */
    public double getQualityPTS()
    {
        if(rigorType.equals("AP"))
        {
            if(determineGrade(getOverallPercent()).equals("A"))
            {
                return 5;
            }
            else if(determineGrade(getOverallPercent()).equals("B"))
            {
                return 4;
            }
            else if(determineGrade(getOverallPercent()).equals("C"))
            {
                return 3;
            }
            else if(determineGrade(getOverallPercent()).equals("D"))
            {
                return 1;
            }
        }
        else if(rigorType.equals("H"))
        {
            if(determineGrade(getOverallPercent()).equals("A"))
            {
                return 4.5;
            }
            else if(determineGrade(getOverallPercent()).equals("B"))
            {
                return 3.5;
            }
            else if(determineGrade(getOverallPercent()).equals("C"))
            {
                return 2.5;
            }
            else if(determineGrade(getOverallPercent()).equals("D"))
            {
                return 1;
            }
        }
        else
        {
            if(determineGrade(getOverallPercent()).equals("A"))
            {
                return 4;
            }
            else if(determineGrade(getOverallPercent()).equals("B"))
            {
                return 3;
            }
            else if(determineGrade(getOverallPercent()).equals("C"))
            {
                return 2;
            }
            else if(determineGrade(getOverallPercent()).equals("D"))
            {
                return 1;
            }
        }
        return 0;
    }
    
    /**
     * method that displays the percentage with grade of a 
     * specific class
     * @return the message of percent with class
     */
    public String displayGradeAndPercent()
    {
        return getOverallPercent() + "% " + determineGrade(getOverallPercent());
    }
    
    /**
     * method to return the name of a class
     * @return name of class
     */
    public String getName()
    {
        return name;
    }
    
    /**
     * method to return the type of class
     * @return type of class
     */
    public String getClassType()
    {
        return classType;
    }
    
    /**
     * method to return the rigor of class
     * @return rigor of class
     */
    public String getRigorType()
    {
        return rigorType;
    }
    
    /**
     * method to return the period in which class takes place
     * @return period of class
     */
    public int getPeriod()
    {
        return period;
    }
}
