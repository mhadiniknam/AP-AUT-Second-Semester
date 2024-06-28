import java.util.Scanner ;

public class cipher{
	public static void main(String[] args){	
		// ---------- PreProcessing ----------------

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt() ; 
		String s3= scanner.nextLine() ; 
		for(int i = 0 ; i < n ; i++){
			String s = scanner.nextLine();
			// tokenizing and Parsing 
			// Regex
			// Use String manipulation methods
			String[] s1 = s.toLowerCase().split("\\s+");
			// Maybe we could handle this anywhere else BTW 

			//----------pass it through the functions--------
			switch(s1[0].length()){
				case 15 :
					AdditiveCipher(s1,s);	
					break ;
				case 21 :
					MultiplicativeCipher(s1,s);
					break ;
				case 13 :
					AffineCipher(s1,s);	
					break ;
				case 14 :
					MappingCipher(s1,s) ; 
					break ;
				default:
					System.out.println("There is a problem in Parser !");
					System.exit(0) ; 
			}
		}
	}
	private static void AdditiveCipher(String[] s,String s1){
		int key = 0 ; 
		String text = "";
		String output = "" ; 	
		int position1 = s1.indexOf("\"") ; 
		int position2 = s1.indexOf("\"",position1 +1 ) ; 
		text = s1.substring(position1 + 1 , position2 ).trim().toLowerCase() ; 
		for(int i = 0 ; i < s.length ; i++ ){
			if(s[i].equals("-key")){
				key = Integer.parseInt(s[i+1]) ;
				break ;
			}
		}
		for(int i = 0 ; i < text.length() ; i++ ) {
			Character c = ' ';
			if(text.charAt(i) != ' ' ){ 
				int x = text.codePointAt(i) ;
				x -= 97 ; 
				x += key ; 
				x = x % 26 ; 
				x += 97 ;
				c = (char) x ;
			}
			output += c ; 	
		}
		System.out.println(output.toUpperCase()) ;
	}

	private static void MultiplicativeCipher(String[] s,String s1){
		int key = 0 ; 
		String output = "" ; 	
		int position1 = s1.indexOf("\"") ; 
		int position2 = s1.indexOf("\"",position1 +1 ) ; 
		String text = s1.substring(position1 + 1 , position2 ).trim().toLowerCase() ; 
		for(int i = 0 ; i < s.length ; i++ ){
			if(s[i].equals("-key")){
				key = Integer.parseInt(s[i+1]) ;
				break ;
			}
		}
		for(int i = 0 ; i < text.length() ; i++ ) {
			Character c = ' ';
			if(text.charAt(i) != ' ' ){ 
				int x = text.codePointAt(i) ;
				x -= 97 ; 
				x *= key ; 
				x = x % 26 ; 
				x += 97 ;
				c = (char) x ; 
			}
			output += c ; 	

		}
		System.out.println(output.toUpperCase()) ;
	}	
	private static void AffineCipher(String[] s, String s1){
		int a = 0 , b = 0 ; 
		String output = "" ; 	
		boolean flag = false ; 
		int position1 = s1.indexOf("\"") ; 
		int position2 = s1.indexOf("\"",position1 +1 ) ; 
		String text = s1.substring(position1 + 1 , position2 ).trim().toLowerCase() ; 
		for(int i = 0 ; i < s.length ; i++ ){
			if(s[i].equals("-a")){
				a = Integer.parseInt(s[i+1]) ;
				if(flag){
					break ; 
				}
				flag = true ;
			}
			if(s[i].equals("-b")){
				b = Integer.parseInt(s[i+1]) ;
				if(flag){
					break ; 
				}
				flag = true ;
			}
		}
		for(int i = 0 ; i < text.length() ; i++ ) {
			Character c = ' ';
			if(text.charAt(i) != ' ' ){
				int x = text.codePointAt(i) ;
				x -= 97 ; 
				x *= a ;
				x += b ; 	
				x = x % 26 ; 
				x += 97 ;
				c = (char) x ; 
			}
			output += c ; 	
		}
		System.out.println(output.toUpperCase()) ;
	}

	private static void MappingCipher(String[] s,String s1){
		String output = "" ;
		int position1 = s1.indexOf("\"") ; 
		int position2 = s1.indexOf("\"",position1 +1 ) ; 
		String text = s1.substring(position1 + 1 , position2 ).trim().toLowerCase() ; 
		position1 = s1.indexOf("\"",position2+ 1) ; 
		position2 = s1.indexOf("\"",position1 +1 ) ; 
		String mapping = s1.substring(position1 + 1 , position2 ).trim().toLowerCase() ; 

		for(int i = 1 ; i < s.length ; ++i ){
			boolean a = false , b = false ;
			if(s[i].compareTo("-text") == 0 ){
				a = true ;
			}
			if(s[i].compareTo("-maping") == 0 ){
				b = true ;
			}
			if(a){
				break ;
			}
			if(b){
				String temp = "" ;
				temp = text ; 
				text = mapping ; 
				mapping = temp ;
				break; 
			}
		}
		for(int i = 0 ; i < text.length() ; i++ ) { 	
			Character c = ' ';
			if(text.charAt(i) != ' ' ){		
				int x = text.codePointAt(i) ;
				x -= 97 ; 
				c = mapping.charAt(x) ;
			}
			output += c ; 
		}
		System.out.println(output.toUpperCase()) ;
	}
}
