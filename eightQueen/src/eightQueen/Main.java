package eightQueen;
import java.util.*;
/*
 * N皇后问题
 */
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入一个正整数：");
		Method1(sc.nextInt());
		sc.close();
	}

	private static void Method1(int n) {
		//int[][] book = new int[n][n];//创建一个数组用来存放该位置是否被放置Queen,初始化均为0
		int[] Queen = new int[n];//创建数组来存放每一个行的皇后位置
		for(int i = 0; i < n; ++i)
			Queen[i] = -1;
		System.out.println(dfs(0,Queen));
	}

	private static int dfs(int step, int[] Queen) {
		if(step == Queen.length){
			return 1;
		}
		int sum = 0;
		for(int i = 0;i < Queen.length;i++){//在第step行的一个格子放入Queen
			Queen[step] = i;
			boolean flag = true;
			for(int j = 0;j < step;j++){
				if(Queen[j] == Queen[step] || step - j == Math.abs(Queen[step] - Queen[j])){
					flag = false;
					break;
				}
			}
			if(flag == true)
				sum += dfs(step + 1,Queen);
		}
		return sum;
	}

}
