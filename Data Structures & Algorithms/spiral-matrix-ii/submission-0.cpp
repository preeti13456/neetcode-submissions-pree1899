class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //we have given n2 matrix we are done with outer case but left with moving inside edge 
        //so kind of we are solving a sub problem here 
        //one spiral + subroblem 
        //4 pointers approach 
        //L-R (which part ot strat and end ) 
        //T-B (which range we go through )

        vector<vector<int>>matrix(n, vector<int>(n));
        int left = 0, right = n-1;
        int top=0, bottom=n-1;int num = 1;

        //boundaries not crossing each other yet 
        while(left<=right && top<=bottom)
        {
            //fill in every value at top row 
            for(int col=left; col<=right; col++)
            matrix[top][col]=num++;

//shift it down 
            top++;
            
            //after done we fill at right column 
            for(int row=top; row<=bottom; row++)
            matrix[row][right] = num++;

            right--;
            //fill every column at bottom column (reverse row)

        if(top<=bottom)
        {
            //reverse order
            for(int col=right; col>=left; col--)
            matrix[bottom][col] = num++;

            bottom--;
        }
            //fill ervy column at left column(reverse row)
            if(left<=right)
            {
                for(int row=bottom; row>=top; row--)
                matrix[row][left] = num++;

                left++;
            }

        }
        return matrix;
    }
};