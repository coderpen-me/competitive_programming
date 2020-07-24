# July LeetFree Document

## [July 1 2020]

> Questions :
    1 - Design Tiny URL
        (Scheduled for 2/july)

    2 - Two Sum
        > Using Hashmaps O(n)
    
    3 - Subarray Sum Equals K
        > Cab be done using windows techniques & Hashmaps O(n)
    
    4 - Add two numbers
        > Linked list question simple traversal and keep track of carry and sum using '/' & '%'. Keep 2 important cases, If any one list goest null first and if carry is created at last node.
    
    5 - Media of two sorted arrays
        > Use binary search on smaller array to find partition position, then find position of partition on larger array. After that check the conditions, 1. MaxXLeft <= MinYRight, 2. MaxYleft <= MinXright. If this is true, we found else, according to value of MaxXleft and MinYright, we will shift our partition pointer in X.
    
    6 - ZigZag Conversion
        > Another array question, we just need to be fast here.

    7 - Design and implement LRU DS
        (Scheduled for 2/July)

## [July 2 2020]

> Questions :
    1 - Merge K sorted linked Lists <https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/>
        > There are three methods to do this.

            1. Heap methods                        -- O(nk log k) -- O(k)
            - Can be used if size O(k) is no problem.
            - Create a min heap from all heads of k lists. Now, put min node in heap to be first node of result list. Then, Add next node of list, whose element is move to result.
            
            2. Divide & Conquer method             -- O(nk log k) -- O(1)
            - Best approach
            - Pair up all the lists and merge them in sorted manner to create n/2 lists of bigger sizes. After that again pair up, and so on until single list remains. Return that single list.

            3. Traversal method
            - Loop from 2nd list to last list, one by one merge them to first list in sorted order.

    2 - Merge K sorted Arrays <>
        > There are 3 methods.

            1. Traveral method                     -- O(nk log(nk)) -- O(nk)
            - Brute force
            - Traverse all arrays and put them into array of size (n * k), then sort using merge sort.

            2. Heap methods Similar to linked lists method        -- O(nk log k) -- O(k)
            - Best method, if size of arrays are different.
            - Create a min heap from all heads of k lists. Now, put min node in heap to be first node of result list. Then, Add next node of list, whose element is move to result.

            3. Divide & Conquer                    -- O(nk log k) -- O(nk log k)
            - Best algo, if size of arrays are equal.
            - Similar algo as for linked list.

    3 - Trapping rain water
        > 4 methods.

            1. Traversal method                    -- O(n^2) -- O(1)
            - Brute force
            - For each i, we need to find left max and right max. now compute min(left max, right max) - height of i. this is water stored at that i.

            2. Precompute method                   -- O(n) -- O(n)
            - optimized method using space.
            - Precompute using 2 O(n) loops. one for left max for each i, and one for right max for each i. Now we have two arrays, one that contains left max of i, one contains right of i. compute min(left max, right max) - height of i. this is water stored at that i.

            3. Using two vars, left max & right max.  -- O(n) -- O(1)
            - Optimized and best algo
            - Use two pointers, one at beg and one at end of array. Now, get min of elements at two pointers, side(beg or end) which is minimum will be calculated for water. If left max is more than current side element, then do left/right max - height of i. This is water at that element. Do this, till both points are less or equal.
    4 - Regular expression matching (DP)
    5 - Wildcard Matching (DP)

## [July 3 2020]

> Questions :

    1 - Max points on a line
        > For each point store count of slopes with other points. and max of (max of count of slopes + overlapping points for each point) is result.

## [July 4 2020]

> Questions :
    1 - Largest Rectangular Area
        > 3 methods.

            1. Traversal method                            -- O(n^2) -- O(1)
            - Pick histograms one by one, for each height, calculate max area possible. 
            
            2. Divide & Conquer                            -- O(n log n) -- O(size to make segment tree)
            - Create segment tree to find minimum height in range.
            - Now, answer would be:
            a) Maximum area in left side of minimum value (Not including the min value)
            b) Maximum area in right side of minimum value (Not including the min value)
            c) Number of bars multiplied by minimum value (Includig min value).

            3. Hashing                                     -- O(n) -- O(n)
            - For each bar x as smallest calculate area using first small left & right.
            - Create a stack, and run a loop from i = 0 to n-1, if stack is empty or top of stack is small than current element, push to stack. else, pop from stack, now current element is first right small and top of stack is first left small. using this, calculate area with x as small. Now, update max area if needed.
    1 - Maximal Rectangle
    2 - Edit Distance
    3 - Number of Digit one
