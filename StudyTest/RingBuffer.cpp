template<typename T>
class RingBuffer
{
public:
	RingBuffer(int buffer_size=10)
	{
		head = 0;
		end = 0;
		t = new T[buffer_size];
		this->buffer_size = buffer_size;
	}
	~RingBuffer()
	{
		delete[] t;
	}
	bool empty()
	{
		return head == end;
	}
	bool full()
	{
		return head == (end + 1) % buffer_size;
	}
	bool put(T data)
	{
		if (full())
			return false;
		t[end] = data;
		end = (end + 1) % buffer_size;
		return true;
	}
	T get()
	{
		if (empty())
			return 0;
		T data = t[head];
		head = (head + 1) % buffer_size; 
		return data;
	}
private:
	T* t;
	int head;
	int end;
	int buffer_size;
};