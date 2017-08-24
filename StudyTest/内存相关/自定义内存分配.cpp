class A
{
public:
	A(){ a = 10; }
	~A(){ cout << "A被注销了"<< endl; };
	void* operator new(size_t size)
	{
		cout <<"进入自定义分配" << endl;
		void* a = malloc(sizeof(A));
		return a;
	}
	void operator delete(void* p)
	{
		free(p);
		cout << "释放A占的内存"<< endl;
	}
	int a;
};
int main()
{
	A* a = new A();
	cout << a->a << endl;
	delete a;
	getchar();
	return 1;
}