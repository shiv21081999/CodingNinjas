
public class Solution {
	static void print(int[][] arr)
	{
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				System.out.print(arr[i][j]+" ");
			}
		}
		System.out.println();
	}
	public static void ratInAMaze(int maze[][]){
		int[][] ans = new int[maze.length][maze.length];
		ratInAMaze(maze,0,0,ans);
	}
	public static void ratInAMaze(int[][] maze , int i , int j , int[][] ans)
	{
		if(i < 0 || j < 0 || i>=ans.length || j>= ans.length)
			return;
		if(i==ans.length-1 && j==ans.length-1)
		{
			ans[i][j] = 1;
			print(ans);
			ans[i][j] = 0;
			return;
		}
		if(maze[i][j] == 0)
		{
			return;
		}
		ans[i][j] = 1;
		maze[i][j] = 0;
		ratInAMaze(maze,i+1,j,ans);
		ratInAMaze(maze,i-1,j,ans);
		ratInAMaze(maze,i,j+1,ans);
		ratInAMaze(maze,i,j-1,ans);
		ans[i][j] = 0;
		maze[i][j] = 1;
	}
}
