// ����ѡ����Ҫ����-std=c++11 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

char sanxing[30][20]={"������","����","��Ӱ����","��ԡ��Ѫ�Ľ�","�������","ѻ��","����","����Ӣ��̷","ħ������","������","��ӧǹ"};
char sixing[50][20]={"������","��¶ɺ","����","����","����","������","��л��","��ɯ����","�Ű���","ɰ��","����","����","����","��ɯ","����","����","ŵ����","����","����","��������","�����","���","����","�ϰ���","����","����","����","�����","�ӽ�","���罣","����","�ѽ�","����","�����Թ�","����","����","�����ص�","��������","�������","���糤ǹ","ϻ����"};
char wuxing[10][20]={"ɺ�����ĺ�","����","������","Ī��","��","��¬��","����"};

int cnt4=1,cnt5=1,sixingwai=0;
bool dbd;

struct Node{
	int rarity;
	char* name;
}b[30],a[50],s[10];

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

Node aroll(){
	int tmp=onepull(),x=0;
	if(tmp==6) return s[0];
	if(tmp==5){
		x=Randint(1,6);
		return s[x];
	}
	if(tmp==3){
		x=Randint(0,10);
		return b[x];
	}
	if(tmp==4){
		// four star: 0-2 up, 3-26 character. 27-40 weapon.
		x=Randint(233,234);
		if(sixingwai) return a[Randint(0,2)];
		if(x&1){
			sixingwai=0;
			return a[Randint(0,2)];
		}
		else{
			sixingwai=1;
			x=Randint(3,40);
			return a[x];
		}
	}
}

void pull1(){
	Node ans=aroll();
	if(ans.rarity==5)
		printf(" ***** %s\n",ans.name);
	else printf("%d* %s\n",ans.rarity,ans.name);
}

void Init(){
	puts("��ӭʹ���׳س鿨ģ����(lsj ver.)");
	puts("���ڿ��ſ���:���ǣ�ɺ�����ĺ� ����up, ���ǣ������ߡ���¶ɺ����������up");
	puts("�����밴1, ʮ�����밴2, �˳��밴0:");
	for(int i=0;i<11;i++) b[i].rarity=3,b[i].name=sanxing[i];
	for(int i=0;i<41;i++) a[i].rarity=4,a[i].name=sixing[i];
	for(int i=0;i<7;i++) s[i].rarity=5,s[i].name=wuxing[i];
}

int main(){
	Init();
	int x,numru=1;
	scanf("%d",&x);
	while(x){
		if(x==1) pull1();
		else if(x==2)
			for(int i=1;i<=10;i++) pull1();
		else printf("Error\n");
		printf("\n����ǰ�Ѿ���%d��δ�����ǣ�%d��δ������\n",cnt5-1,cnt4-1);
		scanf("%d",&x);
		numru++;
	}
	return 0;
}


