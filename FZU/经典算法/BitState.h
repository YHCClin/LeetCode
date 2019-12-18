#ifndef __BITSTATE__
#define __BITSTATE__

#include <iostream>
#include <string>

class BitState {
	friend unsigned int CountBit(unsigned long long &n);
public:
	BitState();					// 无参构造函数
	BitState(unsigned int len); // 带参数 len 的构造函数， 申明一个二进制长度为len的bitset
	BitState(unsigned int len, unsigned long long val); // 用 val 初始化长度为len的bitset
	BitState(const BitState &tmp);// 拷贝构造函数
	~BitState();

	bool any();//是否存在置为1的二进制位？
	bool none();//不存在置为1的二进制位吗？
	unsigned int count();//置为1的二进制位的个数
	unsigned int size();//二进制位的个数

	bool test(unsigned int pos);//在pos处的二进制位是否为1？
	void set();//把所有二进制位都置为1
	void set(unsigned int pos);//在pos处的二进制位置为1
	void reset();//把所有二进制位都置为0
	void reset(unsigned int pos);//在pos处的二进制位置为0
	void flip();//把所有二进制位逐位取反
	void flip(unsigned int pos);//在pos处的二进制位取反
	unsigned long long to_ulong();//返回一个unsigned long值

protected:
	unsigned int bitlen;		// 二进制位数
	unsigned int numlen;		// 数组长度
	unsigned long long *bits;	// 数组
};

BitState::BitState()
{
	// 默认构造一个 64 和位数的bitset
	bitlen = 8 * sizeof(unsigned long long);
	numlen = 1;
	bits = new unsigned long long[numlen];
}

BitState::BitState(unsigned int len, unsigned long long val)
{
	// 构造指定 len 长度的bitset
	bitlen = len;
	// numlen 向上取整 , 对于 x/y ,向上取整为 (x + y - 1) / y;
	numlen = (len + 8 * sizeof(unsigned long long) - 1) / (8 * sizeof(unsigned long long));
	bits = new unsigned long long[numlen];
	if(len) bits[0] = val; // 以 val 初始化
}

BitState::BitState(const BitState &tmp)
{
	bitlen = tmp.bitlen;
	numlen = tmp.numlen;
	bits   = new unsigned long long[numlen];
	for(int i = 0;i < numlen; ++i)
	{
		bits[i] = tmp.bits[i];
	}
}

BitState::~BitState()
{
	delete[] bits;
}

bool BitState::any()
{
	for(int i = 0;i < numlen; ++i)
	{
		if(bits[i] != 0ULL) return true;
	}
	return false;
}

bool BitState::none()
{
	for(int i = 0;i < numlen; ++i)
	{
		if(bits[i] != 0ULL) return false;
	}
	return true;
}

unsigned int CountBit(unsigned long long &n)
{
	unsigned int cnt = 0;
	while(n)
	{
		cnt++;
		n = n & (n - 1);
	}
	return cnt;
}
unsigned int BitState::count()
{
	unsigned int cnt = 0;
	for(int i = 0;i < numlen; ++i)
	{
		cnt += CountBit(bits[i]);
	}
	return cnt;
}

unsigned int BitState::size()
{
	return bitlen;
}


bool BitState::test(unsigned int pos)
{
	if(pos < bitlen)
	{
		int n = (pos / (8 * sizeof(unsigned long long))); // 得到在数组中的哪个数中
		int final = pos - n * (8 * sizeof(unsigned long long));
		return ((bits[n] >>  (8 * sizeof(unsigned long long) - final)) & 1ULL);
	}
	std::cerr << "Out of Bounds" << std::endl;
	exit(0);
	return false;
}

void BitState::set()
{
	for(int i = 0;i < numlen; ++i)
		bits[i] = 0xffffffffffffffff;
}

void BitState::set(unsigned int pos)
{
	if(pos < bitlen)
	{
		int n = (pos / (8 * sizeof(unsigned long long))); // 得到在数组中的哪个数中
		int final = pos - n * (8 * sizeof(unsigned long long));// 最终位置
		bits[n] |= ( 1ULL << ((8*sizeof(unsigned long long) - final)));	// 置 1
	}
}

void BitState::reset()
{
	for(int i = 0;i < numlen; ++i)
	{
		bits[i] = 0ULL;
	}
}

void BitState::reset(unsigned int pos)
{
	if(pos < bitlen)
	{
		int n = (pos / (8 * sizeof(unsigned long long))); // 得到在数组中的哪个数中
		int final = pos - n * (8 * sizeof(unsigned long long));// 最终位置
		bits[n] &= ~( 1ULL << (8*sizeof(unsigned long long) - final));	// 置 0
	}
}

void BitState::flip()
{
	for(int i = 0;i < numlen; ++i)
	{
		bits[i] = ~bits[i];
	}
}

void BitState::flip(unsigned int pos)
{
	if(pos < bitlen)
	{
		int n = (pos / (8 * sizeof(unsigned long long))); // 得到在数组中的哪个数中
		int final = pos - n * (8 * sizeof(unsigned long long))+1;// 最终位置
		bits[n] ^= ( 1ULL << (8*sizeof(unsigned long long) - final));	// 取反
	}
}


#endif