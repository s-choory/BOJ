import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		Deque deque = new Deque();
		
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			
			if(s.contains("push_front")) {
				deque.pushFront(Integer.parseInt(s.substring(11)));
			}
			else if(s.contains("push_back")) {
				deque.pushBack(Integer.parseInt(s.substring(10)));
			}
			else if(s.equals("pop_front")) {
				deque.popFront();
			}
			else if(s.equals("pop_back")) {
				deque.popback();
			}
			else if(s.equals("size")) {
				System.out.println(deque.head);
			}
			else if(s.equals("empty")) {
				if(deque.head == 0) {
					System.out.println(1);
				}else {
					System.out.println(0);
				}
			}
			else if(s.equals("front")) {
				if(deque.head == 0) {
					System.out.println(-1);
				}else {
					System.out.println(deque.deque[0]);
				}
			}
			else if(s.equals("back")) {
				if(deque.head == 0) {
					System.out.println(-1);
				}else {
					System.out.println(deque.deque[deque.head-1]);
				}
			}
		}
		
	}	
	
	public static class Deque {
		int [] deque;
		int head = 0;
		
		public Deque() {
			super();
			deque = new int[10000];
		}

		public void pushFront(int x){
			if(head != 0){
				for (int i = head; i > 0; i--) {
					deque[i] = deque[i-1];
				}
			}
			deque[0] = x;
			head++;
		}
		
		public void pushBack(int x){
			deque[head++] = x;
		}
		
		public void popFront() {
		
			if(head != 0) {
				System.out.println(deque[0]);
				for (int i = 0; i < head-1; i++) {
					deque[i] = deque[i+1];
				}
				head--;
			}
			else {
				System.out.println("-1");
			}
			
		}

		public void popback() {
			if(head != 0) {
				System.out.println(deque[head-1]);
				head--;
			}else {
				System.out.println("-1");
			}
		}
		
	}
}

