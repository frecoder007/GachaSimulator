// 编译选项需要加上-std=c++11 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

int cnt4=1,cnt5=1,sixingwai=0;
bool dbd;

char sanxing[50][20]={"黎明神剑","冷刃","铁影阔剑","沐浴龙血的剑","以理服人","鸦羽弓","弹弓","讨龙英杰谭","魔导诸论","翡玉法球","黑缨枪"};
char sixing[110][20]={"鹿野院平藏","珐露珊","柯莱","香菱","行秋","班尼特","菲谢尔","罗莎莉亚","芭芭拉","砂糖","凝光","安柏","凯亚","丽莎","雷泽","重云","诺艾尔","云堇","五郎","九条裟罗","久岐忍","烟绯","辛焱","迪奥娜","早柚","北斗","托马","西风大剑","钟剑","西风剑","祭礼剑","笛剑","祭礼弓","西风猎弓","绝弦","昭心","西风秘典","流浪乐章","祭礼残章","西风长枪","匣里灭辰"};
char wuxing[10][20]={"珊瑚宫心海","刻晴","提纳里","莫娜","琴","迪卢克","七七"};

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
	printf("欢迎使用米池抽卡模拟器(lsj ver.)\n本期开放卡池:五星\"珊瑚宫心海\"概率up, 四星鹿野院平藏、珐露珊、柯莱概率up\n单抽请按1, 十连抽请按2, 退出请按0:");
	int x,numru=1;scanf("%d",&x);
	while(x){
		if(x==1) printf("%s\n",aroll());
		else if(x==2){
			for(int i=1;i<=10;i++)
				printf("%s\n",aroll());
		}
		else printf("Error\n");
		printf("\n您当前已经有%d抽未出五星，%d抽未出四星\n",cnt5-1,cnt4-1);
		scanf("%d",&x);
		numru++;
	}
	return 0;
}


