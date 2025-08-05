#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
// Function to evaluate a postfix expression
int evaluatePostfix(const string &expr)
{
    stack<int> st;
    stringstream ss(expr);
    string token;
    while (ss >> token)
    {
        if (isdigit(token[0]) ||
            (token.length() > 1 && token[0] == '-' && isdigit(token[1])))
        {
            // Operand (including negative numbers)
            st.push(stoi(token));
        }
        else
        {
            // Operator
            if (st.size() < 2)
            {
                cerr << "Invalid Expression!\n";
                return -1;
            }
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int result = 0;
            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/")
                result = a / b;
            else
            {
                cerr << "Unsupported operator: " << token << "\n";
                return -1;
            }
            st.push(result);
        }
    }
    return st.size() == 1 ? st.top() : -1;
}
// Sample usage
int main()
{
    string postfixExpr = "5 3 + 8 2 - *"; // (5 + 3) * (8 - 2) = 48
    cout << "Postfix Expression:   " << postfixExpr << "\n";
    int result = evaluatePostfix(postfixExpr);
    cout << "Result            :   " << result << "\n";
    return 0;
}