package eightQueen;
import java.util.*;
/*
 * N�ʺ�����
 */
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("������һ����������");
		Method1(sc.nextInt());
		sc.close();
	}

	private static void Method1(int n) {
		//int[][] book = new int[n][n];//����һ������������Ÿ�λ���Ƿ񱻷���Queen,��ʼ����Ϊ0
		int[] Queen = new int[n];//�������������ÿһ���еĻʺ�λ��
		for(int i = 0; i < n; ++i)
			Queen[i] = -1;
		System.out.println(dfs(0,Queen));
	}

	private static int dfs(int step, int[] Queen) {
		if(step == Queen.length){
			return 1;
		}
		int sum = 0;
		for(int i = 0;i < Queen.length;i++){//�ڵ�step�е�һ�����ӷ���Queen
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
