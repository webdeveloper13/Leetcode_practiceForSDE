/*Given a string S consisting of lowercase latin letters, arrange all its letters in lexographical order using Counting Sort.*/


char* countSort(char arr[])
{
int a[26];
for(int i=0;i<26;i++)
a[i]= 0;
for(int i=0;arr[i]!='\0';i++){
a[arr[i]-97]++;
}
int j=0;
for(int i = 0;i<26;i++){
while(a[i]>0){
arr[j++]= (char) (i+97);
a[i]--;
}
}
return(arr);
    