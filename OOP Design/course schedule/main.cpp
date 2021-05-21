#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
//ѧ���ڵ�
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

//����ͷ����ӽڵ�
void AddHeadStuMSG(string arrStuNum, string arrStuName, int iStuScore);

//Clear
void FreeLinkData();
//Print
void ShowData();
//��ʾָ��
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

	printf("*****************ѧ����Ϣ����ϵͳ*******************\n");
	printf("*****************��ϵͳ����ָ������*****************\n");
	printf("***           1. ����һ��ѧ������Ϣ(β���)       ***\n");
	printf("***          11. ����һ��ѧ������Ϣ(ͷ���)       ***\n");
	printf("***         111. ����һ��ѧ������Ϣ(ָ��λ����ӣ� ***\n");
	printf("***           2. ����ָ��ѧ������Ϣ(����/ѧ��)    ***\n");
	printf("***           3. �޸�ָ��ѧ������Ϣ              ***\n");
	printf("***           4. ����ҵ������Ϣ���ļ���          ***\n");
	printf("***           5. ��ȡ�ļ��е�ҵ����Ϣ            ***\n");
	printf("***           6. ɾ��ָ��ѧ����Ϣ                ***\n");
	printf("***           7. �ָ�ɾ����ѧ����Ϣ              ***\n");
	printf("***           9. ��ʾ����ѧ������Ϣ              ***\n");
	printf("***           0. �˳�ϵͳ                       ***\n");
	printf("***************************************************\n");
	
	while (nFlag)
	{
		printf("������ָ��(10.�鿴ָ��):");
		scanf_s("%d", &nOrder);
	
		switch (nOrder)
		{
		case 0:
			//exit the program
			nFlag = false;
			break;
		case 1:
			//add a student's info
			printf("����ѧ��:");
			scanf("%s", arrStuNum);
			printf("��������:");
			scanf("%s", arrStuName);
			printf("�������:");
			scanf("%d", &iStuScore);
			AddStuMSG(string(arrStuNum), string(arrStuName), iStuScore);
			break;
		case 2:
			printf("����ѧ��:");
			scanf("%s", arrStuNum);
			findStuInfo(arrStuNum);
			break;
		case 3:
			printf("����ѧ��:");
			scanf("%s", arrStuNum);
			printf("�������:");
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
			printf("����ѧ��:");
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
			//�鿴ָ��
			ShowOrder();
			break;
		case 11:
			//add a student's info
			printf("����ѧ��:");
			scanf("%s", arrStuNum);
			printf("��������:");
			scanf("%s", arrStuName);
			printf("�������:");
			scanf("%d", &iStuScore);
			AddHeadStuMSG(arrStuNum, arrStuName, iStuScore);
			break;
		case 111:
			//add a student's info
			printf("����λ��:");
			scanf("%s", insertNum);
			printf("����ѧ��:");
			scanf("%s", arrStuNum);
			printf("��������:");
			scanf("%s", arrStuName);
			printf("�������:");
			scanf("%d", &iStuScore);
			AddHeadStuMSG(insertNum, arrStuNum, arrStuName, iStuScore);
			break;
		default:
			printf("�����ָ���!!!\n");
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
		printf("ѧ����Ϣ�������!\n");
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
		printf("ѧ��:%10s,     ����:%10s,      ����:%3d\n", s1.c_str(), s2.c_str(), pTemp->iStuScore);
		pTemp = pTemp->pNext;
	}
}

void ShowOrder()
{	
	printf("*****************��ϵͳ����ָ������*****************\n");
	printf("***           1. ����һ��ѧ������Ϣ              ***\n");
	printf("***          11. ����һ��ѧ������Ϣ(ͷ���)       ***\n");
	printf("***         111. ����һ��ѧ������Ϣ(ָ��λ����ӣ� ***\n");
	printf("***           2. ����ָ��ѧ������Ϣ(����/ѧ��)    ***\n");
	printf("***           3. �޸�ָ��ѧ������Ϣ              ***\n");
	printf("***           4. ����ҵ������Ϣ���ļ���          ***\n");
	printf("***           5. ��ȡ�ļ��е�ҵ����Ϣ            ***\n");
	printf("***           6. ɾ��ָ��ѧ����Ϣ                ***\n");
	printf("***           7. �ָ�ɾ����ѧ����Ϣ              ***\n");
	printf("***           9. ��ʾ����ѧ������Ϣ              ***\n");
	printf("***           0. �˳�ϵͳ                       ***\n");
	printf("***************************************************\n");
}

void AddHeadStuMSG(string arrStuNum, string arrStuName, int iStuScore)
{
	if (arrStuNum.length() == 0 || arrStuName.length() == 0 || iStuScore < 0)
	{
		printf("ѧ����Ϣ�������!\n");
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
		printf("�����ڲ���λ��ѧ����Ϣ!\n");
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
		printf("������ѧ��ѧ��!\n");
		return;
	}
	STUNODE* pTemp= findStuNum(arrStuNum);
	if (!pTemp)
	{
		printf("������ѧ����Ϣ!\n");
		return;
	}
	else
	{
		string s1 = pTemp->arrStuNum;
		string s2 = pTemp->arrStuName;
		printf("ѧ��:%10s,     ����:%10s,      ����:%3d\n", s1.c_str(), s2.c_str(), pTemp->iStuScore);
	}

}

void ModifyStuInfo(string arrStuNum, int iStuScore) {
	if (arrStuNum.length() == 0)
	{
		printf("������ѧ��ѧ��!\n");
		return;
	}
	STUNODE* pTemp = findStuNum(arrStuNum);
	if (!pTemp)
	{
		printf("������ѧ����Ϣ!\n");
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
		printf("������ѧ��ѧ��!\n");
		return;
	}
	STUNODE* pTemp = findStuNum(arrStuNum);
	if (!pTemp)
	{
		printf("������ѧ����Ϣ!\n");
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
		printf("����Ϊ��,û��ѧ��!\n");
		return;
	}
	FILE* pFile = NULL;
	string strBuf;
	pFile = fopen("dat.dat","wb+");
	if (NULL == pFile)
	{
		printf("�ļ���ʧ��!\n");
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
		printf("�ļ���ʧ��!\n");
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