class solution
{
public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high)
        {
            int p=partition(arr,low,high);
            // quickSort(arr,low,p);           // for hoares partition
            quickSort(arr,low,p-1);           // for lamuto partition
            
            quickSort(arr,p+1,high);
        }
    }
    
    public:
    int partition (int arr[], int l, int h)
    {
       // Your code here
       // for lamuto
       
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
    
    // for hoares partition
    // int p=arr[low],i=low-1,j=high+1;
    // while(true)
    // {
    //     do{
    //         i++;
    //     }while(arr[i]<p);
        
    //     do{
    //         j--;
    //     }while(arr[j]>p);
    //     if(i>=j)return j;
    //     swap(arr[i],arr[j]);
    // }
       
    }
};
