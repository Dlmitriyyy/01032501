#include <iostream>
#include <fstream>
#include <string>
#include <locale>
using namespace std;

void countWords(wchar_t& input)
{
	wifstream read_file("text.txt");

	wstring word;
	int count = 0;

	while (isdigit(input) || input == '!' || input == '@' || input == '#' || input == '№' || input == '%' || input == '^' || input == '&' || input == '*' || input == '(' || input == ')' || input == '-' || input == '+' || input == '=' || input == ';' || input == ':' || input == '?' || input == '_')
	{
		cout << "Помилка. Треба ввести букву!" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введіть букву українського алфавіту: ";
		wcin >> input;
	}

	while (read_file >> word)
	{
		if (!word.empty() && word[0] == input)
		{
			count++;
		}
	}
	if (count == 0)
	{
		wcout << endl << "У данному файлі немає слів на букву " << input << endl;
	}
	else
	{
		wcout << endl << "У данному файлі " << count << " слів на букву " << input << endl;
	}
	read_file.close();
}

void displayText()
{
	ifstream read_file("text.txt");
	string text;
	
	cout << endl << "Текст якій міститься у файлі: " << endl << endl;
	while (getline(read_file, text))
	{
		cout << text;
	}
	cout << endl << endl;
	read_file.close();
}

int main()
{
	system("chcp 1251 > nul");
	wchar_t  input;

	cout << "Ця програма підраховує скількі разів у тексті файлу який включений в програму стрічаються слова які починаються на буквувведеною користувачем." << endl << endl;
	cout << "Введіть букву українського алфавіту: ";
	wcin >> input;

	countWords(input);
	displayText();
}