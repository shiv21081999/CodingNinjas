import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
	static ArrayList<String> explored = new ArrayList<>();
	static boolean X = false;
	static void print(char[][] arr)
	{
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				System.out.print(arr[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
	static void convertX(char[][] arr)
	{
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				if(arr[i][j] == 'X')
					arr[i][j] = '+';
			}
		}
	}
	static void retrieve(char[][] arr)
	{
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				if(arr[i][j] == '+')
					arr[i][j] = 'X';
			}
		}
	}
	static char[][] copyArray(char[][] arr)
	{
		char[][] clone = new char[arr.length][arr.length];
		for (int i = 0; i < clone.length; i++) {
			for (int j = 0; j < clone.length; j++) {
				clone[i][j] = arr[i][j];
			}
		}
		return clone;
	}
	static boolean checkVertical(char[][] grid , int row, int col, String word)
	{
		int i = 0,c=0;
		int length = word.length();
		if(row-1>=0)
		{
			if(grid[row-1][col] != '+')
			{
				if(grid[row-1][col] == word.charAt(0))
				{
					i = 1;
					c = 1; 
				}
				else if(grid[row-1][col] != word.charAt(0))
				{
					return false;
				}
			}
		}
		for (; row<10 && i<length; row++,i++) {
			if(grid[row][col] == '-')
				c++;
			else if(grid[row][col] == word.charAt(i))
				c++;
			else
				return false;
		}
		if(c==length)
			return true;
		return false;
	}
	static boolean checkHorizontal(char[][] grid , int row, int col, String word)
	{
		int i = 0,c=0;
		int length = word.length();
		if(col-1>=0)
		{
			if(grid[row][col-1] != '+')
			{
				if(grid[row][col-1] == word.charAt(0))
				{
					i = 1;
					c = 1; 
				}
				else if(grid[row][col-1] != word.charAt(0))
				{
					return false;
				}
			}
		}
		for (; col<10 && i<length; col++,i++) {
			if(grid[row][col] == '-')
				c++;
			else if(grid[row][col] == word.charAt(i))
				c++;
			else 
				return false;
		}
		if(c==length)
			return true;
		return false;
	}
	static void fillVertical(char[][] grid, String word, int row, int col)
	{
		int i = 0;
		int length = word.length();
		if(row-1>= 0)
		{
			if(grid[row-1][col] == word.charAt(0))
			{
				i = 1;
			}
		}
		for(;i<length; i++,row++)
		{
			grid[row][col] = word.charAt(i);
		}
		
	}
	static void fillHorizontal(char[][] grid, String word, int row, int col)
	{
		int i = 0;
		int length = word.length();
		if(col-1>= 0)
		{
			if(grid[row][col-1] == word.charAt(0))
			{
				i = 1;
			}
		}
		for(;i<length; i++,col++)
		{
			grid[row][col] = word.charAt(i);
		}
		
	}
	static void fillGrid(char[][] grid, String[] words)
	{
		boolean flag = false;
		int row = 0,col = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if(grid[i][j] == '-')
				{
					row = i;
					col = j;
					flag = true;
					break;
				}
			}
			if(flag == true)
				break;
		}
		// System.out.println((row+" "+col));
		if(flag == false)
		{
			if(X)
			{
				retrieve(grid);
			}
				print(grid);
			System.exit(0);
		}
		for (int i = 0; i < words.length; i++) {
			
			if(checkVertical(grid, row, col, words[i]))
			{
				char[][] copy = copyArray(grid);
				fillVertical(copy, words[i], row, col);
				fillGrid(copy, words);
			}
			if(checkHorizontal(grid, row, col, words[i]))
			{
				char[][] copy = copyArray(grid);
				fillHorizontal(copy, words[i], row, col);
				fillGrid(copy, words);
			}
		}
		
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		char[][] grid = new char[10][10];
		boolean x = false;
		for (int i = 0; i < grid.length; i++) {
			String str = sc.nextLine();
			for (int j = 0; j < grid.length; j++) {
				grid[i][j] = str.charAt(j);
				if(grid[i][j] == 'X')
					x = true;
			}
		}
		String words = sc.nextLine();
		String[] word_array = words.split(";");
		if(x == true)
		{
			convertX(grid);
			X = true;
			fillGrid(grid,word_array);
		}
		
		fillGrid(grid,word_array);
	}
}