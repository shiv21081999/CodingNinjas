import java.util.Scanner;

public class Main {

		public static void main(String[] args) {
			Scanner s = new Scanner(System.in);

			int board[][] = new int[9][9];
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++){
					board[i][j] = s.nextInt();
				}
			}
			System.out.println(Solution.sudokuSolver(board));	
		}



}
