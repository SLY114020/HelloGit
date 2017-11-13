void get()
{
	int num = 10;
	bool have_num = false;
	int num2 = 0x40000000;
	for (int i = 0; i <= 30; i++)
	{
		if (!have_num)
		{
			if (num & num2)
			{
				have_num = true;
				num -= num2;
			}
		}
		else
		{
			num = (num & num2) ? (num - num2) : (num + num2);
		}
		num2 = num2 >> 1;
	}
}


// base 
void otherGet()
{
	class Solution {
public:
    int findComplement(int num) {
        
           int x = floor(log2(num)) + 1;
            return num^((1<<x)- 1);

        
    }
};
}