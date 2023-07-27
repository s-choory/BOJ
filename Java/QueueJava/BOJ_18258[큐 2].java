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
		String Queue[] = new String[n];
		int idx = 0;
		int pidx = 0;
		
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			
			if(str.contains("push")) {
				Queue[idx++] = str.substring(5);
			}else if(str.equals("pop")) {
				if(Queue[pidx] == null) {
					bw.write("-1\n");
				}else {
					bw.write(Queue[pidx]);
					bw.newLine();
					pidx++;
				}
			}else if(str.equals("size")) {
				bw.write(String.valueOf(idx-pidx));
				bw.newLine();
			}else if(str.equals("empty")){
				if(idx - pidx == 0)
					bw.write("1");
				else
					bw.write("0");
				bw.newLine();
			}else if(str.equals("front")){
				if(idx - pidx == 0)
					bw.write("-1");
				else
					bw.write(Queue[pidx]);
				bw.newLine();
			}else if(str.equals("back")){
				if(idx - pidx == 0)
					bw.write("-1");
				else
					bw.write(Queue[idx-1]);
				bw.newLine();
			}
		}
		bw.flush();
		bw.close();
	}
}
