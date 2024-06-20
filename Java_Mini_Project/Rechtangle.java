public class Rechtangle extends ShapeInh{
    private double height ;
    private double width ;
    private double Area ;
    private double Perimeter ;
    private double widht;

//----inner functions--------------------------------
    public Rechtangle (){
        this.height = 0.0;
        this.width = 0.0;
    }
    public Rechtangle (double h , double w){
        this.height = h;
        this.width = w;
    }
    public Rechtangle (double x){
        this.height = this.width ;
        this.width = x ; 
    }

//----Set & Get----
public double getheight(){
    return this.height ; 
}
public void setheight (double h){
    this.height = h ; 
}
public double getwidth(){
    return this.width ; 
}
public void setwidth (double w){
    this.widht = w ; 
}

//-----Area & Perimeter ----------------------------------------------------------------

    public double getArea(){
        return this.Area = this.height * this.width ; 
    }
    public double getPerimeter(){
        return this.Perimeter = 2*(this.height + this.width) ; 
    }
}
