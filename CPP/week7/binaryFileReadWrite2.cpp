#include <iostream>
#include <fstream>
using namespace std;

class CStudent
{
public:
	char szName[20];
	int nScore;
};

int main() {
	CStudent s;
	fstream ioFile("students.txt", ios::in|ios::out|ios::binary);
	if (!ioFile)
	{
		cout << "error" << endl;
		return 0;
	}

	ioFile.seekp(2*sizeof(s), ios::beg);	// 定位写指针到第三个记录
	ioFile.write("Mike", strlen("Mike"+1));
	ioFile.seekg(0, ios::beg);	//定位读指针到开头

	while (ioFile.read((char *)&s, sizeof(s))) {
		int nReadedBytes = ioFile.gcount();  // 看刚才读了多少字节
		cout << s.szName << " " << s.nScore << endl;
	}

	ioFile.close();
	return 0;
}