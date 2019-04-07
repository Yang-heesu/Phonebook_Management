/* Name : common.h	ver 1.0
 * Content : main 함수
 * 프로그램 사용자의 입력을 받고 그에 따른 처리를
 * 담당하도록 구성
 * Implementation : YHS
 *
 * Last modified 2018 / 01 / 05
 */

#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

/* 함수 : int main(void
 * 기능 : 사용자 선택 처리
 * 반환 : 정상 종료 시 0)
 */

enum {INPUT=1 , SHOWALL, SEARCH, DELETE, CHANGE, QUIT};
int main(){

	int inputMenu = 0;

	while (1){
		ShowMenu(); //화면에 메뉴를 표시
		scanf("%d", &inputMenu);
		fflush(stdin);
		
		switch (inputMenu){
		case INPUT :
			InputPhoneData();
			break;
		case SHOWALL :
			ShowAllData();
			break;
		case SEARCH :
			SearchPhoneData();
			break;
		case DELETE :
			DeletePhoneData();
			break;
		case CHANGE:
			ChangePhoneData();
			break;
		}

		if (inputMenu == QUIT){
			puts("이용해 주셔서 감사합니다.");
			break;
		}
	}

	return 0;
}