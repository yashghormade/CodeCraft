#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int>& st, int element) {
    if (st.empty()) {
        st.push(element); // Base case: if stack is empty, push the element
    } else {
        // Recursive case: pop all elements, insert element at the bottom, then push elements back
        int top = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(top);
    }
}

// Function to reverse the stack
void reverseStack(stack<int>& st) {
    if (!st.empty()) {
        // Step 1: Pop the top element
        int top = st.top();
        st.pop();
        
        // Step 2: Reverse the remaining stack recursively
        reverseStack(st);
        
        // Step 3: Insert the popped element at the bottom of the reversed stack
        insertAtBottom(st, top);
    }
}

// Utility function to print the stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    
    // Push elements onto the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    // Print the original stack
    cout << "Original Stack: ";
    printStack(st);
    
    // Push elements again for reverse operation
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    // Reverse the stack
    reverseStack(st);
    
    // Print the reversed stack
    cout << "Reversed Stack: ";
    printStack(st);
    
    return 0;
}
