#include "Menu.h"

int main() {
	system("chcp 1251 > nul");
	while(1) {
		system("COLOR F1");
		int choice = borderInputNums(cin, "1 - Admin\n2 - User\n\n0 - exit\n\nChoice: ", 0, 2);
		if (!choice) break;
		switch (choice) {
		case 1:
			if(!Menu().Admin()) return 0;
			break;
		case 2:
			if(!Menu().User()) return 0;
			break;
		}
	}
	return 0;
}