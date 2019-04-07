
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
		puts("메모리 공간이 부족합니다.");
	}

	pData = (phoneData *)malloc(sizeof(phoneData)); // 새로 추가!

	printf("\n이름 입력 : ");

	scanf("%s", pData->name);
	//gets(pData->name);
	//gets(data.name);



	printf("전화번호 입력 : ");
	scanf("%s", pData->phoneNum);
	//gets(pData->phoneNum);
	//gets(data.phoneNum);

	for (i = 0; i < numofData; i++){
		if (strcmp(pData->phoneNum, phoneList[i]->phoneNum) == 0 && strcmp(pData->name, phoneList[i]->name) == 0){
			printf("동일한 데이터가 있습니다.");
			free(pData);
			getchar();
			return;	//0이나 1을 넣는 것은 운영체제에게 돌려주는 거임
					//return 하면 이 함수를 부른 곳으로 돌아감
		}
	}

	phoneList[numofData] = pData;
	numofData++;

	printf("입력이 완료되었습니다.");
	getchar();
	getchar();
}

void ShowAllData(){
	for (int i = 0; i < numofData; i++){
		ShowPhoneInfoByPtr(phoneList[i]);
		//ShowPhoneInfo(phoneList[i]);
	}

	printf("출력이 완료되었습니다.");
	getchar();
	getchar();
}

void SearchPhoneData(){
	char name[LIST_NUM];
	printf("찾는 사람 이름 : ");
	scanf("%s", name);
	//gets(name);

	for (int i = 0; i < numofData; i++){
		if (!strcmp(name, phoneList[i]->name)){
			ShowPhoneInfoByPtr(phoneList[i]);
			printf("검색 성공");
			getchar();
			return;
		}
	}
	printf("데이터가 존재하지 않습니다.");
	getchar();
	getchar();
}

void DeletePhoneData(){
	int i, j=0;
	char name[LIST_NUM];

	int IdxOfMatchingData[LIST_NUM]; //추가
	int matchedCount = 0;
	int deliex = 0; //추가
	int selection;

	fputs("삭제할 사람 이름 : ",stdout); //printf와 같음
	scanf_s("%s", name);
	//gets(name);

	//for (i = 0; i < numofData; i++){
	//	if (!strcmp(phoneList[i]->name, name)){
	//		for (j = i; j < numofData - 1; j++){
	//			phoneList[j] = phoneList[j + 1];
	//		}
	//		numofData--;
	//		puts("삭제가 완료되었습니다.");
	//		getchar();
	//		return;
	//	}
	//}

	//puts("찾는 이름의 데이터가 존재하지 않습니다.");
	//getchar();

	for (i = 0; i < numofData; i++){
		if (strcmp(phoneList[i]->name, name) == 0)
			IdxOfMatchingData[matchedCount++] = i;
	}

	if (matchedCount == 0){
		puts("찾는 데이터가 없다.");
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

		puts("선택 : ");
		scanf("%d", &selection);
		deliex = IdxOfMatchingData[selection - 1];
	}

	free(phoneList[deliex]);

	for (j = deliex; j < numofData - 1; j++){
		phoneList[j] = phoneList[j + 1];
	}
	numofData--;

	puts("삭제가 완료되었습니다.");
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

	fputs("변경 대상의 이름 : ",stdout);
	gets(searchName);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, searchName))
			idxOfMatchingData[matchedCount++] = i;
	}

	if (matchedCount == 0){
		puts("변경 대상의 이름이 존재하지 않습니다.");
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
		fputs("선택 : ", stdout);
		scanf("%d", &selection);
		fflush(stdin);

		delIdx = idxOfMatchingData[selection - 1];
	}


	printf("변경할 전화번호는? : ");
	gets(newPhoneNumber);
	strcpy(phoneList[delIdx]->phoneNum, newPhoneNumber);

	puts("변경이 완료되었습니다.");
	getchar();
	getchar();
	
}