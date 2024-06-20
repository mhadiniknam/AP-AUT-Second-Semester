import java.util.Scanner ;
public class Maghsomelayh {
public static void main(String[] args) {
    System.out.print("Enter your integer");
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    int count = 0 ;
    for(int i = 1 ; i <= n ; i += 1) { 
        if(n % i == 0){
            System.out.format("%d\n", i);
            count++ ;
        }
    }
    System.out.format("%d has %d maghsom",n,count);   
}


}