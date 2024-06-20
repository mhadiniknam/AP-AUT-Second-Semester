public class ShapeAbstract {
    private String color ; 
    private boolean filled ;
    
    public ShapeAbstract() {
        this("",false)
    }

    public ShapeAbstract(String color , boolean filled) {
        this.color = color ; 
        this.filled = filled ; 
    }

    public String Getcolor(){
        return this.color;
    }

    public boolean Getfilled(){
        return this.filled;
    }

    public void Setcolor(String c){
        this.color = c; 
    }
    public void Setfilled(boolean b){
        this.filled = b; 
    }
}