import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
import java.util.Comparator;
class StructSort implements Comparator<Struct>{
    public int compare(Struct a , Struct b)
    {
        if(a.score<b.score)
            return 1;
        else if(a.score == b.score)
        {
            if(a.index<b.index)
                return -1;
            else
                return 1;
        }
        else{
            return -1;
        }
    }
}
class Struct{
    String name;
    int score;
    int index;
}
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Struct[] arr = new Struct[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new Struct();
            String str = sc.next();
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            arr[i].name = str;
            arr[i].score = x+y+z;
            arr[i].index = i;
        }
        Arrays.sort(arr,0,n,new StructSort());
        for (int i = 0; i < arr.length; i++) {
            Struct x = arr[i];
            System.out.println(i+1+" "+x.name);
        }
    }
}