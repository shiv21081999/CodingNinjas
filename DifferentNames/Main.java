import java.util.*;
import java.util.Arrays;
import java.math.BigInteger;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String[] split = str.split(" ");
        HashMap<String,Integer> map = new HashMap<>();
        for (int i = 0; i < split.length; i++) {
            if(map.containsKey(split[i]))
            {
                int temp = map.get(split[i]);
                map.put(split[i], ++temp);
            }
            else
                map.put(split[i], 1);
        }
        for (int i = 0; i < split.length; i++) {
            String name = split[i];
            int occur = map.get(name);
            if(occur > 1)
            {
                System.out.println(name + " " + occur);
                map.put(name,0);
            }
        }
    }
}