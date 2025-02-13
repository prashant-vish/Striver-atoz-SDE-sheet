class Solution
{
    public:
    void insert(int arr[], int i)
    {
            int x=arr[i];
            int j=i-1;
            while(j>=0&&x <arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=x;
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++){
           insert(arr,i);
        }
    }
};