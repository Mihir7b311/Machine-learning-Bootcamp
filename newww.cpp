/*bubble*/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements to be stored in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "The sorted array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}



/* selection*/



#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int minSwapsToSort(vector<int> arr) {
    int n = arr.size();
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        while (arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
            swaps++;
        }
    }

    return swaps;
}

int main() {
    vector<int> arr;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter " << n << " elements to be stored in the array: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int swaps = minSwapsToSort(arr);
    cout<<swaps;
    cout << "Number of swaps required: " << swaps << endl;
    cout << "Elements to be swapped are: ";
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << "(" << arr[i] << ", " << i + 1 << ")";
            if (i < n - 1) {
                cout << " & ";
            }
        }
    }

    cout << endl;

    return 0;
}



/*insertion*/


#include <iostream>
using namespace std;

void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements to be stored in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertSort(arr, n);

    cout << "The sorted array in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}



/*merge*/

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int left_half[n1];
    int right_half[n2];

    for (int i = 0; i < n1; i++) {
        left_half[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        right_half[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_half[i] > right_half[j]) {
            arr[k] = left_half[i];
            i++;
        } else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements to be stored in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "The final sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}



/*quick*/


#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
const int mod=1e9+7;
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[],int low,int high) {
    int pivot=arr[high];
    int i=(low-1);

    for (int j=low;j<=high-1;j++) {
        if (arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quickSort(int arr[],int low,int high) {
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int binary_search(int arr[],int low,int high,int key){
    if(high>=low){
        int mid=low+(high-low)/2 ;

       if(key == arr[mid]){
          return mid;
       }
       if(key>arr[mid]){
          return binary_search(arr,mid+1,high,key);
       }
       if(key<arr[mid]){
          return binary_search(arr,low,mid-1,key);
       }
    }
    return -1;
}

int32_t main(){
   int n;
   cin>>n;
   int arr[n];
//    cout<<"Array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    // cout<<"Array after sorting:";
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    // cout<<'\n';
    // cout<<"Enter element to be searched: ";
    // int num;
    // cin>>num;
    // int result=binary_search(arr,0,n-1,num);
    // cout<<n-1-result;

    return 0;
}



/*heap*/



#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int,int>
#define MAX 1000
const int mod=1e9+7;
using namespace std;
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int maxnum(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
void swapnumbers(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void HEAPIFY(int *a,int p,int i)
{
    if(2*i+1==p-1)
    {
        int largest=maxnum(a[i],a[2*i+1]);
        if(largest==a[2*i+1])
        {
            swapnumbers(&a[i],&a[2*i+1]);
            HEAPIFY(a,p,2*i+1);
        }
    }
    else if(2*i+1<p-1)
    {
        int largest=maxnum(a[i],maxnum(a[2*i+1],a[2*i+2]));
        if(largest==a[2*i+1])
        {
            swapnumbers(&a[i],&a[2*i+1]);
            HEAPIFY(a,p,2*i+1);
        }
        else if(largest==a[2*i+2])
        {
            swapnumbers(&a[i],&a[2*i+2]);
            HEAPIFY(a,p,2*i+2);
        }
    }
}
void MAXHEAP(int *a,int p)
{
    for(int i=floor(p/2)-1;i>=0;i--)
    {
        HEAPIFY(a,p,i);
    }
}
void heapsort(int *a,int n)
{
    int temp=n;
    MAXHEAP(a,n);
    for(int i=n-1;i>=1;i--)
    {
        swapnumbers(a,a+i);
        temp-=1;
        HEAPIFY(a,temp,0);
    }
}
int32_t main(){
   int arr[MAX];
   int k=0,n=0;
   int x;
   char c;
   cout<<"Do You Want to Enter a Element(Y/N):";
   cin>>c;
   while(c=='Y'){
     cin>>x;
     arr[k]=x;
     k++;
     n++;
     cout<<"Do You Want to Enter a Element(Y/N):";
     cin>>c;
   }
   heapsort(arr,n);
   cout<<"array after heapsort\n";
   display(arr,n);

    return 0;
}


/*radix*/


#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp)
{

	int output[n];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{

	int m = getMax(arr, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 543, 986, 217, 765, 329 };
	int n = sizeof(arr) / sizeof(arr[0]);

	radixsort(arr, n);
	print(arr, n);
	return 0;
}


/*bucket sort*/


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n)
{

	vector<float> b[n];

	for (int i = 0; i < n; i++) {


		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}

	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

int main()
{
	float arr[]
		= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}

/*merge 3 arrays*/



#include <bits/stdc++.h>
#define int long long
using namespace std;

int n1,n2,n3;
int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void MergeThree(int arr[],int brr[],int crr[],int drr[]){
	int i,j,k;
    i=j=k=0;
    int cur=0;
    while (i<n1 && j<n2 && k<n3) {
        int m = min(min(arr[i],brr[j]),crr[k]);
 		drr[cur]=m;
 		cur++;
        if(m==arr[i]){
            i++;
        }
        else if(m==brr[j]){
            j++;
        }
        else{
            k++;
        }
    }

    while(i<n1 && j<n2){
        if(arr[i]<=brr[j]){
            drr[cur]=arr[i];
            i++;
            cur++;
        }
        else{
            drr[cur]=brr[j];
            cur++;
            j++;
        }
    }

    while(i<n1 && k<n3){
        if(arr[i]<=crr[k]) {
            drr[cur]=arr[i];
            cur++;
            i++;
        }
        else {
            drr[cur]=crr[k];
            cur++;
            k++;
        }
    }

    while (j<n2 && k<n3){
        if(brr[j]<=crr[k]) {
            drr[cur]=brr[j];
            cur++;
            j++;
        }
        else{
            drr[cur]=crr[k];
            cur++;
            k++;
        }
    }
    while(i<n1){
    	drr[cur]=arr[i];
    	cur++;
    	i++;
    }

    while (j<n2){
    	drr[cur]=brr[j];
    	cur++;
    	j++;
    }
    while(k<n3){
    	drr[cur]=crr[k];
    	cur++;
    	k++;
    }
}

int32_t main(){

    cout<<"Enter the size of first sorted array : ";
    cin>>n1;
    cout<<'\n';

    cout<<"Enter the size of second sorted array : ";
    cin>>n2;
    cout<<'\n';

    cout<<"Enter the size of third sorted array : ";
    cin>>n3;
    cout<<'\n';

    int arr[n1],brr[n2],crr[n3];

    for(int i=0;i<n1;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n2;i++){
        cin>>brr[i];
    }

    for(int i=0;i<n3;i++){
        cin>>crr[i];
    }

    int n=n1+n2+n3;
    int drr[n];

    MergeThree(arr,brr,crr,drr);
    cout<<"final array after merging the three arrays\n";
    display(drr,n);

    return 0;
}
