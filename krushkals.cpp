
void krushkalAlgo()
{

	Min=INT_MAX;
	while(i<n-1)
	{
		for(int j=0;j<e;j++)
		{
			if(included[j]!=0 && cost[2][j]<Min){
				u=cost[0][j];
				v=cost[1][j];
				k=j;
			}
		}

		if(find(u)!=find(v))
		{
			t[0][i]=u;
			t[1][i]=v;
			union(find(u),find(v));
			i++;
		}
		included[k]=1;
	}
}