#define vvc vector<vector<char>>
bool rowcheck(vvc &A, int row, int num){
    char c;
    if(num==1)    c = '1';
    if(num==2)    c = '2';
    if(num==3)    c = '3';
    if(num==4)    c = '4';
    if(num==5)    c = '5';
    if(num==6)    c = '6';
    if(num==7)    c = '7';
    if(num==8)    c = '8';
    if(num==9)    c = '9';
    for(int i = 0; i < 9; i++){
        if(A[row][i] == c)
            return false;
    }
    return true;
}

bool colcheck(vvc &A, int col, int num){
    char c;
    if(num==1)    c = '1';
    if(num==2)    c = '2';
    if(num==3)    c = '3';
    if(num==4)    c = '4';
    if(num==5)    c = '5';
    if(num==6)    c = '6';
    if(num==7)    c = '7';
    if(num==8)    c = '8';
    if(num==9)    c = '9';
    for(int i = 0; i < 9; i++){
        if(A[i][col] == c)
            return false;
    }
    return true;
}

bool divcheck(vvc &A, int row, int col, int num){
    char c;
    if(num==1)    c = '1';
    if(num==2)    c = '2';
    if(num==3)    c = '3';
    if(num==4)    c = '4';
    if(num==5)    c = '5';
    if(num==6)    c = '6';
    if(num==7)    c = '7';
    if(num==8)    c = '8';
    if(num==9)    c = '9';
    for(int i = row*3; i < (row*3)+3; i++){
        for(int j = col*3; j <(col*3)+3; j++){
            if(A[i][j] == c)
                return false;
        }
    }
    return true;
}

bool find(vvc &A, int &row, int &col){
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            if(A[row][col] == '.')
            {   
                //cout<<*row<<" "<<*col<<" -- ";
                return true;
            }
        }
    }
    return false;
}
bool isPos(vvc &A, int row, int col, int num){
    //cout<<rowcheck(A, row, num)<<" "<<colcheck(A, col, num)<<" "<<divcheck(A, row/3, col/3, num)<<" "<<num<<" -- ";
    return (rowcheck(A, row, num) && colcheck(A, col, num) && divcheck(A, row/3, col/3, num));
}

bool solver(vvc &A){
    int row, col;
    
    if(!find(A, row, col))
        return true;
    //cout<<row<<" "<<col<<" ---- ";
    for(int i = 1; i <= 9; i++){
        char c;
        if(i==1)    c = '1';
        if(i==2)    c = '2';
        if(i==3)    c = '3';
        if(i==4)    c = '4';
        if(i==5)    c = '5';
        if(i==6)    c = '6';
        if(i==7)    c = '7';
        if(i==8)    c = '8';
        if(i==9)    c = '9';
        if(isPos(A, row, col, i)){
            A[row][col] = c;
            if(solver(A)){
                return true;
            }
            else{
                A[row][col] = '.';    
            }
        }
    }
    return false;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    solver(A);
}
