// ����ѡ����Ҫ����-std=c++11 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

int cnt4=1,cnt5=1,sixingwai=0;
bool dbd;

char sanxing[50][20]={"������","����","��Ӱ����","��ԡ��Ѫ�Ľ�","�������","ѻ��","����","����Ӣ��̷","ħ������","������","��ӧǹ"};
char sixing[110][20]={"¹ҰԺƽ��","��¶ɺ","����","����","����","������","��л��","��ɯ����","�Ű���","ɰ��","����","����","����","��ɯ","����","����","ŵ����","����","����","��������","�����","���","����","�ϰ���","����","����","����","�����","�ӽ�","���罣","����","�ѽ�","����","�����Թ�","����","����","�����ص�","��������","�������","���糤ǹ","ϻ����"};
char wuxing[10][20]={"ɺ�����ĺ�","����","������","Ī��","��","��¬��","����"};

int Randint(int l,int r){
    static std::mt19937 mt(time(NULL));
    return std::uniform_int_distribution<int>(l,r)(mt);
}

void count(int x){
	if(x==5) cnt5++,cnt4=1;
	else cnt5++,cnt4++;
}

int onepull(){
	int rx=Randint(1,10000);
	if(cnt5<=73){
		if(rx>=1 && rx<=60){
			if(dbd==1) {cnt5=1;dbd=0;cnt4++;return 6;}
			int wai=Randint(895,896);
			if(wai&1){cnt5=1;dbd=1;cnt4++;return 5;}
			else{cnt5=1;dbd=0;cnt4++;return 6;}
		}
		else{
			if(cnt4<=8){
				if(rx>=61 && rx<=570){
					count(5);return 4;
				}
				else {count(0);return 3;}
			}
			else{
				if(rx>=61 && rx<=570+5100*(cnt4-8)){
					count(5);return 4;
				}
				else {count(0);return 3;}
			}
		}
	}
	else{
		int fiverv=60+600*(cnt5-73);
		if(rx>=1 && rx<=fiverv){
			if(dbd==1) {cnt5=1;dbd=0;cnt4++;return 6;}
			int wai=Randint(895,896);
			if(wai&1){cnt5=1;dbd=1;cnt4++;return 5;}
			else{cnt5=1;dbd=0;cnt4++;return 6;}
		}
		else{
			if(cnt4<=8){
				if(rx>fiverv && rx<=510+fiverv){
					count(5);return 4;
				}
				else {count(0);return 3;}
			}
			else{
				if(rx>fiverv && rx<=510+fiverv+5100*(cnt4-8)){
					count(5);return 4;
				}
				else {count(0);return 3;}
			}
		}
	}
}

char* aroll(){
	int tmp=onepull(),x=0;
	if(tmp==6) return wuxing[0];
	if(tmp==5){
		x=Randint(1,6);
		return wuxing[x];
	}
	if(tmp==3){
		x=Randint(0,10);
		return sanxing[x];
	}
	if(tmp==4){
		// four star: 0-2 up, 3-26 character. 27-40 weapon.
		x=Randint(233,234);
		if(sixingwai) return sixing[Randint(0,2)];
		if(x&1){
			sixingwai=0;
			return sixing[Randint(0,2)];
		}
		else{
			sixingwai=1;
			x=Randint(3,40);
			return sixing[x];
		}
	}

}

int main(){
	printf("��ӭʹ���׳س鿨ģ����(lsj ver.)\n���ڿ��ſ���:����\"ɺ�����ĺ�\"����up, ����¹ҰԺƽ�ء���¶ɺ����������up\n�����밴1, ʮ�����밴2, �˳��밴0:");
	int x,numru=1;scanf("%d",&x);
	while(x){
		if(x==1) printf("%s\n",aroll());
		else if(x==2){
			for(int i=1;i<=10;i++)
				printf("%s\n",aroll());
		}
		else printf("Error\n");
		printf("\n����ǰ�Ѿ���%d��δ�����ǣ�%d��δ������\n",cnt5-1,cnt4-1);
		scanf("%d",&x);
		numru++;
	}
	return 0;
}


