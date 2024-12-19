// A palindrome is a string of character that‘s the same forward and backward. Typically, 
// punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a 
// droop” is a palindrome, as can be seen by examining the characters “poor danisina 
// droop” and observing that they are the same forward and backward. One way to check 
// for a palindrome is to reverse the characters in the string and then compare with them 
// the original-in a palindrome, the sequence will be identical. Write C++ program with 
// functionsa) To print original string followed by reversed string using stack
// b) To check whether given string is palindrome or not

#include<iostream>
#include<stack>
using namespace std;

string remove_space(const string& str)
{
    string result;
    for(char ch : str){
        if( ch != ' '){
            result = result + ch;
        }
    }
    return result;
}

string reversed_str(const string& str)
{
    stack<char> s;
    for(char ch : str){
        s.push(ch);
    }
    string reverse;
    while(!s.empty()){
        reverse  = reverse + s.top();
        s.pop();
    }
    return reverse;
}


int main(){
    string str;
    
    cout<<"Enter the string: ";
    getline(cin,str);
    
    string no_space = remove_space(str);
    cout<<"The original one: "<<no_space<<endl;
    string reversed = reversed_str(no_space);
    cout<<"The reversed one: "<<reversed<<endl;
    if(no_space == reversed){
        cout<<"The string is palindrom !!!"<<endl;
    }
    else
    {
        cout<<"The string is not a palindrom !!!"<<endl;
    }
}