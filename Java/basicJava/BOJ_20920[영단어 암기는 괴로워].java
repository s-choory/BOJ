import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Main {

	public static void main(String[] args) throws IOException {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String [] arrNM = br.readLine().split(" ");
		int n = Integer.parseInt(arrNM[0]);
		int m = Integer.parseInt(arrNM[1]);
		
		String [] arr = new String[n];
		int i = 0;
		while(n-- > 0) {
			String word = br.readLine();
			if(word.length() >= m) {
				arr[i++] = word; 
			}
		}
		br.close();
		
		Map<String, Integer> map = new HashMap<>();
		
		for (String string : arr) {
			if(string == null) {
				
			}else if(map.containsKey(string)) {
				map.put(string,map.get(string)+1);
			}else {
				map.put(string, 1);
			}
		}
		
        List<Map.Entry<String, Integer>> entryList = new ArrayList<>(map.entrySet());

        // Comparator를 사용하여 값을 기준으로 엔트리 정렬
        entryList.sort((entry1, entry2) -> {
            int valueCompare = entry2.getValue().compareTo(entry1.getValue());
            if (valueCompare == 0) {	
                // 값이 같을 경우, 길이가 긴 문자열 우선 정렬
                int lengthCompare = Integer.compare(entry2.getKey().length(), entry1.getKey().length());
                if (lengthCompare == 0) {
                    // 길이가 같을 경우, 알파벳 순 정렬
                    return entry1.getKey().compareTo(entry2.getKey());
                }
                return lengthCompare;
            }
            return valueCompare;
        });
        
        for (Map.Entry<String, Integer> entry : entryList) {
        	bw.append(entry.getKey()+"\n");
        }
        bw.flush();
        bw.close();
	}
}
