import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Card2 {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		try {
			int N = Integer.parseInt(br.readLine());
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			HashMap<Integer, Integer> num = new HashMap<>();
			
			for(int i = 0; i < N; i++) {
				int temp = Integer.parseInt(st.nextToken());
				if(num.containsKey(temp)) {
					num.replace(temp, num.get(temp) + 1);
				} else {
					num.put(temp, 1);
				}
			}
			
			int M = Integer.parseInt(br.readLine());
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < M; i++) {
				int key = Integer.parseInt(st.nextToken());
				
				if(num.containsKey(key)) {
					bw.write(num.get(key) + " ");
				} else {
					bw.write("0 ");
				}
			}
			bw.close();
		} catch(Exception e) {
		}
		
	}
}
