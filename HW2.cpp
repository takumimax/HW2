#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef int* IntPtr;
IntPtr create2DArray(int rows,int columns);
void set(IntPtr arr,int rows,int columns,int desired_row,int desired_column,int val,ofstream& output);
int get(IntPtr arr,int rows,int columns,int desired_row,int desired_column)  ;

//branch in the github

int main(int argc, char* argv[])
{
    ifstream input(argv[1]);
    ofstream output(argv[2]);

    int rows,columns;
    string fl;
    getline(input,fl);
    istringstream first_line(fl);
    first_line>>rows>>columns;

    IntPtr Arr=create2DArray(rows,columns);

    string line;

    while(getline(input,line))
    {
        istringstream iss(line);
        string cmd;
        int var1,var2,val;

        iss>>cmd>>var1>>var2;

        if(iss>>val) //要set
        {
            set(Arr,rows,columns,var1,var2,val,output);
        }
        else //要get
        {
            int value=get(Arr,rows,columns,var1,var2);
            if(value==-1)
            {
                output<<"Error: Index out of bounds"<<endl;
                // output<<" desired_row="<<var1<<" "<<"row="<<rows<<endl;
                // output<<" desired_column="<<var2<<" "<<"columns="<<columns<<endl;
            }
            else
            {
                output<<value<<endl;
            }
        }
    }

    input.close();
    output.close();

    return 0;
}

IntPtr create2DArray(int rows,int columns)
//1d array當2d用
{
    IntPtr Arr=new int[rows*columns];
    for(int i=0;i<rows*columns;i++)
    {
        Arr[i]=0;
    }
    return Arr;
}

void set(IntPtr arr,int rows,int columns,int desired_row,int desired_column,int val,ofstream& output) 
//arr[desired_row][desired_column]=val
//rows,columns是arr的長寬
//if indices are out of bounds,print"Error: Index out of bounds"
{
    bool a=desired_row<0 || desired_row>(rows-1);
    bool b=desired_column<0 || desired_column>(columns-1);

    if(a||b)
    {
        output<<"Error: Index out of bounds"<<endl;
        // output<<" desired_row="<<desired_row<<" "<<"row="<<rows<<endl;
        // output<<" desired_column="<<desired_column<<" "<<"columns="<<columns<<endl;
        return;
    }

    else
    {
        arr[(desired_row)*(columns)+(desired_column)]=val;
        return;
    }
}

int get(IntPtr arr,int rows,int columns,int desired_row,int desired_column)  
//回傳arr[desired_row][desired_column]
//if indices are out of bounds,print"Error: Index out of bounds"
//if the value at the position has not been set, print 0.
{
    bool a=desired_row<0 || desired_row>(rows-1);
    bool b=desired_column<0 || desired_column>(columns-1);

    if(a||b)
    {
        return -1;
    }

    else
    {
        return arr[(desired_row)*(columns)+(desired_column)];
    }

    cout<<"uploaded to github."<<endl;


}