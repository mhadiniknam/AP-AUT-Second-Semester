import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        StringBuilder str = new StringBuilder("OOP");
        str.append(" 14012");

        System.out.println(str);
        str.reverse();
        System.out.println(str);
        str.replace(2,7,"Tamrin");
        System.out.println(str);
        System.out.println(str.indexOf("OO"));
        str.insert(5,"Ali");
        System.out.println(str);
        str.delete(5,8);
        System.out.println(str);
        System.out.println(str.length());

        //==============================

        ArrayList<String> Arr = new ArrayList<>();
        Arr.add("salam");
        ArrayList<String> Arr2 = new ArrayList<>();
        Arr2.add("OOP");
        Arr2.add("Ali");

        Arr.addAll(Arr2);

        System.out.println(Arr2.indexOf("OOP"));
        System.out.println(Arr2.indexOf("OP"));
        System.out.println(Arr.contains("Tamrin"));
        System.out.println(Arr.contains("salam"));

        Arr.addAll(Arrays.asList(new String[]{"Amir", "Mammad", "Array"}));

        System.out.println(Arr.get(5));

        Arr.remove(5);
        Arr.remove("salam");

        System.out.println(Arr.toString());

        for (String s : Arr) {
            System.out.print(s+", ");
        }

        Arr.set(1,"Oooo");

        Arr.clear();
        System.out.println(Arr.isEmpty());

        Student s1 = new Student();
        s1.a = "401555555";
        s1.moadel = 100;
        Student s2 = new Student();
        s2.a = "401444444";
        s1.moadel = 500;
        ArrayList<Student> students = new ArrayList<>();

        students.add(s1);
        students.add(s2);

        Collections.sort(students);

        System.out.println(students.get(0).a);

    }
}
class Student implements Comparable<Student> {
    String a = new String("10");
    int moadel =20;

    @Override
    public int compareTo(Student o) {
        return this.moadel-o.moadel;
    }
}