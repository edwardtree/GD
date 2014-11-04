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
	if (*a>*b) return -1;
	if (*a==*b) return 0;
	return 1;
}



int ***record_elements_in_edgesets; //the sets in the paper.  x:which set ; y: element in the set ; z: which round

int **which_two_vertice_connected_edge;


/*----------count edge lengh-----------*/


double lengh[N]={0.0},initial_lengh[N]={0.0};


double edgelengh( int vertex_a_x, int vertex_a_y, int vertex_b_x,int vertex_b_y){
	
	double num;

	num=(vertex_a_x-vertex_b_x)*(vertex_a_x-vertex_b_x)+(vertex_a_y-vertex_b_y)*(vertex_a_y-vertex_b_y);
	num=pow(num,0.5);
	printf("num : %f\n",num);

	return num;
} 

/*----------Edge Crossing-----------*/

/*
int EdgeCrossing(int Q1[],int Q2[]){
	int Q1_lengh,Q2_lengh,i=0,j=0;
	while(Q1[i]!=0){
		Q1_lengh++;i++;
	}

	while(Q2[j]!=0){
		Q2_lengh++;j++;
	}

	

}
*/


/*----------TEST BundlingGain-----------*/

//int BundlingGain(int n)



int m,n;


int main(){
	int x,y,i,j;
	int graph[N][N]={0};
	
/*----------input graph-----------*/

	//1.vertices
	printf("total vertices number : ");
	scanf("%d",&n); //n = total number of vertices
		
	
	for( i = 0 ; i < n ; i++ ){
	  printf("coordinates_x , coordinates_y  : ");
	  scanf("%d %d",&node_arr[i].x,&node_arr[i].y);
	}

	printf("---------------------------\n");
	for( i = 0 ; i < n; i++ )
	    printf("%d %d\n", node_arr[i].x, node_arr[i].y );

	//1.Edges
	
	for( i = 0 ; i < n ; i++ )
	  for( j = 0 ; j < n ; j++ ){
	    graph[i][j]=0; 
	    if(i==j)graph[i][j]=1;
	}

	printf("total edges number :");        
	scanf("%d",&m);

	which_two_vertice_connected_edge = (int** )malloc(sizeof(int*)*m);
	for( i = 0 ; i < m ; i++ )
	which_two_vertice_connected_edge[i]  = (int*)malloc(sizeof(int)*2);

	


	for( i = 0 ; i < m ; i++ ){
		printf("edge %d ( vertex x , vertex y ) = ",i);
		scanf("%d %d",&x,&y);

		j=0;
		which_two_vertice_connected_edge[i][j] = x;
		j++;
		which_two_vertice_connected_edge[i][j] = y;
		
		lengh[i]=initial_lengh[i]=edgelengh(node_arr[x].x,node_arr[x].y,node_arr[y].x,node_arr[y].y);
		printf("lengh : %f\n",lengh[i]);
		graph[x][y]=graph[y][x] = 1;	

	}

	//printf(" total vertice are %d\n", n );
	for( i = 0 ; i < n ; i++ )
	  for( j = 0 ; j < n ; j++ ){
	    //printf("%d" ,graph[i][j]);
	    if(j == n-1) printf("\n");
	}


	qsort(lengh,m,sizeof(double),cmp);//edge lengh max to min

	
	for( i = 0; i<m ; i++ ) printf("lengh[%d] =%f\n",i ,lengh[i]);
	
	/*----------record after sort edge lengh max to min coordinates-----------*/

	int after_sort_two_vertices_connected_edge[m][2];

	i=0,j=0;
	int number=0,num=0,count=0;
	double tmp;
	while(i!=m){
	  tmp=lengh[i];
	  
	  while(1){
	  	
	  	number++;i++;
		if(lengh[i]!=lengh[i-1]) break;
	  	printf("%d\n",i);
	  }
	  
	  while(1){
	  	
	  	if(initial_lengh[j]==tmp ){

		after_sort_two_vertices_connected_edge[num][0] = which_two_vertice_connected_edge[j][0];
		after_sort_two_vertices_connected_edge[num][1] = which_two_vertice_connected_edge[j][1];
	  	
		//printf("which_two_vertice_connected_edge[%d][0]=%d\nwhich_two_vertice_connected_edge[%d][1]=%d\n",j,which_two_vertice_connected_edge[num][0],j,which_two_vertice_connected_edge[num][1]);
		//printf("after_sort_vertices_coordinates[%d][0]=%d\nafter_sort_vertices_coordinates[%d][1]=%d\n",num,after_sort_vertices_coordinates[num][0],num,after_sort_vertices_coordinates[num][1]);
		num++;
		count++;
		}
		if(number==count)break;
		
		j++;
	  }
	  j=0;number=0;count=0;
	}
	
	
           for( i = 0 ; i < m ; i++ ){
             printf("aftersort_coordinates_x , aftersort_coordinates_y  : ");
             printf("%d %d\n",after_sort_two_vertices_connected_edge[i][0],after_sort_two_vertices_connected_edge[i][1]);
	     }


	










/*----------Function AgglomerativeBundling-----------*/
	
/*
	int set_arr[n][n];

	for( i = 0 ; i < n ; i++ ){
	  for( j = 0 ; j < n ; j++ ){
	  	if(i == j ) set_arr[i][j]=1;
		else set_arr[i][j]=0;
	  }
	 }


	----------sets in the paper-----------

	record_elements_in_edgesets=(int***)malloc(a*sizeof(int**));

	for( i = 0 ; i < n; i++)
	    record_elements_in_edgesets[i] = (int**)malloc(sizeof(int*)*n);
	    
	for(i = 0 ; i < n ; i++ )
	  for(j = 0 ; j < n ; j++ )
	    record_elements_in_edgesets[i][j]=(int*)malloc(sizeof(int)*n);
	         

	for( i = 0 ; i < 10 ; i++ )
	  for( j = 0 ; j < 10 ; j++ )
	    for( k = 0 ; k < 10 ; k++ ){
	       arr[i][j][k]=m;
	       m++;
	     }


*/








	//count_setarr_i_equal_1_is_n= n-1;

	//while(count_setarr_i_equal_1_is_n){
		
	//}










/*----------minimize vertice to bundling vertice-----------*/









/*----------bundling vertice to bundling vertice-----------*/


/*----------minimize bundling vertice to vertice -----------*/


	
  return 0;


}
