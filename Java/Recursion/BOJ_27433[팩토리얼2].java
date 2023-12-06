import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		br.close();
		
		long result = factorial(n);
		
		bw.append(String.valueOf(result));
		bw.flush();
		bw.close();
	}
	
	static long factorial(int n) {
		if(n>0) 
			return n*factorial(n-1);
		else
			return 1;
	}
}
