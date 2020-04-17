//https://leetfree.com/problems/find-the-celebrity.html

/*
Solution Approach 1 - Java - Simple Array Traversal:

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int c = 0;
        for (int i = 1; i < n; i++)
            if (knows(c, i)) c = i;
        for (int i = 0; i < n; i++) {
            if (i == c) continue;
            if (!knows(i, c) || knows(c, i))
                return -1;
        }
        return c;
    }
};


Solution Approach 2 - using stack

Push all elements in stack, pop 2 and check the relation. Now remaining one possible candidate will be checked against top of stack.
Repeat this step until stack contains only 0 element.

Solution Approach 3 - Using Graph

Count out and In for each node.
 */