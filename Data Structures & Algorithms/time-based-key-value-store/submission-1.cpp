class TimeMap {
public:
//string, va;ue , timestamp 
unordered_map<string, vector<pair<int, string>>>store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        //timeMap.set("alice", "happy", 1);  
        // store the key "alice" and value "happy" along with timestamp = 1.
        store[key].push_back({timestamp, value});

    }
    
    string get(string key, int timestamp) {
       // timeMap.get("alice", 1);         
         // return "happy"
//timeMap.get("alice", 2);         
  // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
       // int n = store[key].size();
       auto&arr = store[key];
        // string value;
        int l = 0;
        int r = arr.size()-1;
        string res = "";
        //no values condfition
        // if(n==0) return "";
        //previous timestamp can't be greater 
        // if(store[key][l].first>timestamp) return "";
        //left and right start from the given key 
        // if(store[key][l].first <= timestamp) l=r; 

        // else
        
            while(l <= r)
            {
                int m = l+(r-l)/2;
                //shift right top curreny largest value previous timestamp > timestamp
                //reducing soace to searcg 
                if(arr[m].first<=timestamp) {res = arr[m].second; l=m+1;}
                else
                {
                   r = m-1;
                }
            }
        return res;
    }
};
