class A
{
public:
	A(){ a = 10; }
	~A(){ cout << "A��ע����"<< endl; };
	void* operator new(size_t size)
	{
		cout <<"�����Զ������" << endl;
		void* a = malloc(sizeof(A));
		return a;
	}
	void operator delete(void* p)
	{
		free(p);
		cout << "�ͷ�Aռ���ڴ�"<< endl;
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