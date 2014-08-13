#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define N 100 

typedef struct {
	int x;
	int y;
} vertex;

vertex node_arr[N];


int cmp(const void *p, const void *q){
	double *a= (double*)p;
	double *b= (double*)q;
	if (*a<*b) return -1;
	if (*a==*b) return 0;
	return 1;
}




double lengh[N]={0.0};

double edgelengh( int vertex_a_x, int vertex_a_y, int vertex_b_x,int vertex_b_y){
	
	double num;

	num=(vertex_a_x-vertex_b_x)*(vertex_a_x-vertex_b_x)+(vertex_a_y-vertex_b_y)*(vertex_a_y-vertex_b_y);
	num=pow(num,0.5);
	printf("num : %f\n",num);

	return num;
} 


int main(){
	int x,y,i,j,n,m;
	int graph[N][N]={0};
	
/*----------input graph-----------*/

	//vertices
	printf("total vertices number : ");
	scanf("%d",&n); //n = total number of vertices
	
	for( i = 0 ; i < n ; i++ ){
	  printf("coordinates_x , coordinates_y  : ");
	  scanf("%d %d",&node_arr[i].x,&node_arr[i].y);
	}

	printf("---------------------------\n");
	for( i = 0 ; i < n; i++ )
	    printf("%d %d\n", node_arr[i].x, node_arr[i].y );

	//Edges
	
	for( i = 0 ; i < n ; i++ )
	  for( j = 0 ; j < n ; j++ ){
	    graph[i][j]=0; 
	    if(i==j)graph[i][j]=1;
	}

	printf("total edges number :");        
	scanf("%d",&m);

	for( i = 0 ; i < m ; i++ ){
		printf("edge %d ( vertex x , vertex y ) = ",i);
		scanf("%d %d",&x,&y);
		lengh[i]=edgelengh(node_arr[x].x,node_arr[x].y,node_arr[y].x,node_arr[y].y);
		printf("lengh : %f\n",lengh[i]);
		graph[x][y]=graph[y][x] = 1;	

	}

	//printf(" total vertice are %d\n", n );
	for( i = 0 ; i < n ; i++ )
	  for( j = 0 ; j < n ; j++ ){
	    //printf("%d" ,graph[i][j]);
	    if(j == n-1) printf("\n");
	}


	qsort(lengh,m,sizeof(double),cmp);

	
	for( i = 0; i<m ; i++ ) printf("lengh[%d] =%f\n",i ,lengh[i]);
	

/*----------minimize vertice to bundling vertice-----------*/









/*----------bundling vertice to bundling vertice-----------*/


/*----------minimize bundling vertice to vertice -----------*/


	
  return 0;


}
