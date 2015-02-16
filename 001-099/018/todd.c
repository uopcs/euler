#include <stdio.h>

struct node_st 
{
	int value;
	struct node_st *left;
	struct node_st *right;
};

struct node_st** buildLayer(int layerStart, int layerEnd, struct node_st** nodes)
{
	int i;
	int curr = layerEnd;
	for (i = layerStart; i < layerEnd; i++)
	{
		nodes[i]->left = nodes[curr++];
		nodes[i]->right = nodes[curr];
	}
	return nodes;
}

struct node_st* buildTestTree()
{
	int data[10] = {3, 
					7, 4, 
					2, 4, 6, 
					8, 5, 9, 3};
	
	struct node_st **nodes;
	nodes = malloc(10 * sizeof(struct node_st *));

	int i;
	for (i = 0; i < 10; i++)
	{
		nodes[i] = malloc(sizeof(struct node_st));
		nodes[i]->value = data[i];
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("%i - %p\n", nodes[i]->value, nodes[i]);
	}
	
	// build structure of test tree
	int layer = 0;
	int tri = 1;
	while (layer+tri < 10)
	{
		nodes = buildLayer(layer, layer+tri, nodes);
		layer += tri;
		tri++;
	
	}
	
	// leaves
	for (i = layer; i < layer+tri; i++)
	{
		nodes[i]->left = NULL;
		nodes[i]->right = NULL;
	}
	
	return nodes[0];

	
}



struct node_st* buildTree()
{
	int data[120] =   {75, // fug
					95, 64, 
					17, 47, 82,
					18, 35, 87, 10, 
					20, 4, 82, 47, 65, 
					19, 1, 23, 75, 3, 34, 
					88, 2, 77, 73, 7, 63, 67, 
					99, 65, 4, 28, 6, 16, 70, 92, 
					41, 41, 26, 56, 83, 40, 80, 70, 33, 
					41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 
					53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 
					70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 
					91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 
					63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 
					4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23};
	
	struct node_st** nodes;
	nodes = malloc(120 * sizeof(struct node_st *));

	int i;
	for (i = 0; i < 120; i++)
	{
		nodes[i] = malloc(sizeof(struct node_st));
		nodes[i]->value = data[i];
	}
	
	for (i = 0; i < 120; i++)
	{
		printf("%i - %p\n", nodes[i]->value, nodes[i]);
	}
	
	// build structure of test tree
	int layer = 0;
	int tri = 1;
	while (layer+tri < 120)
	{
		nodes = buildLayer(layer, layer+tri, nodes);
		layer += tri;
		tri++;
	}
	
	// leaves
	for (i = layer; i < layer+tri; i++)
	{
		nodes[i]->left = NULL;
		nodes[i]->right = NULL;
	}
	
	return nodes[0];
}

int getMaxPath(struct node_st* root, int sum, int* max_p)
{
	
	sum += root->value;
	int nmax = sum; 
	if (sum > *max_p)
	{
		*max_p = nmax;
	}
	if (root->left != NULL)
	{
		getMaxPath(root->left, sum, max_p);
	}
	if (root->right != NULL)
	{
		getMaxPath(root->right, sum, max_p);
	}
	return *max_p;
	
}

int main(int argc, char **argv)
{
	// project euler q18
	
	struct node_st* root = buildTree();
	int max = 0;
	int* max_p;
	max_p = &max;
	printf("%i\n", getMaxPath(root, 0, max_p));
	
	
	
	return 0;
}
