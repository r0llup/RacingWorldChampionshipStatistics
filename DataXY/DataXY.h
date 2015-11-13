#ifndef DATAXY_H
#define DATAXY_H
#include <iostream>

class DataXY
{
	friend std::ostream & operator<<(std::ostream &s, DataXY &d);
	friend std::istream & operator>>(std::istream &s, DataXY &d);
	private:
		int valeurX;
		int valeurY;
		int effectifX;
		int effectifY;
	public:
		DataXY(void);
		DataXY(int xi, int nxi, int yi, int nyi);
		DataXY(const DataXY &d);
		~DataXY(void) { };
		inline const int getValeurX(void) const { return valeurX; }
		inline const int getValeurY(void) const { return valeurY; }
		inline const int getEffectifX(void) const { return effectifX; }
		inline const int getEffectifY(void) const { return effectifY; }
		inline void setValeurX(const int vx) { valeurX = vx; }
		inline void setValeurY(const int vy) { valeurY = vy; }
		inline void setEffectifX(const int ex) { effectifX = ex; }
		inline void setEffectifY(const int ey) { effectifY = ey; }
		DataXY & operator=(const DataXY &d);
		bool operator<(const DataXY &d);
		bool operator<=(const DataXY &d);
		bool operator==(const DataXY &d);
		bool operator>(const DataXY &d);
		bool operator>=(const DataXY &d);
};

#endif
