class MovingAverage {
public:
    long long s = 0, sum = 0, curr = 0;
    /*
    * @param size: An integer
    
    */MovingAverage(int size) {
        // do intialization if necessary
        this->s = size;
        this->sum = 0;
        this->curr = 0;
    }

    /*
     * @param val: An integer
     * @return:  
     */
    queue<long long> q;
    double next(long long val) {
        q.push(val);
        curr++;
        if(curr > s){
            sum -= q.front();
            q.pop();
            sum += q.back();
            curr--;
        }
        else{
            sum += q.back();
        }
        return (double)sum / (double)curr;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */