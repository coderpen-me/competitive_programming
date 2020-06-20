import java.util.*;
import java.io.*;
  
class Codechef {

    static int[] a = new int[200001];
    static boolean[] vis = new boolean[200001];

    public static ArrayList<Integer> Depth_First(int src) {
        ArrayList<Integer> result = new ArrayList<>();
        int temp = src;
        while (a[temp] != src) {
            vis[temp] = true;
            result.add(temp);
            temp = a[temp];
        }
        vis[temp] = true;
        result.add(temp);
        return result;
    }

    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        int test = in.nextInt();
        int n, k, j;
        for (int i = 0; i < test; i++) {
            n = in.nextInt();
            k = in.nextInt();
            int cnt = 0;
            int odd_data = 0;
            int even_data = 0;
            Arrays.fill(vis, false);
            ArrayList<ArrayList<Integer>> odd = new ArrayList<>();
            ArrayList<ArrayList<Integer>> even = new ArrayList<>();
            for (j = 1; j <= n; j++) {
                a[j] = in.nextInt();
            }
            for (j = 1; j <= n; j++){
                if (!vis[j]){
                    ArrayList<Integer> temp = Depth_First(j);
                    if (temp.size() % 2 == 1){
                        odd_data += temp.size() / 2;
                        odd.add(temp);
                    }
                    else{
                        even_data += (temp.size() - 1) / 2;
                        even.add(temp);
                        cnt++;
                    }
                }
            }
            int total = odd_data + even_data + (cnt);
            if (cnt % 2 == 1 || total > k){
                System.out.println(-1);
            }
            else{
                int p, s;
                System.out.println(total);
                for (ArrayList<Integer> l : odd){
                    s = l.size();
                    for (p = 1; p < s - 1; p += 2){
                        System.out.println(l.get(0) + " "+ l.get(p) + " " + l.get(p + 1));
                    }
                }
                for (ArrayList<Integer> l : even){
                    s = l.size();
                    for (p = 1; p < s - 1; p += 2){
                        System.out.println(l.get(0) + " " + l.get(p) + " " + l.get(p + 1));
                    }
                }
                for (p = 0; p < cnt - 1; p += 2){
                    List<Integer> l1 = even.get(p);
                    List<Integer> l2 = even.get(p + 1);
                    int x1 = l1.get(0), y1 = l1.get(l1.size() - 1);
                    int x2 = l2.get(0), y2 = l2.get(l2.size() - 1);
                    System.out.println(x1 + " " +  y1 + " " + x2);
                    System.out.println(y2 + " " +  x2 + " " + x1);
                }
            }
        }
    }
}