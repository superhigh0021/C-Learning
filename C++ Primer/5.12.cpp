#include<iostream>
using namespace std;

int main(void) {
	int ffCnt=0,flCnt=0,fiCnt=0;
	char ch,flag='\0';

	cout<<"请输入一段文本："<<endl;
	while(cin>>ch) {
		bool bl=true;
		if(flag=='f') {
			switch(ch) {
			case 'f':
				bl=false;
				++ffCnt;
				break;
			case 'l':
				++flCnt;
				break;
			case 'i':
				++fiCnt;
				break;
			}
		}
		if(!bl)
			flag='\0';
		else flag=ch;
	}
	cout<<ffCnt<<' '<<flCnt<<' '<<fiCnt<<endl;
	return 0;
}
