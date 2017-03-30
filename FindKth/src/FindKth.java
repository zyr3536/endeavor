/*找出一个数组中第n大的元素（从0开始）
思想：运用快排的思维*/
import java.util.*;
public class FindKth {

	public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n;++i)
				a[i] = sc.nextInt();
			int k = sc.nextInt();
			System.out.println(findKth(a,k));
			sc.close();
	}

	private static int findKth(int[] a,int k) {
		if(k < 0 || k >= a.length)
			return -1;
		return recur(a,0,a.length - 1,k);
	}

	private static int recur(int[] a, int l, int r,int k) {
		if(l == r)
			return a[l];
		int i = l, j = r;
		int v = a[i];
		while(i < j){
			while(i < j && a[j] < v)
				--j;
			if(i < j)
				a[i++] = a[j];
			while(i < j && a[i] > v)
				++i;
			if(i < j)
				a[j--] = a[i];
		}
		a[i] = v;
		if(i == k)
			return a[i];
		else if(i < k)
			return recur(a,i + 1,r,k);
		else
			return recur(a,l,i - 1,k);
	}
}
