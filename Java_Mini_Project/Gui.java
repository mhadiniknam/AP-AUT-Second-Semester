import javax.swing.JOptionPane ;
public class Gui {
    public static void main(String[] args) {
        //JOptionPane.showMessageDialog(null, "Hello" , "Warning",JOptionPane.ERROR_MESSAGE);
   // JOptionPane.showInternalConfirmDialog(null, "Hello", "title", 1, 1, null);
String ans = JOptionPane.showInputDialog(null, "enter your name...");
String message = String.format("Hi %s",ans);
JOptionPane.showMessageDialog(null, message);
}}
