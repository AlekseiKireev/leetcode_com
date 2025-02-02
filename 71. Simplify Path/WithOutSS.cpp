class Solution {
public:
    string simplifyPath(string path) {
        
        deque<string> st;        
        
        for(int i = 0;  i<path.size(); ++i){
            if(path[i] == '/') {continue;}

            string temp;
			// iterate till we doesn't traverse the whole string and doesn't encounter the last /
            while(i < path.size() && path[i] != '/'){
				// add path to temp string
                temp += path[i];
                ++i;
            }

            if(temp == "."){continue;}

			// pop the top element from stack if exists
            if(temp == ".."){
                if(!st.empty()) {st.pop_back();}
            }
            else{ // push the directory file name to stack			
                st.push_back(temp);
            }
        }
		// if no directory or file is present
        if(st.empty()) {return "/";}

        string res;
        // adding all the stack elements to res
        while(!st.empty()){
            res += "/" + st.front();
            st.pop_front();
        }

        return res;
    }
};
