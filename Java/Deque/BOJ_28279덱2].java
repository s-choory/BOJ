import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		Deque deque = new Deque();
		
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			
			if(s.charAt(0) == '1') {
				deque.pushFront(Integer.parseInt(s.substring(2)));
			}
			else if(s.charAt(0) == '2') {
				deque.pushBack(Integer.parseInt(s.substring(2)));
			}
			else if(s.charAt(0) == '3') {
				System.out.println(deque.popFront());
			}
			else if(s.charAt(0) == '4') {
				System.out.println(deque.popback());
			}
			else if(s.charAt(0) == '5') {
				System.out.println(deque.size());
			}
			else if(s.charAt(0) == '6') {
				if(deque.isEmpty()) {
					System.out.println(1);
				}else {
					System.out.println(0);
				}
			}
			else if(s.charAt(0) == '7') {
				if(deque.isEmpty()) {
					System.out.println("-1");
				}else {
					System.out.println(deque.getFront());
				}
			}
			else if(s.charAt(0) == '8') {
				if(deque.isEmpty()) {
					System.out.println("-1");
				}else {
					System.out.println(deque.getBack());
				}
			}
		}
	}	
	
	public static class Deque {
		LinkedList<Integer> deque = new LinkedList<>();
		

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

