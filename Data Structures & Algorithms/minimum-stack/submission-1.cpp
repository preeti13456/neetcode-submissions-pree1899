class MinStack {
    struct StackNode {
        int val;
        int min;
    };
    vector<StackNode>data;
    //[]
public:
    MinStack() {
        
    }
    //3, 2, 5
    //stack=[3]
    
    void push(int val) {
        if(data.empty())
        {
            StackNode new_node;
            new_node.val = val;
            new_node.min = val;
            //Stack : [{val:3, min:3}]
            data.push_back(new_node);
            return;
        }
        //current_min. = 3
        int current_min = data.back().min;
        StackNode new_node;
      //  Stack : [{val:3, min:3} ]
      //5<2 false
        if(val<current_min)
        {
            //val =2
            new_node.val = val;
            //min = 2
            new_node.min = new_node.val;
            data.push_back(new_node);
           // Stack : [{val:3, min:3}, {val:2, min:2} ]
        }

        else
        {

//new_node val = 5
            new_node.val = val;
            //min=2
            new_node.min = data.back().min;
            // Stack : [{val:3, min:3}, {val:2, min:2} , {val:5, min:2} ]
            data.push_back(new_node);
        }
    }
    
    void pop() {


        data.pop_back();
        //[{val:3, min:3}, {val:2, min:2}]
    }
    
    int top() {
        return data.back().val;
    }
    
    int getMin() {
        return data.back().min;
    }
};
