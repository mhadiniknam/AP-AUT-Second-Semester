public class EqSolver {
    public static void SolvEqu1(double a , double b) {
        System.out.println("we are solving a linear equation in the form of ax+b =0 ");
        System.out.format("in Which a is equal to %f and b is equal to %f ",a,b);

        double x = -b/a ; 
        System.out.format("The answer is %f",x); 
        
    }
}