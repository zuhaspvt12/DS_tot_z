#include <stdio.h>
//heapify function:
void heapify(int tree[],int i,int n)
{
    int largest=i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (tree[largest]<tree[l] && n>l)
       largest = l;
    if (tree[largest]<tree[r] && n>r)
       largest = r;
    if (largest!=i)
    {
        //swap:
        int temp=tree[largest];
        tree[largest]=tree[i];
        tree[i]=temp;
          heapify(tree,largest,n);
    }

}
//main fucntion:
int main()
{
    int n;
    printf("Enter the number of elements there in your tree: ");
    scanf("%d",&n);
    int tree[n];
    //printf("\n");
    for (int j = 0; j < n; j++)
    {
        printf("Enter: ");
        scanf("%d",&tree[j]);
    }
    //start:
    for (int i = (n/2)-1 ; i >= 0; i--)
    {
        heapify(tree,i,n);
    }
    for (int  j= n-1 ; j >=0 ; j--)
    {
        int t = tree[j];
        tree[j]=tree[0];
        tree[0]=t;
        heapify(tree,0,j); 
    }
    

    //printing the sorted array:
    for (int j = 0; j <n; j++)
    {
        printf("%d ",tree[j]);
    }
}
