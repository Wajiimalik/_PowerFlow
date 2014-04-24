#include "DataBase.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
	Co_Ordinates::Co_Ordinates() : _x(0), _y(0) {}

	void Co_Ordinates :: SetX(int x)	 { _x = x; }
	void Co_Ordinates :: SetY(int y)	{ _y = y; }

	int Co_Ordinates :: GetX()	 { return _x; }
	int Co_Ordinates :: GetY()	{ return _y; }

	bool Co_Ordinates :: operator == (Co_Ordinates c)
	{
		if (_x == c._x && _y == c._y)
		{
			return true;
		}
		return false;
	}


	///=====================================================================///

	void DataBase::SetLevelNo(int level)
	{
		_levelNo = level;
	}

	void DataBase :: AssigningValuesToFactoryHouses(int a,char c)
	{
		ObjectsType[a] = c;	
	}
	void DataBase :: AssigningValuesToConnectionType(int a,char c)
	{
		connectionType[a] = c;
	}
	void DataBase :: AssigningValuesToSolvedPuzzle(int a,char c)
	{
		solvedPuzzle[a] = c; 
	}
	void DataBase :: AssigningValuesToUnSolvedPuzzle(int a,char c)
	{
		unSolvedPuzzle[a] = c;

	}

	void  DataBase:: LoadDataBase()
	{
		ifstream in;
		switch(_levelNo)
		{
		case 1:
		in.open("FILES\\level_1.txt");
		break;

		case 2:
		in.open("FILES\\level_2.txt");
		break;

		case 3:
		in.open("FILES\\level_3.txt");
		break;

		case 4:
		in.open("FILES\\level_4.txt");
		break;

		case 5:
		in.open("FILES\\level_5.txt");
		break;


		default:
		cout<<"incorrect level no "<<endl;
		break;
		}
					
		if (!in)
		{
			cout << "file cannot be open " << endl;
		}
			
		char c;
	
		if (!in)
		{
			cout << "error in opening ";
		}
			
		else 
		{
			int a=0;	
			while(a<25)
			{	
				in.get(c);
					
				if(c=='\n')
					continue;
				
				else
				{		
					solvedPuzzle[a] = c-48; 				
					in.get(c);
					
					unSolvedPuzzle[a] = c-48;
					in.get(c);
								
					switch (c)
					{
					case 'H':
						ObjectsType[a] = 'H';	
						break;

					case 'F':
						ObjectsType[a] = 'F';	
						break;

					case 'C':
						ObjectsType[a] = 'C';
						break;

					default:
						cout << "sorry11" << endl;
						break;
					}


					in.get(c);
							
					switch (c)
					{
					case 'L':
						connectionType[a] = 'L';	
						break;

					case 'T':
						connectionType[a] = 'T';
						break;

					case 'S':
						connectionType[a] = 'S';
						break;

					case 'M':
						connectionType[a] = 'M';
						break;

					default:
						cout << "sorry" << endl;
						break;
					}

					a++;	
				}	
			}	
		}	
	
				
	in.close();
	}

	char  DataBase :: GetObjectType(int index)
	{
		return ObjectsType[index];
	}

	char  DataBase :: GetConnectionType(int index)
	{
		return connectionType[index];
	}

	int  DataBase :: GetSolvedPuzzle(int index)
	{
		return solvedPuzzle[index];
	}

	int  DataBase :: GetUnSolvedPuzzle(int index)
	{
		
		return unSolvedPuzzle[index];
	}
