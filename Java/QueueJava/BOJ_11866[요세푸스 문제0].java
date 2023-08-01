import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String s[] = br.readLine().split(" ");
		int n = Integer.parseInt(s[0]);
		int k = Integer.parseInt(s[1]);
		
		Queue<Integer> queue = new LinkedList<Integer>();
		
		for (int i = 1;  i<= n; i++)
			queue.add(i);
		
		bw.write("<");
		for(int i = 1; i<= n; i++) {
			for (int j = 0; j < k-1; j++) 
				queue.add(queue.poll());
		
			bw.write(String.valueOf(queue.poll()));
			if(i < n) 
				bw.write(", ");
		}
		bw.write(">");
		bw.flush();
		bw.close();
	}
}
