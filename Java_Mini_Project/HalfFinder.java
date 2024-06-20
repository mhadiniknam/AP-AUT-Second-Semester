import java.util.* ; 
public class HalfFinder {
    public static void main(String[] args) {
        System.out.print("Enter your integer.");
        Scanner input = new Scanner(System.in);
        double n = input.nextFloat();
        while( n >= 1 ){
            System.out.format("%f.\n",n);
             n /= 2 ;
        }
    }
}
