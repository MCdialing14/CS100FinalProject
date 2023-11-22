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
};

#endif // !BLOCK_H