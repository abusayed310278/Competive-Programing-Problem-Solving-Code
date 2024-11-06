#include<bits/stdc++.h>
using namespace std;

int R,C;

void printMat(char input[][50]){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<input[i][j];
		}
		cout<<endl;
	}
}

//W,N,E,S
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

//ch is the character to be replaced
//color is the character to be replace

void floodFill(char mat[][50],int i,int j,char ch,char color){
	//base case -matrix bounds
	if(i<0 || j<0 || i>=R || j>=C)return;

	//figure boundary condition
	if(mat[i][j]!=ch)return;
	
	//recursive call
	mat[i][j]=color;
	for(int k=0;k<4;k++){
		floodFill(mat,i+dx[k],j+dy[k],ch,color);
	}
}

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	cin>>R>>C;
	char input[15][50];
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>input[i][j];
		}
	}
	//printMat(input);

	floodFill(input,8,13,'.','r');
	//floodFill(input,0,0,'.','!');
	cout<<"output apple: "<<endl;
	printMat(input);

	return 0;
}

/*

15 30
..............................
.............#####............
.............#...#............
.....#########...########.....
....###.....######......###...
...##....................##...
..##......................#...
..##.....................##...
..###...................##....
....###................###....
......###............###......
........###........###........
..........##########..........
..............................
...........A.P.P.L.E..........


*/