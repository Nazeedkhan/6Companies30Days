class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int len = tokens.size();
        for(auto x: tokens)
        {
            if(x=="+" || x=="-" || x=="*" || x=="/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(x=="+")
                {
                    a = a + b;
                }
                if(x=="-")
                {
                    a = b - a;
                } 
                if(x=="/")
                {
                    a = b / a;
                }
                if(x=="*")
                {
                    a = a * b;
                }
                st.push(a);
            }
            else
            {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};
