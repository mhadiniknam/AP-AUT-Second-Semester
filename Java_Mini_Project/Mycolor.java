 public enum Mycolor {

Black(0,0,0),
White(1,1,1),
Red(1,0,0),
Blue(0,0,1),
Yellow(1,1,0),
Green(0,1,0),
Cyan(0,1,1),
Magenta(1,0,1);


    private float R , G, B  ;

Mycolor(float r, float g, float b) {
    this.R = r ;
    this.G = g ;
    this.B = b ;
}
}