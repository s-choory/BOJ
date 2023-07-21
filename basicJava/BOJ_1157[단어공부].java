import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		
		String s = scan.next();
		
		s = s.toUpperCase();
		
		char [] alpha = new char[27];
		char w = 'A';
		for (int i = 0; i < alpha.length; i++) {
			alpha[i] = w;
			w++;
		}
		int [] index = new int[27];
		
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < alpha.length; j++) {
				if(alpha[j] == s.charAt(i)) {
					 if (j >= 0 && j < index.length) {
			                index[j]++;
			            }
				}
			}
		}
		int maxIndex = 0;
		int maxValue = 0;
		for (int i = 0; i < index.length; i++) {
			if(maxValue < index[i]) {
				maxIndex = i;
				maxValue = index[i];
			}
		}
		int count = 0;
		for (int i = 0; i < index.length; i++) {
			if (maxValue == index[i])
				count++;
		}
		if(count > 1) {
			System.out.println("?");
		}else {
			System.out.println(alpha[maxIndex]);
		}
		
	}
}