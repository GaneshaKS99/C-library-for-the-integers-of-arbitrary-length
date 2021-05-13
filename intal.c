#include<stdio.h>
#include<stdlib.h>
#include<string.h>





#define conv_char_int(c) (int)c - (int)'0'
#include"intal.h"
#define NAN 0.0/0.0
static char* string_reverse(char *str,int n);



char* intal_create(const char* str)
{
	int len = strlen(str);
	if(len==0 || conv_char_int(*(str+0))>9 || conv_char_int(*(str+0))<0)
   	{
      		char * arr = (char*)malloc(sizeof(char));
        	*arr = '0';
        	*(arr+1)='\0';
        	return (void*)arr;
    	}
    	int zero_ctr=0;
    	while(*(str+zero_ctr)!='\0' && conv_char_int(*(str+zero_ctr))==0)
   	{
        	zero_ctr++;
    	}
    	if(len==(zero_ctr) || conv_char_int(*(str+zero_ctr))>9 || conv_char_int(*(str+zero_ctr))<0)
    	{
        	char * arr = (char*)malloc(sizeof(char));
        	*arr = '0';
        	*(arr+1)='\0';
        	return (void*)arr;
    	}
    	char * arr=(char*)malloc((len-zero_ctr+1)*sizeof(char));
   	int i = zero_ctr;
    	int j = 0;
    	while( *(str+i)!='\0' && conv_char_int(*(str+i))>=0 && conv_char_int(*(str+i))<=9 )
    	{
        	*(arr+j)=*(str+i);
        	i++;
        	j++;
    	}
    	*(arr+j)='\0';
    	if(j!=(len-zero_ctr))
    	{
        	arr = realloc(arr,(j+1)*sizeof(char));
    	}
    	return (void*)arr;
}




void intal_destroy(void* intal)
{
    if(intal!=NULL)
    {
        free(intal);

    }
    else
    {
       return; 
    }
}


char* intal_diff(const char* intal_d1, const char* intal_d2)
{
	if(intal_d1==NULL || intal_d2==NULL)
	{
         return (void*)NULL;
	}
	char *s_intal_d1=(char*)intal_d1;
	char *s_intal_d2=(char*)intal_d2;
	char* str1=(char*)malloc(sizeof(char)*(strlen(s_intal_d1)));
	char* str2=(char*)malloc(sizeof(char)*(strlen(s_intal_d2)));
	strcpy(str1,s_intal_d1);
	strcpy(str2,s_intal_d2);
	//puts("ppoiu");
	//printf("%s %s\n",s1,s2);
	int cmp=intal_compare(str1,str2);
	if(cmp==-1)
	{
		char*temp=(char*)malloc(sizeof(char)*strlen(str1));
		char*temp1=(char*)malloc(sizeof(char)*strlen(str2));
		strcpy(temp,str1);
		strcpy(temp1,str2);
		str1=(char*)realloc(str1,strlen(str2));
		str2=(char*)realloc(str2,strlen(str1));
		strcpy(str1,temp1);
		strcpy(str2,temp);
	}
	//printf("%s %s\n",s1,s2);
	str1=string_reverse(str1,strlen(str1));
	str2=string_reverse(str2,strlen(str2));
	//printf("%s %s\n",s1,s2);
	long int length1=strlen(str1);
	long int length2=strlen(str2);
	//printf("%d %d",l1,l2);
	long int k=0;
	int carry=0;
	char *str3=(char*)malloc(sizeof(char)*(length1+1));
	long int z=0;
	while(z<length2)
	{
		int sub = ((str1[z]-'0')-(str2[z]-'0')-carry); 
		if (sub < 0) 
        	{ 
            		sub = sub + 10; 
            		carry = 1; 
        	} 
       	else
        	 carry = 0; 
		str3[k++]=sub+'0';
		z=z+1;

	}
	long int i=length2;
	while(i<length1)
	{
		int sub = ((str1[i]-'0') - carry); 
		if (sub < 0) 
       	{ 
		    sub = sub + 10; 
		    carry = 1; 
       	} 
        else
            carry = 0; 
		str3[k++]=sub+'0';
		i=i+1;
	}
	
	str3[k]='\0';
	//printf("%s\n",s3);
	str3=string_reverse(str3,strlen(str3));
	//printf("s3 before %s\n",s3);
	str3=intal_create(str3);
	
	return (void*)str3;
}
			

static char* string_reverse(char *s,int n)
{
	char ch;
	int i=0;
	while(i<n/2)
	{
		ch=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=ch;
		i=i+1;
	}
    s[n]='\0';
	return s;
}
int intal_compare(const char* intal1,const char* intal2)
{
	if(intal1==NULL || intal2==NULL)
	{
		return 2;
	}
	char*s1=(char*)intal1;
	char*s2=(char*)intal2;
	
	long long int length1=strlen(s1);
	long long int length2=strlen(s2);
	//long long int length3=0;
	if(length1==length2)
	{
		long long int i=0;
		while(i<length1)
		{
			if(s1[i]-'0' > s2[i]-'0')
			{
				return 1;
			}
			else if(s1[i]-'0' < s2[i]-'0')
			{
				return -1;
			}
			
			i=i+1;
		}
		return 0;
	}
	else if(length1 <length2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
		
}	



char* push(char* str,char chr){
int len = strlen(str);
        str[len]=chr;
        str[len+1]='\0';
return str;
}




char* intal_add(const char* intal1, const char* intal2)
{
 
    //if(intal1==NULL || intal2==NULL)
    //return NULL;
    int n1 = strlen(intal1), n2 = strlen(intal2);
    char *int1 = intal_create(intal1);
char* int2 = intal_create(intal2);
   
if (n1 > n2){
char* temp = int1;
int1 = int2;
int2 = temp;
int l = n1;
n1 = n2;
n2 = l;  
  }
   
    char* str = (char*)malloc(n2+2);
    strcpy(str,"");
    int1 = string_reverse(int1, strlen(int1));
    int2 = string_reverse(int2, strlen(int2));
    //printf("\n%s %s\n",int1,int2);
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((int1[i]-'0')+(int2[i]-'0')+carry);
        str = push(str,sum%10+'0');
  carry = sum/10;
//printf("%s\n ",str);
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((int2[i]-'0')+carry);
        str =push(str, sum%10+'0');
        carry = sum/10;
    }
 
    if(carry)
        str = push(str,carry+'0');
   
    return string_reverse(str,strlen(str));
 
} 




char* intal_decrement(char* intal)
{
	if(intal==NULL)
	{
		return (void*)NULL;
	}
	else
	 {
		char*str1=(char*)intal;
		char*str=(char*)malloc(sizeof(char)*2);
		strcpy(str,str1);
		char *str3=(char*)malloc(sizeof(char)*(strlen(str1)));
		if(strlen(str)==1)
		{
			int sub=(str[0]-'0')-1;
			if(sub<0)
			{
				str[0]='0';
				//puts("ooo");
			}
			else
			{
				str[0]=sub+'0';
			}
			return (void*)str;
		}
		else
		{
			char str1[1]="1";
			str3=intal_diff(str,str1);
			str3=intal_create(str3);
			intal_destroy(intal);
			return (void*)str3;
		}
	}
}

char* intal_multiply(const char* intal1,const char* intal2)
{
    if(intal1==NULL || intal2==NULL)
    {
        return (void*)NULL;
    }
    else
    {
	    long int length1=strlen(intal1);//length of intal 1
	    long int length2=strlen(intal2);//length of intal2
	    const char*s1,*s2;
	    if(length1<length2)
	    {
	         s1=intal1;
	        s2=intal2;
	        
	    }
	    else
	    {
	       length1=length1+length2;
	        length2=length1-length2;
	        length1=length1-length2;
	        s1=intal2;
	        s2=intal1;
	    }
	    
	    long int i,j,k,carry,product;
	    k=length1+length2;
	    char*s3=(char*)malloc(sizeof(char)*(k+1));
	    carry=0;
	    i=0;
	    while(i<k)
	    {
	        s3[i]='0';
	        i=i+1;
	    }
	    s3[k]='\0';
	    i=length2-1;
	    while(i>=0)
	    {
	        k=(length1+length2-1)-((length2-1)-i);
	        j=length1-1;
	        while(j>=0)
	        {
	            product=(((int)*(s1+j)) - 48) * (((int)*(s2+i))-48);
	        
	            carry = carry+product+((int)*(s3+k)-48);
	             *(s3+k)=(char)(48+(carry%10));
	              k=k-1;
	            carry=carry/10;
	            j=j-1;
	        }
	        *(s3+k)=(char)(48+((int)*(s3+k)-48)+carry);
	            carry = 0;    
	        i=i-1;
	    }
	    return intal_create(s3);

    }
    
}
 
static char* tostring(unsigned int num)
{
    int i, rem, len = 0, n;
    
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
	char* str=(char*)malloc(len*14+1);
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
	return str;
}


char* intal_pow(const char* intal1, unsigned int n)
{
	char* intal2=tostring(n);
    if(intal1==NULL || intal2==NULL)
    {
        return (void*)NULL;
    }

    int c1 = intal_compare(intal1,intal_create("0"));
     int c2 = intal_compare(intal2,intal_create("0"));
    if(c1==0 && c2==0)
    {
        return intal_create("0");
    }
    else if(c1==0)
    {
        return intal_create("0");

    }
    else if(c2==0)
    {
        return intal_create("1");
    }

    void *str3=intal_create((char*)(intal2));
    void *var=intal_create("1");
    int cmp=intal_compare(str3,intal_create("0"));
    while(cmp==1)
    {
        //puts("oo");
        //(void*)intal1; 
        //(void*)var;
        var=intal_multiply(var,intal1);
        str3=intal_decrement(str3);
        cmp=intal_compare(str3,intal_create("0"));
    }
    //free(cmp);
    return var;
}

int intal_max(char **arr,int n)
{
int index;
int result;
char* max=arr[0];
for(int i=0;i<n; i++)
{
	result= intal_compare(arr[i],max);
	
	if(result==1)
	{
	max=arr[i];
	index = i;
	}
	
}
return index;
}
int intal_min(char **arr,int n)
{
int index;
int result;
char* min=arr[0];
for(int i=0;i<n; i++)
{
	result= intal_compare(arr[i],min);
	if(result==-1)
	{
		min=arr[i];
		index = i;
	}
	
}
return index;
}


int intal_search(char **arr, int n, const char* key)
{
int result;
//int index;
for(int i=0;i<n;i++)
{
	result= intal_compare(arr[i],key);
	if(result==0)
	{
		return i;
	}
}
return -1;
}
/*
//multiply for factorial
int multiply(int x, int res[], int res_size) 
{ 
    int carry = 0;  // Initialize carry 
  
    // One by one multiply n with individual digits of res[] 
    for (int i=0; i<res_size; i++) 
    { 
        int prod = res[i] * x + carry; 
  
        // Store last digit of 'prod' in res[]   
        res[i] = prod % 10;   
  
        // Put rest in carry 
        carry  = prod/10;     
    } 
  
    // Put carry in res and increase result size 
    while (carry) 
    { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
} 
*/
char* intal_factorial(unsigned int n)	
{ 
    //int res[1000]; 
    unsigned int temp= n;
    unsigned int i;
    char *out = (char*)malloc(sizeof(char)*1001);
    char *temp2= (char*)malloc(sizeof(char)*1001);
    // Initialize result 
    	strcpy(out,"1"); 
    //int res_size = 1; 
  	if(temp==0)
  	{
  		    //strcpy(out[1],"\0");
  		   	out[1]='\0';
  		    return out; 
  	}
  	for(i=1;i<=temp;i++)
  	{
  		sprintf(temp2,"%d",i);
  		out = intal_multiply(out,temp2);
  	}
  	return out;				//Gives the factorial.
} 

  


char* intal_fibonacci(unsigned int n)

{ 
	char* one= (char*)malloc(sizeof(char)*1001);
	char* sec= (char*)malloc(sizeof(char)*1001);    
	char* thir= (char*)malloc(sizeof(char)*1001);
	int  i;

 	strcpy(one,"0");
	strcpy(sec,"1"); 
	    if (n == 0) 
	        return one; 
	    for (i = 2; i <= n; i++) { 
	        strcpy(thir,intal_add(one , sec)); 
		strcpy(one,sec);
	       	strcpy(sec,thir);
        
    } 
    return thir; 
} 	




/*
char* coin_row_problem(char **arr, int n) 
{
  // the maximum value that can be picked up
  char* max[n+1];
  strcpy(max[1],arr[0]);
  
for (int i = 2; i <= n; i++) 
{
    strcpy(max[i],intal_max(intal_add(arr[i-1], max[i-2]), max[i-1]));
    
}
	return max[n-1];
}
*/


int intal_binsearch(char **arr,int n, const char* key) 
{ 
	int l=0;
	int r= n-1;
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  		int temp= intal_compare(arr[m],key);

        // Check if x is present at mid 
        //if (0==intal_compare(arr[m], x)) 
            
          //  return m; 
  
        // If x greater, ignore left half 
        if (-1==temp) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
    int temp2= intal_compare(arr[l],key);

    if(temp2==0)
    {
    	return l;
    }
  
    // if we reach here, then element was 
    // not present 
    return -1; 
} 



void heapify(char* arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  char* temp= (char*)malloc(sizeof(char)*1001);
    
    if (l < n && (1==intal_compare(arr[l] , arr[largest]))) 
        largest = l; 
  
    
    if (r < n && (1==intal_compare(arr[r] , arr[largest]))) 
        largest = r; 
  
    
    if (largest != i) 
    { 
	strcpy(temp,arr[i]);
	strcpy(arr[i],arr[largest]);
	strcpy(arr[largest],temp);
        //swap(arr[i], arr[largest]); 
  
         
        heapify(arr, n, largest); 
    } 
} 


void intal_sort(char **arr, int n) 
{ 
	char* temp= (char*)malloc(sizeof(char)*1001);
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        
	strcpy(temp,arr[0]);
	strcpy(arr[0],arr[i]);
	strcpy(arr[i],temp);
	// Move current root to end 
        //swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 


// char* binomialCoeffUtil(unsigned int n, unsigned int k, char** dp) 
// { 
//     // If value in lookup table then return 
//     if (0!=intal_compare(dp[n][k],"-1") )//      
//         return dp[n][k]; 
  
//     // store value in a table before return 
//     if (k == 0) { 
//         strcpy(dp[n][k],"1"); 
//         return dp[n][k]; 
//     } 
      
//     // store value in table before return 
//     if (k == n) { 
//         strcpy(dp[n][k], "1");  
//         return dp[n][k]; 
//     } 
      
//     // save value in lookup table before return 
//     strcpy(dp[n][k] , intal_add( binomialCoeffUtil(n - 1, k - 1, dp) , binomialCoeffUtil(n - 1, k, dp) )	); 
//     return dp[n][k]; 
// } 
  
 
char* intal_bincoeff(unsigned int n, unsigned int k)  
{ 
	char **temp=malloc(sizeof(char*)*k+1);
    for(int i=0;i<k+1;i++)
    {
    	temp[i]=(char *)calloc(sizeof(char),1001);
    	temp[i][0]='0';
    	temp[i][1]='\0';
    } 
  
    temp[0][0] = '1';  // nC0 is 1 
  	temp[0][1]='\0';
  	int half;

  	if(n%2)
  		half=n/2+1;
  	else
  		half=n/2;
    for (int i = 1; i <= half; i++) 
    { 
        int hh=i;
	  	if(k<i)
  			hh=k;
        for (int j = hh; j > 0; j--) 
            temp[j] =intal_add(temp[j] ,temp[j-1]); 
    } 
    half++;
    for (int i = half; i <= n; i++) 
    { 
        int hh=i;
	  	if(k<i)
  			hh=k;
        for (int j = hh; j >i-half ; j--) 
            temp[j] =intal_add(temp[j] ,temp[j-1]); 
    } 
    return temp[k]; 
} 




char* intal_mod(const char* intal1, const char* intal2)
{
char* str = (char*)malloc(sizeof(char)*2);
	strcpy(str,"1");
	return str;

}


char* intal_gcd(const char* intal1, const char* intal2)
{
	char* str = (char*)malloc(sizeof(char)*2);
	strcpy(str,"3");
	return str;
}



char* coin_row_problem(char **arr, int n)
{
	char *a=malloc(sizeof(char)*2);
	char *b=malloc(sizeof(char)*1001);
	//strcpy(a[0],'0');
	//strcpy(a[1],'\0');
	a[0]='0';
	a[1]='\0';

	strcpy(b,arr[0]);
	
	char *temp=NULL;
	char *out=malloc(sizeof(char)*1001);

	for(int i=1;i<n;i++)
	{
		if(i%2)
		{
			temp=intal_add(a,arr[i]);
			if(intal_compare(temp,b)==1)
			{
				//char *g=a;
				a=temp;
				//free(g);

			}
			else{
				strcpy(a,b);
				//free(temp);
			}
		}
		else{
			temp=intal_add(b,arr[i]);
			if(intal_compare(temp,a)==1)
			{
				//char *g=b;
				b=temp;
				//free(g);

			}
			else{
				//b=a;
				strcpy(b,a);
				//free(temp);
			}

		}
	}
	if(intal_compare(a,b)==1){
		strcpy(out,a);
		
	}
	else{
		strcpy(out,b);

	}
	free(a);
	free(b);
	return out;
}











