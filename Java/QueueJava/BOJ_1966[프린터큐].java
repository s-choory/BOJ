import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import javax.swing.text.Document;

public class Main {
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		
		for(int i =0; i<t; i++) {
			String s[] = br.readLine().split(" ");
			int n = Integer.parseInt(s[0]);
			int m = Integer.parseInt(s[1]);
			
			String p[] = br.readLine().split(" ");
			int [] priorities = new int[n];
			
			for (int j = 0; j < n; j++) {
				priorities[j] = Integer.parseInt(p[j]);
			}
			Queue<Document> queue = new LinkedList<>();
			
			for (int j = 0; j < priorities.length; j++) {
				queue.add(new Document(j, priorities[j]));
			}
			
			int count = 1;
			while(!(queue.isEmpty())) {
				Document doc = queue.poll();
				
				boolean isMaxPriority = true;
				for (Document other : queue) {
					if(doc.prioritiy < other.prioritiy) {
						queue.add(doc);
						isMaxPriority = false;
						break;
					}
				}
				if(isMaxPriority == true) {
					if(m == doc.index) {
						System.out.println(count);
					}else {
						count++;
					}
				}
			}
		}
	}
	
	public static class Document {
		int index;
		int prioritiy;
		
		public Document(int index, int prioritiy) {
			super();
			this.index = index;
			this.prioritiy = prioritiy;
		}
	}
	
}
