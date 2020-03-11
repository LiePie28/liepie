#include <stdio.h> 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cMath> 
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

typedef struct hT{
	int id ;
	int number ;
}heaptree;

typedef struct cT {
    string schoolID  ;
    string schoolName ;
    string majorID ;
    string majorName;
    string course;
    string level;
    string studentNum;
    string teacherNum;
    int gNum ;
    string country;
    string type;

}collegeType;



void Swap(vector<hT> &h, int a, int b){
	hT A ;
	hT B ;
	A = h.at(a);
	B = h.at(b);
	h.erase(h.begin()+a) ;
	h.insert(h.begin()+a, B) ;
    B = h.at(b);
	h.erase(h.begin()+b) ;
	h.insert(h.begin()+b, A) ;
}


typedef enum{LEFT,RIGHT} whichChild;

typedef struct heapItem{
	int num ;
	int value ;
	heapItem *parent ;
	heapItem *left ;
	heapItem *right ; 
}heapNode;

class heapTree{

    vector<hT> item ; 

	
	void ReHeapDown( int root, int bottom){
		int child = 2 * root + 1 ;
		if ( child < bottom ){
			int right = child + 1 ;
			if((right < bottom ) && (item.at(right).number > item.at(child).number))
				child = right;
			if( item.at(root).number > item.at(child).number){
				Swap(item, root, child);
				ReHeapDown(child, bottom) ;
			}	
		}
	}
	
	public:

		void heapSort( int size ){
			int index ;
			for( index = (size - 1 )/ 2; index >= 0; index--)
				ReHeapDown(index, size) ;
			for( index = size - 1; index >= 1; index--){
				Swap(item, 0, index) ;
				ReHeapDown(0, index) ;
			}
		}

		void heapInsert( hT& newItem){
		
			item.push_back(newItem) ;
			int place = item.size() - 1 ;
			int parent = (place-1)/2;
			while((parent >= 0 ) && ( item.at(place).number < item.at(parent).number) ){
				Swap(item, place, parent) ;
				place = parent ;
				parent = (place-1)/2 ;
			}	 
		}
		
		void OutPutAll(){
			int i = 0 ;
		   /* while( i < item.size() && !item.empty() ) {
			    hT num = item.at(i) ;
				cout << "[" << num.id << "]" << " " << num.number << endl;
			    i++;
			}*/
			cout << "Root:	[" << item.front().id << "] " << item.front().number << endl ;
			cout << "Bottom:	[" << item.at(item.size() - 1 ).id << "] " << item.at(item.size() - 1 ).number << endl ;
			int n = log2(item.size()) ;
			n = pow(2, n) ;
			cout << "LeftMostBottom:	[" << item.at(n-1).id << "] " << item.at(n - 1 ).number << endl ;
		}
		
		void clear(){
			item.clear();
		}

};

bool readF(string fileName,vector<cT> &cSet){
    ifstream infile ;
    bool success = false;
    collegeType cl;
    fileName = "input" + fileName + ".txt";
    infile.open(fileName.c_str());
    if (!infile.is_open()) {
        cout << "\nFile " << fileName << " does not exist!!" << endl ;
    }
    else {

        string line;
        getline(infile,line);
        getline(infile,line);
        getline(infile,line);

        int firstLetter = 0;
        int pos = 0 ;
        string temp ;

        while ( getline(infile,line) ) {

            firstLetter = 0;
            pos = 0;

            pos = line.find('\t');
            cl.schoolID = line.substr(0,pos);
            line.erase(0,pos+1);

            pos = line.find('\t');
            cl.schoolName = line.substr(0,pos);
            line.erase(0,pos+1);

            pos = line.find('\t');
            cl.majorID = line.substr(0,pos);
            line.erase(0,pos+1);

            pos = line.find('\t');
            cl.majorName = line.substr(0,pos);
            line.erase(0,pos+1);

            pos = line.find('\t');
            cl.course = line.substr(0,pos);
            line.erase(0,pos+1);

            pos = line.find('\t');
            cl.level = line.substr(0,pos);
            line.erase(0,pos+1);

            pos = line.find('\t');
            cl.studentNum =  line.substr(0,pos);
            line.erase(0,pos+1);

            pos = line.find('\t');
            cl.teacherNum = line.substr(0,pos);
            line.erase(0,pos+1);

            pos = line.find('\t');
            temp = line.substr(0,pos);
            cl.gNum = atoi(temp.c_str());
            line.erase(0,pos+1);

            pos = line.find('\t');
            cl.country = line.substr(0,pos);
            line.erase(0,pos+1);

            pos = line.find('\t');
            cl.type = line.substr(0,pos);
            line.erase(0,pos+1);


            cSet.push_back(cl);

        }
        infile.close();
        success = true;
    }
    return success;

}

int main(int argc, char** argv) {
    int command = -1 ;
    int serial ;
    string fileName;
    vector<collegeType> cSet;
    heapTree HT;
    cT ct;
    hT ht ;
    bool check = false ;
    bool m2check = false ;

    while(command!=0){	
    	
		m2check = false ;
        cout << "**  University Graduate Information System **" << endl ;
        cout << "* 0. Quit                                   *" << endl ;
        cout << "* 1. Create min-Heap Trees         		 *" << endl ;
        cout << "* 2. Search by Number of Graduates          *" << endl ;
        cout << "*********************************************" << endl ;
        cout << "Input a command(0 ,1 ,2 ):"<< endl ;
        cin >> command ;
        if(command == 1  ){
            cout << "\nInput the file name():"<< endl ;
            cin >> fileName;
            if(check){
                cSet.clear();
                HT.clear() ;
                serial = 1;
                check = false ;
            }

            if(readF(fileName,cSet)){
                int i = 1 ;
                while (!cSet.empty()) {
                	ct = cSet.front() ;
                	ht.number = ct.gNum ;
                	ht.id = i ;
                    HT.heapInsert(ht) ;
                    cSet.erase(cSet.begin());
                    i++ ;
                }
                check = true;
                HT.OutPutAll() ;
            }
        }
        else if(command == 2){/*
            if(check){
                int number = 0 ;
                cout << "Input the number of graduates : " << endl;
                cin >> number;
                root1.showNum(number,m2check);
                if(!m2check)
                    cout << "There is no match!" << endl ;
                    
                cout << "Input the number of graduates : " << endl;
                cin >> number;
                root1.D(number, m2check) ; 
                cout << "{ Number of graduates } = " << root1.height(root1.GetRoot()) << endl;
                cout << "{ School Name } = " << root2.height(root2.GetRoot()) << endl;
            }
            else
                cout << "Please choose command 1 first!"<<endl;*/


        }

        else if( command != 0)
            cout << "Wrong command!Please enter again!"<<endl;
            
            serial = 1 ;
    }


    return 0 ;

}


