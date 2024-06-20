import java.util.Scanner ; 
public class testEqu {
    public static void main(String[] args) { 
        System.out.println("Enter a coefficient");


        Scanner input1 = new Scanner(System.in);
        System.out.println("Enter b coefficient");
        Scanner input2 = new Scanner(System.in);
        System.out.println("Enter c coefficient");
        Scanner input3 = new Scanner(System.in);
        float a = input1.nextFloat();
        float b = input2.nextFloat();
        float c = input3.nextFloat();
        EquSolvClass.Solve(a , b ,c);


        
    }

}
