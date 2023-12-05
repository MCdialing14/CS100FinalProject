#ifndef BLOCK_H
#define BLOCK_H

class Block 
{
private:
	int value = 0;
	
public:
	Block(int value) : value(value) {};
	int GetValue()
	{
		return value;
	}
	void AddValue(int amount)
	{
		value += amount;
	}
};

#endif // !BLOCK_H