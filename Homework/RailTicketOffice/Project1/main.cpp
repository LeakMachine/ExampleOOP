#include "class.h"

int main() {

	RailTicketOffice rto;

	Date datenig;
	FullName fn;

	fn.name = "A";
	fn.surname = "B";
	fn.patronymic = "C";

	datenig.day = 1;
	datenig.month = 1;
	datenig.year = 2020;

	rto.orderAccept(datenig, 69, 1, fn, 0, "Govno", "Mocha");

	std::string* asshole;

	asshole = rto.orderFormCheque(0);

	std::cout << asshole[0] << std::endl;

	return 0;
}