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
		
		if(n==0) {
			bw.append("0");
		}else if(n==1){
			bw.append("1");
		}else {
			bw.append(String.valueOf(Fibonacci(n)));
		}
		bw.flush();
		bw.close();
	}
	
	static int Fibonacci(int n) {
		if(n>2) {
			return Fibonacci(n-1)+Fibonacci(n-2);
		}else {
			return 1;
		}
	}
}
