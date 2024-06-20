public class mean {
  
    /**
     * @param args
     */
    public static void main(String[] args) {
        double X[] = {12 ,20 ,14 ,18 ,19 , 17, 20 ,18 };
        double sum = 0 ;
        for (double x:X) {
        sum = sum + x ; 
        }
        double mean = sum / X.length ; 
        double var2 ; 
        for (double p:X){
            var2 = var2 +  Math.pow(mean-p,2);
        }
        double fvar = (1/X.length) * var2 ; 
        double fsigma2 = Math.sqrt(fvar); 
        System.out.format("the mean is %f\n the variance is %f \n the sigma2 is %f",mean,fvar,fsigma2);
        
    }
}
