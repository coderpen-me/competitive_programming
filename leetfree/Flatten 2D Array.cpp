class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        begin = vec2d.begin();
        end = vec2d.end();
        pos = 0;
    }

    int next() {
        return (*begin)[pos++];
    }

    bool hasNext() {
        while(begin != end && pos == (*begin).size())
            begin++, pos = 0;
        return begin != end;
    }

private:
    vector<vector<int>>::iterator begin, end;
    int pos;
};