import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Deque<Balloon> deque = new ArrayDeque<>();
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
		String [] arr = br.readLine().split(" ");
		br.close();
		
		sb.append("1 ");
		
		for(int i =1; i<n; i++) {
			Balloon balloon = new Balloon(i+1, Integer.parseInt(arr[i]));
			deque.addLast(balloon);
		}
		Balloon next = new Balloon(1, Integer.parseInt(arr[0]));
		
		while(!deque.isEmpty()) {
			if(next.numValue>0) {
				for(int i = 1; i<next.numValue; i++) {
					deque.add(deque.poll());
				}
				Balloon result = deque.poll();
				sb.append(result.index+" ");
				next = result;
			}else {
				for(int i = 1; i < -next.numValue; i++) {
					deque.addFirst(deque.pollLast());
				}
				Balloon result = deque.pollLast();
				sb.append(result.index+" ");
				next = result;
			}
		}
		System.out.println(sb);
	}
	
	static class Balloon {
		int index;
		int numValue;

		public Balloon(int index, int numValue) {
			super();
			this.index = index;
			this.numValue = numValue;
		}
	}
}
