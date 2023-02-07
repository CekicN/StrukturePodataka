#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(64);
	ChainedScatterObject a("00012345608", "Nikola", 56);
	ChainedScatterObject b("00145455608", "Veljko", 56);
	ChainedScatterObject d("01014458608", "Stevan", 56);
	ChainedScatterObject c("00212545608", "dadw", 56);
	ChainedScatterObject e("02017825608", "dadw", 56);
	tablica.insert(a);
	tablica.insert(b);
	tablica.insert(c);
	tablica.insert(d);
	tablica.insert(e);
	tablica.print();

	char* z = new char[12];
	strcpy(z, "00145455608");
	std::cout << z;
	tablica.withdraw(z);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	tablica.print();
}