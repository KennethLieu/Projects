
/**
 * Write a description of class GradesTester here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class GradesTester
{
    public static void main(String[] args)
    {
        Grade[] c1 = new Grade[(int)(Math.random()*6)+3];
        for(int i = 0; i < c1.length; i++)
        {
            int a = (int)(Math.random()*5)+1;
            int b = (int)(Math.random()*7)+a;
            c1[i] = new Grade(a,b);
        }
        Gradebook grad = new Gradebook(c1);
        System.out.print("Original grades: ");
        grad.displayPercent();
        System.out.println("Average percent: " + grad.getAveragePercent() + "%");
        if(grad.hasPerfectScore()==true||grad.getAveragePercent()>=80)
        {
            System.out.println("No curve!");
        }
        else
        {
            System.out.println();
        }
        grad.curve();
        System.out.print("Curved grades: ");
        grad.displayPercent();
        System.out.println("Average percent: " + grad.getAveragePercent() + "%");
    }
}
