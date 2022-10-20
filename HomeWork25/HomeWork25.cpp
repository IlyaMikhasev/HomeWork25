#include <iostream>
#include <string>
bool palindrome(std::string str);
int search_char(std::string str);
std::string ret_str(std::string str, char ch);
int main() {
	setlocale(LC_ALL, "Russian");
	//Задача 1 Дана строка str.Пользователь вводит символ sym.Программа создаёт новую строку, которая состоит из
	//	символа sym.Длина новой строки равна количеству	совпадений введённого символа в изначальной строке str
	
	std::string str1 = "Hello World";
	char sym;
	std::cout << "Задача 1.\nСуществующая строка: " << str1 << '\n'<<"Введите символ из этой строки -> ";
	std::cin >> sym;// if enter 'l' to new_str = "lll"
	std::string new_str;
	for (int i = 0; i < str1.length(); i++)
		if (sym == str1[i])
			new_str += sym;
	std::cout << "Полученная строка: " << new_str << "\n\n";
	
	//Задача 2 Создайте функцию, которая принимает слово и возвращает true, если оно является палиндромом.В
	//	противном случае возвращается false.Функция должна быть нерегистрозависимой
	
	std::string word;
	std::cout << "Задача 2\nВведите слово-> ";
	std::cin.ignore();
	getline(std::cin, word);
	if (palindrome(word))
		std::cout << "Слово является полиндромом!\n\n";
	else
		std::cout << "Слово не является полиндромом!\n\n";
		
	//Задача 3 Создайте функцию, которая принимает строку.Функция считает все пробелы, точки, запятые,
	//восклицательные и вопросительные знаки, которые есть в переданной строке и возвращает их общее количество.
	
	std::cout << "Задача 3\nВведите строку -> ";
	std::string str3;
	getline(std::cin, str3);
	std::cout << "В введеном предложении " << search_char(str3) << " символа \'.\';\',\';\' \';\'!\';\'?\'\n\n";
	
	//Задача 4
	std::string str4;
	char ch4;
	std::cout << "Задача 4.\nВведите строку ->";
	getline(std::cin, str4);
	std::cout << "Введите символ ->";
	std::cin >> ch4;
	std::cout << ret_str(str4, ch4);

	return 0;
}
// проверка слов на полиндром
bool palindrome(std::string str) {
	int point = 0;
	for (int i = 0; i < str.length() / 2; i++)
		if (tolower(str[i]) == tolower(str[str.length() - i - 1]))//tolower - does not work on ru language 
			point++;
	if (point == str.length() / 2)
		return true;
	return false;
}
//Ищет в введеном предложении ',';'.';'!';'?';' '
int search_char(std::string str) {
	char ch[5]{ ' ','!','?','.',',' };
	int point = 0;
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < 5; j++)
			if (str[i] == ch[j])
				point++;
	return point;
}
//Возвращает подстроку с последнего вхождения введеного символа
std::string ret_str(std::string str, char ch) {
	if (str.rfind(ch) <str.length())
		return str.substr(str.rfind(ch));
	return str = "";
}