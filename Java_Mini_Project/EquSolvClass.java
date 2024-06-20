public class EquSolvClass {
    public static void Solve(double a , double b) {
        System.out.println("we are solving a linear equation in the form of ax+b =0 ");
        System.out.format("in Which a is equal to %f and b is equal to %f\n ",a,b);
        double x = -b/a ;
        System.out.format("The answer of your equation is %f",x);   
    }
    public static void Solve(double a , double b , double c) {
        double delta = Math.sqrt(Math.pow(b,2))-4*a*c ; 
        System.out.println("we are solving a linear equation in the form of a^2x+bx+c =0 ");
        System.out.format("in Which a=/f , b=%f , c=%f",a,b,c);
       
        if(delta > 0){
            double x1 = (-b - Math.sqrt(delta))/2*a ; 
            double x2 = (-b + Math.sqrt(delta))/2*a ;
            System.out.format("The roots are %f and %f",x1 ,x2);
        }else if(delta == 0) {
            double x = -b/2*a ;
            System.out.format("The answer is %f",x); 
        }else{
            System.out.print("This equation doesn't have root");
        };

        
        }
    }
  

