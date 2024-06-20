import java.util.* ; 
enum Answer {Yes , No};
public class YesNo {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in) ; 
        System.out.format("Are you Ok ??");
        String str = input.next();
        Answer A = Answer.valueOf(str);
        System.out.format("Entry %s \n",A);
        
    }
}