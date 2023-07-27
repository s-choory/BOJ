import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder("");
		
		String n = br.readLine();
		int num = Integer.parseInt(n);
		int stack[] = new int[num];
		int idx = 1;
		int k = 1;
		boolean flag = true;
		
		try {
			for (int i = 1; i <= num; i++) {
				String s = br.readLine();
				int val = Integer.parseInt(s);
				while(stack[idx] != val) {
					sb.append("+\n");
					stack[idx++] = k++;
				}
				
				if(stack[idx] == val) {
					sb.append("-\n");
					stack[idx-1] = 0;
					idx--;
				}
			}
		} catch (Exception e) {
			flag = false;
			System.out.println("NO");
		}
		if(flag) {
			System.out.println(sb);
		}
	}
}
