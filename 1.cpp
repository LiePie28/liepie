#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

// 10727228¤ý¬£¾^ 10727244 ³¯¨ÎªY 

typedef enum {
	Copy = -1,Right,Left,Up,Down
}Moves;
 
bool gYes = false ; 
int gN = 0;
void Swap( int &a, int &b ){
	int temp = 0 ;
	temp = a ;
	a = b ;
	b = temp ;
	
	
}

class CoXY {
	int x ;
	int y ;
	
	public:
		CoXY():y(0),x(0)
		{};

        CoXY(int py, int px)
        {
        	y = py ;
        	x = px ;
		}
	
		CoXY(const CoXY&pt): y(pt.y),x(pt.x)
		{} 
	
		void setXY( const int py, const int px )
		{
			y = py ;
			x = px ;
		}
		
		int getX() const
		{
			return x ;
		}
		
		int getY() const
		{
			return y ;
		}
		
		CoXY nextXY(Moves dir) const
		{ CoXY pt(y,x) ;
			
			switch (dir)
			{
				case Right:pt.x++ ;
				  break ;
				case Down:pt.y++;
				  break ;
				case Left:pt.x-- ;
				  break ;
				case Up:pt.y--;
				  break ;
				  
				default: ;    
			
			}
			
			return pt ;
		 } 
	    
	    bool match(const CoXY& pt ) const
	    {
	    	if((y == pt.y) && (x == pt.x))
	    	  return true ;
	    
	        return false ;
		}
		
		bool inRange ( const CoXY& maxLimit ) const
		{
			if ((y >= 0) && ( y < maxLimit.y) && (x >= 0) && ( x < maxLimit.x))
			  return true ;
			  
			return false ;  
		}
	
};

class Maze {

  char  **mArray;
  char  **cArray; 
  int xMax;
  int yMax; 
  int   *X;
  int   *Y;
  int   *GX;
  int   *GY;
  int    t; 
  int    k;
  

  public:
  	
 	int xTemp ;
  	int yTemp ;
    Maze(){
	}
	  
	void Copy(){
		CoXY  coMax(yMax,xMax);	
		int line = 0;
		cArray= new char*[coMax.getY() + 1] ;	
		while( line < coMax.getY() ){
			cArray[line] = new char[coMax.getX() + 1] ;
			line++;
		}
		
		for( int i = 0; i < coMax.getY()  ; i++ ) {
  			for( int j = 0 ; j < coMax.getX()  ; j++ )
  				cArray[i][j] = mArray[i][j] ;
		}	
		
	}  
	
  	void Switch(){
		CoXY  coMax(yMax,xMax);		
	    for( int i = 0; i < coMax.getY()  ; i++ ) {
  			for( int j = 0 ; j < coMax.getX()  ; j++ )
  				mArray[i][j] = cArray[i][j] ;
		}	
		
	}
  	
  	void Print(){
  		CoXY  coMax(yMax,xMax);	
  		cout << coMax.getX()<<" " << coMax.getY() ;
        cout << endl ;
  		for( int i = 0; i < coMax.getY()  ; i++ ) {
  			for( int j = 0 ; j < coMax.getX()  ; j++ )
  				cout<< mArray[i][j] ;
	
			cout << endl ;  
		  }
  	
	}
	void Direction( int y, int x ){
	    CoXY Run(0,0); 
	    CoXY coMax(yMax,xMax);	
	    CoXY Pt(0,0);
		Run.setXY(y,x);
		if( Run.getY() == 0 && Run.getX() == 0 ) 
		  mArray[Run.getY()][Run.getX()] = 'V' ;
		if( mArray[Run.getY()][Run.getX()] == 'G' && (xTemp != Run.getX() || yTemp != Run.getY()) ) {
		  gN-- ;
		  if ( gN == 0 )	
		    gYes = true ; 
		  xTemp = Run.getX();
		  yTemp = Run.getY();
	    }
	    if(!gYes && mArray[Run.getY()][Run.getX()] != 'G')  
	      mArray[Run.getY()][Run.getX()] = 'V' ; 
        Pt = Run.nextXY(Right);
	    if( Pt.inRange( coMax ) && ( mArray[Run.getY()][Run.getX()+ 1] == 'E' || mArray[Run.getY()][Run.getX()+ 1] == 'G' ) && !gYes ) 
	      Direction(Run.getY(),Run.getX()+1);
		Pt = Run.nextXY(Down);
	    if( Pt.inRange( coMax ) && ( mArray[Run.getY()+1][Run.getX()] == 'E' || mArray[Run.getY()+1][Run.getX()] == 'G') && !gYes) 
	      Direction(Run.getY()+1,Run.getX());
		Pt = Run.nextXY(Left);
		if( Pt.inRange( coMax ) && ( mArray[Run.getY()][Run.getX()-1] == 'E' || mArray[Run.getY()][Run.getX()-1] == 'G') && !gYes ) 
	      Direction(Run.getY(),Run.getX()-1);
		Pt = Run.nextXY(Up);
		if( Pt.inRange( coMax ) && ( mArray[Run.getY()-1][Run.getX()] == 'E' || mArray[Run.getY()-1][Run.getX()] == 'G') && !gYes ) 
	      Direction(Run.getY()-1,Run.getX());	  
	}
	void Roal( int y, int x ){
	    CoXY Run(0,0); 
	    CoXY coMax(yMax,xMax);
	    CoXY Pt(0,0) ;
		Run.setXY(y,x);
		if( Run.getY() == 0 && Run.getX() == 0 ) 
		  mArray[Run.getY()][Run.getX()] = 'V' ;
		if( mArray[Run.getY()][Run.getX()] == 'G' && (xTemp != Run.getX() || yTemp != Run.getY()) ) {
		  gN-- ;
		  if ( gN == 0 )	
		    gYes = true ; 
		  xTemp = Run.getX();
		  yTemp = Run.getY();
	      GY[k] = Run.getY() ;
	      GX[k] = Run.getX() ;
		  k++ ;
		  
	    }
	    if(!gYes && mArray[Run.getY()][Run.getX()] != 'G')  
	      mArray[Run.getY()][Run.getX()] = 'V' ; 
	   
	    Pt = Run.nextXY(Right);
	    if( Pt.inRange( coMax ) && ( mArray[Run.getY()][Run.getX()+ 1] == 'E' || mArray[Run.getY()][Run.getX()+ 1] == 'G' ) && !gYes ) {
	      Roal(Run.getY(),Run.getX()+1);	
	      if ( gYes ){
	      	Y[t] = Run.getY() ;
	      	X[t] = Run.getX() ;
	      	t++ ;
		  }
	        
		}
		Pt = Run.nextXY(Down);
	    if( Pt.inRange( coMax ) && ( mArray[Run.getY()+1][Run.getX()] == 'E' || mArray[Run.getY()+1][Run.getX()] == 'G') && !gYes) {
	      Roal(Run.getY()+1,Run.getX());
	      if ( gYes ){
	      	Y[t] = Run.getY() ;
	      	X[t] = Run.getX() ;
	      	t++ ;
		  }
		}
		Pt = Run.nextXY(Left);
		if( Pt.inRange( coMax ) && ( mArray[Run.getY()][Run.getX()-1] == 'E' || mArray[Run.getY()][Run.getX()-1] == 'G')  && !gYes) {
	      Roal(Run.getY(),Run.getX()-1);
	      if ( gYes ){
	      	Y[t] = Run.getY() ;
	      	X[t] = Run.getX() ;
	      	t++ ;
		  }
		}
		Pt = Run.nextXY(Up);
		if( Pt.inRange( coMax ) && ( mArray[Run.getY()-1][Run.getX()] == 'E' || mArray[Run.getY()-1][Run.getX()] == 'G') && !gYes) {
	      Roal(Run.getY()-1,Run.getX());
	      if ( gYes ){
	      	Y[t] = Run.getY() ;
	      	X[t] = Run.getX() ;
	      	t++ ;
		  }
		}
	  
	}
	
	void XYGoal(){
	    bool yes = true ;
		
		for( int i = 0 ; i < t; i++ ){
		    for(int j = 0 ; j < k ; j++ ) {
		    	if( Y[i] == GY[j] && X[i] == GX[j]) 
		    	  yes = false ;
		    	
			}
		    
		    if ( yes )
			  mArray[Y[i]][X[i]] = 'R' ;
		    
		    yes = true ;
		}
		
		Print();	
	}

	bool Load( string fileName )
	{
		FILE  *infile = NULL ;
		bool  success = false ;
	    CoXY  coMax(0,0);
		fileName = "input" + fileName + ".txt" ;
		infile = fopen(fileName.c_str(), "r") ;
		if ( infile == NULL )
	  	cout << endl << fileName << "does not exist!" << endl ;
		else {
			int arg1 = 0,arg2 = 0;
			fscanf(infile,"%d %d", &arg1, &arg2 ) ;
			coMax.setXY(arg2, arg1 ) ;
			xMax = arg1;
			yMax = arg2;
			xTemp = 0;
			yTemp = 0;
			int max = xMax*yMax;
			X = new int[max];
			Y = new int[max];
			GX = new int[gN+1];
			GY = new int[gN+1];
			t = 0 ;
			k = 0 ;
			if ((coMax.getX() > 0 ) && (coMax.getY() > 0 )){
				int line = 0;
				char *temp = new char[coMax.getX() + 1] ;
				mArray= new char*[coMax.getY() + 1] ;
				while(fscanf(infile, "%s", temp) != EOF ){
					mArray[line] = new char[coMax.getX() + 1] ;
					strcpy(mArray[line++],temp) ;
				}
				if(line == coMax.getY())
				  success = true ;
			} 
			
			fclose(infile);
		}  
	
		return success ;
	}
};

int main() {
	int i = 0 ;
	int L[i] ;
	int C[i] ;
	int N; 
	int command = 0 ;
	string fileName = "203" ;
	Maze maze ;
	// Modes mode = oneG ; // only one goal(default) 

    cin >> gN ;
    N = gN;

	if ( maze.Load(fileName) == true ) {
	  	maze.Print();
		maze.Copy();
		

		maze.Switch();
		maze.Direction(maze.yTemp,maze.xTemp);
		maze.Print();

		
        gYes = false ;
        gN = N;
		maze.xTemp = 0 ;
		maze.yTemp = 0 ;
		
		maze.Switch(); 
		maze.Roal(0,0);
		maze.Switch(); 
		maze.XYGoal();
	}
	
    else{
	
	
	}
	

	
}
