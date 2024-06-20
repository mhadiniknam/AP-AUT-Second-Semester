import java.util.Scanner;
public class EvenOddnew {

    public static void main(String[] args) {
        System.out.print("enter an integer");
            Scanner input = new Scanner(System.in);
            int n = input.nextInt();
            String type = (n % 2 == 0)? ("This is an even number") : ("This is an odd number");
            System.out.format("Your number is an %s number and it's %d",type , n);
    }
}