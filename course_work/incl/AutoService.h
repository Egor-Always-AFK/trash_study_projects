#ifndef AUTOSERVICE_HPP
# define AUTOSERVICE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

// Номер автомобиля, дата, Услуга автосервиса, норма часов. 
// Показывать перечень услуг автосервиса, произведенных в определенную дату. 
// Рассчитывать стоимость оказанных услуг как суммы нормо-часов, умноженных на стоимость нормо-часа.

class AutoService
{
	private:
		int _dataDay;
		int _dataMonth;
		int _dataYear;
		std::string _autoNumber; 
		int _normHour;
	public:
		AutoService();
		AutoService(int dataDay, int dataMonth, int dataYear, std::string autoNumber, int normHour);
		AutoService(const AutoService &cpy);
		~AutoService();
		AutoService operator=(const AutoService &cpy);

		void setDataDay(int dataDay);
		void setDataMonth(int dataMonth);
		void setDataYear(int dataYear);
		void setAutoNumber(std::string autoNumber);
		void setNormHour(int normHour);

		int getDataDay();
		int getDataMonth();
		int getDataYear();
		std::string getNumber();
		int getNormHour();
		friend std::ostream &operator<<(std::ostream &out, AutoService &src);
};

#endif