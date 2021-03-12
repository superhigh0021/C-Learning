#include<iostream>
using namespace std;

int main(void) {
	char ch;
	int aCnt=0,oCnt=0,eCnt=0,iCnt=0,uCnt=0,spaceCnt=0,tabCnt=0,lineCnt=0;
	cout<<"请输入一段文本"<<endl;
	while(cin.get(ch)) {
		switch(ch) {
		case 'a':
			aCnt++;
			break;
		case 'o':
			oCnt++;
			break;
		case 'e':
			eCnt++;
			break;
		case 'i':
			iCnt++;
			break;
		case 'u':
			uCnt++;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++lineCnt;
			break;
		default:
			break;
		}
	}
	cout<<aCnt<<' '<<oCnt<<' '<<eCnt<<' '<<iCnt<<' '<<uCnt
	    <<spaceCnt<<' '<<tabCnt<<' '<<lineCnt<<endl;

	return 0;
}
