class ZigzagIterator {
public:
    vector<int> a, b;
    int s1 = 0;
    int s2 = 0;
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        // do intialization if necessary
        a = v1;
        b = v2;
        s1 = v1.size();
        s2 = v2.size();
    }
    
    int p1 = 0, p2 = 0;
    /*
     * @return: An integer
     */
    int next() {
        //cout<<p1<<" "<<p2<<"\n";
        if(p1 > p2){
            if(p2 < s2){
                p2++;
                return b[p2-1];
            }
            else{
                p1++;
                return a[p1-1];
            }
        }
        else{
            if(p1 < s1){
                p1++;
                return a[p1-1];
            }
            else{
                p2++;
                return b[p2-1];
            }
        }
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        if(p1 < s1){
            //cout<<"A\n";
            return true;
        }
        if(p2 < s2){
            //cout<<"B\n";
            return true;
        }
        else return  false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */