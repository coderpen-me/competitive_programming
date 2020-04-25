import java.util.*;

public class WordAbbreviation {
    public static List<String> generateAbbreviations(String word) {
        List<String> result = new ArrayList<>();
 
        result.add(word);
        generateHelper(0, word, result);
         
        return result;
    }
     
    private static void generateHelper(int start, String s, List<String> result) {
        if (start >= s.length()) {
            return;
        }
         
        for (int i = start; i < s.length(); i++) {
            for (int j = 1; i + j <= s.length(); j++) {
                String num = Integer.toString(j);
                String abbr = s.substring(0, i) + num + s.substring(i + j);
                result.add(abbr);
                generateHelper(i + 1 + num.length(), abbr, result); // skip 1b
            }
        }
    }

    public static void main(String args[]){

        Scanner sc= new Scanner(System.in);
        String word = sc.nextLine();
        List<String> ret = generateAbbreviations(word);
        for(String i : ret){
            System.out.println(i);
        }
    }
}