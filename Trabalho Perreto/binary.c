#include"binary.h"

treeNode* Find_Min(treeNode *node){
        if(node==NULL)	return NULL;
        if(node->left)	return Find_Min(node->left);
        else			return node;
}

treeNode* Find_Max(treeNode *node){
        if(node==NULL)	return NULL;
        if(node->right)	Find_Max(node->right);
        else			return node;
}

treeNode * add(treeNode *node,int data){
        if(node==NULL){
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp->data = data;
                temp->left = temp->right = NULL;
                return temp;
        }

        if(data >(node->data))			node->right = add(node->right,data);
        else if(data < (node->data))	node->left = add(node->left,data);
        return node;

}

treeNode * rm(treeNode *node, int data){
        treeNode *temp;
        if(node==NULL)					printf("Elemento %d Não encontrado para Remoção!\n",data);
        else if(data < node->data)		node->left = rm(node->left, data);
        else if(data > node->data)		node->right = rm(node->right, data);
        else
        {
        	if(node->right && node->left)
                {
                        temp = Find_Min(node->right);
                        node -> data = temp->data; 
                        node -> right = rm(node->right,temp->data);
                }
                else
                {
                        temp = node;
                        if(node->left == NULL)				node = node->right;
                        else if(node->right == NULL)		node = node->left;
                        free(temp); 
                }
        }
		//printf("Elemento %d Removido!\n",data);
        return node;

}

info find(treeNode *node, int data){
		info information;
		information.index = 0;
		information.node_left = 0;
		information.node_right = 0;
		int call_left=0,call_right=0;
        if(node==NULL)				return information;
		while(node!=NULL){
			if (data < node->data){
				if(call_left == 0){
					call_left = 1; call_right = 0;
					information.index++;
				}
				snprintf(information.data[information.index],30,"- %d nó(s) à esquerda ",information.node_left+1);
				node = node->left;
				information.node_left++;
			}	
			else if (data > node->data){
				if(call_right == 0){
					call_left = 0; call_right = 1;
					information.index++;
				}
				snprintf(information.data[information.index],30,"- %d nó(s) à direita ",information.node_right+1);
				information.node_left = 0;
				node = node->right;
				information.node_right++;
			}
         	else{
				information.element = node->data;
				return information;
			}
   		}
		return information;
}

void in_order(treeNode *node){
        if(node==NULL)	return;
        in_order(node->left);
        printf("%d ",node->data);
        in_order(node->right);
}

void pre_order(treeNode *node){
        if(node==NULL) return;
        printf("%d ",node->data);
        pre_order(node->left);
        pre_order(node->right);
}

void post_order(treeNode *node){
        if(node==NULL) return;
        post_order(node->left);
        post_order(node->right);
        printf("%d ",node->data);
}

