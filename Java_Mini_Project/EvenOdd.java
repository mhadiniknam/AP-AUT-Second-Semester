import java.util.Scanner ; 
public class EvenOdd {
    public static void main(String[] args) {
        System.out.println("enter your number");
        Scanner input = new Scanner(System.in);
        int n = input.nextInt() ; 
        int m ;  
        m = n % 2 ; 
        if (m == 0 ){
            System.out.print("This is an even number");
        }else{
            System.out.print("This is an odd number");
        }
    }
}
