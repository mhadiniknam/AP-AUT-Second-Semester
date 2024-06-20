import java.util.*;

public class Dise {
    public static void main(String[] args) {
    Random rnd = new Random();
    int Eterate = 10 ; 
    int s = 6 ;  
    int A[] = new int[s+1]; 
    for(int i = 1 ; i < Eterate ; i++) {
        int k = rnd.nextInt(s)+1;
        A[k]++ ; 
    }
    double p[] = new double[s+1];
    for(int q = 1 ; q < s ; q++) {
        p[q] =  (double) A[q]/Eterate ;
        System.out.format("There are %d time for the number %d with the chance of %f \n", A[q] , q , p[q]);
    }
    
}
}