import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String n = br.readLine();
		int num = Integer.parseInt(n);
		
		for (int i = 0; i < num; i++) {
			int index = 0;
			String vps = br.readLine();
			for (int j = 0; j < vps.length(); j++) {
				if(vps.charAt(j) == '(') {
					index++;
				}
				else if(vps.charAt(j) == ')') {
					index--;
				}
				if(index < 0) {
					break;
				}
			}
			if(index == 0) {
				bw.write("YES");
			}else {
				bw.write("NO");
			}
			bw.newLine();
		}
		bw.flush();
		bw.close();
	}
}
