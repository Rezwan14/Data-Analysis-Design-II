#include <iostream>
#include <stack>
#include <string>

namespace calculator
{
  /** tells whether string has balanced or unbalanced parenthesis
    // @param string we are checking
    // @return returns true if it does have unbalanced parenthesis, false if it doesn't
    // Example (9 + 10) is valid
    // Example ((21 + 0) is not valid, parenthesis are not balanced
    // MUST USE A STACK!
  */
    bool unbalanced_paranthesis(std::string postfix_expression)
    {
        std::stack<char> s;
        for (int i = 0; i < postfix_expression.length(); i++) 
        {
            char x = postfix_expression[i];
            if (x == '(') 
                {
                    s.push(x);
                } 
            else if (x == ')') 
                {
                    if (s.empty()) return false;
                    char topp = s.top();
                    if (topp == '('){
                    s.pop();}
                    else return false;
                }
        }
        return (s.empty()); //once we finish
    }
    

    /** Helper function that tells whether the char is an operator
  // @param char we are checking
  // @return returns true if the char is an operator, and false if it isn't
  */
    bool isOperator(char sub_string)
    {
        if(sub_string == '+' || sub_string == '-'|| sub_string == '*'|| sub_string == '/')
        {
            return 1;//is operator
        }
    return 0;//not operator
    }//end isOperator

  /** Helper function that checks if char is an int
  // @param char we are checking
  // @return returns true if the char is an int, and false if it isn't
  */
    bool isInteger(char sub_string)
    {
        if(sub_string >= '0' && sub_string <= '9')
        {
            return 1; //return true
        }
    return 0;
    }//end isInteger

  /** tells whether there is an illegal operator or not (such as ^ or factorial !)
    // @param string we checking, the infix expression
    // @return returns true if it doesn't have illegal operator
      An example of an illegal expression (you'll get the FBI on you):
      `( 2 + 3 ) ^ 2`
      An example of a legal expresion:
      (5 + 2 ) * 3 / 2 -    5
      ^Notice the extra white space, white space does NOT make it illegal
 */
    bool legalOperator(std::string s)
    {
        for(int i = 0; i < s.length(); i++)
        {
        char x = s[i];
        if(x == ' ') continue;
        else if(isInteger(x)) continue;
        else if(isOperator(x)) continue;
        else if(x == '('|| x == ')') continue;
        else return false;
        }//end for
    return true;
    }//end legalOperator

  /**
    // check for precedence, multiplication and division return a higher number than addition and subtraction 
    // Useful for PEMDAS
    @pre assumes op is either one of the following: *, /, +, -
    @return 2 if op == "*" or "/", 1 if op == "+" or "-"
  */
    int precedence(char op)
    {
        if(op == '+' || op == '-')
        {
            return 1;
        }
        if(op == '*'|| op == '/')
        {
            return 2;
        }   
        return 0;
    }//end precedence

  /** Converts infix expression to postfix expression
 // @param string to convert
 // @return returns the correct postfix expression if its a valid infix expression 
 // @return "Not a valid expression!" if it is not a valid infix expression (has illegal characters or unbalanced paranthesis)
 // Example: input: â€œ3 - (134 + 76)"  output: "3 134 76 + -"
 */
    std::string convertToPostfix(std::string infix_expression)
    {
        if (unbalanced_paranthesis(infix_expression))
        return "Not a valid expression!";
        if (!legalOperator(infix_expression)) return "Not a valid expression!";
        std::stack<char> s;
        std::string result = "";
        for (int i = 0; i < infix_expression.length(); i++) {
        char x = infix_expression[i];
    
        if (x == ' ') continue;
    
        if (isInteger(x)) {
        std::string number = "";
        while (i < infix_expression.length() && isInteger(infix_expression[i]))
        number += infix_expression[i++];
        i = i - 1;
        if (result.length() == 0)
        result += number;
        else
        result += " " + number;
    } else if (x == '(')
      s.push('(');
    else if (x == ')') {
      // process all operands till you encounter )
      while (s.top() != '(') {
        result += ' ';
        result += s.top();
        s.pop();
      }
      s.pop();
    } else {
      // pop out all operators with higher or equal precedence
      while (!s.empty() && precedence(x) <= precedence(s.top())) {
        result += ' ';
        result += s.top();
        s.pop();
      }
      s.push(x);
    }
  }

  // process the remaining characters in the stack
  while (!s.empty()) {
    result += ' ';
    result += s.top();
    s.pop();
  }

  // return the computed postfix expression
  return result;
    }

  /** calculates post fix expression 
    // @param post fix expression 
    // @return result (as a string) if valid expression 
    // @return "Not a valid expression" if the parameter postfix_expression is "Not A valid expression!" 
 */
  std::string calculatePostfix(std::string postfix_expression)
{
    if (postfix_expression == "Not a valid expression!") 
    {
    return "Not a valid expression!";
    }
  // your code under here
  std::stack<double> s;
  int i = 0;
  while (i < postfix_expression.length()) 
  {
    // space character is ignored
    if (postfix_expression[i] == ' ') 
    {
      i++;
    } 
    else if (isInteger(postfix_expression[i])) 
    {
      // collect the number and add it to stack
      int number = 0;
      while (i < postfix_expression.length() &&
             isInteger(postfix_expression[i]))
        number = number * 10 + (postfix_expression[i++] - '0');
      s.push(number);
    } 
    else 
    {
      // apply the operator
      double val1 = s.top();
      s.pop();
      double val2 = s.top();
      s.pop();
      char op = postfix_expression[i++];
      if (op == '+')
        s.push(val2 + val1);
      else if (op == '-')
        s.push(val2 - val1);
      else if (op == '*')
        s.push(val2 * val1);
      else if (op == '/')
        s.push(val2 / val1);
    }
  }

  // return the value of the final expression
  return std::to_string(s.top());
}
}
