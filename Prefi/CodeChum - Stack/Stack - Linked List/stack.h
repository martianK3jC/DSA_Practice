class Stack{
	public:
		virtual void push(int num) = 0;//addHead
		virtual int pop() = 0;//removeHead
		virtual int size() = 0;
		virtual int top() = 0;
		virtual bool isEmpty() = 0;
		virtual void print() = 0;		
};