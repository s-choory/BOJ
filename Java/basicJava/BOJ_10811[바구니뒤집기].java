import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		int m = scan.nextInt();
		
		Integer arr[] = new Integer[n];
		
		for(int i=0; i<n; i++) {
			arr[i] = i+1;
		}
		
		Arrays.asList(arr);
		
		for(int i=0; i<m; i++) {
			int start = scan.nextInt();
			int end = scan.nextInt();

			Collections.reverse(Arrays.asList(arr).subList(start-1, end));
		}
		
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
	}
	

}
