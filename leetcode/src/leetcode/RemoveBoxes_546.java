/*
 * Given several boxes with different colors represented by different positive numbers. 
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.
Example:
Input:
	[1,3,2,2,2,4,4,3,1]
Output:
	23
	
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
*/
package leetcode;
import java.util.*;
public class RemoveBoxes_546 {
	static int max;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Please enter a number:");
		int n = sc.nextInt();
		int[] a = new int[n];
		System.out.println("Input an array:");
		for(int i = 0;i < n; ++i)
			a[i] = sc.nextInt();
		System.out.println(removeBoxesofBFM(a));
		sc.close();
	}
	
	public static int removeBoxesofBFM(int[] a){
		boolean[] book = new boolean[a.length];
		dfs(0,a,book);
		return 0;
	}
	
	public static void dfs(int )

}
