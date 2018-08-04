#include<stdio.h>
#define n 3

//    int M[n]={1,2,3,4,5};
//    int W[n]={1,2,3,4,5};
    
//    int PM[n][n]={{5,1,2,3,4},{1,2,3,4,5},{2,3,4,5,1},{1,2,3,4,5},{2,1,5,4,3}};
//    int PW[n][n]={{2,3,1,5,4},{2,1,4,3,5},{5,3,2,1,4},{4,3,2,1,5},{1,4,2,5,3}};
    
    int PM[n][n]={{1,2,3},{3,2,1},{1,3,2}};
    int PW[n][n]={{2,3,1},{3,1,2},{1,2,3}};
    
//    int Engaged[n]={0,0,0,0,0};//solution array ith man & jth woman Engaged=> A[i]=j
    int Engaged[n]={0,0,0};
    
//    int proposed_list[n][n]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};    
    int proposed_list[n][n]={{0,0,0},{0,0,0},{0,0,0}};
    
    int unengaged_men=n;
    
int get_index(int val, int Array[])
{
    int i=0;
    int trav;
    for(trav=0;trav<n;trav++)
        if(Engaged[trav]==val)
        return trav;
    return -1;
}

void propose(int ind_m, int ind_w)
{
//     printf("%d   %d ",ind_m,ind_w);
    int h=get_index(ind_w,Engaged);//if woman is enganged
    int h_prio=get_index(h,PW[ind_w]);//priority of husband 
    int man_prio=get_index(ind_m,PW[ind_w]);//priority of man
    int i=0;
    
    if(h==-1)//if woman is not engaged
    {
        Engaged[ind_m]=ind_w;//engage man and woman
        unengaged_men--;//as one got enganged
    }
    else//check priority of man over husband
    {
        if(man_prio>h_prio)//man is preffered over husband
        Engaged[ind_m]=ind_w;
    }        
    
    for(i=0;i<n;i++)
    if(proposed_list[ind_m][i]==0)
    proposed_list[ind_m][i]=ind_w;
}

int main()
{
    int i=0;
    int ind_m=0;
    int ind_w=0;
    
    while(unengaged_men!=0 && ind_m<n)
    {
        while(ind_w<n)
        {
            if(Engaged[ind_m]==0)
            {
                propose(ind_m,ind_w);
                ind_w++;
            }
            else
            continue;
        }
        ind_m++;
    }
    
    for(i=0;i<n;i++)
    printf("%d : %d \n",i+1,Engaged[i]);//i+1 man no i+1 in ith 
}

