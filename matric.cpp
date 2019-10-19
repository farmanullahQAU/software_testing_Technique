#include<iostream>
#include<iomanip>
using namespace std;
const int N=2;
bool oracle(int[N][N],int [N][N],int);
void cal_inverse(int[N][N]);
void display(int [N][N]);

int main()
{
    
    int matric[N][N];
cout<<"ENTER SQUARE MATRIC "<<endl;
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    {

        cin>>matric[i][j];
    }
}
cal_inverse(matric); 
}

void cal_inverse(int A_mat[N][N]) //inverse function
{
int determent=1;
int bc=1;
int ad=1;
int A_invrs[N][N];
for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
   	 {
	A_invrs[i][j]=A_mat[i][j];
	if((i==0&&j==1)||(i==1&&j==0))
	{
	bc=bc*A_invrs[i][j];
	}
	else
	ad=ad*A_invrs[i][j];  //multiply index 00,11 to calculate ad
    	}
}
determent=(ad-bc);
cout<<setw(10)<<"----------> Determent: "<<determent<<endl;
if(determent==0)
{
cout<<"Inverse cannot exist: "<<endl;
}
else
{
	for(int i=0;i<N;i++)
    		for(int j=0;j<N;j++)
    		{
			if((i==0&&j==1)||(i==1&&j==0))
			{
				A_invrs[i][j]=-A_invrs[i][j];  //change position of 1st and last element
			}
else{
}
		}
		
int temp=A_invrs[0][0];
A_invrs[0][0]=A_invrs[1][1];
A_invrs[1][1]=temp;
cout<<setw(10)<<"----------> A Inverse "<<endl;
display(A_invrs); 
cout<<endl;
if(oracle(A_mat,A_invrs,determent))
	{
cout<<"VERDICT-----------------> PASS"<<endl;
	}
else
cout<<"VERDICT-----------------> FAIL"<<endl;
}
}



bool oracle(int A[N][N],int A_i[N][N],int Deter)  //calculate observe output
{
int I[N][N]={{1,0},
{0,1}};
int i, j, k; 
int obsrv_mat[N][N];

    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
	  obsrv_mat[i][j] = 0; 
         	for (k = 0; k < N; k++) 
                obsrv_mat[i][j] =obsrv_mat[i][j]+ A[i][k] * A_i[k][j]; 
		if(i==j)
		{
		obsrv_mat[i][j]=obsrv_mat[i][j]/Deter;
		}
        } 
    } 
cout<<" "<<"Identity"<<endl;
display(obsrv_mat);
cout<<endl;
for(int i=0;i<N;i++)
{
for(int j=0;j<N;j++)
if(obsrv_mat[i][j]!=I[i][j])
return false;
}
return true;
}


void display(int m[N][N])
{
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    {

        cout<<m[i][j]<<" ";
    }
    cout<<endl;
}
}
