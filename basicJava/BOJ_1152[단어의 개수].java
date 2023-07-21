import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		
		String s = scan.nextLine();
		String S = s.trim();
		
		if(S.length()==0)
			System.out.println(0);
		else {
			String [] arr = S.split(" ");
			System.out.println(arr.length);
		}
	}
}
