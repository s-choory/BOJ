import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		Deque deque = new Deque();
		String [] m = br.readLine().split(" ");
		
		for (int i = 0; i < n; i++) {
			deque.pushBack(Integer.parseInt(m[i]));
		}

		
		for (int i = 0; i < n; i++) {
			if(deque.get(i) >= 0) {
				deque.get(i)
			}
			
			deque.pushBack(Integer.parseInt(m[i]));
		}
		
		
		
		
		}
	
	public static class Deque {
		LinkedList<Integer> deque = new LinkedList<>();
		
		public int get(int n) {
			return deque.get(n);
		}
		
		public void pushFront(int x){
			deque.addFirst(x);
		}
		
		public void pushBack(int x){
			deque.addLast(x);
		}
		
		public String popFront() {
			if(deque.isEmpty()) {
				return "-1";
			}
			return String.valueOf(deque.pollFirst());
		}

		public String popback() {
			if(deque.isEmpty()) {
				return "-1";
			}
			return String.valueOf(deque.pollLast());
		}
		
		public int size() {
			return deque.size();
		}
		
		public int getFront() {
			if(deque.isEmpty()) {
				return -1;
			}
			return deque.getFirst();
		}

		public int getBack() {
			if(deque.isEmpty()) {
				return -1;
			}
			return deque.getLast();
		}
		
		public boolean isEmpty() {
			return deque.isEmpty();
		}
	}
}

