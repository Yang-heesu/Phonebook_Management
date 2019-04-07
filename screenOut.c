#include "common.h"
#include "phoneData.h"

void ShowMenu(){
	system("cls"); //ȭ���� �����ϰ� ������

	printf("\n---------------�޴�---------------\n");
	printf("1. ��ȭ��ȣ �Է�\n");
	printf("2. ��ü ���� ���\n");
	printf("3. ��ȭ��ȣ �˻�\n");
	printf("4. ��ȭ��ȣ ����\n");
	printf("5. ��ȭ��ȣ ����\n");
	printf("6. ����\n");
	printf("----------------------------------\n");
	printf("���� >> ");

}

void ShowPhoneInfo(phoneData phone){
	printf("\n����������������������������������������������������������\n");
	printf("��  �� �̸� : %s\n", phone.name);
	printf("��\n");
	printf("��  �� ��ȭ��ȣ : %s\n", phone.phoneNum);
	printf("������������������������������������������������������������\n\n");
}

void ShowPhoneInfoByPtr(phoneData* pPhone){
	printf("\n����������������������������������������������������������\n");
	printf("��  �� �̸� : %s\n", pPhone->name);
	printf("��\n");
	printf("��  �� ��ȭ��ȣ : %s\n", pPhone->phoneNum);
	printf("������������������������������������������������������������\n\n");
}