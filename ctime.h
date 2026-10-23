#ifndef CTIME_H

#define CTIME_H

class CTime
{
		int Sec, Min, H;

	public:
		void print();
		CTime();
		CTime(int, int, int Sec = 0);
		void setTime(int, int, int Sec = 0);
};

#endif
