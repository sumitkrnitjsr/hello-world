// https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/

void PrintMinNumberForPattern(string seq)
{
    // result store output string
    string result;
    
    // create an empty stack of integers
    stack<int> stk;
    
    // run n+1 times where n is length of input sequence
    for (int i = 0; i <= seq.length(); i++)
    {
        // push number i+1 into the stack
        stk.push(i + 1);
        
        // if all characters of the input sequence are
        // processed or current character is 'I'
        // (increasing)
        if (i == seq.length() || seq[i] == 'I')
        {
            // run till stack is empty
            while (!stk.empty())
            {
                // remove top element from the stack and
                // add it to solution
                result += to_string(stk.top());
                result += " ";
                stk.pop();
            }
        }
    }
    
    cout << result << endl;
}
