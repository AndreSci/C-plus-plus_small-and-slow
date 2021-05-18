#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <thread>

using namespace std;

/*
	input
	5
	add hack
	add hackerrank
	find ank
	find hac
	find hak

	output
	1
	2
	0
*/


/*  0 = "error"
	1 = "add"
	2 = "find" 
*/

int first_word(const string& line_in)
{
	//из условия можно допустить что во входном потоке первая буква будет означать нужное действие "add или find"
	if (line_in[0] == 'a')
	{
		return 1;
	}
	else if (line_in[0] == 'f')
	{
		return 2;
	}
	return 0;
}

bool find_word(const string& line_in, const string& word)
{
	int size_line = line_in.size();
	int size_word = word.size();

	if (size_line < size_word) return false;

	for (int i(0); i <= (size_line - size_word); i++)
	{
		if (line_in[i] == word[0])
		{
			int find_char_line = 0;
			for (int j(0); j < size_word; j++)
			{
				if (line_in[i + j] == word[j])
				{
					find_char_line++;
				}
			}
			if (find_char_line == size_word) return true;
		}
	}
	return false;
}


int multi(const string& it, const string& word)
{
	if (find_word(it, word))
	{
		return 1;
	}
	return 0;
}

int main()
{
	deque<string> Words_Base;
	int number = 0;

	cin >> number;

	for (int i(0); i <= number; i++)
	{
		string line;
		getline(cin, line);
		int nubmer_f = first_word(line);
		
		// 1 добавляем слово в массив
		// 2 начинаем искать совпадения
		if (nubmer_f == 1)
		{
			Words_Base.push_back({ line.begin() + 4, line.end() }); // вырезаем по шаблону из строки слово
		}
		else if (nubmer_f == 2)
		{
			int find = 0;

			// цикл поиска совпадений - одно совпадение на одно слово
			for (const auto& it : Words_Base)
			{
				find += multi(it, { line.begin() + 5, line.end() });
			}

			cout << find << endl;
		}
	}

	return 0;
}
