//https://leetfree.com/problems/one-edit-distance.html

/*

Solution Approach 1 - Array Traversal 

Let the input strings be s1 and s2 and lengths of input 
strings be m and n respectively.

1) If difference between m an n is more than 1, 
     return false.
2) Initialize count of edits as 0.
3) Start traversing both strings from first character.
    a) If current characters don't match, then
       (i)   Increment count of edits
       (ii)  If count becomes more than 1, return false
       (iii) If length of one string is more, then only
             possible  edit is to remove a character.
             Therefore, move ahead in larger string.
       (iv)  If length is same, then only possible edit
             is to  change a character. Therefore, move
             ahead in both strings. 
    b) Else, move ahead in both strings. 


*/