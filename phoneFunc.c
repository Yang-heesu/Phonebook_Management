
#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "phoneData.h"
#include "phoneFunc.h"
#include "screenOut.h"

#define LIST_NUM 100

int numofData = 0;
//phoneData phoneList[LIST_NUM];
phoneData* phoneList[LIST_NUM];

void InputPhoneData(){
	int i;
	phoneData *pData;
	//phoneData data;

	if (numofData >= LIST_NUM){
		puts("�޸� ������ �����մϴ�.");
	}

	pData = (phoneData *)malloc(sizeof(phoneData)); // ���� �߰�!

	printf("\n�̸� �Է� : ");

	scanf("%s", pData->name);
	//gets(pData->name);
	//gets(data.name);



	printf("��ȭ��ȣ �Է� : ");
	scanf("%s", pData->phoneNum);
	//gets(pData->phoneNum);
	//gets(data.phoneNum);

	for (i = 0; i < numofData; i++){
		if (strcmp(pData->phoneNum, phoneList[i]->phoneNum) == 0 && strcmp(pData->name, phoneList[i]->name) == 0){
			printf("������ �����Ͱ� �ֽ��ϴ�.");
			free(pData);
			getchar();
			return;	//0�̳� 1�� �ִ� ���� �ü������ �����ִ� ����
					//return �ϸ� �� �Լ��� �θ� ������ ���ư�
		}
	}

	phoneList[numofData] = pData;
	numofData++;

	printf("�Է��� �Ϸ�Ǿ����ϴ�.");
	getchar();
	getchar();
}

void ShowAllData(){
	for (int i = 0; i < numofData; i++){
		ShowPhoneInfoByPtr(phoneList[i]);
		//ShowPhoneInfo(phoneList[i]);
	}

	printf("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
	getchar();
}

void SearchPhoneData(){
	char name[LIST_NUM];
	printf("ã�� ��� �̸� : ");
	scanf("%s", name);
	//gets(name);

	for (int i = 0; i < numofData; i++){
		if (!strcmp(name, phoneList[i]->name)){
			ShowPhoneInfoByPtr(phoneList[i]);
			printf("�˻� ����");
			getchar();
			return;
		}
	}
	printf("�����Ͱ� �������� �ʽ��ϴ�.");
	getchar();
	getchar();
}

void DeletePhoneData(){
	int i, j=0;
	char name[LIST_NUM];

	int IdxOfMatchingData[LIST_NUM]; //�߰�
	int matchedCount = 0;
	int deliex = 0; //�߰�
	int selection;

	fputs("������ ��� �̸� : ",stdout); //printf�� ����
	scanf_s("%s", name);
	//gets(name);

	//for (i = 0; i < numofData; i++){
	//	if (!strcmp(phoneList[i]->name, name)){
	//		for (j = i; j < numofData - 1; j++){
	//			phoneList[j] = phoneList[j + 1];
	//		}
	//		numofData--;
	//		puts("������ �Ϸ�Ǿ����ϴ�.");
	//		getchar();
	//		return;
	//	}
	//}

	//puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
	//getchar();

	for (i = 0; i < numofData; i++){
		if (strcmp(phoneList[i]->name, name) == 0)
			IdxOfMatchingData[matchedCount++] = i;
	}

	if (matchedCount == 0){
		puts("ã�� �����Ͱ� ����.");
		getchar();
		return;
	}
	else if (matchedCount == 1){
		deliex = IdxOfMatchingData[0];
	}
	else{
		for (i = 0; i < numofData; i++){
			printf("NUM. %d\n", i+1);
			ShowPhoneInfoByPtr(phoneList[IdxOfMatchingData[i]]);
		}

		puts("���� : ");
		scanf("%d", &selection);
		deliex = IdxOfMatchingData[selection - 1];
	}

	free(phoneList[deliex]);

	for (j = deliex; j < numofData - 1; j++){
		phoneList[j] = phoneList[j + 1];
	}
	numofData--;

	puts("������ �Ϸ�Ǿ����ϴ�.");
	getchar();
	getchar();
	
}

void ChangePhoneData(){
	int i;
	char searchName[30];
	char newPhoneNumber[30];

	int idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int selection = 0;
	int delIdx = 0;

	fputs("���� ����� �̸� : ",stdout);
	gets(searchName);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, searchName))
			idxOfMatchingData[matchedCount++] = i;
	}

	if (matchedCount == 0){
		puts("���� ����� �̸��� �������� �ʽ��ϴ�.");
		getchar();
		getchar();
		return;
	}
	else if (matchedCount == 1){
		delIdx = idxOfMatchingData[0];
	}
	else{
		for (i = 0; i < matchedCount; i++){
			printf("NUM. %d \n", i + 1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}
		fputs("���� : ", stdout);
		scanf("%d", &selection);
		fflush(stdin);

		delIdx = idxOfMatchingData[selection - 1];
	}


	printf("������ ��ȭ��ȣ��? : ");
	gets(newPhoneNumber);
	strcpy(phoneList[delIdx]->phoneNum, newPhoneNumber);

	puts("������ �Ϸ�Ǿ����ϴ�.");
	getchar();
	getchar();
	
}