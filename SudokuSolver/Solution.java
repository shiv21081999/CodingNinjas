
public class Solution {
	public static void print(int[][] arr)
	{
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
	public static boolean isPossible(int[][] arr, int row , int col , int digit)
	{
		for (int j = 0; j < 9; j++) {
			if(arr[row][j] == digit)
				return false;
		}
		for (int i = 0; i < 9; i++) {
			if(arr[i][col] == digit)
				return false;
		}
		int i = (row/3)*3;
		int j = (col/3)*3;
		for ( ; i < (row/3)*3+3; i++) {
			for ( ; j < (col/3)*3+3; j++) {
				if(arr[i][j] == digit)
					return false;
			}
		}
		return true;
	}
	public static boolean sudokuSolver(int board[][]){
		return sudokuSolver(board,0,0);
	}
	public static boolean sudokuSolver(int[][] arr, int row, int col)
	{
		if(col == 9)
		{
			if(sudokuSolver(arr, row+1, 0))
				return true;
			return false;
		}
		if(row==9 && col == 0)
		{
			// print(arr);
			return true;
		}
		if(arr[row][col] == 0)
		{
			for (int digit = 1; digit <= 9; digit++) {
				if(isPossible(arr, row, col, digit))
				{
					arr[row][col] = digit;
					if(sudokuSolver(arr, row, col+1))
						return true;
					arr[row][col] = 0;
					
				}
			}
		}
		else if(sudokuSolver(arr, row, col+1))
			return true;
		return false;
	}
}
