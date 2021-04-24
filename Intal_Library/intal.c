#include <stdio.h>
#include <stdlib.h>
#include "intal.h"
#include <string.h>
#define MAX 3000

static int partition(char **arr, int low, int high)
{
    char *pivot = (char *) calloc(MAX, sizeof(char));

    strcpy(pivot, arr[low]);
    int temp1=low-1;
    int temp2=high+1;
    while(1)
    {
        temp2--;
        while (intal_compare(arr[temp2], pivot) == 1)
        {
            temp2--;
        }
        temp1++;
        while (intal_compare(arr[temp1], pivot) == -1)
        {
            temp1++;
        }
        if(temp1<temp2)
        {            
            char *temp = arr[temp1];
            arr[temp1] = arr[temp2];
            arr[temp2] = temp;
        }
        else
        {
            free(pivot);
            return temp2;
        }
        
    }

}

static void quicksort(char **arr, int low, int high)
{
    if(low<high)
    {
        int partitionind=partition(arr,low,high);
        quicksort(arr,low,partitionind);
        quicksort(arr, partitionind + 1, high);
    }
    else
    {
        return;
    }
    
}

static char *reverse(char *string) {

    for (int i = 0, j = strlen(string) - 1; i < j; i++, j--) {
        string[i] ^= string[j];
        string[j] ^= string[i];
        string[i] ^= string[j];
    }

    return string;
}


static char *remove_leading_zeroes(char *string1)
{
    int length=strlen(string1);
    int i;
    for(i=0;i<length && string1[i]=='0';i++);
    for(int k=0;k<=length-i;k++)
    {
        string1[k]=string1[i+k];
    }
    if(i==length)
    {
        string1[0]='0';
        string1[1]='\0';
    }
    return string1;
}


char* intal_add(const char* intal1, const char* intal2)
{

    const char *greaterstring;
    const char *smallerstring;
    if(intal_compare(intal1,intal2)<0)
    {
        greaterstring=intal2;
        smallerstring=intal1;
    }
    else
    {
        greaterstring=intal1;
        smallerstring=intal2;
    }
    int length1=strlen(greaterstring);
    int length2=strlen(smallerstring);
    int carry=0;
    int sum=0;
    int resultlength=0;
    char * result=(char*)calloc(MAX,sizeof(char));
    int i=length2-1;
    while(i>=0)
    {
        sum = ((greaterstring[i+(length1-length2)]-'0')+(smallerstring[i]-'0')+carry);
        result[resultlength++]=(sum%10)+'0';
        carry=sum/10;
        i--;
    }
    for(int j=length1-length2-1;j>=0;j--)
    {
        sum=((greaterstring[j]-'0')+carry);
        result[resultlength++]=(sum%10)+'0';
        carry=sum/10;
    }
    if(carry)
    {
        result[resultlength++]=carry+'0';
    }
    char *newstr=reverse(result);
    return newstr;
}


int intal_compare(const char* intal1, const char* intal2)
{
    if(strlen(intal1)>strlen(intal2))
    {
        return 1;
    } 
    else if(strlen(intal2)>strlen(intal1))
    {
        return -1;
    }

    else
    {
        for(int i=0;i<strlen(intal1);i++)
        {
            if(intal1[i]>intal2[i])
            {
                return 1;
            }
            if(intal2[i]>intal1[i])
            {
                return -1;
            }
        }
    }
    return 0;
}

char* intal_diff(const char* intal1, const char* intal2)
{
    const char *greaterstring;
    const char *smallerstring;
    if(intal_compare(intal1,intal2)<0)
    {
        greaterstring=intal2;
        smallerstring=intal1;
    }
    else
    {
        greaterstring=intal1;
        smallerstring=intal2;
    }
    int length1=strlen(greaterstring);
    int length2=strlen(smallerstring);
    int carry=0;
    int difference=0;
    int resultlength=0;
    char * result=(char*)calloc(MAX,sizeof(char));
    int i=length2-1;
    while(i>=0)
    {        
        difference = ((greaterstring[i+(length1-length2)]-'0')-(smallerstring[i]-'0')-carry);
        if(difference<0)
        {
            difference=difference+10;
            carry=1;
        }
        else
        {
            carry=0;
        }
        result[resultlength++]=difference+'0';
        i--;
    }
    for(int j=length1-length2-1;j>=0;j--)
    {
        difference=((greaterstring[j]-'0')-carry);
        if(difference<0)
        {
            difference=difference+10;
            carry=1;
        }
        else
        {
            carry=0;
        }
        result[resultlength++]=difference+'0';
    }
    char *newstr=reverse(result);
    return remove_leading_zeroes(newstr);
}

char* intal_multiply(const char* intal1, const char* intal2)
{
    const char *greaterstring;
    const char *smallerstring;
    if(intal_compare(intal1,intal2)<0)
    {
        greaterstring=intal2;
        smallerstring=intal1;
    }
    else
    {
        greaterstring=intal1;
        smallerstring=intal2;
    }
    int length1=strlen(greaterstring);
    int length2=strlen(smallerstring);
    int numofzeros=length2-1;
    char *result = (char *) calloc(MAX, sizeof(int));
    int carry=0;
    int prod=0;
    result[0] = '0';
    result[1] = '\0';
    for(int i=0;i<length2;i++)
    {
        char *partialresult = (char *) calloc(MAX, sizeof(int));
        int s=0;
        for(s=0;s<numofzeros;s++)
        {
            partialresult[s]='0';
        }
        numofzeros--;
        carry=0;
        for(int j=length1-1;j>=0;j--)
        {
            prod = (smallerstring[i] - '0') * (greaterstring[j] - '0') + carry;

            carry=prod/10;

            partialresult[s++]=(prod%10)+'0';
        }
        partialresult[s++]=carry+'0';
        char *temp=reverse(partialresult);
        char *temp1=result;
        result = intal_add(result, partialresult);
        free(temp);
        free(temp1);

    }
    
    return remove_leading_zeroes(result);
}


char* intal_pow(const char* intal1, unsigned int n)
{
    char *result = (char *) calloc(MAX, sizeof(char));
    strcpy(result, "1");
    if(n==0)
    {
        return result;
    }
    if(intal_compare(intal1,"0")==0)
    {
        strcpy(result, "0");
        return result;
    }
    char *tempvar = (char *) calloc(MAX, sizeof(char));
    strcpy(tempvar, intal1);
    while(n>0)
    {
        if(n%2==1)
        {   
            char *temp = result;
            result=intal_multiply(result,tempvar);
            free(temp);
        }
        if(n>1)
	    {
        	char *temp=tempvar;
        	tempvar=intal_multiply(tempvar,tempvar);
        	free(temp);
	    }	
	n=n >> 1;
    }
    free(tempvar);
return result;
}

char* intal_fibonacci(unsigned int n)
{
    char *before = (char *) calloc(MAX, sizeof(char));
    char *present = (char *) calloc(MAX, sizeof(char));
    strcpy(before, "0");
    strcpy(present, "1");
    if(n==0)
    {
        return before;
    }
    if(n==1)
    {
        return present;
    }
    int i=1;
    while(i<n)
    {
        char *temp=intal_add(before,present);
        strcpy(before,present);
        strcpy(present,temp);
        free(temp);
        i++;
    }
    free(before);
    return present;

}

char* intal_factorial(unsigned int n)
{
    char *result = (char *) calloc(MAX, sizeof(char));
    strcpy(result, "1");
    char *temp = (char *) calloc(MAX, sizeof(char));
    strcpy(temp, "2");
    if(n==0 || n==1)
    {
        return result;
    }
    int i=2;
    while(i<=n)
    {
        char *tempvar1=result;
        char *tempvar2=temp;
        result=intal_multiply(result,temp);
        temp=intal_add(temp,"1");
        free(tempvar1);
        free(tempvar2);
        i++;
    }
free(temp);
return result;
}

int intal_max(char **arr, int n)
{
    char *max = (char *) calloc(MAX, sizeof(char));
    strcpy(max, arr[0]);
    int index=0;
    int i=1;
    while(i<n)
    {
        if(intal_compare(arr[i],max)>0)
        {
            strcpy(max,arr[i]);
            index=i;
        }
        i++;
    }
    return index;
}

int intal_min(char **arr, int n)
{
    char *min = (char *) calloc(MAX, sizeof(char));
    strcpy(min, arr[0]);
    int index=0;
    int i=1;
    while(i<n)
    {
        if(intal_compare(arr[i],min)<0)
        {
            strcpy(min,arr[i]);
            index=i;
        }
        i++;
    }
    return index;
}

int intal_search(char **arr, int n, const char* key)
{
    for (int i = 0; i < n; i++)
    {
        if (intal_compare(arr[i], key) == 0)
        {    
            return i;
        }
    }
    return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
    int first=0;
    int last=n-1;
    int mid;
    int index=-1;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(intal_compare(arr[mid],key)==0)
        {
            index=mid;
            last=mid-1;
        }
        else if(intal_compare(key,arr[mid])==1)
        {
            first=mid+1;
        }
        else
        {
            last=mid-1;
        }
        
    }
    return index;
}





void intal_sort(char **arr, int n)
{
    quicksort(arr,0,n-1);
}

char* coin_row_problem(char **arr, int n)
{
    char *prevelem=(char*)calloc(MAX,sizeof(char));
    strcpy(prevelem,"0");
    if(n==0)
    {
        return prevelem;
    }
    char *currelement=(char*)calloc(MAX,sizeof(char));
    strcpy(currelement,arr[0]);
    int i=1;
    while(i<n)
    {
        char *temp=intal_add(prevelem,arr[i]);
        if(intal_compare(temp,currelement)==1)
        {
            strcpy(prevelem,currelement);
            strcpy(currelement,temp);
        }
        else
        {
            strcpy(prevelem,currelement);
        }

        i++;
        free(temp);
    }
    

free(prevelem);
return currelement;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{

    if(k>n)
    {
        char *res = (char *)calloc(MAX,sizeof(char));
        strcpy(res,"0");
        return res;
    }
    if(k>n/2)
    {
        k=n-k;
    }

    char **result = (char **) calloc(k+1, sizeof(char*));
    for (int i = 0; i < k + 1; i++) 
    {
        result[i] = (char *) calloc(MAX, sizeof(char));
        if(i==0)
        {
            strcpy(result[i], "1");
        }
        else
        {
            strcpy(result[i],"0");
        }
        
    }
    for(int i=1;i<=n;i++)
    {
        int temp = i < k ? i : k;
        for(int j=temp; j > 0; j--)
        {
            char *temp=result[j];
            result[j]=intal_add(result[j],result[j-1]);
            free(temp);
        }
    }
    for(int i=0;i<k;i++)
    {
        free(result[i]);
    }
    return result[k];
}

char* intal_mod(const char* intal1, const char* intal2)
{
    int length1=strlen(intal1);
    int length2=strlen(intal2);
    char *dividend=(char *) calloc(MAX, sizeof(char));
    strcpy(dividend,intal1);
    char *divisor=(char*)calloc(MAX,sizeof(char));
    strcpy(divisor,intal2);
    while(intal_compare(dividend,divisor)>=0)
    {
        char *newdividend=(char*)calloc(MAX,sizeof(char));
        int ind=0;
        int x=0;
        while(ind<length2)
        {
            newdividend[ind++]=dividend[x++];
        }
        newdividend[ind]='\0';
        if(intal_compare(newdividend,divisor)==-1)
        {   
            int ind=0;
            int x=0;
            while(ind<length2+1)
            {
                newdividend[ind++]=dividend[x++];
            }
        newdividend[ind]='\0';
        }
        int new_length=strlen(newdividend);
        while(intal_compare(newdividend,divisor)>=0)
        {
            char * temp=newdividend;
            newdividend=intal_diff(newdividend,divisor);
            free(temp);
        }
        if(intal_compare(newdividend,"0")==0)
        {
            int ind=0;
            int x=new_length;
             while(x<length1)
            {
                newdividend[ind++]=dividend[x++];
            }
            newdividend[ind]='\0';
            strcpy(dividend,newdividend);
        }
        else
        {
            char *remdividend=(char*)calloc(MAX,sizeof(char));
            int ind=0;
            int x=new_length;
            while(x<length1)
            {
                remdividend[ind++]=dividend[x++];
            }
            remdividend[ind]='\0';          
            strcat(newdividend, remdividend);
            strcpy(dividend, newdividend);
            free(remdividend);
        }
        free(newdividend);
        dividend=remove_leading_zeroes(dividend);
        length1=strlen(dividend);
    }
    free(divisor);
    return dividend;    
}


char* intal_gcd(const char* intal1, const char* intal2)
{
    if(intal_compare(intal1,"0")==0)
    {
        char *result=(char*)calloc(MAX,sizeof(char));
        strcpy(result,intal2);
        return result;
    }
    char *ans=intal_mod(intal2,intal1);
    char *temp=(char*)calloc(MAX,sizeof(char));
    strcpy(temp,ans);
    free(ans);
    return intal_gcd(temp, intal1);
}
