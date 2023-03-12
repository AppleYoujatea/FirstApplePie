import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static int[][] mapp;
	public static Pair[] chick_arr;
	public static Pair[] home_arr;
	public static int chick_idx, home_idx;
	public static int []numbers, dp;
	
	public static int n, m, min;
	
	// x좌표, y좌표
	//x는 거리, y는 치킨집 번호
	static class Pair{
        int x, y;

        public Pair(int x, int y) {
        	this.x = x;
        	this.y = y;
        }
    }
	
	public static void combination(int cnt,int start) {
		if(cnt == m) {
//			System.out.println(Arrays.toString(numbers));
			
			calculate();
			
			return;
		}
		for(int i=start; i<chick_idx; ++i) {
			numbers[cnt] = i;
			combination(cnt+1,i+1);
		}
	}
	
	public static void calculate() {
		int sum = 0;
		dp = new int [home_idx];
		
		for(int i = 0; i < home_idx; i++) {
			dp[i] = Integer.MAX_VALUE;
		}
		
		for(int i = 0; i < numbers.length; i++) {
			for(int j = 0; j < home_idx; j++) {
				sum = Math.abs(chick_arr[numbers[i]].x - home_arr[j].x) + Math.abs(chick_arr[numbers[i]].y - home_arr[j].y);
				
				if(dp[j] > sum) {
					dp[j] = sum;
				}
			}
//			System.out.println(Arrays.toString(dp));
		}
		
		int total = 0;
		
		for(int i = 0; i < home_idx; i++) {
			total += dp[i];
		}
		
//		System.out.println(Arrays.toString(dp));
//		System.out.println("total: " + total);
		
		if(min > total) {
			min = total;
		}
		
	}
	
	
	

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine(), " ");
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		mapp = new int[n][n];
		chick_arr  = new Pair[13];
		home_arr  = new Pair[2 * n];
		chick_idx = 0;
		home_idx = 0;

		for(int i  = 0;  i< n; i++) {
			st = new StringTokenizer(br.readLine(), " ");			
			for(int j = 0; j< n; j++) {
				mapp[i][j] = Integer.parseInt(st.nextToken());
				
				if(mapp[i][j] == 2) {
					chick_arr[chick_idx++] = new Pair(j, i);
				}
				else if(mapp[i][j] == 1) {
					home_arr[home_idx++] = new Pair(j, i);
				}
			}
		}
		
		numbers = new int[m];
		min = Integer.MAX_VALUE;
		
		combination(0, 0);
		
		System.out.println(min);
		
		
		
	}

}
