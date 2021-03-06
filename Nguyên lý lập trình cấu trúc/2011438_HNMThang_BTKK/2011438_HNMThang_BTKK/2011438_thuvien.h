
#define MAX 7

typedef int maTran[MAX][MAX];

int NhapThang();
int NhapNam();
void KhoiTao(maTran lich);
int TimThuTrongTuan(int m, int y);
int NamNhuan(int y);
int SoNgayTrongThang(int m, int y);
void TaoLich(maTran lich, int m, int y);
void XuatLich_CN(maTran lich, int m);
void XuatLich_T2(maTran lich, int m);
void XuatTieuDe(int m, int y);

int NhapThang()
{
	int kq;
	do
	{
		cout << "\nNhap 1 thang trong nam (1..12) : ";
		cin >> kq;
	} while (kq < 1 || kq > 12);
	return kq;
}

int NhapNam()
{
	int kq;
	do
	{
		cout << "\nNhap 1 nam bat ky bat dau tu 0 : ";
		cin >> kq;
	} while (kq < 0);
	return kq;
}

// Khoi tao tat ca phan tu cua ma tran ban dau bang 0
void KhoiTao(maTran lich)
{
	int i, j;
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			lich[i][j] = 0;
}

int TimThuTrongTuan(int m, int y)
{
	int t, x, k, w;
	t = y - (14 - m) / 12;
	x = t + t / 4 - t / 100 + t / 400;
	k = m + 12 * ((14 - m) / 12) - 2;
	w = (1 + x + (31 * k) / 12) % 7;
	return w;
}

int NamNhuan(int y)
{
	int kq = 0;

	if (kq % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		kq = 1;

	return kq;
}

int SoNgayTrongThang(int m, int y)
{
	int soNgay;

	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		soNgay = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		soNgay = 30;
		break;
	case 2:
		if (NamNhuan(y))
			soNgay = 29;
		else
			soNgay = 28;
		break;
	}
	return soNgay;
}

void TaoLich(maTran lich, int m, int y)
{
	int thu, dem, soNgay, i, j;

	thu = TimThuTrongTuan(m, y);
	soNgay = SoNgayTrongThang(m, y);
	KhoiTao(lich);

	dem = 1;

	// Hang dau tien cua lich
	for (j = thu; j < MAX; j++)
		lich[0][j] = dem++;

	// Cac hang tiep theo
	for (i = 1; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (dem > soNgay)
				break;
			else
				lich[i][j] = dem;
			dem++;
		}
	}
}

void XuatLich_CN(maTran lich, int m)
{
	int i, j;

	setiosflags(ios::left);

	cout << endl;
	cout << setw(7) << "Sun"
		<< setw(7) << "Mon"
		<< setw(7) << "Tue"
		<< setw(7) << "Wed"
		<< setw(7) << "Thu"
		<< setw(7) << "Fri"
		<< setw(7) << "Sat";
	cout << endl;

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (lich[i][j] != 0)
				cout << setw(7) << lich[i][j];
			else
				cout << setw(7) << " ";
		}
		cout << endl;
	}
}

void XuatLich_T2(maTran lich, int m)
{
	int i, j;

	setiosflags(ios::left);

	cout << endl;
	cout << setw(7) << "Mon"
		<< setw(7) << "Tue"
		<< setw(7) << "Wed"
		<< setw(7) << "Thu"
		<< setw(7) << "Fri"
		<< setw(7) << "Sat"
		<< setw(7) << "Sun";
	cout << endl;

	if (lich[0][0] == 0)
		for (i = 0; i < MAX - 1; i++)
			lich[i][0] = lich[i + 1][0];

	for (i = 0; i < MAX; i++)
	{
		for (j = 1; j < MAX; j++)
		{
			if (lich[i][j] != 0)
				cout << setw(7) << lich[i][j];
			else
				cout << setw(7) << " ";
		}

		// Chu nhat luon xuat hien o cot cuoi cung
		if (lich[i][0] != 0)
			cout << setw(7) << lich[i][0];
		else
			cout << setw(7) << " ";

		cout << endl;
	}
}

void XuatTieuDe(int m, int y)
{
	cout << endl;
	cout << "    ";
	switch (m)
	{
	case 1:
		cout << "January";
		break;
	case 2:
		cout << "February";
		break;
	case 3:
		cout << "March";
		break;
	case 4:
		cout << "April";
		break;
	case 5:
		cout << "May";
		break;
	case 6:
		cout << "June";
		break;
	case 7:
		cout << "July";
		break;
	case 8:
		cout << "August";
		break;
	case 9:
		cout << "September";
		break;
	case 10:
		cout << "October";
		break;
	case 11:
		cout << "November";
		break;
	case 12:
		cout << "December";
		break;
	}
	cout << " " << y << endl;
}