#include <stdio.h>
#include <string.h>
void merge(char * str, int l,int m,int h)//merges two sorted portions of the string in sorted order
{
    int n=h-l+1,i=0,p1=l,p2=m+1;char temp[n];
    while (p1<=m && p2<=h)//copying elements in sorted order in temp array
    {
        if (str[p1]<str[p2])
            temp[i++]=str[p1++];
        else
            temp[i++]=str[p2++];
    }
    while (p1<=m)
            temp[i++]=str[p1++];
    while (p2<=h)
            temp[i++]=str[p2++];
    for (int i=0;i<n;i++)//copying the sorted array to orignal string
        str[l+i]=temp[i];
}
void merge_sort(char * str,int l, int h)//sorting function
{
    if (l==h)return;// if only one element in string return , since single element is always sorted
    int m=(l+h)/2;
    merge_sort(str,l,m);
    merge_sort(str,m+1,h);
    merge(str,l,m,h);
}
int main()//driver function
{
    char str [][12]={"polynomial","test case"};//test cases
    merge_sort(str[0],0,9);
    merge_sort(str[1],0,8);
    printf ("\nSorted strings\n%s\n%s\n",str[0],str[1]);
}
