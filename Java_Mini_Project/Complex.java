public class Complex {
    public static final Complex i = new Complex(0,1);
    public static final Complex zero = new Complex();
    private double Real;
    private double Img;
    public Complex (){
        Real = 0 ;
        Img = 0 ; 
    }
    public Complex (double x){
        Real = x ;
        Img = 0; 
    }
    public Complex (double x,double y){
        Real = x ;
        Img = y ; 
    }
    public double getReal(Complex z){
        return(Real);
    }
    public void setReal(double x){
        Real = x ;
    }
    public double getImg(Complex z){
        return(Img);
    }
    public void setImg(double y){
        Img = y ;
    }

    /*
     
    @Override
public String toString {
    return String str = String.format("%f+ %fi",Real , Img); 
}

public Complex add(Complex z){
    return new Complex(Real + getReal()+Img + getImg());
}*/
public Complex multiply(Complex z){
    return new Complex(Real*z.getReal(z)-Img*z.getImg(z), Real *z.getImg(z)-Img*getReal(z));
    //We could also write our code in this way return new Complex((Real*z.getReal()-Img*z.getImg(),Real*z.getImg()-Img*getReal()))
    //We didnt bring any middle valuable   
}
public Complex divide(Complex z){
    //We know that z1 / z2 is eqal to 
    Complex newZ = new Complex(getReal(z),(-1)*getImg(z));
    Complex z1 = new Complex(Real,Img).multiply(newZ) ;
    double divider = Math.pow(getReal(z),2) +  Math.pow(getImg(z),2)  ;

    double zImg = getImg(z1)/divider ; 
    double zReal = getReal(z1)/divider ;
    return new Complex(zReal, zImg);
    }
}