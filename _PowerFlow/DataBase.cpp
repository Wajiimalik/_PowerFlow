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
		cout<<a<<"-"<<c<<endl;
	}
	void DataBase :: AssigningValuesToConnectionType(int a,char c)
	{
		connectionType[a] = c;
		cout<<a<<"-"<<c<<endl;
	}
	void DataBase :: AssigningValuesToSolvedPuzzle(int a,char c)
	{
		solvedPuzzle[a] = c; 
		cout<<a<<"-"<<c<<endl;
	}
	void DataBase :: AssigningValuesToUnSolvedPuzzle(int a,char c)
	{
		unSolvedPuzzle[a] = c;
		cout<<a<<"-"<<c<<endl;

	}

	void DataBase :: AssigningValuesToFactoryHouses()
	{
		ObjectsType[16] = 'F'; ObjectsType[0] = 'H'; ObjectsType[3] = 'H'; ObjectsType[4] = 'H';
		ObjectsType[8] = 'H'; ObjectsType[17] = 'H'; ObjectsType[18] = 'H'; ObjectsType[20] = 'H';

		for (int i = 0; i < 25; i++)
		{
			if (ObjectsType[i] != 'H' && ObjectsType[i] != 'F')
			{
				ObjectsType[i] = 'C';
			}
		}
	}

	//2nd array telling the connection type
	//method for test program //in end this part would be removed
	void  DataBase :: AssigningValuesToConnectionType()
	{
		connectionType[0] = 'M';
		connectionType[3] = 'M'; connectionType[4] = 'M'; connectionType[8] = 'M';
		connectionType[16] = 'M'; connectionType[17] = 'M'; connectionType[18] = 'M'; connectionType[20] = 'M';

		connectionType[1] = 'L'; connectionType[15] = 'L'; connectionType[24] = 'L';

		connectionType[2] = 'S'; connectionType[5] = 'S'; connectionType[7] = 'S'; connectionType[9] = 'S';
		connectionType[12] = 'S'; connectionType[19] = 'S'; connectionType[21] = 'S'; connectionType[23] = 'S';


		connectionType[6] = 'T'; connectionType[10] = 'T'; connectionType[11] = 'T';
		connectionType[13] = 'T'; connectionType[14] = 'T'; connectionType[22] = 'T';
	}

	//3rd array and the main array. UnSolved puzzle would be compared by this at every move
	//method for test program //in end this part would be removed
	void  DataBase :: AssigningValuesToSolvedPuzzle()
	{
		solvedPuzzle[0] = 3; solvedPuzzle[1] = 2; solvedPuzzle[2] = 1; solvedPuzzle[3] = 4; solvedPuzzle[4] = 3;

		solvedPuzzle[5] = 2; solvedPuzzle[6] = 4; solvedPuzzle[7] = 1; solvedPuzzle[8] = 4; solvedPuzzle[9] = 2;

		solvedPuzzle[10] = 4; solvedPuzzle[11] = 3; solvedPuzzle[12] = 1; solvedPuzzle[13] = 1; solvedPuzzle[14] = 2;

		solvedPuzzle[15] = 1; solvedPuzzle[16] = 4; solvedPuzzle[17] = 3; solvedPuzzle[18] = 1; solvedPuzzle[19] = 2;

		solvedPuzzle[20] = 2; solvedPuzzle[21] = 1; solvedPuzzle[22] = 3; solvedPuzzle[23] = 1; solvedPuzzle[24] = 4;

	}

	//4rth array having values of unsolved puzzle that would changed by user to make it solve
	//method for test program //in end this part would be removed
	void  DataBase :: AssigningValuesToUnSolvedPuzzle()
	{
		unSolvedPuzzle[0] = 4; unSolvedPuzzle[1] = 1; unSolvedPuzzle[2] = 1; unSolvedPuzzle[3] = 2; unSolvedPuzzle[4] = 1;

		unSolvedPuzzle[5] = 1; unSolvedPuzzle[6] = 1; unSolvedPuzzle[7] = 2; unSolvedPuzzle[8] = 2; unSolvedPuzzle[9] = 1;

		unSolvedPuzzle[10] = 1; unSolvedPuzzle[11] = 4; unSolvedPuzzle[12] = 1; unSolvedPuzzle[13] = 3; unSolvedPuzzle[14] = 4;

		unSolvedPuzzle[15] = 2; unSolvedPuzzle[16] = 3; unSolvedPuzzle[17] = 1; unSolvedPuzzle[18] = 4; unSolvedPuzzle[19] = 2;

		unSolvedPuzzle[20] = 4; unSolvedPuzzle[21] = 1; unSolvedPuzzle[22] = 2; unSolvedPuzzle[23] = 1; unSolvedPuzzle[24] = 2;

	}


	void  DataBase:: LoadDataBase()
	{


		/*/
		this->AssigningValuesToConnectionType();
		this->AssigningValuesToFactoryHouses();
		this->AssigningValuesToSolvedPuzzle();
		this->AssigningValuesToUnSolvedPuzzle();
		//assigns value from filing to these 4 params //(set method)
		*/

		/*
		ifstream in;
		switch(level)
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

		default:
		cout<<"incorrect level no "<<endl;
		break;
		}
		*/

		ifstream in;
		
				in.open("FILES\\level_3.txt");
					
				if(!in)
					cout<<"file cannot be open "<<endl;
			
			//string a1[5];
			char c;
	
			if(!in)
				cout<<"error in opening ";
	
			else 
				{int a=0;
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
			//cout<<"got H"<<endl;
			break;

		case 'F':
		ObjectsType[a] = 'F';	
		//	cout<<"got F"<<endl;
		break;

		case 'C':
			ObjectsType[a] = 'C';
				//cout<<"got C"<<endl;
			break;


		default:
			cout << "sorry11" << endl;

			break;
		}


								in.get(c);
								
									//void AssigningValuesToConnectionType(int a,char c);
							
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
//cout<<"================"<<endl;
//cout<<"a"<<a<<endl;
//							cout<<solvedPuzzle[a] <<endl;
//							cout<<unSolvedPuzzle[a]<<endl;
//							cout<<ObjectsType[a]<<endl;
//							cout<<connectionType[a]<<endl;
//							cout<<"================"<<endl;
						
a++;
							
					    	}
								
						}
					}	
	
				
	//in.close();
	
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
