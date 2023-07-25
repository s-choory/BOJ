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
		String stack[] = new String[n];
		int idx = 0;
		
		for(int i=0; i<n; i++) {
			String str = br.readLine();
			
			if(str.contains("push")) {
				stack[idx++] = str.substring(5);
			}else if(str.equals("pop")) {
				if(idx == 0) {
					bw.write("-1\n");
				}else {
					bw.write(stack[idx-1]);
					bw.newLine();
					idx--;
				}
			}else if(str.equals("size")) {
				bw.write(String.valueOf(idx));
				bw.newLine();
			}else if(str.equals("empty")){
				if(idx == 0)
					bw.write("1");
				else
					bw.write("0");
				bw.newLine();
			}else if(str.equals("top")){
				if(idx == 0)
					bw.write("-1");
				else
					bw.write(stack[idx-1]);
				bw.newLine();
				
			}
			
		}
		bw.flush();
		bw.close();
		
	}
}
