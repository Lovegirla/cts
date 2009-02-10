#include <stdio.h>
#include "ds.h"
#include "connect.h"

BOX frame	; 
SOURCE source  ;
SINK sink	; 
WIRELIB wirelib;
BUFLIB	buflib ; 
VDDLIB	vddlib ; 
int SlewLimit; 
int CapLimit ; 
BLOCKAGE blockage;

int num_node ; 
int num_buffer; 
int num_wire ; 
int num_sinknode ; 
int num_total_nodes ; 


int main(int argc, char * argv[]){
	FILE *ifp; 
	FILE *ofp ; 
	BUF_NODE ** OBUF;  
	DME_TREE_NODE * OT ;
	DME_TREE_NODE ** OTmap ; 
	if(argc > 3 || argc < 2){
		printf("error: command inputfile\n");
		exit(1);
	}
	ifp = fopen( argv[1], "r") ; 
	ofp = fopen(argv[2], "w") ; 
	printf("%d\n",InputFile(ifp));

	constructg(&blockage);
	outputg();
	printf("\n---------------------------------------------------------\n");
	output_dirs();

	// input two points
	NODE s,t;
	s.x = 0.0; s.y = 40.0;
	t.x = 55.0;t.y = 40.0;
	add2pt(s,t,&blockage);

	// (blockage.num - 2) denotes the index of first point
	dijkstra(&blockage,g_size-2);

	printf("s to t: %lf\n",g[g_size-2][g_size-1]);

	free_all();
	return 0;
}
