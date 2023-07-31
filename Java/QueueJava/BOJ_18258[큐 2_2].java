import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static String Queue[];
	static int head = 0;
	static int tail = 0;
	
	public static void push(String n) {
		Queue[head++] = n.substring(5);
	}
	
	public static String pop() {
		String s = "";
		if(Queue[tail] == null) {
			s = "-1\n";
		}else {
			s = Queue[tail]+"\n";
			tail++;
		}
		return s;
	}
	
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		Queue = new String[n];
		
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			
			if(str.contains("push")) {
				push(str);
			}else if(str.equals("pop")) {
				String s = pop();
				bw.write(s);
			}else if(str.equals("size")) {
				bw.write(String.valueOf(head-tail));
				bw.newLine();
			}else if(str.equals("empty")){
				if(head - tail == 0)
					bw.write("1");
				else
					bw.write("0");
				bw.newLine();
			}else if(str.equals("front")){
				if(head - tail == 0)
					bw.write("-1");
				else
					bw.write(Queue[tail]);
				bw.newLine();
			}else if(str.equals("back")){
				if(head - tail == 0)
					bw.write("-1");
				else
					bw.write(Queue[head-1]);
				bw.newLine();
			}
		}
		bw.flush();
		bw.close();
	}
}
