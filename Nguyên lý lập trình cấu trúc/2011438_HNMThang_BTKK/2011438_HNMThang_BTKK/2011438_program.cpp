///////////////////
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

#include "2011438_thuvien.h"


int main()
{
	int thang, nam;
	maTran lich;

	thang = NhapThang();
	nam = NhapNam();

	system("cls");

	TaoLich(lich, thang, nam);

	XuatTieuDe(thang, nam);
	XuatLich_CN(lich, thang);

	XuatTieuDe(thang, nam);
	XuatLich_T2(lich, thang);

	return 0;
}
