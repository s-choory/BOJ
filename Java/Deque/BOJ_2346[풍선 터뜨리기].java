import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		Deque<Integer> deque = new ArrayDeque<>();

		String [] str = br.readLine().split(" ");
		int [] stri = new int[n];
		
		for (int i = 0; i < n; i++) {
			deque.add(i+1);
			stri[i] = Integer.parseInt(str[i]);
		}
		
		System.out.println(deque);
		
	}
	
}

