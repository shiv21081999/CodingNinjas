
public class Solution {
	static boolean[] column = new boolean[100];
	static boolean[] d1 = new boolean[100];
	static boolean[] d2 = new boolean[100];
	public static boolean isPossible(int n, int i ,int j)
	{
		if(column[j] == true)
			return false;
		else if(d1[n+i-j] == true)
			return false;
		else if(d2[i+j] == true)
			return false;
		return true;
	}
	public static void print(int[][] arr)
	{
		for(int k = 0 ; k<arr.length ; k++)
		{
			for(int l = 0 ; l<arr.length ; l++)
			{
				System.out.print(arr[k][l]+" ");
			}
		}
		System.out.println();
	}
	public static void placeNQueens(int n){
		int[][] arr = new int[n][n];
		placeNQueens(arr, 0,0,n);
	}
	public static void placeNQueens(int[][] board, int i , int j , int n)
	{
		// System.out.println(i+" "+j);
		if(i==board.length && j==0)
		{
			print(board);
			return;
		}
		if(j==board.length)
		{
			return;
		}
		if(isPossible(n,i,j))
		{
			// System.out.println(i+" "+j);
			board[i][j] = 1;
			column[j] = true;
			d1[n+i-j] = true;
			d2[i+j] = true;
			placeNQueens(board,i+1,0,n);
			board[i][j] = 0;
			column[j] = false;
			d1[n+i-j] = false;
			d2[i+j] = false;
		}
		// System.out.println(j);
		placeNQueens(board,i,j+1,n);
		
	}
		
}
	