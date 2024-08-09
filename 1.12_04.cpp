#include<iostream>
#include<string>
#include<fstream>

int main()
{
	std::fstream up("in.txt");
	
	if(!(up.is_open()))
	{
		std::cout << "Not Open";
	}

	int rows;
	int cols;
	int number;
	
	up >> rows;
	up >> cols;

	std::cout << rows << " ";
	std::cout << cols << std::endl;

	

	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++) 
	{
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			up >> arr[i][j];
		}
	}
	up.close();

	for (int i = 0; i < rows; ++i)
	{
		for (int j = cols-1; j >= 0; --j)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr [i];
	}

	delete[] arr;

	return 0;
}