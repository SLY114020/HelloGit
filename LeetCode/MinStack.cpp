class MinStack {
public:
	MinStack() {
		cur_max_size = 4;
		a = new int[cur_max_size];
		top_index = -1;
		min_index = -1;
	}

	void push(int x) {
		if (top_index + 1 == cur_max_size)
		{
			int* new_stack = new int[cur_max_size * 2];
			if (new_stack == NULL)
				return;
			cur_max_size = cur_max_size * 2;
			for (int i = 0; i <= top_index; ++i)
				new_stack[i] = a[i];
			delete[] a;
			a = new_stack;
		}
		++top_index;
		a[top_index] = x;
		if (min_index == -1)
		{
			min_index = 0;
			return;
		}
		if (x < a[min_index])
			min_index = top_index;
	}

	void pop() {
		if (top_index == -1)
			return;
		if (top_index == min_index)
		{
			int index = 0;
			for (int i = 1; i <= top_index - 1; i++)
			{
				if (a[index] > a[i])
				{
					index = i;
				}
			}
			min_index = index;
		}
		a[top_index] = 0;
		--top_index;
	}

	int top() {
		if (top_index == -1)
			return 0;
		return a[top_index];
	}

	int getMin() {
		if (top_index == -1)
			return 0;
		return a[min_index];
	}
private:
	int* a;
	int top_index;
	int min_index;
	int cur_max_size;
};