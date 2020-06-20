def isInsideBoard(x, y): 
        if (x >= 0 and x < 8 and y >= 0 and y < 8):  
            return True
        return False

def solution(src, dest):
    col_src = src % 8
    row_src = int(src / 8)
    
    col_dest = dest % 8
    row_dest = int(dest / 8)
    
    #print(col_src, row_src, col_dest, row_dest)
    
    x_moves = [2, 2, -2, -2, 1, 1, -1, -1] 
    y_moves = [1, -1, 1, -1, 2, -2, 2, -2] 
    
    que = []
    
    visited = [[False for i in range(8)] for j in range(8)]
    
    que.append([row_src, col_src, 0])
    visited[row_src][col_src] = True
    
    while(len(que) > 0):
    
        pos = que[0]
        que.pop(0)
    
        if(pos[0] == row_dest and pos[1] == col_dest):
            print(pos[2])
    
        else:
            for i in range(8): 
    
                new_x = pos[0] + x_moves[i] 
                new_y = pos[1] + y_moves[i]
    
                if(isInsideBoard(new_x, new_y) and not visited[new_x][new_y]): 
                    visited[new_x][new_y] = True
                    que.append([new_x, new_y, pos[2] + 1])