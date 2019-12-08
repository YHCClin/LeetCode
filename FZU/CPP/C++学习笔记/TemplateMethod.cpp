#include <iostream>
using namespace std;

class CDocument {
public:
	void OnFileOpen()
	{
		// 这是个算法，每个 cout 输出代表一个实际动作
		cout << "dialog ..." << endl;
		cout << "check file status..." << endl;
		cout << "open file..." << endl;
		Serialize();
		cout << "close file..." << endl;
		cout << "update all views..." << endl;
	}

	virtual void Serialize() { }; // impure virtual, derived class must override this method
};

class CMyDoc : public CDocument {
public:
	virtual void Serialize() {
		// 自有应用程序本身才知道如何读取自己的文件格式
		cout << "CMyDoc::Serialize called" << endl;
	}
};

int main()
{
	CMyDoc myDoc;
	myDoc.OnFileOpen();
}