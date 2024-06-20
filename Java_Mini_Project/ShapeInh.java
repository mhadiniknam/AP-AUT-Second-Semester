public class ShapeInh {

  private String color ; 
  private boolean filled ; 
  public ShapeInh(){
    this.color = "";
    this.filled = false ;
  }

  public ShapeInh(String color , Boolean filled){
    this.color = color ;
    this.filled = filled ;
}
// Set and get method when we have private properties

public String GetColor(){
    return this.color ;
}
public Boolean GetFilled(){
    return this.filled ;
}
public void SetColor(String color){
    this.color = color ;
}
public void SetFilled(Boolean filled){
    this.filled = filled ;
}

/* 
public void Fill(Boolean filled){
    this.SetFilled(filled) = True ; 
}
Its wrong ;
*/
public void Fill(){
    this.SetFilled(true) ; 
}
public void UnFill(){
    this.SetFilled(false) ; 
}

} 