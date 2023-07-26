import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		while(true){
			char stack[] = new char[101];
			int idx = 0;
			
			String vps = br.readLine();
			if(vps.charAt(0) == '.')
				break;
			
			boolean isValid = true;
			
			for (int j = 0; j < vps.length(); j++) {
				char ch = vps.charAt(j);
				if(ch == '(' || ch == '[') {
					stack[idx] = ch;
					idx++;
				}
				else if(ch == ')') {
					if(idx > 0 && stack[idx-1] == '(')
						idx--;
					else {
						isValid = false;
						break;
					}
				}
				else if(ch == ']') {
					if(idx > 0 && stack[idx-1] == '[')
						idx--;
					else {
						isValid = false;
						break;
					}
				}
			}
			if(isValid && idx == 0) {
				bw.write("yes");
			}else {
				bw.write("no");
			}
			bw.newLine();
		}
		bw.flush();
		bw.close();
	}
}
