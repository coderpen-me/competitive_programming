import java.util.*;
import java.lang.*;
import java.io.*;

class Nth_Magical_Number {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0){
		    int nm = sc.nextInt();
		    int p = 1, res = 0;
		    while(nm > 0){
		        p = p * 5;
		        if((nm & 1) != 0)
		            res += p;
		        nm >>= 1;
		    }
		    System.out.println(res);
		    t--;
		}
	}
}