#include<iostream>
#define N 4
using namespace std;

//int PM[N][N]={{1,2,3,4},{1,3,2,4},{4,2,3,1},{2,3,1,4}};
//int PW[N][N]={{3,2,1,4},{1,2,3,4},{3,1,4,2},{2,1,3,4}};
//int unengagedMale[N]={0,0,0,0};//if male engages make their value 1
//int womanEngangedWith[N]={-1,-1,-1,-1};//if woman enganges, make their value index of husband
//int unengaged_male=N;
//int morePreferace(int PW[N][N], int w, int m1, int m2)

int mMorePreferred(int PW[N][N], int w, int h, int m)
{
	for (int i = 0; i < N; i++)//to return highest preffered
    {
        if (PW[w][i] == h)
            return -1;
        if (PW[w][i] == m)
            return 1;
    }
}

int main()
{
	int PM[N][N]={{2,1,3,4},{1,3,2,4},{4,2,1,3},{2,3,1,4}};
	int PW[N][N]={{3,2,1,4},{2,1,3,4},{3,1,4,2},{2,1,3,4}};

	int unengagedMale[N]={0,0,0,0};//if male engages make their value 1
	int womanEngagedWith[N]={-1,-1,-1,-1};//if woman enganges, make their value index of husband

	int unengaged_male=N;
	
//	printf("Initially number of unengaged male was %d",unengaged_male);
//	int w=4;
//	printf("Initially %d(W) engaged with %d(M)",w,womanEngagedWith[w-1]);
	
	while(unengaged_male!=0)
	{
		int m;//m is the index of the man
		for(m=0;m<N;m++)//traverse through the array of the 
		if (unengagedMale[m]==0) break;//m is the first unaengaegd male
		
//		printf("Number of unengaged male was %d",unengaged_male);
		
		for(int i=0; i<N && unengagedMale[m]==0 ; i++)//propose all the woman until engaged
		{
			int w= PM[m][i];
			if(womanEngagedWith[w-1]==-1)//unengaged woman?
			{
				womanEngagedWith[w-1]=m;//engage with her
				//make man enganged
				unengagedMale[m]=1;
				unengaged_male--;
				printf("\n%d(M) got engaged with %d(W)\n",m+1,w);				
			}
			else//if woman is engaged
			{
				int h;//husband or previously engaged with
				h=womanEngagedWith[w-1];
				if(mMorePreferred(PW,w,h,m)==1)//is m more preffered than husban?
				{
					womanEngagedWith[w-1]=m;//woman got engaged with m
					unengagedMale[h]=0;
						printf("\n%d(M) got unengaged with %d(W) &",h+1,w);
					unengagedMale[m]=1;
						printf("\n%d(M) got engaged with %d(W)\n",m+1,w);
//						if(m==0 && w==4) printf("\n%d\n",h+1);
				}
				//no. of unenganged man does not change here
			}
		}
	}	
}
