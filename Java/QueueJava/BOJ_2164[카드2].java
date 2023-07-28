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
		int Queue[] = new int[n*2];
		int idx = 0;
		
		for (int i = 0; i < Queue.length; i++) {
			Queue[i] = i+i;
		}
		
		while(true) {
			Queue[idx] = 0;
			idx++;
			bw.write(String.valueOf(Queue[idx]));	//큐 인덱스가 n값과 같아지면 마지막인줄 알았는데 앋뇜
			bw.newLine();
			if(idx == n)
				break;
			n++;
			Queue[n-1] = Queue[idx];
			
			Queue[idx] = 0;
			idx++;
		}
		
		for (int i : Queue) {
			if(i != 0)
				bw.write(String.valueOf(i));
		}
		
	
		bw.flush();
		bw.close();
	}
}
