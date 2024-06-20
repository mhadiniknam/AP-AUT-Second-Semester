import java.util.Scanner ; 
public class GiveValue {
public static void main(String[] args) {
    System.out.print("send me a number");
    Scanner input = new Scanner(System.in);
    int x = input.nextInt();
    System.out.format("The entered number is %d",x);
}   
}