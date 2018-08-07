class MyQueue {
private:
  stack<int> input, output;
public:
  // constructor
  MyQueue() {}
  
  // push x to the back of queue
  void push(int x) {
    input.push(x);
  }

  // remove the element from in front
  // of queue and returns that element
  int pop() {
    int tmp = peek();
    output.pop();
    return tmp;
  }

  // get the front element
  int peek() {
    if (output.empty()) 
      while (input.size()) 
	output.push(input.top()), input.pop();
    
    return output.top();
  }

  // return whether queue is empty
  bool empty() {
    return input.empty() && output.empty();
  }

};
