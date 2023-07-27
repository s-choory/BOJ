import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String n = br.readLine();
		int nInt = Integer.parseInt(n);
		ArrayList<String> stack = new ArrayList<>();
		
		for(int i=0; i<nInt; i++) {
			String str = br.readLine();
			
			if(!(str.equals("0"))) {
				stack.add(str);
			}else{
				stack.remove(stack.size()-1);
			}
		}
		int sum = 0;
		for(int i=0; i<stack.size(); i++) {
			sum += Integer.parseInt(stack.get(i));
		}
		bw.write(Integer.toString(sum));
		bw.flush();
		bw.close();
	}

}
