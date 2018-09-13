
/**
 * 
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Student
{
    private String name;
    private Class[] classd;
    
    public Student(String n)
    {
        name = n;
        classd = new Class[7];
    }
    
    /**
     * Method to determine whether student goes on fieldtrip
     * Student goes on a fieldtrip if student has no Fs or Ds 
     * on any of their classes, otherwise they do not go!
     * @return whether student goes on fieldtrip
     */
    public boolean goOnFieldTrip()
    {
        int occF = 0;
        int occD = 0;
        for(Class c: classd)
        {
            if(c.determineGrade(c.getOverallPercent()).equals("F"))
            {
                occF++;
            }
            else if(c.determineGrade(c.getOverallPercent()).equals("D"))
            {
                occD++;
            }
        }
        return occF == 0 && occD == 0;
    }
    
    /**
     * Method to display percentage as well as grade for 
     * every class in the array
     * @return the message containing percent and grade
     */
    public String[] displayGradesAndPercentages()
    {
        String[] message = new String[classd.length];
        for(int i = 0; i < classd.length; i++)
        {
            message[i] = classd[i].displayGradeAndPercent();
        }
        return message;
    }
    
    /**
     * Method to determine the GPA of a student based on 
     * grades received from classes and difficulty of the
     * class
     * @return the gpa 
     */
    public double determineGPA()
    {
        double qualityPTS = 0.0;
        for(Class a: classd)
        {
            qualityPTS += a.getQualityPTS();
        }
        return qualityPTS/classd.length;
    }
}
