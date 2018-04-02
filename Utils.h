#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Utils 
{
public:
	static std::string read_file(const char* path) 
	{
		std::ifstream file;
		file.open(path);
		
		std::string line, file_contents;

		if (file.is_open()) 
		{
			while (std::getline(file, line)) 
			{
				file_contents.append(line + "\n");
			}
			file.close();
		}

		return file_contents;
	}
};