class MyQueue {
public:
	stack<int> input;
	stack<int> output;
	MyQueue() {

	}
	void push(int x) {
		input.push(x);

	}
	int pop() {
		int t = peek();
		output.pop();
		return t;

	}
	int peek() {
		if (output.empty()){
			while (input.size()){
				output.push(input.top());
				input.pop();
			}
		}
		return output.top();
	}
	bool empty() {
		return input.empty() && output.empty();
	}
};