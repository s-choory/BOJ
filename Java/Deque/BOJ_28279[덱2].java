import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
	
	static Deque<Integer> deque = new ArrayDeque<>();
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		while(n-- > 0) {
			solution(br.readLine());
		}
		br.close();
		
		System.out.println(sb);
	}
	static void solution(String query) {
		char c = query.charAt(0);
		switch (c) {
		case '1':deque.addFirst(Integer.parseInt(query.substring(2)));return;
		case '2':deque.addLast(Integer.parseInt(query.substring(2)));return;
		case '3':sb.append((deque.isEmpty()?"-1":deque.pop())+"\n");return;
		case '4':sb.append((deque.isEmpty()?"-1":deque.pollLast())+"\n");return;
		case '5':sb.append((deque.size())+"\n");return;
		case '6':sb.append((deque.isEmpty()?"1":"0")+"\n");return;
		case '7':sb.append((deque.isEmpty()?"-1":deque.peekFirst())+"\n");return;
		case '8':sb.append((deque.isEmpty()?"-1":deque.peekLast())+"\n");return;
		default:break;
		}
	}
}
