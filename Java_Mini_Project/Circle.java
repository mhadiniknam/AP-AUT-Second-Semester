public class Circle extends ShapeInh {
    private double radius ; 
    private double Area ;
    private double Perimeter ; 
 

    public Circle() {
        super();
        this.radius = 0 ;
    }

    public Circle(double r) {
        super();
        this.radius = r ;
    } 
    public Circle(double r , String color , boolean Filled) {
        super(color , Filled);
        this.radius = r ;
    } 
    public double getradius(){
        return this.radius ; 
    }
    public void setradius (double r){
        this.radius = r ; 
    }
    /* 
    public double getArea(double r){
        this.Area = 2 * r * Math.PI  ;        
    }
    fargh in code va code payin in ast ke 
    in code migoyad to yek r be man bede man be to area midam 
    vali code payin mige baraye class dakhel man area hesam mikonam
    */
    public double getArea(){
        return this.Area = this.radius * 2 *Math.PI;        
    }
    public double getPerimeter(){
       return this.Perimeter = Math.pow(this.radius,2) *Math.PI  ;        
    }
    
}