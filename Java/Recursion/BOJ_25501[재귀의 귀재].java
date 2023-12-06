import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {

	static int cnt = 0;
	
	static int recursion(char[] s, int l, int r){
		cnt++;
	    if(l >= r) return 1;
	    else if(s[l] != s[r]) return 0;
	    else return recursion(s, l+1, r-1);
	}

	static int isPalindrome(char [] s){
	    return recursion(s, 0, s.length-1);
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		
		while(n-- >0) {
			String str = br.readLine();
			char [] s = str.toCharArray(); 
			bw.append(String.valueOf(isPalindrome(s))+" "+cnt);
			bw.append("\n");
			cnt = 0;
		}
		br.close();
		bw.flush();
		bw.close();
	}
}
