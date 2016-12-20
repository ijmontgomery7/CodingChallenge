/*
Ian Montgomery
Coding Challenge
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Cell{ // outline the cell types
	
	
	public:
		void setData(string input){
				
		}
		int getData(vector<vector<Cell>> grid);
};

class StringCell: public Cell{ //stores strings
	
	public:
		void setData(string input){
			data = input;
		}
		
		string getData(vector<vector<Cell>> grid){
			return data;
		}

	private:
		 string data;
};

class IntCell: public Cell{ //stores ints
	
	public:
		void setData(string input){
			istringstream(input) >> data;
		}

		int getData(vector<vector<Cell>> grid){
			return data;
		}
		
	private:
		int data; 
};

class EquationCell: public Cell{ //store equations in form of =(1,1)*(2,2)

	public:
		void setData(string input){
			// needs to parse
		}

		int getData(vector<vector<Cell>> grid){
			// grid[1x][1y] operation grid [2x][2y]
		}
	private:
		string operation;
		int oneX;
		int oney;
		int twox;
		int twoy;
};

int main() {

	string file;
	cout << "enter file to open" << endl;
	getline(cin, file); // take in file name
	vector<vector<Cell>> grid;
	ifstream reader(file);
	string line;
	
	


	while (getline(reader, line)){
		string word;
		stringstream parser(line);
		int count;
		vector<Cell> row;
		while(getline(parser, word, ',')){
			if(word.at(0) == '='){ //equations start with = sign 
				EquationCell newCell;
				newCell.setData(word);
				row.push_back(newCell);
			}else if(isdigit(word.at(0))){
				IntCell newCell;
				newCell.setData(word);
				row.push_back(newCell);
			}else{
				StringCell newCell;
				newCell.setData(word);
				row.push_back(newCell);
			
			}
			grid.push_back(row);
		}
		

	}

	for(int x = 0; x < grid.size(); x++){
		string printLn = "";
		for(int y = 0; y < grid[x].size(); y++){
			//print grid data for [x][y] by calling operation .getdata(grid)
		}
		cout << printLn << endl;
	}
	

	

	return 0;
}
