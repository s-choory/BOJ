import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		int n=0;
		
		int[] arr = new int[9];
		for(int i=0; i<9; i++) {
			int a = scan.nextInt();
			arr[i] = a;
		}
		int max = arr[0];
		
		for(int i=1; i<9; i++) {
			if(arr[i] > max) {
				max = arr[i];
				n = i;
			}
		}
		System.out.println(max);
		System.out.println(n+1);
	}

}
