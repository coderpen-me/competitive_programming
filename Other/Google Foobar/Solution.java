import java.util.*;

public class Solution{
    public static void main(String[] args){
        int[] a = {14, 27, 1, 4, 2, 50, 3, 1};
        int[] b = {2, 4, -4, 3, 1, 1, 14, 27, 50};
        int n = a.length;
        int m = b.length;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        if(n > m){
            for(int i = 0; i < m; i++){
                map.put(b[i], map.getOrDefault(b[i], 0) + 1);
            }
            for(int i = 0; i < n; i++){
                if(!map.containsKey(a[i])){
                    System.out.println(a[i]);
                    break;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                map.put(a[i], map.getOrDefault(a[i], 0) + 1);
            }
            for(int i = 0; i < m; i++){
                if(!map.containsKey(b[i])){
                    System.out.println(b[i]);
                    break;
                }
            }
        }
    }
};