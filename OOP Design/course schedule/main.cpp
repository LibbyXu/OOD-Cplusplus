#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
//学生节点
typedef struct STU {
	string arrStuNum;
	string arrStuName;
	int iStuScore;
	struct STU* pNext;
	STU(string s1, string s2, int m) :arrStuNum(s1), arrStuName(s2), iStuScore(m),pNext(nullptr) {};
} STUNODE;

//The head of the linked list and the tail oif the linked list
STUNODE* g_pHead = nullptr;
STUNODE* g_pEnd = nullptr;
stack<STUNODE*>del;
//add
void AddStuMSG(string arrStuNum, string arrStuName, int iStuScore);

//链表头部添加节点
void AddHeadStuMSG(string arrStuNum, string arrStuName, int iStuScore);

//Clear
void FreeLinkData();
//Print
void ShowData();
//显示指令
void ShowOrder();
STUNODE* findStuNum(string insertNum);
void AddHeadStuMSG(string insertNum, string arrStuNum, string arrStuName,int iStuScore);
void findStuInfo(string arrStuNum);
void ModifyStuInfo(string arrStuNum, int iStuScore);
void DeleteStuInfo(string arrStuNum);
//store student info function
void SaveStuToFile();
void ReadStuInfo();
void RecoverStuInfo();
int main(void)
{
	
	int nOrder = -1; //The command for the input
					 //initilization
	char arrStuNum[10] = {'\0'};
	char arrStuName[10] = {'\0'};
	int iStuScore = -1;
	char insertNum[10] = {'\0'};
	bool nFlag = true;
	ReadStuInfo();

	printf("*****************学生信息管理系统*******************\n");
	printf("*****************本系统操作指令如下*****************\n");
	printf("***           1. 增加一个学生的信息(尾添加)       ***\n");
	printf("***          11. 增加一个学生的信息(头添加)       ***\n");
	printf("***         111. 增加一个学生的信息(指定位置添加） ***\n");
	printf("***           2. 查找指定学生的信息(姓名/学号)    ***\n");
	printf("***           3. 修改指定学生的信息              ***\n");
	printf("***           4. 保存业主的信息到文件中          ***\n");
	printf("***           5. 读取文件中的业主信息            ***\n");
	printf("***           6. 删除指定学生信息                ***\n");
	printf("***           7. 恢复删除的学生信息              ***\n");
	printf("***           9. 显示所有学生的信息              ***\n");
	printf("***           0. 退出系统                       ***\n");
	printf("***************************************************\n");
	
	while (nFlag)
	{
		printf("请输入指令(10.查看指令):");
		scanf_s("%d", &nOrder);
	
		switch (nOrder)
		{
		case 0:
			//exit the program
			nFlag = false;
			break;
		case 1:
			//add a student's info
			printf("输入学号:");
			scanf("%s", arrStuNum);
			printf("输入姓名:");
			scanf("%s", arrStuName);
			printf("输入分数:");
			scanf("%d", &iStuScore);
			AddStuMSG(string(arrStuNum), string(arrStuName), iStuScore);
			break;
		case 2:
			printf("输入学号:");
			scanf("%s", arrStuNum);
			findStuInfo(arrStuNum);
			break;
		case 3:
			printf("输入学号:");
			scanf("%s", arrStuNum);
			printf("输入分数:");
			scanf("%d", &iStuScore);
			ModifyStuInfo(arrStuNum, iStuScore);
			break;
		case 4:
			//store the student info
			SaveStuToFile();
			break;
		case 5:
			ReadStuInfo();
			break;
		case 6:
			printf("输入学号:");
			scanf("%s", arrStuNum);
			DeleteStuInfo(arrStuNum);
			break;
		case 7:
			RecoverStuInfo();
			break;
		case 9:
			//show all data
			ShowData();
			break;
		case 10:
			//查看指令
			ShowOrder();
			break;
		case 11:
			//add a student's info
			printf("输入学号:");
			scanf("%s", arrStuNum);
			printf("输入姓名:");
			scanf("%s", arrStuName);
			printf("输入分数:");
			scanf("%d", &iStuScore);
			AddHeadStuMSG(arrStuNum, arrStuName, iStuScore);
			break;
		case 111:
			//add a student's info
			printf("插入位置:");
			scanf("%s", insertNum);
			printf("输入学号:");
			scanf("%s", arrStuNum);
			printf("输入姓名:");
			scanf("%s", arrStuName);
			printf("输入分数:");
			scanf("%d", &iStuScore);
			AddHeadStuMSG(insertNum, arrStuNum, arrStuName, iStuScore);
			break;
		default:
			printf("输入的指令不对!!!\n");
		}
	
		printf("\n");
	}
	
	//STORE STUDENT INFO FUNCTION
	FreeLinkData();
	system("Pause");
	return 0;
}

void AddStuMSG(string arrStuNum, string arrStuName, int iStuScore)
{
	if (arrStuNum.length() == 0 || arrStuName.length() == 0 || iStuScore < 0)
	{
		printf("学生信息输入错误!\n");
		return;
	}
	STUNODE* pTemp = new STUNODE(arrStuNum, arrStuName, iStuScore);
	if (g_pHead == nullptr)
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else 
	{
		g_pEnd->pNext = pTemp;
		g_pEnd = g_pEnd->pNext;
	}
}

void FreeLinkData()
{
	STUNODE* pTemp;
	while (g_pHead)
	{
		pTemp = g_pHead;
		g_pHead = g_pHead->pNext;
		free(pTemp);
	}
}

void ShowData()
{
	STUNODE* pTemp = g_pHead;
	while (pTemp)
	{
		string s1 = pTemp->arrStuNum;
		string s2 = pTemp->arrStuName;
		printf("学号:%10s,     姓名:%10s,      分数:%3d\n", s1.c_str(), s2.c_str(), pTemp->iStuScore);
		pTemp = pTemp->pNext;
	}
}

void ShowOrder()
{	
	printf("*****************本系统操作指令如下*****************\n");
	printf("***           1. 增加一个学生的信息              ***\n");
	printf("***          11. 增加一个学生的信息(头添加)       ***\n");
	printf("***         111. 增加一个学生的信息(指定位置添加） ***\n");
	printf("***           2. 查找指定学生的信息(姓名/学号)    ***\n");
	printf("***           3. 修改指定学生的信息              ***\n");
	printf("***           4. 保存业主的信息到文件中          ***\n");
	printf("***           5. 读取文件中的业主信息            ***\n");
	printf("***           6. 删除指定学生信息                ***\n");
	printf("***           7. 恢复删除的学生信息              ***\n");
	printf("***           9. 显示所有学生的信息              ***\n");
	printf("***           0. 退出系统                       ***\n");
	printf("***************************************************\n");
}

void AddHeadStuMSG(string arrStuNum, string arrStuName, int iStuScore)
{
	if (arrStuNum.length() == 0 || arrStuName.length() == 0 || iStuScore < 0)
	{
		printf("学生信息输入错误!\n");
		return;
	}
	STUNODE* pTemp = new STUNODE(arrStuNum, arrStuName, iStuScore);
	if (g_pHead == nullptr) {		
		g_pEnd = pTemp;
	}
	else 
	{
		pTemp->pNext = g_pHead;		
	}
	g_pHead = pTemp;
}

STUNODE* findStuNum(string insertNum) {
	if (insertNum.length() == 0) 
	{
		return nullptr;
	}
	STUNODE* pTemp = g_pHead;
	while (pTemp && pTemp->arrStuNum != insertNum) {
		pTemp = pTemp->pNext;
	}
	if (!pTemp)return nullptr;
	return pTemp;
}

void AddHeadStuMSG(string insertNum, string arrStuNum, string arrStuName, int iStuScore)
{
	STUNODE* pTemp = findStuNum(insertNum);
	if (!pTemp) 
	{
		printf("不存在插入位置学生信息!\n");
		return;
	}
	else 
	{
		STUNODE* pCur = new STUNODE(arrStuNum, arrStuName, iStuScore);
		pCur->pNext = pTemp->pNext;
		pTemp->pNext = pCur;
	}
	
}

void findStuInfo(string arrStuNum)
{
	if(arrStuNum.length()==0)
	{
		printf("请输入学生学号!\n");
		return;
	}
	STUNODE* pTemp= findStuNum(arrStuNum);
	if (!pTemp)
	{
		printf("不存在学生信息!\n");
		return;
	}
	else
	{
		string s1 = pTemp->arrStuNum;
		string s2 = pTemp->arrStuName;
		printf("学号:%10s,     姓名:%10s,      分数:%3d\n", s1.c_str(), s2.c_str(), pTemp->iStuScore);
	}

}

void ModifyStuInfo(string arrStuNum, int iStuScore) {
	if (arrStuNum.length() == 0)
	{
		printf("请输入学生学号!\n");
		return;
	}
	STUNODE* pTemp = findStuNum(arrStuNum);
	if (!pTemp)
	{
		printf("不存在学生信息!\n");
		return;
	}
	else
	{
		pTemp->iStuScore = iStuScore;
	}
}

void DeleteStuInfo(string arrStuNum) {
	if (arrStuNum.length() == 0)
	{
		printf("请输入学生学号!\n");
		return;
	}
	STUNODE* pTemp = findStuNum(arrStuNum);
	if (!pTemp)
	{
		printf("不存在学生信息!\n");
		return;
	}
	else {
		STUNODE* pNewTemp = g_pHead;
		if (pNewTemp->arrStuName == pTemp->arrStuName) {
			g_pHead = pNewTemp->pNext;
			pTemp=nullptr;
			return;
		}
		while (pNewTemp->pNext->arrStuName != pTemp->arrStuName) {
			pNewTemp = pNewTemp->pNext;
		}
		pNewTemp->pNext = pTemp->pNext;
		del.push(move(pTemp));
	}
}

void SaveStuToFile() {
	if (!g_pHead) {
		printf("链表为空,没有学生!\n");
		return;
	}
	FILE* pFile = NULL;
	string strBuf;
	pFile = fopen("dat.dat","wb+");
	if (NULL == pFile)
	{
		printf("文件打开失败!\n");
		return;
	}

	STUNODE* pTemp = g_pHead;
	while (pTemp) {
		strBuf += pTemp->arrStuNum;
		strBuf += "," + pTemp->arrStuName;
		strBuf += "," + to_string(pTemp->iStuScore);
		fwrite(strBuf.c_str(), 1, strlen(strBuf.c_str()), pFile);
		fwrite("\r\n",1,strlen("\r\n"),pFile);
		pTemp = pTemp->pNext; 
		strBuf.clear();
	}
	fclose(pFile);
}

void ReadStuInfo() 
{
	FILE* pFile = fopen("dat.dat", "rb+");
	if (NULL == pFile)
	{
		printf("文件打开失败!\n");
		return;
	}
	char strBuff[40] = {'\0'};
	string arrStuNum;
	string arrStuName;
	string iStuScore;
	
	int n_count = 0;
	while (fgets(strBuff, 30, pFile)!=NULL) 
	{		
		int i = 0;
		for (; strBuff[i] != '\r';++i) {
			if (0 == n_count) {
				arrStuNum += strBuff[i];
				if (',' == strBuff[i])n_count++;
			}
			else if (1 == n_count) {
				arrStuName += strBuff[i];
				if (',' == strBuff[i])n_count++;
			}
			else {
				iStuScore += strBuff[i];
			}
		}
		//cout << arrStuNum.substr(0, arrStuNum.size() - 1) << ' ' << arrStuName.substr(0, arrStuName.size() - 1) << ' ' << stoi(iStuScore) << endl;
		AddStuMSG(arrStuNum.substr(0, arrStuNum.size()-1), arrStuName.substr(0, arrStuName.size()-1), stoi(iStuScore));
		arrStuNum.clear();
		arrStuName.clear();
		iStuScore.clear();
		n_count = 0;
	}

	fclose(pFile);
}

void RecoverStuInfo()
{
	STUNODE* pTemp = del.top(); del.pop();
	AddStuMSG(pTemp->arrStuNum, pTemp->arrStuName, pTemp->iStuScore);
	free(pTemp);
}