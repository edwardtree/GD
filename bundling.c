#include <stdio.h>
#include <stdlib.h>

#define N 10 

typedef struct {
	int x;
	int y;
} vertex;


int main(){
	int x,y,i,j,n;
	int graph[N][N];

/*----------input graph-----------*/

	scanf("%d",&n);
	vertex node_arr[n];
	for( i = 0 ; i < N ; i++ )
	  for( j = 0 ; j < N ; j++ )
	    graph[i][j]=0;
	
	for( i = 0 ; i < n ; i++ ){
	  scanf("%d %d",&x,&y);
	  node_arr[i].x = x,node_arr[i].y = y;
	}
	printf("---------------------------");
	for( i = 0 ; i < n; i++ )
	    printf("%d %d\n", node_arr[i].x, node_arr[i].y );
	    //if( j == N-1)printf("\n");
	
/*
	for( i = 0 ; i < N ; i++ )
	  for( j = 0 ; j < N ; j++ ){
	    printf("%d", graph[i][j]);
	    if( j == N-1)printf("\n");
	}
*/






/*----------minimize vertice to bundling vertice-----------*/





/*----------bundling vertice to bundling vertice-----------*/


/*----------minimize bundling vertice to vertice -----------*/


	
  return 0


}
